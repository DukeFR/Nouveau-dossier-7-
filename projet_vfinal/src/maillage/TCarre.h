#ifndef TCARRE_H_INCLUDED
#define TCARRE_H_INCLUDED
#include "forme.h"
#include "../util/util.h"

class TeCarre : public Carre ///Classe T carr� h�rite de Carr�
{
private:
    std::vector<Carre*> tCarre; ///Vector de Carr�

public :
    TeCarre(std::vector<Sommet*> TSommets); ///Constructeur TCarr�
    void dessiner(Svgfile& svgout,Couleur c); ///Dessin sur le svg

};




#endif // TCARRE_H_INCLUDED
