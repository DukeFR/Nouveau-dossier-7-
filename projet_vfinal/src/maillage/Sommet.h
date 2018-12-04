#ifndef SOMMET_H_INCLUDED
#define SOMMET_H_INCLUDED
#include <iostream>
#include "../svg/svgfile.h"
#include "../geometrie/coords.h"

class Sommet{

    private:
        Coords m_position;
        bool selection;

    public:
        Sommet(double x1,double y1,bool selec=false);
        Sommet();
        ~Sommet();
        void saisir();
        void afficher(int i)const;
        void dessiner(Svgfile& svgout)const;
        Coords getm_position()const;
        void selectionner();
        void deselectionner();
        void translation(Coords& modif);
        bool getSelection()const;
};

#endif // SOMMET_H_INCLUDED
