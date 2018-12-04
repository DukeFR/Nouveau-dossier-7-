#ifndef FUSEE_H_INCLUDED
#define FUSEE_H_INCLUDED
#include "../svg/svgfile.h"
#include "../geometrie/coords.h"
#include "elements.h"
#include "../graphisme/couleur.h"

class Fusee : public Element//classe fille de element
{
  private:
  bool m_vole;
  float m_taille;
  Couleur m_color;
  public:
  Fusee(double x,double y,bool vol,double taille,uint8_t r, uint8_t g, uint8_t b);//constructeur
};

#endif // FUSEE_H_INCLUDED
