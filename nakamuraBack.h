/*
Nakamura Backend
Backend for Nakamura, the RC Circuit Simulator
*/

#include <stdio.h>

// global variables desu

/*
VAmp: voltage source amplitude
VFre: voltage source frequency
VPha: voltage source phase
VSrc: voltage source type
  0: sinusoid
  1: squarewave
  2: triangular wave
VNu: initial voltage at t==0
*/
double VAmp, VFre, VPha, VNu;
int VSrc;

/*
TStart: start time
TStop: end time
TNum: number of samples to be taken
*/
double TStart, TStop;
int TNum;

/*
Res: resistance
Cap: capacitance
*/
double Res, Cap;

/*
Vin: double->double function for the voltage in terms of time
and in terms of the above values
*/
double Vin (double t)
{
  return 0.0;
}

/*
tpFile: our temporary file
Since there'll be a lot of numbers involved, it is best to store
the data to a temporary file to be recovered and plotted later.

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
