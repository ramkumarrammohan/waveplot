#ifndef SAWTOOTHGENERATOR_H
#define SAWTOOTHGENERATOR_H

#include "common.h"

class SawtoothGenerator
{
public:
    SawtoothGenerator();

    Point getPlot();

private:
    int _bufferReadPtr = 0;
    int _x = 0;
};

#endif // SAWTOOTHGENERATOR_H
