// Library:  TextGraph
//
// This example shows the use of dotGraph() from the TextGraph library for Arduino 
// @language Wiring (Arduino)
// @author   David Smith
// @version  1.0	2014 released for use in Public Domain
// @updated  2017

// generate an vertical stripchart graph using text in the monitor
// print the value of a function or input data
// then pass the value to dotGraph(n) to see a graph of the amplitude.
// A quick way to visualize a data stream

// usage: TG.dotGraph(n) to explicitly pick bar and dot characters
//   where n must be a positive integer, and scaled to the width you want. Values of 50 - 100 are typical.
//   and TG is arbitrary name assigned to the instance of TextGraph

// To keep the graph aligned horizontally, the numerical value must be a constant width;
// Using the decimal-to-string function is a good way to format a floating point number
// @see dtostrf(FLOAT,WIDTH,PRECISION,BUFFER); gist.github.com/2343665

// In the example below, a sin function is calculated and printed. The output is scaled to a range of 1 - 60 for plotting

#include <TextGraph.h>

// global variables
char cbuf[16];	   // container to hold formatted number

TextGraph TG(1);   // create an instance of TextGraph named "TG"
// -----------------------------------------------------------------------
void setup(void) {
  Serial.begin(57600);  // set preferred baudrate
  Serial.println("\nPrint a numerical value and add a graph.\n");
}

void loop(void) {
  unsigned int i;
  static float tstep = 0.01;
  static float t = 0;
  float y;
  int y_scaled;

  y = 1.0 * sin(6.2832 * 3.0 * t);  // a simple function to graph
  dtostrf(y, 6, 2, cbuf);           // -nn.nn for consistent format
  Serial.print(cbuf);               // print the actual function's value
  y_scaled = 50 * y + 50;          // scale function to fit Monitor window: set window at least as wide as graph range
  TG.dotGraph(y_scaled);            // dotGraph function, simplest form
  t = t + tstep;
  delay(200);                       // control output rate to screen
}



