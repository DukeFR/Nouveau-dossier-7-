#ifndef PLAN2_H_INCLUDED
#define PLAN2_H_INCLUDED
#include "plan.h"
#include <random>
#include "../objet/astronaute.h"
#include "../objet/drapeau.h"
#include "../objet/fond.h"
#include "planscene.h"

class Plan2 : public PlanScene///Plan Lunaire
{
    public:
    Plan2(std::mt19937 r,int choix);///constructeur
    Astronaute* ajouterAstronaute(double x, double y,double taille,uint8_t r, uint8_t g, uint8_t b);//permet d ajouter des elements astronautes
    Drapeau_fr* ajouterDrapeau_fr(double x, double y,double taille);//permet d ajouter des elements drapeau francais
    Drapeau_us* ajouterDrapeau_us(double x, double y,double taille);//permet d ajouter des elements drapeaux usa
    Fond* ajouterFond(double x, double y, double t ,uint8_t r, uint8_t g, uint8_t b);//permet d ajouter des elements fond
    void modifierdens(unsigned int densite,std::mt19937 r);//permet de modif le nombre d objets presents
};


#endif // PLAN2_H_INCLUDED
