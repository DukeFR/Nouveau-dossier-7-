#include <iostream>
#include "fusee.h"
#include "../svg/svgfile.h"


Fusee::Fusee(double x,double y,bool vole, double taille,uint8_t r, uint8_t g, uint8_t b)//constructeur
: Element(x,y),m_vole(vole),m_taille(taille),m_color(r,g,b)
{
  mesSommets.push_back(ajouterSommet(x,y-50*m_taille));//on place les sommets
  mesSommets.push_back(ajouterSommet(x-50*m_taille,y-50*m_taille));
  mesSommets.push_back(ajouterSommet(x+50*m_taille,y-50*m_taille));
  mesSommets.push_back(ajouterSommet(x-50*m_taille,y));
  mesSommets.push_back(ajouterSommet(x+50*m_taille,y));
  mesSommets.push_back(ajouterSommet(x-50*m_taille,y+20*m_taille));
  mesSommets.push_back(ajouterSommet(x+50*m_taille,y+20*m_taille));
  mesSommets.push_back(ajouterSommet(x-50*m_taille,y+40*m_taille));
  mesSommets.push_back(ajouterSommet(x+50*m_taille,y+40*m_taille));
  mesSommets.push_back(ajouterSommet(x-50*m_taille,y+60*m_taille));
  mesSommets.push_back(ajouterSommet(x+50*m_taille,y+60*m_taille));
  mesSommets.push_back(ajouterSommet(x-50*m_taille,y+80*m_taille));
  mesSommets.push_back(ajouterSommet(x+50*m_taille,y+80*m_taille));
  mesSommets.push_back(ajouterSommet(x-50*m_taille,y+300*m_taille));
  mesSommets.push_back(ajouterSommet(x+50*m_taille,y+300*m_taille));
  mesSommets.push_back(ajouterSommet(x-100*m_taille,y+100*m_taille));
  mesSommets.push_back(ajouterSommet(x-50*m_taille,y+100*m_taille));
  mesSommets.push_back(ajouterSommet(x-100*m_taille,y+320*m_taille));
  mesSommets.push_back(ajouterSommet(x-50*m_taille,y+320*m_taille));
  mesSommets.push_back(ajouterSommet(x-75*m_taille,y+80*m_taille));
  mesSommets.push_back(ajouterSommet(x+50*m_taille,y+100*m_taille));
  mesSommets.push_back(ajouterSommet(x+100*m_taille,y+100*m_taille));
  mesSommets.push_back(ajouterSommet(x+50*m_taille,y+320*m_taille));
  mesSommets.push_back(ajouterSommet(x+100*m_taille,y+320*m_taille));
  mesSommets.push_back(ajouterSommet(x+75*m_taille,y+80*m_taille));
  mesSommets.push_back(ajouterSommet(x-50*m_taille,y+300*m_taille));
  mesSommets.push_back(ajouterSommet(x-17*m_taille,y+300*m_taille));
  mesSommets.push_back(ajouterSommet(x-33.5*m_taille,y+400*m_taille));
  mesSommets.push_back(ajouterSommet(x+17*m_taille,y+300*m_taille));
  mesSommets.push_back(ajouterSommet(x+50*m_taille,y+300*m_taille));
  mesSommets.push_back(ajouterSommet(x+33.5*m_taille,y+400*m_taille));
  mesSommets.push_back(ajouterSommet(x-100*m_taille,y+320*m_taille));
  mesSommets.push_back(ajouterSommet(x-50*m_taille,y+320*m_taille));
  mesSommets.push_back(ajouterSommet(x-75*m_taille,y+410*m_taille));
  mesSommets.push_back(ajouterSommet(x+50*m_taille,y+320*m_taille));
  mesSommets.push_back(ajouterSommet(x+100*m_taille,y+320*m_taille));
  mesSommets.push_back(ajouterSommet(x+75*m_taille,y+410*m_taille));
  mesSommets.push_back(ajouterSommet(x,y+450*m_taille));

  mesFormes.push_back(ajouterCercle(mesSommets[0], 52*m_taille,1, r,g,b));//on cree les formes pour faire l element

  mesFormes.push_back(ajouterCarre(mesSommets[1],mesSommets[2],mesSommets[3],mesSommets[4],255,255,255));
  mesFormes.push_back(ajouterCarre(mesSommets[3],mesSommets[4],mesSommets[5],mesSommets[6],r,g,b));
  mesFormes.push_back(ajouterCarre(mesSommets[5],mesSommets[6],mesSommets[7],mesSommets[8],255,255,255));
  mesFormes.push_back(ajouterCarre(mesSommets[7],mesSommets[8],mesSommets[9],mesSommets[10],r,g,b));
  mesFormes.push_back(ajouterCarre(mesSommets[9],mesSommets[10],mesSommets[11],mesSommets[12],255,255,255));
  mesFormes.push_back(ajouterCarre(mesSommets[11],mesSommets[12],mesSommets[13],mesSommets[14],r,g,b));
  mesFormes.push_back(ajouterCarre(mesSommets[15],mesSommets[16],mesSommets[17],mesSommets[18],255,255,255));
  mesFormes.push_back(ajouterCarre(mesSommets[20],mesSommets[21],mesSommets[22],mesSommets[23],255,255,255));
  mesFormes.push_back(ajouterTriangle(mesSommets[15], mesSommets[16], mesSommets[19],255,255,255));
  mesFormes.push_back(ajouterTriangle(mesSommets[20], mesSommets[21], mesSommets[24],255,255,255));
if (vole==true)//rajoute les flammes a la fusee
{
  mesFormes.push_back(ajouterTriangle(mesSommets[25], mesSommets[26], mesSommets[27],255,160,2));
  mesFormes.push_back(ajouterTriangle(mesSommets[28], mesSommets[29], mesSommets[30],255,160,2));
  mesFormes.push_back(ajouterTriangle(mesSommets[31], mesSommets[32], mesSommets[33],255,100,10));
  mesFormes.push_back(ajouterTriangle(mesSommets[34], mesSommets[35], mesSommets[36],255,100,10));
  mesFormes.push_back(ajouterTriangle(mesSommets[26], mesSommets[28], mesSommets[37],255,100,10));
}
}
