/*
 Nakamura Backend
 Backend for Nakamura, the RC Circuit Simulator
 */

#include <cstdio>
#include <cmath>
#include <string>
#include <fstream>

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
    if (fmod(t,period) <= period/2)  //first half of the cycle
      return VAmp;
    if (fmod(t,period) >= period/2)  //second half of the cycle
      return (-1) * VAmp;
  }
  if (VSrc == 2)  //triangular
  {
    double period = 2 * M_PI/VFre;
    double m = 4 * VAmp/period;
    if (fmod(t,period) <= period/2)  //first half of the cycle
      return m * fmod(t,period) - VAmp;
    if (fmod(t,period) >= period/2)  //second half of the cycle
      return (-1) * m * (fmod(t,period) - period/2) + VAmp;
  }
  // and otherwise
  return 0;
}

/*
 all the functions that were supposed to be lambdas
 but wxDev hates C++11 and is a horrible IDE overall.
 */
double dVin (double t)  // first differential of Vin
{
  double TStep = (TStop - TStart) / TNum;
  return ((Vin(t+TStep) - Vin(t)) / TStep);
}

double f (double x, double y)  // differential equation
{
  return (dVin(x) - y / (Res*Cap));
}

/*
 writeOut: void function that will do the appropriate maths (fucking ODEs)
 to the temporary file to be retrieved later.
 */
void writeOut ()
{
  std::string VType;
  if (VSrc == 0)
    VType = "Sinusoidal";
  else if (VSrc == 1)
    VType = "Rectangular";
  else if (VSrc == 2)
    VType = "Triangular";

  // First, open up the file
  std::ofstream output;
  output.open ("RCOutput.csv");
  //block of text containing initial informations
  output << "Voltage Source: " << VType << std::endl;
  output << "Amplitude: " << VAmp << "V\n";
  output << "Frequency: " << VFre << "rad/s\n";
  output << "Phase: " << VPha << "rad\n";
  output << "Resistance: " << Res << "Ohm\n";
  output << "Capacitnace: " << Cap << "Farads\n";
  output << "Initial Voltage for Capacitance: " << VNu << "V\n";
  output << "Start: " << TStart << "s  Stop: " << TStop << "s\n";
  output << "Data points: " << TNum << std::endl << std::endl;

  // Determine our step size for time
  // look at all the vars starting with TSt lol
  double TStep = (TStop - TStart) / TNum;

  // Note that we shall be using classical fourth-order Runge-Kutta
  // Press et.al: Numerical Recipes The Art of Scientific Computing

  // do some variables
  double k1, k2, k3, k4;  // to be used for later; just allocate mem now
  double TNow = 0;  // what's the current time?
  double Vout = Vin(0) - VNu;  // output voltage at a certain time (HIGHLY IMPORTANT)

  // the table thingy
  output << "Time" << "," << "Vin" << "," << "VOut" << std::endl;
  while (TNow < TStop)
  {
    k1 = TStep * f(TNow, Vout);
    k2 = TStep * f(TNow + TStep/2, Vout + k1/2);
    k3 = TStep * f(TNow + TStep/2, Vout + k2/2);
    k4 = TStep * f(TNow + TStep, Vout + k3);
    Vout += k1/6 + k2/3 + k3/3 + k4/6;  // nothing should go wrong, rite?
    if (TNow > TStart) // in that case, put it in the temp file
      output << TNow << "," << Vin(TNow) << "," << Vout << std::endl;
    TNow += TStep;  // to not make the loop infinite
  }
}
