#ifndef ELEMENTS_H_INCLUDED
#define ELEMENTS_H_INCLUDED
#include <vector>
#include "../maillage/Sommet.h"
#include "../maillage/forme.h"

class Element//classe Elements qui sert a construire tous nos objets
{
    protected :
        std::vector <Forme*> mesFormes;//on stockje toutes les formes de l element
        std::vector <Sommet*> mesSommets;//on stocke tous les sommets de l element
        Coords m_position;//on stocke une coord de base de l element
    public :
        Element(double x,double y);
        virtual ~Element()=default;
        virtual void dessiner(Svgfile& svgout)const;//permet de dessiner l objet
        Sommet* ajouterSommet(double x,double y);//permet d ajouter des sommets dans l element
        Coords getPosition()const;//permet d avoir sa position
        Triangle* ajouterTriangle(Sommet* som1, Sommet* som2, Sommet* som3, uint8_t rouge, uint8_t vert, uint8_t bleu);//ajout de triangles
        Pentagone* ajouterPentagone(Sommet* som1, Sommet* som2, Sommet* som3, Sommet* som4, Sommet* som5, uint8_t rouge, uint8_t vert, uint8_t bleu);//ajout de pentagone
        Ellipse* ajouterEllipse(Sommet* som1,double rx, double ry, uint8_t rouge, uint8_t vert, uint8_t bleu);//ajout d ellipse
        Carre* ajouterCarre(Sommet* som1, Sommet* som2, Sommet* som3, Sommet* som4, uint8_t rouge, uint8_t vert, uint8_t bleu);//ajout d un quadrilatere
        Line* ajouterLine(Sommet* som1, Sommet* som2,uint8_t rouge, uint8_t vert, uint8_t bleu);//ajout de ligne
        Etoile* ajouterEtoile(Sommet* som1,double t, int b,uint8_t rouge, uint8_t vert, uint8_t bleu);//ajout d etoile
        Cercle* ajouterCercle(Sommet*som1,double r,bool rempli,uint8_t rouge, uint8_t vert, uint8_t bleu);//ajout de cercle
        void supprimer();//supprimer l element et ses composants
        void modifiercol(int choix);//modifie la couleur de l element
};


struct MonFoncteur//https://bakura.developpez.com/tutoriel/cpp/tri///structure permettant de comparer deux elements en fonction de la coord y
{//on utilise cette structure pour faire le tri des elements
   bool operator() (const Element* e1, const Element * e2) const
   {
      return e1->getPosition().getY() < e2->getPosition().getY();
   }
};
#endif // ELEMENTS_H_INCLUDED
