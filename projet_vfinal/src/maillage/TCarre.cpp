#include "TCarre.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <string>


TeCarre::TeCarre(std::vector<Sommet*> TSommets) : Carre(TSommets,util::alea(0,255),util::alea(0,255),util::alea(0,255)) ///Constructeur Tcarré
{
        TSommets.clear();
        tCarre.push_back(this);
        Sommet* s1=this->getSommetsCarre0(); ///Création du 1er Carré en récupérant ses sommets
        TSommets.push_back(s1);
        Sommet* s2=this->getSommetsCarre2();
        TSommets.push_back(s2);
        Sommet *s3=new Sommet{s1->getm_position().getX()+20,s1->getm_position().getY()};
        TSommets.push_back(s3);
        Sommet *s4 =new Sommet{s2->getm_position().getX()+20,s2->getm_position().getY()};
        TSommets.push_back(s4);
        Carre *c1=new Carre{TSommets,0,255,0}; ///Création du 1er Carré
        tCarre.push_back(c1);
        TSommets.clear();
        TSommets.push_back(s3); ///Création du 2ème Carré en reprenant la même méthode
        TSommets.push_back(s4);
        Sommet *s5=new Sommet{s3->getm_position().getX()+20,s3->getm_position().getY()};
        TSommets.push_back(s5);
        Sommet *s6 =new Sommet{s4->getm_position().getX()+20,s4->getm_position().getY()};
        TSommets.push_back(s6);
        Carre *c2=new Carre{TSommets,0,255,0}; ///Crée le 2ème Carré
        tCarre.push_back(c2);
        TSommets.clear();
        TSommets.push_back(s4); ///De même pour le 3ème Carré
        TSommets.push_back(s2);
        Sommet *s7=new Sommet{s4->getm_position().getX(),s4->getm_position().getY()+20};
        TSommets.push_back(s7);
        Sommet *s8 =new Sommet{s2->getm_position().getX(),s2->getm_position().getY()+20};
        TSommets.push_back(s8);
        Carre *c3=new Carre{TSommets,0,255,0};
        tCarre.push_back(c3); ///Création du 3ème Carré
        TSommets.clear();
        TSommets.push_back(s1); ///De même pour le 4ème Carré
        TSommets.push_back(s2);
        Sommet *s9=new Sommet{s1->getm_position().getX()-20,s1->getm_position().getY()};
        TSommets.push_back(s9);
        Sommet *s10 =new Sommet{s2->getm_position().getX()-20,s2->getm_position().getY()};
        TSommets.push_back(s10);
        Carre *c4=new Carre{TSommets,0,255,0};
        tCarre.push_back(c4); ///Création du 4ème Carré
}

void TeCarre::dessiner(Svgfile& svgout,Couleur c) ///Dessin sur le svg
{
    for(unsigned int i=0; i<tCarre.size(); i++) ///Boucle pour parcourir le vector -> Affiche carré + contour
    {
        svgout.addSquare(tCarre[i]->getSommetsCarre0()->getm_position().getX(),tCarre[i]->getSommetsCarre0()->getm_position().getY(),tCarre[i]->getSommetsCarre1()->getm_position().getX(),tCarre[i]->getSommetsCarre1()->getm_position().getY(),tCarre[i]->getSommetsCarre2()->getm_position().getX(),tCarre[i]->getSommetsCarre2()->getm_position().getY(),tCarre[i]->getSommetsCarre3()->getm_position().getX(),tCarre[i]->getSommetsCarre3()->getm_position().getY(),c);
        svgout.addLine(tCarre[i]->getSommetsCarre2()->getm_position().getX(),tCarre[i]->getSommetsCarre2()->getm_position().getY(),tCarre[i]->getSommetsCarre3()->getm_position().getX(),tCarre[i]->getSommetsCarre3()->getm_position().getY(),"gold");
        svgout.addLine(tCarre[i]->getSommetsCarre0()->getm_position().getX(),tCarre[i]->getSommetsCarre0()->getm_position().getY(),tCarre[i]->getSommetsCarre1()->getm_position().getX(),tCarre[i]->getSommetsCarre1()->getm_position().getY(),"gold");
        svgout.addLine(tCarre[i]->getSommetsCarre1()->getm_position().getX(),tCarre[i]->getSommetsCarre1()->getm_position().getY(),tCarre[i]->getSommetsCarre3()->getm_position().getX(),tCarre[i]->getSommetsCarre3()->getm_position().getY(),"gold");
        svgout.addLine(tCarre[i]->getSommetsCarre2()->getm_position().getX(),tCarre[i]->getSommetsCarre2()->getm_position().getY(),tCarre[i]->getSommetsCarre0()->getm_position().getX(),tCarre[i]->getSommetsCarre0()->getm_position().getY(),"gold");
    }

}

