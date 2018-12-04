#include "Carre4.h"
#include "Sommet.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <string>

Carre4::Carre4(std::vector<Sommet*> c4Sommets) : Carre(c4Sommets,util::alea(0,255),util::alea(0,255),util::alea(0,255)) ///Constructeur d'un carré constitué de 4 carrés
{
        c4Sommets.clear();
        carres.push_back(this); ///Création du premier carré
        Sommet* s1=this->getSommetsCarre1(); ///On crée les sommets du 2ème Carré
        c4Sommets.push_back(s1);
        Sommet* s2=this->getSommetsCarre3();
        c4Sommets.push_back(s2);
        Sommet *s3=new Sommet{s1->getm_position().getX()+20,s1->getm_position().getY()};
        c4Sommets.push_back(s3);
        Sommet *s4 =new Sommet{s2->getm_position().getX()+20,s2->getm_position().getY()};
        c4Sommets.push_back(s4);
        Carre *c1=new Carre{c4Sommets,0,255,0}; ///Créer le 2ème Carré
        carres.push_back(c1);
        c4Sommets.clear();
        c4Sommets.push_back(s2); ///De même pour le 3ème Carré
        c4Sommets.push_back(s4);
        Sommet *s5=new Sommet{s2->getm_position().getX(),s2->getm_position().getY()+20};
        c4Sommets.push_back(s5);
        Sommet *s6 =new Sommet{s4->getm_position().getX(),s4->getm_position().getY()+20};
        c4Sommets.push_back(s6);
        Carre *c2=new Carre{c4Sommets,0,255,0};
        carres.push_back(c2);
        c4Sommets.clear();
        c4Sommets.push_back(s5); ///De même pour le 4ème Carré
        c4Sommets.push_back(s2);
        Sommet *s7=new Sommet{s5->getm_position().getX()-20,s5->getm_position().getY()};
        c4Sommets.push_back(s7);
        Sommet *s8 =new Sommet{s2->getm_position().getX()-20,s2->getm_position().getY()};
        c4Sommets.push_back(s8);
        Carre *c3=new Carre{c4Sommets,0,255,0};
        carres.push_back(c3);
}

void Carre4::dessiner(Svgfile& svgout,Couleur c) ///Dessin du carré sur le svg
{
    for(unsigned int i=0; i<carres.size(); i++) ///On crée 4 carrés et 4 lignes
    {
        svgout.addSquare(carres[i]->getSommetsCarre0()->getm_position().getX(),carres[i]->getSommetsCarre0()->getm_position().getY(),carres[i]->getSommetsCarre1()->getm_position().getX(),carres[i]->getSommetsCarre1()->getm_position().getY(),carres[i]->getSommetsCarre2()->getm_position().getX(),carres[i]->getSommetsCarre2()->getm_position().getY(),carres[i]->getSommetsCarre3()->getm_position().getX(),carres[i]->getSommetsCarre3()->getm_position().getY(),c);
        svgout.addLine(carres[i]->getSommetsCarre2()->getm_position().getX(),carres[i]->getSommetsCarre2()->getm_position().getY(),carres[i]->getSommetsCarre3()->getm_position().getX(),carres[i]->getSommetsCarre3()->getm_position().getY(),"gold");
        svgout.addLine(carres[i]->getSommetsCarre0()->getm_position().getX(),carres[i]->getSommetsCarre0()->getm_position().getY(),carres[i]->getSommetsCarre1()->getm_position().getX(),carres[i]->getSommetsCarre1()->getm_position().getY(),"gold");
        svgout.addLine(carres[i]->getSommetsCarre1()->getm_position().getX(),carres[i]->getSommetsCarre1()->getm_position().getY(),carres[i]->getSommetsCarre3()->getm_position().getX(),carres[i]->getSommetsCarre3()->getm_position().getY(),"gold");
        svgout.addLine(carres[i]->getSommetsCarre2()->getm_position().getX(),carres[i]->getSommetsCarre2()->getm_position().getY(),carres[i]->getSommetsCarre0()->getm_position().getX(),carres[i]->getSommetsCarre0()->getm_position().getY(),"gold");
    }

}
