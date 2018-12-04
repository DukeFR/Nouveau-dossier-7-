#ifndef COLLINE_H_INCLUDED
#define COLLINE_H_INCLUDED
#include "../geometrie/coords.h"
#include "../svg/svgfile.h"
#include "../maillage/forme.h"
#include <vector>
#include "elements.h"
#include "../graphisme/couleur.h"


class Colline : public Element//classe fille de element
{
    private :
    double m_r;
    Couleur m_color;
    public :
    Colline(double x, double y,double r, uint8_t ro, uint8_t g, uint8_t b);//constructeur
};

#endif // COLLINE_H_INCLUDED
