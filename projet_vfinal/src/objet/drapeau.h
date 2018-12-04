#ifndef DRAPEAU_H_INCLUDED
#define DRAPEAU_H_INCLUDED
#include "../svg/svgfile.h"
#include "../geometrie/coords.h"
#include <iostream>
#include "elements.h"

class Drapeau : public Element//classe fille de element
{
  protected:
  double m_taille;
  public:
  Drapeau(double x, double y,double taille);//constructeur
};

class Drapeau_us : public Drapeau//class fille de drapeau
{
  public:
  Drapeau_us(double x, double y,double taille);//constructeur
};

class Drapeau_fr : public Drapeau//classe fille de drapeau
{
  public:
  Drapeau_fr(double x, double y,double taille);//constructeur
};

#endif // DRAPEAU_H_INCLUDED
