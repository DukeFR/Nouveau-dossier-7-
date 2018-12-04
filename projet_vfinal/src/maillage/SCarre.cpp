#include "SCarre.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <string>

SCarre::SCarre(std::vector<Sommet*> SSommets) : Carre(SSommets,util::alea(0,255),util::alea(0,255),util::alea(0,255)) ///Constructeur de Scarré
{
        SSommets.clear();
        vsCarre.push_back(this); ///Création du 1er Carré
        Sommet* s1=this->getSommetsCarre2(); ///On récupère les sommets pour créer le 2ème Carré
        SSommets.push_back(s1);
        Sommet* s2=this->getSommetsCarre3();
        SSommets.push_back(s2);
        Sommet *s3=new Sommet{s1->getm_position().getX(),s1->getm_position().getY()+20};
        SSommets.push_back(s3);
        Sommet *s4 =new Sommet{s2->getm_position().getX(),s2->getm_position().getY()+20};
        SSommets.push_back(s4);
        Carre *c1=new Carre{SSommets,0,255,0}; ///On construit le 2ème Carré
        vsCarre.push_back(c1);
        SSommets.clear();
        SSommets.push_back(s2); ///De même pour le 3ème Carré
        SSommets.push_back(s4);
        Sommet *s5=new Sommet{s2->getm_position().getX()+20,s2->getm_position().getY()};
        SSommets.push_back(s5);
        Sommet *s6 =new Sommet{s4->getm_position().getX()+20,s4->getm_position().getY()};
        SSommets.push_back(s6);
        Carre *c2=new Carre{SSommets,0,255,0}; ///On créer le 3ème Carré
        vsCarre.push_back(c2);
        SSommets.clear();
        SSommets.push_back(s4); ///De même pour le 4ème Carré
        SSommets.push_back(s6);
        Sommet *s7=new Sommet{s4->getm_position().getX(),s4->getm_position().getY()+20};
        SSommets.push_back(s7);
        Sommet *s8 =new Sommet{s6->getm_position().getX(),s6->getm_position().getY()+20};
        SSommets.push_back(s8);
        Carre *c3=new Carre{SSommets,0,255,0};
        vsCarre.push_back(c3); ///On créer le 4ème Carré
}

void SCarre::dessiner(Svgfile& svgout,Couleur c) ///Dessin sur le svg
{
    for(unsigned int i=0; i<vsCarre.size(); i++) ///Boucle pour créer les carrés + contours
    {
        svgout.addSquare(vsCarre[i]->getSommetsCarre0()->getm_position().getX(),vsCarre[i]->getSommetsCarre0()->getm_position().getY(),vsCarre[i]->getSommetsCarre1()->getm_position().getX(),vsCarre[i]->getSommetsCarre1()->getm_position().getY(),vsCarre[i]->getSommetsCarre2()->getm_position().getX(),vsCarre[i]->getSommetsCarre2()->getm_position().getY(),vsCarre[i]->getSommetsCarre3()->getm_position().getX(),vsCarre[i]->getSommetsCarre3()->getm_position().getY(),c);
        svgout.addLine(vsCarre[i]->getSommetsCarre2()->getm_position().getX(),vsCarre[i]->getSommetsCarre2()->getm_position().getY(),vsCarre[i]->getSommetsCarre3()->getm_position().getX(),vsCarre[i]->getSommetsCarre3()->getm_position().getY(),"gold");
        svgout.addLine(vsCarre[i]->getSommetsCarre0()->getm_position().getX(),vsCarre[i]->getSommetsCarre0()->getm_position().getY(),vsCarre[i]->getSommetsCarre1()->getm_position().getX(),vsCarre[i]->getSommetsCarre1()->getm_position().getY(),"gold");
        svgout.addLine(vsCarre[i]->getSommetsCarre1()->getm_position().getX(),vsCarre[i]->getSommetsCarre1()->getm_position().getY(),vsCarre[i]->getSommetsCarre3()->getm_position().getX(),vsCarre[i]->getSommetsCarre3()->getm_position().getY(),"gold");
        svgout.addLine(vsCarre[i]->getSommetsCarre2()->getm_position().getX(),vsCarre[i]->getSommetsCarre2()->getm_position().getY(),vsCarre[i]->getSommetsCarre0()->getm_position().getX(),vsCarre[i]->getSommetsCarre0()->getm_position().getY(),"gold");
    }

}
