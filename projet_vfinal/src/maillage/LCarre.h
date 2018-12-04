#ifndef LCARRE_H_INCLUDED
#define LCARRE_H_INCLUDED
#include "forme.h"
#include "../util/util.h"

class LettreCarre : public Carre ///Classe LCarr� h�rite Carr�
{
private:
    std::vector<Carre*> liCarre; ///Vector de Carr�

public :
    LettreCarre(std::vector<Sommet*> lSommets); ///Constructeur du L
    void dessiner(Svgfile& svgout, Couleur c); ///M�thode pour dessiner sur le svg

};


#endif
