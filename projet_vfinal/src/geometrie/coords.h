#ifndef COORDS_H_INCLUDED
#define COORDS_H_INCLUDED

class Coords ///Classe Coords
{
    public :
        Coords(double x, double y); ///Constructeur
        Coords(); ///Destructeur
        static Coords aleatoire(double amplitude); ///Aleatoire de coords

        void afficher() const; ///Affichage console (debug)
        void saisir(); ///Saisie des valeurs

        double getX() const; ///Getter x
        double getY() const; ///Getter y

        void setX(double x1); ///Setter x
        void setY(double y1); ///Setter y

        /// Positions relatives
        bool estAGauche(const Coords& autre) const;
        bool estADroite(const Coords& autre) const;
        bool estAuDessus(const Coords& autre) const;
        bool estAuDessous(const Coords& autre) const;

        /// Somme vectorielle
        friend Coords operator+(const Coords& c1, const Coords& c2);

        /// Soustraction vectorielle
        friend Coords operator-(const Coords& c1, const Coords& c2);

        /// Produit vectoriel
        friend double operator*(const Coords& c1, const Coords& c2);

        /// Multiplication par un réel
        friend Coords operator*(double m, const Coords& c);

    private :
        double m_x; ///Attributs en x/y
        double m_y;
};


#endif // COORDS_H_INCLUDED
