#include <iostream>
#include "etoiles.h"

Etoiles::Etoiles(double x, double y,double t,double br)//constructeur
:Element{x,y}
{
    mesSommets.push_back(ajouterSommet(x,y));//on met les sommets dont a besoin
    mesFormes.push_back(ajouterEtoile(mesSommets[0],t,br,255,255,255));//on cree les formes
}
