#ifndef TCARRE_H_INCLUDED
#define TCARRE_H_INCLUDED
#include "forme.h"
#include "../util/util.h"

class TeCarre : public Carre ///Classe T carré hérite de Carré
{
private:
    std::vector<Carre*> tCarre; ///Vector de Carré

public :
    TeCarre(std::vector<Sommet*> TSommets); ///Constructeur TCarré
    void dessiner(Svgfile& svgout,Couleur c); ///Dessin sur le svg

};




#endif // TCARRE_H_INCLUDED
