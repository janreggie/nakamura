/*
Nakamura Backend
Backend for Nakamura, the RC Circuit Simulator
*/

#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <string>
#include <fstream> //for testing
#include <iostream> //for testing

#ifndef M_PI
  #define M_PI 3.14159265358979323846
#endif

using namespace std;

// global variables desu

/*
sine: sine wave input
tria: triangular wave input
squa: square wave input
*/
bool sine = false, tria = false, squa = false;

/*
sw1: switch 1 - for sine
sw2: switch 2 - for triangular
sw3: switch 3 - for square

int sw1, sw2, sw3; */

/*
VAmp: voltage source amplitude (Volts)
VFre: voltage source frequency (rad/s) (NOTE: RADIANS PER SECOND!)
VPha: voltage source phase (radians)
VSrc: voltage source type (integer)
  0: sinusoid
  1: square wave
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
  return 0.0;
}

/*
Units_Res: resistance units
Units_Cap: capacitance units
Units_Amp: amplitude units
Units_Freq: frequency units
Units_Pha: phase units
Units_TStart: time start units
Units_TStop: time stop units
Units_IC: IC units 
*/
string Units_Res, Units_Cap, Units_Amp, Units_Freq;
string Units_Pha, Units_TStart, Units_TStop, Units_IC;

/*
Checks for the validity of the input
error: error in user input
error_msg: error message displayed
*/
string error_msg = "INPUT ERROR!\n"
              "Please check proper input in the text fields\n"
              "and choose only 1 voltage source.";
int error;
void ErrorChecker(string value)
{
  int dot_count = 0; //checks for multiple instances of decimal pt
  for (int i = 0; i < value.length(); i ++)
  {
    if (!(isdigit(value[i])) || value.empty())
    {
      if (value[i] == '.') ++dot_count;
      else 
      {
        ++error;
        break;
      }
    }
    else
      continue;
  }
  if(dot_count>0) ++error;
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
//tpFile = tmpfile();

/*
writeToTemp: void function that will do the appropriate maths (fucking ODEs)
to the temporary file to be retrieved later.
*/
/*void writeToTemp ()
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
}*/

