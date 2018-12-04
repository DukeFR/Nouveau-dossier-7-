#include "TCarre.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <string>


TeCarre::TeCarre(std::vector<Sommet*> TSommets) : Carre(TSommets,util::alea(0,255),util::alea(0,255),util::alea(0,255)) ///Constructeur Tcarr�
{
        TSommets.clear();
        tCarre.push_back(this);
        Sommet* s1=this->getSommetsCarre0(); ///Cr�ation du 1er Carr� en r�cup�rant ses sommets
        TSommets.push_back(s1);
        Sommet* s2=this->getSommetsCarre2();
        TSommets.push_back(s2);
        Sommet *s3=new Sommet{s1->getm_position().getX()+20,s1->getm_position().getY()};
        TSommets.push_back(s3);
        Sommet *s4 =new Sommet{s2->getm_position().getX()+20,s2->getm_position().getY()};
        TSommets.push_back(s4);
        Carre *c1=new Carre{TSommets,0,255,0}; ///Cr�ation du 1er Carr�
        tCarre.push_back(c1);
        TSommets.clear();
        TSommets.push_back(s3); ///Cr�ation du 2�me Carr� en reprenant la m�me m�thode
        TSommets.push_back(s4);
        Sommet *s5=new Sommet{s3->getm_position().getX()+20,s3->getm_position().getY()};
        TSommets.push_back(s5);
        Sommet *s6 =new Sommet{s4->getm_position().getX()+20,s4->getm_position().getY()};
        TSommets.push_back(s6);
        Carre *c2=new Carre{TSommets,0,255,0}; ///Cr�e le 2�me Carr�
        tCarre.push_back(c2);
        TSommets.clear();
        TSommets.push_back(s4); ///De m�me pour le 3�me Carr�
        TSommets.push_back(s2);
        Sommet *s7=new Sommet{s4->getm_position().getX(),s4->getm_position().getY()+20};
        TSommets.push_back(s7);
        Sommet *s8 =new Sommet{s2->getm_position().getX(),s2->getm_position().getY()+20};
        TSommets.push_back(s8);
        Carre *c3=new Carre{TSommets,0,255,0};
        tCarre.push_back(c3); ///Cr�ation du 3�me Carr�
        TSommets.clear();
        TSommets.push_back(s1); ///De m�me pour le 4�me Carr�
        TSommets.push_back(s2);
        Sommet *s9=new Sommet{s1->getm_position().getX()-20,s1->getm_position().getY()};
        TSommets.push_back(s9);
        Sommet *s10 =new Sommet{s2->getm_position().getX()-20,s2->getm_position().getY()};
        TSommets.push_back(s10);
        Carre *c4=new Carre{TSommets,0,255,0};
        tCarre.push_back(c4); ///Cr�ation du 4�me Carr�
}

void TeCarre::dessiner(Svgfile& svgout,Couleur c) ///Dessin sur le svg
{
    for(unsigned int i=0; i<tCarre.size(); i++) ///Boucle pour parcourir le vector -> Affiche carr� + contour
    {
        svgout.addSquare(tCarre[i]->getSommetsCarre0()->getm_position().getX(),tCarre[i]->getSommetsCarre0()->getm_position().getY(),tCarre[i]->getSommetsCarre1()->getm_position().getX(),tCarre[i]->getSommetsCarre1()->getm_position().getY(),tCarre[i]->getSommetsCarre2()->getm_position().getX(),tCarre[i]->getSommetsCarre2()->getm_position().getY(),tCarre[i]->getSommetsCarre3()->getm_position().getX(),tCarre[i]->getSommetsCarre3()->getm_position().getY(),c);
        svgout.addLine(tCarre[i]->getSommetsCarre2()->getm_position().getX(),tCarre[i]->getSommetsCarre2()->getm_position().getY(),tCarre[i]->getSommetsCarre3()->getm_position().getX(),tCarre[i]->getSommetsCarre3()->getm_position().getY(),"gold");
        svgout.addLine(tCarre[i]->getSommetsCarre0()->getm_position().getX(),tCarre[i]->getSommetsCarre0()->getm_position().getY(),tCarre[i]->getSommetsCarre1()->getm_position().getX(),tCarre[i]->getSommetsCarre1()->getm_position().getY(),"gold");
        svgout.addLine(tCarre[i]->getSommetsCarre1()->getm_position().getX(),tCarre[i]->getSommetsCarre1()->getm_position().getY(),tCarre[i]->getSommetsCarre3()->getm_position().getX(),tCarre[i]->getSommetsCarre3()->getm_position().getY(),"gold");
        svgout.addLine(tCarre[i]->getSommetsCarre2()->getm_position().getX(),tCarre[i]->getSommetsCarre2()->getm_position().getY(),tCarre[i]->getSommetsCarre0()->getm_position().getX(),tCarre[i]->getSommetsCarre0()->getm_position().getY(),"gold");
    }

}

