#include "geometry.h"
bool al(int x, int y)
{
    int s = (x - y) % 2;
    int temp;
    while (y != 0)
    {
        temp = y;
        y = x % y;
        x = temp;
    }
    if ((temp == 1) && (s != 0))
    {
        return true;
    }
    return false;
}