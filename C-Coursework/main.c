#include <stdio.h>
#include <math.h>
#include "gnuplot.h"

FILE * gnu;

void GnuPlotOpen(char * title, char * filename) {
    gnu = popen("gnuplot -persistent", "w");
    if (filename != NULL) {
        fprintf(gnu, "set title \"%s\"; set terminal png; set output \"%s.png\"; plot '-' with lines\n", title, filename);
    } else {
        fprintf(gnu, "plot '-' with lines\n");
    }
}

void GnuPlotClose(void) {

    pclose(gnu);
}

void GnuPlotValue(float v1, float v2) {
    fprintf(gnu, "%0.2f %0.2f\n", v1, v2);
}

int functions();

int main() {
   
   functions;

   return 0;

}

int functions(){

     GnuPlotOpen("Airplane Function", "airplane_function");
    
    // Given functions
    float x, y;
    for (x = 0; x < 10; x += 0.1) {
        y = 1 - exp(-x);
        GnuPlotValue(x, y);
    }
    for (x = 10; x < 18; x += 0.1) {
        y = 20 - pow((x - 14), 2);
        GnuPlotValue(x, y);
    }
    for (x = 18; x < 23; x += 0.1) {
        y = 1 - exp(-30 + x);
        GnuPlotValue(x, y);
    }
    for (x = 23; x < 25; x += 0.1) {
        y = 2 * x - 45;
        GnuPlotValue(x, y);
    }
    for (x = 25; x < 27; x += 0.1) {
        y = 5;
        GnuPlotValue(x, y);
    }
    for (x = 27; x < 28; x += 0.1) {
        y = -4 && 2 * x + 118.4;
        GnuPlotValue(x, y);
    }

    for (x = 28; x < 30; x += 0.1) {
        y = 1 - exp(-30 + x);
        GnuPlotValue(x, y);
    }

    // Mirroring on the x-axis

     for (x = 0; x < 10; x += 0.1) {
        y = 1 - exp(-x);
        GnuPlotValue(x, -y);
    }
    for (x = 10; x < 18; x += 0.1) {
        y = 20 - pow((x - 14), 2);
        GnuPlotValue(x, -y);
    }
    for (x = 18; x < 23; x += 0.1) {
        y = 1 - exp(-30 + x);
        GnuPlotValue(x, -y);
    }
    for (x = 23; x < 25; x += 0.1) {
        y = 2 * x - 45;
        GnuPlotValue(x, -y);
    }
    for (x = 25; x < 27; x += 0.1) {
        y = 5;
        GnuPlotValue(x, -y);
    }
    for (x = 27; x < 28; x += 0.1) {
        y = -4 && 2 * x + 118.4;
        GnuPlotValue(x, -y);
    }

    for (x = 28; x < 30; x += 0.1) {
        y = 1 - exp(-30 + x);
        GnuPlotValue(x, -y);
    }       

    GnuPlotClose();
    
}