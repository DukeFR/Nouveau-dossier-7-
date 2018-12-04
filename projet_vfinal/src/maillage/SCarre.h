#ifndef SCARRE_H_INCLUDED
#define SCARRE_H_INCLUDED
#include "forme.h"
#include "../util/util.h"

class SCarre : public Carre ///Classe SCarré hérite de Carre
{
private:
    std::vector<Carre*> vsCarre; ///Vector de carrés

public :
    SCarre(std::vector<Sommet*> SSommets); ///Constructeur
    void dessiner(Svgfile& svgout,Couleur c); ///Dessin sur le svg

};


#endif // SCARRE_H_INCLUDED
