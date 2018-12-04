#include <iostream>
#include "astronaute.h"
#include <vector>
#include "../util/util.h"


Astronaute::Astronaute(double x, double y,double taille, uint8_t r, uint8_t g, uint8_t b)//constructeur d astronaute
:Element{x,y},m_taille(taille),color{r,g,b}
{

    x=x+6*taille;//on modifie les coordonnes de depart pour que le point de depart soit au niveau de l epaule gauche
    y=y-20*taille;
    mesSommets.push_back(ajouterSommet(x,y));//on place tous les points dont on a besoin
    mesSommets.push_back(ajouterSommet(x+14*taille,y));
    mesSommets.push_back(ajouterSommet(x+3*taille,y+6*taille));
    mesSommets.push_back(ajouterSommet(x+11*taille,y+6*taille));
    mesSommets.push_back(ajouterSommet(x+7*taille,y+9*taille));

    mesSommets.push_back(ajouterSommet(x+7*taille,y+9*taille));
    mesSommets.push_back(ajouterSommet(x+3*taille,y+12*taille));
    mesSommets.push_back(ajouterSommet(x+11*taille,y+12*taille));
    mesSommets.push_back(ajouterSommet(x+4*taille,y+12*taille));
    mesSommets.push_back(ajouterSommet(x+6*taille,y+12*taille));
    mesSommets.push_back(ajouterSommet(x+4*taille,y+20*taille));
    mesSommets.push_back(ajouterSommet(x+6*taille,y+20*taille));
    mesSommets.push_back(ajouterSommet(x+8*taille,y+12*taille));
    mesSommets.push_back(ajouterSommet(x+10*taille,y+12*taille));
    mesSommets.push_back(ajouterSommet(x+8*taille,y+20*taille));
    mesSommets.push_back(ajouterSommet(x+10*taille,y+20*taille));

    mesSommets.push_back(ajouterSommet(x+2*taille,y-2*taille));
    mesSommets.push_back(ajouterSommet(x+12*taille,y-2*taille));
    mesSommets.push_back(ajouterSommet(x+2*taille,y+11*taille));
    mesSommets.push_back(ajouterSommet(x+12*taille,y+11*taille));

    mesSommets.push_back(ajouterSommet(x+7*taille,y-3*taille));

    mesSommets.push_back(ajouterSommet(x+taille,y+2*taille));
    mesSommets.push_back(ajouterSommet(x+2*taille,y+4*taille));
    mesSommets.push_back(ajouterSommet(x-6*taille,y+6*taille));

    mesSommets.push_back(ajouterSommet(x+13*taille,y+2*taille));
    mesSommets.push_back(ajouterSommet(x+12*taille,y+4*taille));
    mesSommets.push_back(ajouterSommet(x+20*taille,y+6*taille));


    mesFormes.push_back(ajouterCarre(mesSommets[16],mesSommets[17],mesSommets[18],mesSommets[19],r,g,b));//on cree toutes les formes dont a besoin
    modifcol(r,g,b,60,60,60);//on fait varier la couleur
    mesFormes.push_back(ajouterCarre(mesSommets[2],mesSommets[3],mesSommets[6],mesSommets[7],r,g,b));
    modifcol(r,g,b,-30,10,0);
    mesFormes.push_back(ajouterCarre(mesSommets[8],mesSommets[9],mesSommets[10],mesSommets[11],r,g,b));
    mesFormes.push_back(ajouterCarre(mesSommets[12],mesSommets[13],mesSommets[14],mesSommets[15],r,g,b));
    modifcol(r,g,b,20,-20,-10);
    mesFormes.push_back(ajouterPentagone(mesSommets[0],mesSommets[1],mesSommets[2],mesSommets[3],mesSommets[4],r,g,b));
    modifcol(r,g,b,50,50,50);
    mesFormes.push_back(ajouterEllipse(mesSommets[20],r,g,b,4*taille,5*taille));
    mesFormes.push_back(ajouterEllipse(mesSommets[20],0,0,0,4*taille,2*taille));
    modifcol(r,g,b,-70,-30,-40);
    mesFormes.push_back(ajouterTriangle(mesSommets[21],mesSommets[22],mesSommets[23],r,g,b));
    mesFormes.push_back(ajouterTriangle(mesSommets[24],mesSommets[25],mesSommets[26],r,g,b));
}

void modifcol(uint8_t&r,uint8_t &g, uint8_t&b,int depr, int depg,int depb)//permet de faire varier la couleur
{//on rentre notre couleur et les nombres dont on veut deplacer sa couleur et ca cree une nouvelle couleur
    if(r+depr>255)//blindage
    {
        r=255;
    }
    else
    {
        if(r+depr<0)
        {
            r=0;
        }
        else
            r=r+depr;
    }
    if(g+depg>255)
    {
        g=255;
    }
    else
    {
        if(g+depg<0)
        {
            g=0;
        }
        else
            g=g+depg;
    }
    if(b+depb>255)
    {
        b=255;
    }
    else
    {
        if(b+depb<0)
        {
            b=0;
        }
        else
            b=b+depb;
    }
}
