#include <iostream>
#include "fond.h"

Fond::Fond(double x, double y,double t, uint8_t r, uint8_t g, uint8_t b)
:Element{x,y},color{r,g,b}
{
    mesSommets.push_back(ajouterSommet(x,y));//on cree les sommets
    mesSommets.push_back(ajouterSommet(x+1000,y));
    mesSommets.push_back(ajouterSommet(x,y+t));
    mesSommets.push_back(ajouterSommet(x+1000,y+t));
    mesFormes.push_back(ajouterCarre(mesSommets[0],mesSommets[1],mesSommets[2],mesSommets[3],r,g,b));//on cree la forme
}
