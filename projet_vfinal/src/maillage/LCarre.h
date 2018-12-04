#ifndef LCARRE_H_INCLUDED
#define LCARRE_H_INCLUDED
#include "forme.h"
#include "../util/util.h"

class LettreCarre : public Carre ///Classe LCarré hérite Carré
{
private:
    std::vector<Carre*> liCarre; ///Vector de Carré

public :
    LettreCarre(std::vector<Sommet*> lSommets); ///Constructeur du L
    void dessiner(Svgfile& svgout, Couleur c); ///Méthode pour dessiner sur le svg

};


#endif
