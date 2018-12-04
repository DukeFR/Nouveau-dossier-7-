#ifndef PLANETE_H_INCLUDED
#define PLANETE_H_INCLUDED
#include "elements.h"

class Planete : public Element//classe fille de element
{
    private :
    double m_taille;
    Couleur color;
    public :
    Planete(double x, double y,double taille, uint8_t r, uint8_t g, uint8_t b);//constructeur
};


#endif // PLANETE_H_INCLUDED
