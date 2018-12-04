#ifndef PLAN3_H_INCLUDED
#define PLAN3_H_INCLUDED
#include "plan.h"
#include <random>
#include "../objet/fusee.h"
#include "../objet/colline.h"
#include "planscene.h"

class Plan3 : public PlanScene//classe fille de PlanScene
{
  public:
  Plan3(std::mt19937 r,int choix);//constructeur
  Fusee* ajouterFusee(double x, double y,bool vol,double taille, uint8_t r, uint8_t g, uint8_t b);//permet d ajouter l element fusee
  Colline* ajouterColline(double x,double y, double r, uint8_t ro, uint8_t g, uint8_t b);//permet d'ajouter l element colline
  void modifierdens(unsigned int densite,std::mt19937 r);//permet de modifier le nombre d element dans le plan
};


#endif // PLAN3_H_INCLUDED
