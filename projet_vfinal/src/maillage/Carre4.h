#ifndef CARRE4_H_INCLUDED
#define CARRE4_H_INCLUDED
#include "forme.h"
#include "../util/util.h"

class Carre4 : public Carre ///Classe Carré4 hérite de Carrés
{
private:
    std::vector<Carre*> carres; ///Vector de carré

public :
    Carre4(std::vector<Sommet*> c4Sommets); /// Constructeur de Carré4
    void dessiner(Svgfile& svgout,Couleur c); ///Dessin sur le svg

};


#endif // CARRE4_H_INCLUDED
