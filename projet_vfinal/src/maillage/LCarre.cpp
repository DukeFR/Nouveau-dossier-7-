#include "LCarre.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <string>

LettreCarre::LettreCarre(std::vector<Sommet*> lSommets) : Carre(lSommets,util::alea(0,255),util::alea(0,255),util::alea(0,255)) ///Constructeur de L Carr�
{
        lSommets.clear();
        liCarre.push_back(this); ///Cr�ation du 1er Carr�
        Sommet* s1=this->getSommetsCarre2(); ///On r�cup�re les sommets pour faire le 2�me Carr�
        lSommets.push_back(s1);
        Sommet* s2=this->getSommetsCarre3();
        lSommets.push_back(s2);
        Sommet *s3=new Sommet{s1->getm_position().getX(),s1->getm_position().getY()+20};
        lSommets.push_back(s3);
        Sommet *s4 =new Sommet{s2->getm_position().getX(),s2->getm_position().getY()+20};
        lSommets.push_back(s4);
        Carre *c1=new Carre{lSommets,0,255,0};
        liCarre.push_back(c1); ///Cr�ation du 2�me Carr�
        lSommets.clear();
        lSommets.push_back(s3);
        lSommets.push_back(s4); ///De m�me pour le 3�me Carr�
        Sommet *s5=new Sommet{s3->getm_position().getX(),s3->getm_position().getY()+20};
        lSommets.push_back(s5);
        Sommet *s6 =new Sommet{s4->getm_position().getX(),s4->getm_position().getY()+20};
        lSommets.push_back(s6);
        Carre *c2=new Carre{lSommets,0,255,0}; ///Cr�ation du 3�me Carr�
        liCarre.push_back(c2);
        lSommets.clear();
        lSommets.push_back(s4); ///De m�me pour le 4�me Carr�
        lSommets.push_back(s6);
        Sommet *s7=new Sommet{s4->getm_position().getX()+20,s4->getm_position().getY()};
        lSommets.push_back(s7);
        Sommet *s8 =new Sommet{s6->getm_position().getX()+20,s6->getm_position().getY()};
        lSommets.push_back(s8);
        Carre *c3=new Carre{lSommets,0,255,0};
        liCarre.push_back(c3); ///Cr�ation du 4�me Carr�
}

void LettreCarre::dessiner(Svgfile& svgout,Couleur c) ///Dessin sur le svg
{
    for(unsigned int i=0; i<liCarre.size(); i++) ///Cr�ation du carr� et des contours
    {
        svgout.addSquare(liCarre[i]->getSommetsCarre0()->getm_position().getX(),liCarre[i]->getSommetsCarre0()->getm_position().getY(),liCarre[i]->getSommetsCarre1()->getm_position().getX(),liCarre[i]->getSommetsCarre1()->getm_position().getY(),liCarre[i]->getSommetsCarre2()->getm_position().getX(),liCarre[i]->getSommetsCarre2()->getm_position().getY(),liCarre[i]->getSommetsCarre3()->getm_position().getX(),liCarre[i]->getSommetsCarre3()->getm_position().getY(),c);
        svgout.addLine(liCarre[i]->getSommetsCarre2()->getm_position().getX(),liCarre[i]->getSommetsCarre2()->getm_position().getY(),liCarre[i]->getSommetsCarre3()->getm_position().getX(),liCarre[i]->getSommetsCarre3()->getm_position().getY(),"gold");
        svgout.addLine(liCarre[i]->getSommetsCarre0()->getm_position().getX(),liCarre[i]->getSommetsCarre0()->getm_position().getY(),liCarre[i]->getSommetsCarre1()->getm_position().getX(),liCarre[i]->getSommetsCarre1()->getm_position().getY(),"gold");
        svgout.addLine(liCarre[i]->getSommetsCarre1()->getm_position().getX(),liCarre[i]->getSommetsCarre1()->getm_position().getY(),liCarre[i]->getSommetsCarre3()->getm_position().getX(),liCarre[i]->getSommetsCarre3()->getm_position().getY(),"gold");
        svgout.addLine(liCarre[i]->getSommetsCarre2()->getm_position().getX(),liCarre[i]->getSommetsCarre2()->getm_position().getY(),liCarre[i]->getSommetsCarre0()->getm_position().getX(),liCarre[i]->getSommetsCarre0()->getm_position().getY(),"gold");
    }

}

