#include "coords.h"
#include "../util/util.h"
#include <iostream>

Coords::Coords(double x, double y) ///Constructeur objet Coords
    : m_x{x}, m_y{y}
{ }

Coords::Coords() ///Constructeur par défaut
    : m_x{0}, m_y{0}
{ }


void Coords::afficher() const ///méthode pour afficher les coords
{
    std::cout << "(" << m_x << ", " << m_y << ")";
}

void Coords::saisir() ///Méthode pour saisir des coords
{
    std::cout << "Veuillez saisir x et y SVP : ";
    std::cin >> m_x >> m_y;
}

double Coords::getX() const ///Getter de coordonnées en x
{
    return m_x;
}

double Coords::getY() const ///Getter de coordonnées en y
{
    return m_y;
}

/// Positions relatives
bool Coords::estAGauche(const Coords& autre) const
{    return m_x < autre.m_x;  }

bool Coords::estADroite(const Coords& autre) const
{    return m_x > autre.m_x;  }

bool Coords::estAuDessus(const Coords& autre) const
{    return m_y < autre.m_y;  }

bool Coords::estAuDessous(const Coords& autre) const
{    return m_y > autre.m_y;  }


/// Somme vectorielle
Coords operator+(const Coords& c1, const Coords& c2)
{
    return { c1.m_x + c2.m_x, c1.m_y + c2.m_y };
}

/// Soustraction vectorielle
Coords operator-(const Coords& c1, const Coords& c2)
{
    return { c1.m_x - c2.m_x, c1.m_y - c2.m_y };
}

/// Produit vectoriel
double operator*(const Coords& c1, const Coords& c2)
{
    return c1.m_x*c2.m_x + c1.m_y*c2.m_y ;
}

/// Multiplication par un réel
Coords operator*(double m, const Coords& c)
{
    return { m*c.m_x, m*c.m_y };
}

void Coords::setX(double x1) ///Setter en X
{
    m_x=m_x+x1;
}

void Coords::setY(double y1) ///Setter en Y
{
    m_y=m_y+y1;
}
