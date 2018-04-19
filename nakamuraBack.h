/*
 Nakamura Backend
 Backend for Nakamura, the RC Circuit Simulator
 */

#include <cstdio>
#include <cmath>
#include <string>

#ifndef M_PI
  #define M_PI 3.14159265358979323846
#endif

// global variables desu

/*
 VAmp: voltage source amplitude (Volts)
 VFre: voltage source frequency (rad/s)
 VPha: voltage source phase (radians)
 VSrc: voltage source type (integer)
 0: sinusoid
 1: squarewave
 2: triangular wave
 VNu: initial voltage at t==0 (Volts)
 */
double VAmp, VFre, VPha, VNu;
int VSrc;

/*
 TStart: start time (seconds)
 TStop: end time (seconds)
 TNum: number of samples to be taken (long long)
 */
double TStart, TStop;
long long TNum;

/*
 Res: resistance (Ohms)
 Cap: capacitance (Farads)
 */
double Res, Cap;

/*
 Vin: double->double function for the voltage in terms of time
 and in terms of the above values
 input: time in seconds
 output: voltage in volts
 */
double Vin (double t)
{
  if (VSrc == 0)  //sinusoidal
  {
       return VAmp * sin(VFre * t - VPha);
    // frequency is b/2pi, wherein Asin(bt), wherein A is amplitude. therefore, b is 2pi * freq.
  }

  if (VSrc == 1)  //square
  {
    double period = 2 * M_PI/VFre;
    if (fmod(t,period) <= period/2)
      return VAmp;
    //first half of the cycle
    if (fmod(t,period) >= period/2)
      return (-1) * VAmp;
    //second half of the cycle
  }

  if (VSrc == 2)  //triangular
  {
    double period = 2 * M_PI/VFre;
    double m = 4 * VAmp/period;
    if (fmod(t,period) <= period/2)
      return m * fmod(t,period) - VAmp;
    //first half of the cycle
    if (fmod(t,period) >= period/2)
      return (-1) * m * (fmod(t,period) - period/2) + VAmp;
    //second half of the cycle
  }
  //these are from point-slope formula.

  else
  {
    return 0;
  }
  //return 0.0;
}

/*
 tpFile: our temporary file
 Since there'll be a lot of numbers involved, it is best to store
 the data to a temporary file to be recovered and plotted later.
 The temporary file should contain the output voltage already.

 SYNTAX FOR TEMPORARY FILE: time-space-vout e.g.

 0 1.2
 0.000001 1.19532
 0.000002 1.99320
 */
FILE * tpFile;

/*
 all the functions that were supposed to be lambdas
 but wxDev hates C++11 and is a horrible IDE overall.
 */
double dVin(double t)  // first differential of Vin
{
  double TStep = (TStop - TStart) / TNum;
  return ((Vin(t+TStep) - Vin(t)) / TStep);
}

double f (double x, double y)  // differential equation
{
  return (dVin(x) - y / (Res*Cap));
}

/*
 writeToTemp: void function that will do the appropriate maths (fucking ODEs)
 to the temporary file to be retrieved later.
 */
void writeToTemp ()
{
  // First, open up the file
  tpFile = tmpfile();

  // Determine our step size for time
  // look at all the vars starting with TSt lol
  double TStep = (TStop - TStart) / TNum;

  // Note that we shall be using classical fourth-order Runge-Kutta
  // Press et.al: Numerical Recipes The Art of Scientific Computing

  // do some variables
  double k1, k2, k3, k4;  // to be used for later; just allocate mem now
  double TNow = 0;  // what's the current time?
  double Vout = VNu;  // output voltage at a certain time (HIGHLY IMPORTANT)
  while (TNow < TStop)
  {
    k1 = TStep * f(TNow, Vout);
    k2 = TStep * f(TNow + TStep/2, Vout + k1/2);
    k3 = TStep * f(TNow + TStep/2, Vout + k2/2);
    k4 = TStep * f(TNow + TStep, Vout + k3);
    Vout += k1/6 + k2/3 + k3/3 + k4/6;  // nothing should go wrong, rite?
    TNow += TStep;
    if (TNow > TStart)
    {
      // in that case, put it in the temp file
      std::string temp = std::to_string(TNow)+' '+std::to_string(Vout)+'\n';
      fputs(temp.c_str(), tpFile);
    }
  }
}
