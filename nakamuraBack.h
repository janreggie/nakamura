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
VFre: voltage source frequency (Volts)
VPha: voltage source phase (radians)
VSrc: voltage source type (integer)
  0: sinusoid
  1: squarewave
  2: triangular wave
VNu: initial voltage (of the capacitor!) at t==0 (Volts)
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
VOMax, VOMin: maximum and minimum values for output voltage.
Both shall be used for graphing the output voltages.
*/
double VOMax = 0, VOMin = 0;

/*
Vin: double->double function for the voltage in terms of time
and in terms of the above values
input: time in seconds
output: voltage in volts
*/
double Vin (double t)
{
  return 0.0;
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
  // and now for lambda function
  auto dVin = [&TStep](double t) -> double
  {
    return (Vin(t+TStep) - Vin(t)) / TStep;
  };

  // Note that we shall be using classical fourth-order Runge-Kutta
  // Press et.al: Numerical Recipes The Art of Scientific Computing
  // lambda function for the differential equation
  auto f = [&dVin](double x, double y) -> double
  {
    return (dVin(x) - y/(Res*Cap));
  };
  // do some variables
  double k1, k2, k3, k4;  // to be used for later; just allocate mem now
  double TNow = 0;  // what's the current time?
  // Note VNu is vital for initial condition!
  double Vout = Vin(0) - VNu;  // output voltage at a certain time (HIGHLY IMPORTANT)
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
      // and check VOMax and VOMin
      if (Vout > VOMax) VOMax = Vout;
      if (Vout < VOMin) VOMin = Vout;
    }
  }
}
