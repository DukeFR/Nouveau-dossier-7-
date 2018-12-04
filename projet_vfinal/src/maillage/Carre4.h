#ifndef CARRE4_H_INCLUDED
#define CARRE4_H_INCLUDED
#include "forme.h"
#include "../util/util.h"

class Carre4 : public Carre ///Classe Carr�4 h�rite de Carr�s
{
private:
    std::vector<Carre*> carres; ///Vector de carr�

public :
    Carre4(std::vector<Sommet*> c4Sommets); /// Constructeur de Carr�4
    void dessiner(Svgfile& svgout,Couleur c); ///Dessin sur le svg

};


#endif // CARRE4_H_INCLUDED
