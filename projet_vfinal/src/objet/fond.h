#ifndef FOND_H_INCLUDED
#define FOND_H_INCLUDED
#include "../graphisme/couleur.h"
#include "elements.h"

class Fond : public Element//class fille de element
{
    private :
    Couleur color;//on ajoute la couleur
    public :
        Fond(double x, double y,double t, uint8_t r, uint8_t g, uint8_t b);//constructeur
};


#endif // FOND_H_INCLUDED
