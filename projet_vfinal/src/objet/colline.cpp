#include "colline.h"

Colline::Colline(double x,double y, double r, uint8_t ro, uint8_t g, uint8_t b)//constructeur de colline
:Element(x,y-450),m_r(r),m_color(ro,g,b)
{
  mesSommets.push_back(ajouterSommet(x,y));//on place les sommets
  mesFormes.push_back(ajouterCercle(mesSommets[0], m_r,1, ro, g, b));//on cree les formes
  mesFormes.push_back(ajouterCercle(mesSommets[0], m_r,0, 0, 0, 0));
}

