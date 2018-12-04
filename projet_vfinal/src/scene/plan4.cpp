#include "plan4.h"
#include <iostream>
#include "../util/util.h"
#include <algorithm>


Plan4::Plan4(std::mt19937 r,int choix)//Constructeur de plan etoile
:PlanScene{r}
{
    mesElements.push_back(ajouterFond(0,0,800,0,0,0));//ajout d un fond
    int nbr_et=util::alea(45,55,r);//nombre d etoiles aleatoire
    for(int i=0;i<nbr_et;++i)
    {
        double x=util::alea(0,1000,r);//coordonnees et taille alea
        double y=util::alea(0,250,r);
        double t=util::alea(0.1,0.5,r);
        double br=util::alea(5,6,r);//nombre de branches d etoiles alea
        mesElements.push_back(ajouterEtoiles(x,y,t,br));
    }
    int nbr_plan=util::alea(1,2,r);//nombre de planetes alea
    for(int i=0;i<nbr_plan;++i)
    {
        double x=util::alea(0,1000,r);//coords taille et couleur alea
        double y=util::alea(0,250,r);
        double t=util::alea(5,50,r);
        int ro1=util::alea(0,255,r);
        int g1=util::alea(0,255,r);
        int b1=util::alea(0,255,r);
        uint8_t ro=ro1;
        uint8_t g=g1;
        uint8_t b=b1;
        mesElements.push_back(ajouterPlanete(x,y,t,ro,g,b));
    }
    if(choix==3)//si on modifie la densite
    {
        int dens;
        do
        {
            system("CLS"); ///Affichage graphique
            for(int i =0; i<10; i++)
            {
                std::cout<<std::endl; ///Saut a la ligne 10 fois
            }
            std::cout << "Saisissez le nombre d'objets que vous voulez!" << std::endl; ///Saisie de la graine
            std::cin >> dens;
        }while((dens<1)||(dens>200));
        modifierdens(dens,r);//modifie la densite
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
            std::cout << "Quelle est la couleur dominante de votre plan ?" << std::endl<< std::endl ///Saisie de la graine
                      << "1.Rouge"<<std::endl
                      << "2.Vert"<<std::endl
                      << "3.Bleu"<<std::endl;
            std::cin >> dec;
        }while((dec<1)||(dec>3));
        modifiercol(dec);//modif de la couleur
    }
}



Fond* Plan4::ajouterFond(double x, double y,double t, uint8_t r, uint8_t g, uint8_t b)//ajout du fond
{
    Fond* nouveau= new Fond(x,y,t,r,g,b);//alloc dynamic
    return nouveau;
}

Planete* Plan4::ajouterPlanete(double x, double y,double t, uint8_t r, uint8_t g, uint8_t b)//ajout de planete
{
    Planete* nouveau= new Planete(x,y,t,r,g,b);//alloc dynamic
    return nouveau;
}

Etoiles* Plan4::ajouterEtoiles(double x, double y,double t, double br)//ajout d etoiles
{
    Etoiles* nouveau= new Etoiles(x,y,t,br);//alloc dynamic
    return nouveau;
}

void Plan4::modifierdens(unsigned int densite,std::mt19937 r)//modif du nombre d element
{
    if(densite>mesElements.size()-1)///Comme pour le plan 2
    {
        densite=densite-(mesElements.size()-1);
        for(unsigned int i=0;i<densite;i++)
        {
            int choix=util::alea(1,10,r);
            if(choix<10)//on ajoute des etoiles
            {
                double x=util::alea(0,1000,r);
                double y=util::alea(0,250,r);
                double t=util::alea(0.1,0.5,r);
                double br=util::alea(5,6,r);
                mesElements.push_back(ajouterEtoiles(x,y,t,br));
            }
            if(choix==10)//on ajoute des planetes
            {
                double x=util::alea(0,1000,r);
                double y=util::alea(0,250,r);
                double t=util::alea(5,50,r);
                int ro1=util::alea(0,255,r);
                int g1=util::alea(0,255,r);
                int b1=util::alea(0,255,r);
                uint8_t ro=ro1;
                uint8_t g=g1;
                uint8_t b=b1;
                mesElements.push_back(ajouterPlanete(x,y,t,ro,g,b));
            }
        }
    }
    else
    {
        if(densite<mesElements.size()-1)//on supprime le nombre d elements en trop
        {
            std::sort(mesElements.begin(),mesElements.end(),MonFoncteur());
            for(size_t i=mesElements.size()-1; i>densite;i--)
            {
                mesElements[i]->supprimer();
                delete mesElements[i];
                mesElements.erase(mesElements.begin()+i);
            }
        }
    }
}
