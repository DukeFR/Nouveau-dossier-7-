#include <iostream>
#include "elements.h"
#include "../maillage/forme.h"

Element::Element(double x,double y)//constructeur d element
:m_position{x,y}
{}

void Element::dessiner(Svgfile& svgout)const
{
    for(size_t i=0;i<mesFormes.size();i++)//on parcourt toutes les formes et on les dessine
        {
            mesFormes[i]->dessiner(svgout);
        }
}

void Element::supprimer()
{
    for(size_t i=0;i<mesFormes.size();i++)//on parcourt toutes les formes et on les supprime
        {
            delete mesFormes[i];
            mesFormes.erase(mesFormes.begin()+i);
        }
    for(size_t i=0;i<mesSommets.size();i++)//on parcourt tous les sommets et on les supprime
        {
            delete mesSommets[i];
            mesSommets.erase(mesSommets.begin()+i);
        }
}

Coords Element::getPosition()const
{
    return m_position;//on recupere la position de l objet
}

Sommet* Element::ajouterSommet(double x, double y)//Ajout d un sommet
{
    Sommet* nouveau = new Sommet(x,y);//alloc dunamic
    return nouveau;
}

Triangle* Element::ajouterTriangle(Sommet* som1, Sommet* som2, Sommet* som3, uint8_t rouge, uint8_t vert, uint8_t bleu)//ajout d un triangle
{
    std::vector<Sommet*> sommets;//on cree un vecteur de sommets pr faire l alloc dynamic
    sommets.push_back(som1);
    sommets.push_back(som2);
    sommets.push_back(som3);
    Triangle* nouveau =new Triangle(sommets,rouge,vert,bleu);
    for(size_t i=0;i<sommets.size();i++)//on supprime le vecteur temporaire
    {
        sommets.erase(sommets.begin()+i);
    }
    return nouveau;
}

Pentagone* Element::ajouterPentagone(Sommet* som1, Sommet* som2, Sommet* som3, Sommet* som4, Sommet* som5, uint8_t rouge, uint8_t vert, uint8_t bleu)//ajout d un pentagone
{
    std::vector<Sommet*> sommets;//on cree un vecteur de sommets pr faire l alloc dynamic
    sommets.push_back(som1);
    sommets.push_back(som2);
    sommets.push_back(som3);
    sommets.push_back(som4);
    sommets.push_back(som5);
    Pentagone* nouveau =new Pentagone(sommets,rouge,vert,bleu);
    for(size_t i=0;i<sommets.size();i++)//on supprime le vecteur temporaire
    {
        sommets.erase(sommets.begin()+i);
    }
    return nouveau;
}

Ellipse* Element::ajouterEllipse(Sommet* som1, double rx, double ry, uint8_t rouge, uint8_t vert, uint8_t bleu)//ajout d une ellipse
{
    std::vector<Sommet*> sommets;//vecteur de sommets tempo pour faire l alloc
    sommets.push_back(som1);
    Ellipse* nouveau =new Ellipse(sommets,rx, ry,rouge,vert,bleu);
    for(size_t i=0;i<sommets.size();i++)//on supprime ce vecteur
    {
        sommets.erase(sommets.begin()+i);
    }
    return nouveau;
}

Carre* Element::ajouterCarre(Sommet* som1, Sommet* som2, Sommet* som3, Sommet* som4, uint8_t rouge, uint8_t vert, uint8_t bleu)//ajout d un quadrilatere
{
    std::vector<Sommet*> sommets;//vecteur de sommets tempos
    sommets.push_back(som1);
    sommets.push_back(som2);
    sommets.push_back(som3);
    sommets.push_back(som4);
    Carre* nouveau =new Carre(sommets,rouge,vert,bleu);
    for(size_t i=0;i<sommets.size();i++)//on supprime le vecteur de sommet
    {
        sommets.erase(sommets.begin()+i);
    }
    return nouveau;
}

Line* Element::ajouterLine(Sommet* som1, Sommet* som2,uint8_t rouge, uint8_t vert, uint8_t bleu)//ajout d une ligne
{
    std::vector<Sommet*> sommets;//vecteur de sommets temporaire
    sommets.push_back(som1);
    sommets.push_back(som2);
    Line* nouveau =new Line(sommets,rouge,vert,bleu);
    for(size_t i=0;i<sommets.size();i++)//on supprime ce vecteur
    {
        sommets.erase(sommets.begin()+i);
    }
    return nouveau;
}


Etoile* Element::ajouterEtoile(Sommet* som1,double t, int b,uint8_t rouge, uint8_t vert, uint8_t bleu)//ajout d une etoile
{
    std::vector<Sommet*> sommets;
    sommets.push_back(som1);//vecteur de sommmets temporarire
    Etoile* nouveau =new Etoile(sommets,t,b,rouge,vert,bleu);
    for(size_t i=0;i<sommets.size();i++)//on supprime ce vecteur
    {
        sommets.erase(sommets.begin()+i);
    }
    return nouveau;
}

Cercle* Element::ajouterCercle(Sommet* som1, double r, bool rempli,uint8_t rouge, uint8_t vert, uint8_t bleu)//ajout d u ncercle
{
    std::vector<Sommet*> sommets;
    sommets.push_back(som1);//vecteur de sommets tempos
    Cercle* nouveau =new Cercle(sommets,rouge,vert,bleu,r,rempli);
    for(size_t i=0;i<sommets.size();i++)//suppression de ce vecteur
    {
        sommets.erase(sommets.begin()+i);
    }
    return nouveau;
}

void Element::modifiercol(int choix)//modification de la couleur
{
    for(size_t i=0;i<mesFormes.size();i++)//on parcourt toutes les formes
    {
        mesFormes[i]->modifiercol(choix);//on modifie la couleur de chaque forme
    }
}
