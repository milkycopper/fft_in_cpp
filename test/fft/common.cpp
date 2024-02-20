#include "common.h"

Float random_float()
{
    return Float(std::rand()) / Float(RAND_MAX);
}