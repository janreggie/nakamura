/*
Nakamura Backend
Backend for Nakamura, the RC Circuit Simulator
*/

#include <cstdio>
#include <cmath>
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
tpFile = tmpfile();

/*
writeToTemp: void function that will do the appropriate maths (fucking ODEs)
to the temporary file to be retrieved later.
*/
void writeToTemp
{
  // lol
}
