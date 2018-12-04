#ifndef PLAN_H_INCLUDED
#define PLAN_H_INCLUDED
#include "../objet/elements.h"
#include <random>

class Plan///Interface de plan
{
    protected :
    std::mt19937 rg1;///une graine
    public :
    Plan(std::mt19937 r);
};


#endif // PLAN_H_INCLUDED
