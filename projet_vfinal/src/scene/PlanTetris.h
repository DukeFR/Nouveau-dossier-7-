#ifndef PLANTETRIS_H_INCLUDED
#define PLANTETRIS_H_INCLUDED
#include <random>
#include "../maillage/Carre4.h"
#include "../maillage/SCarre.h"
#include "../maillage/TCarre.h"
#include "../maillage/ligne.h"
#include "../maillage/LCarre.h"
#include <vector>
#include "plan.h"

class PlanTetris : public Plan///Classe PlanTetris
{
    public:
        PlanTetris(std::mt19937 rg1); ///Constructeur
        void creerPlan(Svgfile&svgout,int &choix); ///Dessin le plan sur le svg

};


#endif // PLANTETRIS_H_INCLUDED
