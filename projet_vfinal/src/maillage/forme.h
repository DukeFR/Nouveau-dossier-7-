#ifndef FORME_H_INCLUDED
#define FORME_H_INCLUDED
#include <iostream>
#include "Sommet.h"
#include "../graphisme/couleur.h"
#include <vector>

class Forme//classe mere
{
  protected:
  std::vector<Sommet*> m_sommets;
  Couleur m_color;

  public:
  Forme(std::vector<Sommet*> sommets, Couleur color);//constructeur de forme
  virtual ~Forme()=default;//destructeur
  virtual void dessiner(Svgfile& svgout)const =0;//methode dessiner abastraite
  void modifiercol(int choix);//methode pour modifier la couleur d une forme
};

class Triangle : public Forme//classe fille de Formes
{
  public:
  Triangle(std::vector<Sommet*> sommetsTriangle,uint8_t rouge, uint8_t vert, uint8_t bleu);//constructeur
  virtual ~Triangle()=default;//destructeur
  virtual void dessiner(Svgfile& svgout)const;//methode dessiner
};

class Carre : public Forme
{
    public:
        Carre(std::vector<Sommet*> sommetsCarre,uint8_t rouge, uint8_t vert, uint8_t bleu); ///Constructeur de Carré
        ~Carre(); /// Destructeur de Carre
        Sommet* getSommetsCarre0(); ///Getter des 4 sommets de Carre
        Sommet* getSommetsCarre1();
        Sommet* getSommetsCarre2();
        Sommet* getSommetsCarre3();
        Couleur* getColor(); ///Getter Couleur
        void dessiner(Svgfile& svgout)const; ///Dessiner graphiquement
};

class Cercle : public Forme//classe fille de Formes
{
  private:
  double m_rayon;
  bool m_rempli;
  public:
  Cercle(std::vector<Sommet*> centre,uint8_t rouge, uint8_t vert, uint8_t bleu,double rayon, bool rempli);//constructeur
  virtual ~Cercle()=default;//destructeur
  virtual void dessiner(Svgfile& svgout)const;//dessiner
};

class Pentagone : public Forme//classe fille de Formes
{
  public:
  Pentagone(std::vector<Sommet*> sommets,uint8_t rouge, uint8_t vert, uint8_t bleu);
  virtual ~Pentagone()=default;//destrcuteur
  virtual void dessiner(Svgfile& svgout)const;//metode dessiner
};

class Etoile : public Forme///class fille de forme
{
  private:
  int branche;
  double m_taille;
  public:
  Etoile(std::vector<Sommet*> centre,double taille,int branches,uint8_t rouge, uint8_t vert, uint8_t bleu);//constructeur
  virtual ~Etoile()=default;//destructeur
  virtual void dessiner(Svgfile& svgout)const;//dessine
};

class Ellipse : public Forme//classe fille de forme
{
  private:
  double m_rx;
  double m_ry;
  public:
  Ellipse(std::vector<Sommet*> centre,uint8_t rouge, uint8_t vert, uint8_t bleu,double rx, double ry);//constructeur
  virtual ~Ellipse()=default;//destructeur
  virtual void dessiner(Svgfile& svgout)const;//methode dessiner
};

class Line : public Forme//classe fille de forme
{
    public:
    Line(std::vector<Sommet*> centre,uint8_t rouge, uint8_t vert, uint8_t bleu);//constructeur
    virtual void dessiner(Svgfile& svgout)const;//dessiner
    virtual ~Line()=default;//destructeur
};
#endif // FORME_H_INCLUDED
