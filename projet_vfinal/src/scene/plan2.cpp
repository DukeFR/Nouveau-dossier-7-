#include <iostream>
#include "plan2.h"
#include "../util/util.h"
#include <algorithm>

Plan2::Plan2(std::mt19937 r,int choix)//constructeur
:PlanScene{r}
{
    mesElements.push_back(ajouterFond(0,500,300,128,128,128));//ajout d un fond
    int nbr_astro=util::alea(2,5,r);//choix aleatoires du nombre de perso
    for(int i=0;i<nbr_astro;++i)
    {
        double x=util::alea(0,980,r);//coordonnes,taille  et couleurs alea
        double y=util::alea(48,330,r);
        double t=0.018*(y-48)+2;
        int ro1=util::alea(0,255,r);
        int g1=util::alea(0,255,r);
        int b1=util::alea(0,255,r);
        uint8_t ro=ro1;
        uint8_t g=g1;
        uint8_t b=b1;
        mesElements.push_back(ajouterAstronaute(x,470+y,t,ro,g,b));//ajout d astronautes
    }
    int nbr_drap=util::alea(2,5,r);//nombre de drapeaux ajoutes
    for(int i=0;i<nbr_drap;++i)
    {
        double x=util::alea(0,980,r);//coordonnes et taille alea
        double y=util::alea(48,330,r);
        double t=0.0012*(y-48)+0.18;
        int choix=util::alea(1,2,r);
        if(choix==1)
        {
            mesElements.push_back(ajouterDrapeau_us(x,470+y,t));//ajout d element drapeau usa
        }
        else
        {
            mesElements.push_back(ajouterDrapeau_fr(x,470+y,t));//ajout d'element drapeau fr
        }
    }
    std::sort(mesElements.begin(),mesElements.end(),MonFoncteur());//tri des elements selon leur pos y
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

Astronaute* Plan2::ajouterAstronaute(double x, double y,double taille, uint8_t r, uint8_t g, uint8_t b)//ajout d un astronaute
{
    Astronaute* nouveau= new Astronaute(x,y,taille,r,g,b);//alloc dynamique de l element astronaute
    return nouveau;
}

Drapeau_fr* Plan2::ajouterDrapeau_fr(double x, double y,double taille)//ajout de l element drapeau francais
{
    Drapeau_fr* nouveau= new Drapeau_fr(x,y,taille);//alloc dynamique
    return nouveau;
}

Drapeau_us* Plan2::ajouterDrapeau_us(double x, double y,double taille)//ajout de l element drapeau usa
{
    Drapeau_us* nouveau= new Drapeau_us(x,y,taille);//alloc dynamqie
    return nouveau;
}

Fond* Plan2::ajouterFond(double x, double y,double t, uint8_t r, uint8_t g, uint8_t b)
{
    Fond* nouveau= new Fond(x,y,t,r,g,b);//alloc dynamic
    return nouveau;
}

void Plan2::modifierdens(unsigned int densite,std::mt19937 r)//modificatoin du nombre d element
{
    if(densite>mesElements.size()-1)//Si le nombre d elements demande est superieur au nombre d elements actuel
    {
        densite=densite-(mesElements.size()-1);
        for(unsigned int i=0;i<densite;i++)//on ajoute le nombre d element demande

        {
            int choix=util::alea(1,3,r);//on choisit aleatoirement l element rajoute
            if(choix==1)//un astronaute
            {
                double x=util::alea(0,980,r);
                double y=util::alea(48,330,r);
                double t=0.018*(y-48)+2;
                int ro1=util::alea(0,255,r);
                int g1=util::alea(0,255,r);
                int b1=util::alea(0,255,r);
                uint8_t ro=ro1;
                uint8_t g=g1;
                uint8_t b=b1;
                mesElements.push_back(ajouterAstronaute(x,470+y,t,ro,g,b));
            }
            if(choix==2)//un drapeau usa
            {
                double x=util::alea(0,980,r);
                double y=util::alea(48,330,r);
                double t=0.0012*(y-48)+0.18;
                mesElements.push_back(ajouterDrapeau_us(x,470+y,t));
            }
            if(choix==3)//un drapeau fr
            {
                double x=util::alea(0,980,r);
                double y=util::alea(48,330,r);
                double t=0.0012*(y-48)+0.18;
                mesElements.push_back(ajouterDrapeau_fr(x,470+y,t));
            }
        }
        std::sort(mesElements.begin(),mesElements.end(),MonFoncteur());
    }
    else
    {
        if(densite<mesElements.size()-1)//si le nombre d'element demande est inferieur au nombre d element
        {
            for(size_t i=mesElements.size()-1; i>densite;i--)//on supprime les elements en trop
            {
                mesElements[i]->supprimer();
                delete mesElements[i];
                mesElements.erase(mesElements.begin()+i);
            }
        }
    }
}
