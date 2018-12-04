#include "forme.h"
#include "../objet/astronaute.h"

Forme::Forme(std::vector<Sommet*> sommets, Couleur color)//constructeur de forme
{
  m_sommets=sommets;
  m_color=color;
}


Carre::Carre(std::vector<Sommet*> sommetsC, uint8_t rouge, uint8_t vert, uint8_t bleu)
:Forme{sommetsC,{rouge,vert,bleu}}
{}

Carre::~Carre()
{}

void Carre::dessiner(Svgfile& svgout)const ///Dessiner graphiquement carre
{
    svgout.addSquare(m_sommets[0]->getm_position().getX(),m_sommets[0]->getm_position().getY(),m_sommets[1]->getm_position().getX(),m_sommets[1]->getm_position().getY(),m_sommets[2]->getm_position().getX(),m_sommets[2]->getm_position().getY(),m_sommets[3]->getm_position().getX(),m_sommets[3]->getm_position().getY(),m_color);
}

Sommet* Carre::getSommetsCarre0() ///Getter des sommets (en haut � gauche)
{
    return m_sommets[0];
}

Sommet* Carre::getSommetsCarre1() ///Getter Sommet en haut � droite
{
    return m_sommets[1];
}

Sommet* Carre::getSommetsCarre2() ///Getter Sommet en bas a gauche
{
    return m_sommets[2];
}

Sommet* Carre::getSommetsCarre3() ///Getter Sommet en bas a droite
{
    return m_sommets[3];
}

Couleur* Carre::getColor() ///Getter de la couleur
{
    return &m_color;
}


Triangle::Triangle(std::vector<Sommet*> sommetsTriangle,uint8_t rouge, uint8_t vert, uint8_t bleu)
:Forme(sommetsTriangle,{rouge,vert,bleu})
{}


void Triangle::dessiner(Svgfile& svgout) const//on dessine triangle en appelant une fonction de dessin
{
  svgout.addTriangle(m_sommets[0]->getm_position().getX(),m_sommets[0]->getm_position().getY(),m_sommets[1]->getm_position().getX(),m_sommets[1]->getm_position().getY(),m_sommets[2]->getm_position().getX(),m_sommets[2]->getm_position().getY(), m_color);
}

Cercle::Cercle(std::vector<Sommet*> centre,uint8_t rouge, uint8_t vert, uint8_t bleu, double rayon,bool rempli)
:Forme{centre,{rouge,vert,bleu}}
{
  m_rayon=rayon;
  m_rempli=rempli;
}


void Cercle::dessiner(Svgfile& svgout) const
{
  if(m_rempli==true)//on dessine cercle en fonction de si on veut un Disque ou un Cercle
  {
    svgout.addDisk(m_sommets[0]->getm_position().getX(),m_sommets[0]->getm_position().getY(),m_rayon,m_color);
  }
  else
  {
    svgout.addCircle(m_sommets[0]->getm_position().getX(),m_sommets[0]->getm_position().getY(),m_rayon,5,m_color);
  }
}


Pentagone::Pentagone(std::vector<Sommet*> sommets,uint8_t rouge, uint8_t vert, uint8_t bleu)
:Forme{sommets,{rouge,vert,bleu}}
{}


void Pentagone::dessiner(Svgfile &svgout) const//on dessine un pentagone en fonction des sommets donnees
{
  svgout.addPentagone(m_sommets[0]->getm_position().getX(),m_sommets[0]->getm_position().getY(),m_sommets[1]->getm_position().getX(),m_sommets[1]->getm_position().getY(),m_sommets[2]->getm_position().getX(),m_sommets[2]->getm_position().getY(),m_sommets[3]->getm_position().getX(),m_sommets[3]->getm_position().getY(),m_sommets[4]->getm_position().getX(),m_sommets[4]->getm_position().getY(),m_color,m_color);
}

Etoile::Etoile(std::vector<Sommet*> centre,double taille,int branches,uint8_t rouge, uint8_t vert, uint8_t bleu)
:Forme{centre,{rouge,vert,bleu}}
{
    m_taille=taille;
    branche=branches;
}

void Etoile::dessiner(Svgfile &svgout)const//on dessine une etoile
{
  double posX, posY;
  posX=m_sommets[0]->getm_position().getX();
  posY=m_sommets[0]->getm_position().getY();
  if(branche==6)//a 6 branches
  {
    svgout.addTriangle(posX-10*m_taille, posY-10*m_taille, posX+10*m_taille, posY-10*m_taille, posX, posY+7.3*m_taille, "white");

    svgout.addTriangle(posX-10*m_taille, posY+1.5*m_taille, posX+10*m_taille, posY+1.5*m_taille, posX, posY-15.8*m_taille, "white");
  }
  if(branche==5)//a 5 branches
  {
    svgout.addPentagone(posX-5.9*m_taille, posY-8.1*m_taille, posX+5.9*m_taille, posY-8.1*m_taille,posX-9.5*m_taille,posY+3.1*m_taille, posX+9.5*m_taille, posY+3.1*m_taille, posX,posY+10*m_taille,"white", "white");

  svgout.addTriangle(posX-5.9*m_taille, posY-8.1*m_taille, posX+5.9*m_taille, posY-8.1*m_taille, posX, posY-20.8*m_taille, "white");

  svgout.addTriangle(posX+5.9*m_taille, posY-8.1*m_taille, posX+9.5*m_taille, posY+3.1*m_taille, posX+19.1*m_taille, posY-8.1*m_taille, "white");

  svgout.addTriangle(posX-5.9*m_taille, posY-8.1*m_taille, posX-9.5*m_taille, posY+3.1*m_taille, posX-19.1*m_taille, posY-8.1*m_taille, "white");

  svgout.addTriangle(posX+9.5*m_taille, posY+3.1*m_taille, posX,posY+10*m_taille, posX+13.6*m_taille, posY+15.7*m_taille, "white");

  svgout.addTriangle(posX-9.5*m_taille, posY+3.1*m_taille, posX,posY+10*m_taille, posX-13.6*m_taille, posY+15.7*m_taille, "white");
  }
}


Ellipse::Ellipse(std::vector<Sommet*> centre,uint8_t rouge, uint8_t vert, uint8_t bleu,double rx, double ry)
:Forme{centre,{rouge,vert,bleu}}
{
  m_rx=rx;
  m_ry=ry;
}


void Ellipse::dessiner(Svgfile& svgout) const//on dessine des ellipses
{
    svgout.addEllipse(m_sommets[0]->getm_position().getX(),m_sommets[0]->getm_position().getY(),m_rx,m_ry,m_color,0,m_color);
}

Line::Line(std::vector<Sommet*> sommets,uint8_t rouge, uint8_t vert, uint8_t bleu)
:Forme{sommets,{rouge,vert,bleu}}
{

}


void Line::dessiner(Svgfile& svgout)const//on dessine une ligne
{
    svgout.addLine(m_sommets[0]->getm_position().getX(),m_sommets[0]->getm_position().getY(),m_sommets[1]->getm_position().getX(),m_sommets[1]->getm_position().getY(),m_color);
}


void Forme::modifiercol(int choix)
{
    uint8_t r,g,b;
    r=m_color.getr();
    g=m_color.getg();
    b=m_color.getb();

    if(choix==1)
    {
        modifcol(r,g,b,75,-75,-75);
        m_color={r,g,b};
    }
    else
    {
        if(choix==2)
        {
            modifcol(r,g,b,-75,75,-75);
            m_color={r,g,b};
        }
        else
        {
            if(choix==3)
            {
                modifcol(r,g,b,-75,-75,75);
                m_color={r,g,b};
            }
        }
    }
}

