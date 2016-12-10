
#include <stdio.h>
#include <stdlib.h>

#include "rpn.h"

#define MAXCOLS 80
#define MAXROWS 40

char plot[MAXROWS][MAXCOLS];

void clearPlot()
{
  for (int i = 0; i < MAXROWS; i++) {
    for (int j = 0; j < MAXCOLS; j++) {
      plot[i][j] = ' ';
    }
  }
}

void printPlot()
{
  for (int i = 0; i < MAXROWS; i++) {
    for (int j = 0; j < MAXCOLS; j++) {
      printf("%c", plot[i][j]);
    }
    printf("\n");
  }
}

void plotXY(int x, int y, char c) {
  if ( x <0 || x>=MAXCOLS || y < 0 || y >=MAXROWS) return;
  plot[y][x]=c;
}

void createPlot( char * funcFile, double minX, double maxX) {
  int nvals = MAXCOLS;
  double yy[MAXCOLS];

  clearPlot();

  // Evaluate function and store in vector yy
  
  double minY = rpn_eval(funcFile, minX);
  double maxY = rpn_eval(funcFile, minX);
  double distX = maxX - minX;
  double stepX = distX / MAXCOLS;
  double x = minX;
  int j = 0;

  for (int i = 0; i < MAXCOLS; i++) {
    yy[i] = rpn_eval(funcFile, x);
    x += stepX;

  }
  //Find max and min y values
  for (int i = 0; i < 80; i++) {
    if (yy[i] < minY)
      minY = yy[i];
    if (yy[i] > maxY)
      maxY = yy[i];
  }
  //Plot x and yaxis
  for (int i = 0; i < MAXCOLS; i++) {
    for (int j = 0; j < MAXROWS; j++) {
      if (j == (MAXROWS/2)) 
        plotXY(i,j,'_');
      if (i == (MAXCOLS/2))
	plotXY(i,j,'|');
    }
  }
  
  double distY = maxY - minY;
  double stepY = distY / MAXROWS;

    // Plot function. Use scaling.
  for (int i = 0; i < MAXCOLS; i++) {
    //for (int j, '*');
    plotXY(i, (int)((maxY - yy[i]) / stepY), '*');
    //}
  }
  // minX is plotted at column 0 and maxX is plotted ar MAXCOLS-1
  // minY is plotted at row 0 and maxY is plotted at MAXROWS-1

  printPlot();

}

int main(int argc, char ** argv)
{
  printf("RPN Plotter.\n");
  
  if (argc < 4) {
    printf("Usage: plot func-file xmin xmax\n");
    exit(1);
  }

  // Get arguments
  double xmin = atof(argv[2]);
  double xmax = atof(argv[3]);
  char *funcName = argv[1];
  createPlot(funcName, xmin, xmax);
}
