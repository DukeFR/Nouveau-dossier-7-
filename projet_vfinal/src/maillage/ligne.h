#ifndef LIGNE_H_INCLUDED
#define LIGNE_H_INCLUDED
#include "forme.h"
#include "../util/util.h"

class LigneC : public Carre ///Classe ligne h�rite de carr�
{
private:
    std::vector<Carre*> lCarre; ///Vector de Carr�

public :
    LigneC(std::vector<Sommet*> cSommets); ///Constructeur Carr�
    void dessiner(Svgfile& svgout,Couleur c); ///Dessiner graphiquement la ligne

};

#endif // LIGNE_H_INCLUDED
