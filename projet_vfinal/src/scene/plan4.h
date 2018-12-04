#ifndef PLAN4_H_INCLUDED
#define PLAN4_H_INCLUDED
#include "plan.h"
#include "../objet/fond.h"
#include "../objet/planete.h"
#include "../objet/etoiles.h"
#include "planscene.h"

class Plan4 : public PlanScene
{
    public:
    Plan4(std::mt19937 r,int choix);

    Fond* ajouterFond(double x, double y,double t, uint8_t r, uint8_t g, uint8_t b);//ajout du fond
    Planete* ajouterPlanete(double x, double y,double t, uint8_t r, uint8_t g, uint8_t b);//ajout d une planete
    Etoiles* ajouterEtoiles(double x, double y,double t,double br);//ajout d etoiles
    void modifierdens(unsigned int densite,std::mt19937 r);//modification de la densite
};

#endif // PLAN4_H_INCLUDED
