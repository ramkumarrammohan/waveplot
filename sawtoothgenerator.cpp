#include "sawtoothgenerator.h"

static const int BUFFER_MAX = 80;
static const int STEP_INCR = 5;

SawtoothGenerator::SawtoothGenerator()
{
}

Point SawtoothGenerator::getPlot()
{
    Point pt;
    pt.x = _x++;
    pt.y1 = _bufferReadPtr * STEP_INCR;

    if (_bufferReadPtr >= BUFFER_MAX)
    {
        pt.y2 = 0;

        _bufferReadPtr = 0;
        return  pt;
    }

    pt.y2 = pt.y1 + STEP_INCR;

    _bufferReadPtr++;

    return  pt;
}

