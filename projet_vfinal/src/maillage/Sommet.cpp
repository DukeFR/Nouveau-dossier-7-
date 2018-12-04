#include <iostream>
#include "Sommet.h"
#include "../svg/svgfile.h"


Sommet::Sommet(double x1,double y1,bool selec)
        :m_position{x1,y1},selection{selec}
{}

Sommet::Sommet() ///Constructeur sans paramètre
        :m_position{},selection{false}
{}

Sommet::~Sommet()
{}

void Sommet::saisir()
{
    m_position.saisir();
}

void Sommet::afficher(int i)const
{
    std::cout << i << ":(" << m_position.getX() << ", " << m_position.getY() <<")"<< std::endl;
}


void Sommet::dessiner(Svgfile& svgout)const ///Dessiner sur le svg astre
{
    svgout.addDisk(m_position.getX(),m_position.getY(),5, "black");
    //svgout.addCircle(m_position.getX(),m_position.getY(),10,3,"black");

}

Coords Sommet::getm_position()const
{
    return m_position;
}

void Sommet::selectionner()
{
    if(selection==false)
    {
        selection=true;
    }
}

void Sommet::deselectionner()
{
    if(selection==true)
    {
        selection=false;
    }
}


void Sommet::translation(Coords& modif)
{
    m_position=m_position+modif;
}


bool Sommet::getSelection()const
{
    return selection;
}
