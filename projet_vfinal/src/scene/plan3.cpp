#include <iostream>
#include "plan3.h"
#include "../util/util.h"
#include <algorithm>

Plan3::Plan3(std::mt19937 r,int choix)//constructeur
:PlanScene{r}
{
    int nbr,nbrF;
    double x,y,xF,yF;
    double rayon,taille;
    bool vole=true;
    nbr=util::alea(3,6,r);
    nbrF=util::alea(2,4,r);
    for(int i=0;i<nbr;i++)
    {
      x=util::alea(0,1000/nbr,r);
      y=util::alea(700,750,r);
      rayon=util::alea(300,450,r);
      {
      int ro=util::alea(-10,10,r);
      int g=util::alea(-10,10,r);
      int b=util::alea(-10,10,r);
      mesElements.push_back(ajouterColline(i*(1000/nbr)+x,y,rayon,128+ro,128+g,128+b));
      }
      if(nbrF>0)
      {
        xF=util::alea(50,950,r);        yF=util::alea(275,320,r);//determination aleatoire des coordonnes
        taille=(yF-250)/30;
        int ro1=util::alea(0,255,r);
        int g1=util::alea(0,255,r);
        int b1=util::alea(0,255,r);
        uint8_t ro=ro1;
        uint8_t g=g1;
        uint8_t b=b1;
        mesElements.push_back(ajouterFusee(xF,yF,vole,0.15*taille,ro,g,b));
        nbrF--;
      }
    }
    std::sort(mesElements.begin(),mesElements.end(),MonFoncteur());
    if(choix==3)//si on modifie le nombre d elements
    {
        int dens;
        do
        {
            system("CLS"); ///Affichage graphique
            for(int i =0; i<10; i++)
            {
                std::cout<<std::endl; ///Saut a la ligne 10 fois
            }
            std::cout << "Saisissez le nombre d'objets que vous voulez!" << std::endl; ///Saisie du nombre d elements
            std::cin >> dens;
        }while((dens<1)||(dens>100));
        modifierdens(dens,r);//on modifie la densite d elements
    }
    if(choix==2)//si on modifie la couleur
    {
        int dec;
        do
        {
            system("CLS"); ///Affichage graphique
            for(int i =0; i<10; i++)
            {
                std::cout<<std::endl; ///Saut a la ligne 10 fois
            }
            std::cout << "Quelle est la couleur dominante de votre plan ?" << std::endl<< std::endl ///Saisie du choix de la couleur dominante du plan
                      << "1.Rouge"<<std::endl
                      << "2.Vert"<<std::endl
                      << "3.Bleu"<<std::endl;
            std::cin >> dec;
        }while((dec<1)||(dec>3));
        modifiercol(dec);//on modifie la couleur en fonction du choix
    }
}

Fusee* Plan3::ajouterFusee(double x, double y,bool vol,double taille, uint8_t r, uint8_t g, uint8_t b)//ajout d une fusee
{
    Fusee* nouveau= new Fusee(x,y,vol,taille,r,g,b);//alloc dynamic
    return nouveau;
}

Colline* Plan3::ajouterColline(double x, double y,double r, uint8_t ro, uint8_t g, uint8_t b)//ajout d une colline
{
    Colline* nouveau= new Colline(x,y,r,ro,g,b);//allocation dynamique
    return nouveau;
}

void Plan3::modifierdens(unsigned int densite,std::mt19937 r)//modification du nombre d elements
{//modification comme dans le plan 2 sauf qu on ajoute des fusees et des collines
  bool vole=true;
    if(densite>mesElements.size()-1)
    {
        densite=densite-(mesElements.size()-1);
        for(unsigned int i=0;i<densite;i++)
        {
            int choix=util::alea(1,2,r);
            if(choix==1)
            {
                double x=util::alea(50,950,r);
                double y=util::alea(275,320,r);
                double taille=y/150;
                int ro1=util::alea(0,255,r);
                int g1=util::alea(0,255,r);
                int b1=util::alea(0,255,r);
                uint8_t ro=ro1;
                uint8_t g=g1;
                uint8_t b=b1;
                mesElements.push_back(ajouterFusee(x,y,vole,0.15*taille,ro,g,b));
            }
            if(choix==2)
            {
                double x=util::alea(0,1000,r);
                double y=util::alea(700,750,r);
                double rayon=util::alea(300,450,r);
                int ro=util::alea(-10,10,r);
                int g=util::alea(-10,10,r);
                int b=util::alea(-10,10,r);
                mesElements.push_back(ajouterColline(x,y,rayon,128+ro,128+g,128+b));
            }
        }
        std::sort(mesElements.begin(),mesElements.end(),MonFoncteur());
    }
    else
    {
        if(densite<mesElements.size()-1)
        {
            for(size_t i=mesElements.size()-1; i>densite;i--)
            {
                mesElements[i]->supprimer();
                delete mesElements[i];
                mesElements.erase(mesElements.begin()+i);
            }
        }
    }
}
