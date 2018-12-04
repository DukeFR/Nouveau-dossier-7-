#ifndef ASTRONAUTE_H_INCLUDED
#define ASTRONAUTE_H_INCLUDED
#include "../geometrie/coords.h"
#include "../svg/svgfile.h"
#include "../maillage/forme.h"
#include <vector>
#include "elements.h"
#include <random>


class Astronaute : public Element//classe fille de element
{
    private :
    double m_taille;//avec un attribut taille et couleur
    Couleur color;
    public :
    Astronaute(double x, double y,double taille, uint8_t r, uint8_t g, uint8_t b);//constructeur de astronaute
};

void modifcol(uint8_t&r,uint8_t &g, uint8_t&b,int depr, int depg,int depb);//modif de la couleur selon des parametres

#endif // ASTRONAUTE_H_INCLUDED
