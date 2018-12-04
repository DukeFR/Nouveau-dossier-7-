#include "planete.h"

Planete::Planete(double x, double y,double taille, uint8_t r, uint8_t g, uint8_t b)//constructeur
:Element{x,y},m_taille(taille),color{r,g,b}
{
    mesSommets.push_back(ajouterSommet(x,y));//on cree les sommmets
    mesFormes.push_back(ajouterCercle(mesSommets[0],taille,true,r,g,b));//on cree la forme
}
