#pragma once
#include <cmath>

bool nearlyEquals(float a, float b, float tolerance)
{
    return std::fabs(a - b) < tolerance;
}
