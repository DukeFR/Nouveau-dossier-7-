#include <iostream>
#include "drapeau.h"
#include "../svg/svgfile.h"
#include "../maillage/forme.h"
#include <vector>

Drapeau::Drapeau(double x, double y,double taille)//constructeur de drapeau
:Element{x,y},m_taille(taille)
{//on cree le mat du drapeau
    mesSommets.push_back(ajouterSommet(x,y-300*taille));//on met tous les sommets dont on a besoin
    mesSommets.push_back(ajouterSommet(x+10*taille,y-300*taille));
    mesSommets.push_back(ajouterSommet(x,y));
    mesSommets.push_back(ajouterSommet(x+10*taille,y));
    mesSommets.push_back(ajouterSommet(x+15*taille,y-290*taille));
    mesSommets.push_back(ajouterSommet(x+10*taille,y-150*taille));
    mesSommets.push_back(ajouterSommet(x+15*taille,y-160*taille));

    mesFormes.push_back(ajouterCarre(mesSommets[0],mesSommets[1],mesSommets[2],mesSommets[3],255,255,255));//on cree les formes
    mesFormes.push_back(ajouterLine(mesSommets[1],mesSommets[4],255,255,255));
    mesFormes.push_back(ajouterLine(mesSommets[5],mesSommets[6],255,255,255));
}

Drapeau_fr::Drapeau_fr(double x, double y,double taille)//constructeur
: Drapeau{x,y,taille}
{
    mesSommets.push_back(ajouterSommet(x+80*taille,y-290*taille));//on cree tous les sommets dont a besoin
    mesSommets.push_back(ajouterSommet(x+80*taille,y-160*taille));
    mesSommets.push_back(ajouterSommet(x+140*taille,y-290*taille));
    mesSommets.push_back(ajouterSommet(x+140*taille,y-160*taille));
    mesSommets.push_back(ajouterSommet(x+205*taille,y-290*taille));
    mesSommets.push_back(ajouterSommet(x+205*taille,y-160*taille));

    mesFormes.push_back(ajouterCarre(mesSommets[4],mesSommets[7],mesSommets[6],mesSommets[8],0,0,255));//on cree les formes
    mesFormes.push_back(ajouterCarre(mesSommets[7],mesSommets[9],mesSommets[8],mesSommets[10],255,255,255));
    mesFormes.push_back(ajouterCarre(mesSommets[9],mesSommets[11],mesSommets[10],mesSommets[12],255,0,0));
}


Drapeau_us::Drapeau_us(double x, double y,double taille)//constructeur
: Drapeau(x,y,taille)
{
    mesSommets.push_back(ajouterSommet(x+205*taille,y-290*taille));//on cree tous les sommets dont a besoin
    for(int i=0;i<12;i++)
    {
        mesSommets.push_back(ajouterSommet(x+15*taille,y-(280-10*i)*taille));
        mesSommets.push_back(ajouterSommet(x+205*taille,y-(280-10*i)*taille));
    }
    mesSommets.push_back(ajouterSommet(x+205*taille,y-160*taille));
    mesSommets.push_back(ajouterSommet(x+105*taille,y-290*taille));
    mesSommets.push_back(ajouterSommet(x+105*taille,y-220*taille));

    for(int i=0;i<11;i++)//creation des etoiles
    {
        for (int j=0;j<5;j++)
        {
            if(i%2==0)
            {
                mesSommets.push_back(ajouterSommet(x+(19+8*i)*taille,y-(285-15*j)*taille));
            }
            else
            {
                if((j<4)&&(i<10))
                {
                    mesSommets.push_back(ajouterSommet(x+(19+8*i)*taille,y-(278-15*j)*taille));
                }
            }
        }
    }//on cree les formes
    mesFormes.push_back(ajouterCarre(mesSommets[4],mesSommets[7],mesSommets[8],mesSommets[9],255,0,0));
    mesFormes.push_back(ajouterCarre(mesSommets[6],mesSommets[32],mesSommets[30],mesSommets[31],255,0,0));
    for(int i=8;i<30;i=i+2)
    {
        if(i%4==2)
        mesFormes.push_back(ajouterCarre(mesSommets[i],mesSommets[i+1],mesSommets[i+2],mesSommets[i+3],255,0,0));
        else
            mesFormes.push_back(ajouterCarre(mesSommets[i],mesSommets[i+1],mesSommets[i+2],mesSommets[i+3],255,255,255));
    }
    mesFormes.push_back(ajouterCarre(mesSommets[4],mesSommets[33],mesSommets[20],mesSommets[34],0,0,255));
    for(int i=35;i<85;i++)
    {
        mesFormes.push_back(ajouterEtoile(mesSommets[i],0.2*taille,5,255,255,255));
    }
}
