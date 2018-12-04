#include "ligne.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <string>

LigneC::LigneC(std::vector<Sommet*> cSommets) : Carre(cSommets,util::alea(0,255),util::alea(0,255),util::alea(0,255)) ///Constructeur de carr�
{
        cSommets.clear();
        lCarre.push_back(this); ///Cr�er le 1er carr�
        Sommet* s1=this->getSommetsCarre2(); ///On r�cup�re les 4 sommets pour cr�er le 2�me Carr�
        cSommets.push_back(s1);
        Sommet* s2=this->getSommetsCarre3();
        cSommets.push_back(s2);
        Sommet *s3=new Sommet{s1->getm_position().getX(),s1->getm_position().getY()+20};
        cSommets.push_back(s3);
        Sommet *s4 =new Sommet{s2->getm_position().getX(),s2->getm_position().getY()+20};
        cSommets.push_back(s4);
        Carre *c1=new Carre{cSommets,0,255,0}; ///Cr�er le 2�me Carr�
        lCarre.push_back(c1);
        cSommets.clear();
        cSommets.push_back(s3); ///De m�me pour le 3�me Carr�
        cSommets.push_back(s4);
        Sommet *s5=new Sommet{s3->getm_position().getX(),s3->getm_position().getY()+20};
        cSommets.push_back(s5);
        Sommet *s6 =new Sommet{s4->getm_position().getX(),s4->getm_position().getY()+20};
        cSommets.push_back(s6);
        Carre *c2=new Carre{cSommets,0,255,0};
        lCarre.push_back(c2);
        cSommets.clear();
        cSommets.push_back(s5); ///De m�me pour le 4�me carr�
        cSommets.push_back(s6);
        Sommet *s7=new Sommet{s5->getm_position().getX(),s5->getm_position().getY()+20};
        cSommets.push_back(s7);
        Sommet *s8 =new Sommet{s6->getm_position().getX(),s6->getm_position().getY()+20};
        cSommets.push_back(s8);
        Carre *c3=new Carre{cSommets,0,255,0};
        lCarre.push_back(c3);


}

void LigneC::dessiner(Svgfile& svgout,Couleur c) ///Dessiner sur le svg la ligne
{
    for(unsigned int i=0; i<lCarre.size(); i++) ///Pour les 4 carr�s on ajoute un carr�, et on fait les contours
    {
        svgout.addSquare(lCarre[i]->getSommetsCarre0()->getm_position().getX(),lCarre[i]->getSommetsCarre0()->getm_position().getY(),lCarre[i]->getSommetsCarre1()->getm_position().getX(),lCarre[i]->getSommetsCarre1()->getm_position().getY(),lCarre[i]->getSommetsCarre2()->getm_position().getX(),lCarre[i]->getSommetsCarre2()->getm_position().getY(),lCarre[i]->getSommetsCarre3()->getm_position().getX(),lCarre[i]->getSommetsCarre3()->getm_position().getY(),c);
        svgout.addLine(lCarre[i]->getSommetsCarre2()->getm_position().getX(),lCarre[i]->getSommetsCarre2()->getm_position().getY(),lCarre[i]->getSommetsCarre3()->getm_position().getX(),lCarre[i]->getSommetsCarre3()->getm_position().getY(),"gold");
        svgout.addLine(lCarre[i]->getSommetsCarre0()->getm_position().getX(),lCarre[i]->getSommetsCarre0()->getm_position().getY(),lCarre[i]->getSommetsCarre1()->getm_position().getX(),lCarre[i]->getSommetsCarre1()->getm_position().getY(),"gold");
        svgout.addLine(lCarre[i]->getSommetsCarre1()->getm_position().getX(),lCarre[i]->getSommetsCarre1()->getm_position().getY(),lCarre[i]->getSommetsCarre3()->getm_position().getX(),lCarre[i]->getSommetsCarre3()->getm_position().getY(),"gold");
        svgout.addLine(lCarre[i]->getSommetsCarre2()->getm_position().getX(),lCarre[i]->getSommetsCarre2()->getm_position().getY(),lCarre[i]->getSommetsCarre0()->getm_position().getX(),lCarre[i]->getSommetsCarre0()->getm_position().getY(),"gold");
    }

}

