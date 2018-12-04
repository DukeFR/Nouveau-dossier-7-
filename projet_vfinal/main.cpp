#include <iostream>
#include "src/svg/svgfile.h"
#include "src/scene/plan2.h"
#include <random>
#include "src/scene/plan4.h"
#include "src/maillage/LCarre.h"
#include "src/maillage/Carre4.h"
#include "src/maillage/SCarre.h"
#include "src/maillage/TCarre.h"
#include "src/geometrie/transformation.h"
#include "src/maillage/ligne.h"
#include "src/scene/PlanTetris.h"
#include "src/scene/plan3.h"


int menu(int graine, int& quitter,int& choix,int& choix1);

int main()
{
    int graineT1=30; ///Graine Tetris1
    int grainePL1=12;///Graine Plan Lunaire
    int grainePE1=30;///Graine Plan Etoile
    int grainePM1=12;///Graine Plan Montagne
    int graineTemp=30;///Graine Temporaire
    int quit=10; ///Initialisation de la variable pour quitter
    int choix=-1; ///Choix
    int choix1=0;
    std::mt19937 rg1{graineT1}; ///Graine Tetris 1
    std::mt19937 rg2{grainePL1};///Graine Plan Lunaire
    std::mt19937 rg3{grainePM1};///Graine Plan Montagne
    std::mt19937 rg4{grainePE1};///Graine Plan Etoile
    {
        PlanTetris T1{rg1}; ///Creation d'un objet Plan Tetris
        Plan2 LP1(rg2,choix);///Creation d'un objet Plan Lunaire
        Plan3 MP1(rg3,choix);///Creation d'un objet Plan Montagne
        Plan4 EP1(rg4,choix);///Creation d'un objet Plan Etoile
        Svgfile svgout; ///Initialisation du svgout
        EP1.dessiner(svgout);///affichage des plans
        MP1.dessiner(svgout);
        LP1.dessiner(svgout);
        T1.creerPlan(svgout,choix); ///Création graphique du plan Tetris
        LP1.supprimer();///suppression apres utilisation
        EP1.supprimer();
        MP1.supprimer();
    }
    do
    {
        graineTemp=menu(graineTemp,quit,choix,choix1); ///Lancement du menu
        std::mt19937 rgT{graineTemp};
        if(choix1==4)///si on veut modifier le plan tetris
        {
            Svgfile svgout;//on ouvre pour pouvoir dessiner
            Plan4 EP2(rg4,-1);//on affiche et cree tous les derniers plans inchangés
            EP2.dessiner(svgout);
            Plan3 MP2(rg3,-1);
            MP2.dessiner(svgout);
            Plan2 LP2(rg2,-1);
            LP2.dessiner(svgout);
            EP2.supprimer();
            LP2.supprimer();
            MP2.supprimer();
            if(choix==1)//si on modifie la graine
            {
                rg1=rgT;
            }
            PlanTetris T2{rg1}; ///on cree et affiche le plan modifie
            T2.creerPlan(svgout,choix);
        }
        if(choix1==3)///si on veut modifier le plan lunaire
        {
            Svgfile svgout;//on ouvre pour pouvoir dessiner
            Plan4 EP2(rg4,-1);//on cree et affiche tous les derniers plan
            EP2.dessiner(svgout);
            EP2.supprimer();
            Plan3 MP2(rg3,-1);
            MP2.dessiner(svgout);
            MP2.supprimer();
            if(choix==1)//si on modifie la graine
            {
                rg2=rgT;
            }
            Plan2 LP2(rg2,choix);//on cree et affiche le plan modifie
            LP2.dessiner(svgout);
            LP2.supprimer();
            PlanTetris T2{rg1};//on affiche et cree le dernier plan
            choix=-1;
            T2.creerPlan(svgout,choix);
        }
        if(choix1==1)///si on veut modifier le plan etoile
        {
            Svgfile svgout;
            if(choix==1)//si on modifie la graine
            {
                rg4=rgT;
            }
            Plan4 EP2(rg4,choix);//on affiche et cree le plan modifie
            EP2.dessiner(svgout);
            EP2.supprimer();
            Plan3 MP2(rg3,-1);
            MP2.dessiner(svgout);//on affiche et cree les derniers plans
            MP2.supprimer();
            Plan2 LP2(rg2,-1);
            LP2.dessiner(svgout);
            LP2.supprimer();
            PlanTetris T2{rg1};
            choix=-1;
            T2.creerPlan(svgout,choix);
        }
        if(choix1==2)///si on veut modifier le plan montagne
        {
            Svgfile svgout;//on ouvre
            Plan4 EP2(rg4,-1);//on dessine les derniers plans
            EP2.dessiner(svgout);
            EP2.supprimer();
            if(choix==1)// si on modifie la graine
            {
                rg3=rgT;
            }
            Plan3 MP2(rg3,choix);
            MP2.dessiner(svgout);//on affcihe le plan modifier
            MP2.supprimer();
            Plan2 LP2(rg2,-1);
            LP2.dessiner(svgout);//on affiche les premiers plans
            LP2.supprimer();
            PlanTetris T2{rg1};
            choix=-1;
            T2.creerPlan(svgout,choix);
        }
    }while(quit==10); ///Boucle qui quitte seulement si l'user veut
    return 0;

}

int menu(int graine, int& quitter,int& choix,int& choix1) ///Fonction Menu pour afficher les modifications possibles de plan
{
    quitter=10; ///Valeur pour sortir de la boucle
    bool boucle=false; /// Booléen pour vérifier des conditions (sortie de boucle/blindage)
    int choix2; ///Variables pour récupérer les choix (2 au maximum)
    //system("CLS"); ///Effacement graphique
    do
    {
        for(int i=0; i<20; i++) ///Boucle de pour décaler le titre
        {
            std::cout <<" ";
        }
        std::cout << "BIENVENUE DANS NOTRE GENERATEUR DE PAYSAGES"<< std::endl; ///Affichage du menu
        for(int i =0; i<5; i++)
        {
            std::cout<<std::endl;
        }
        std::cout << "Choississez votre plan!" << std::endl<< std::endl;
        std::cout << "1. Plan Spatial!" << std::endl;
        std::cout << "2. Plan Montagneux!" <<std::endl;
        std::cout << "3. Plan Lunaire!" << std::endl;
        std::cout << "4. Plan Tetris!" << std::endl;
        std::cout << "5. Quitter." << std::endl;
        do
        {
            std::cin >> choix1; ///Recuperation du choix de l'user
        }
        while(choix1<1 || choix1>5); ///Blindage
        if(choix1==5) ///Si il décide de quitter
        {
            quitter=0; ///on modifie la variable
            return graine; ///quitte la boucle
        }
        if(choix1==4) ///Choix du plan tetris
        {
            system("CLS"); ///Affichage graphique
            for(int i =0; i<10; i++)
            {
                std::cout<<std::endl; ///Saut a la ligne 10 fois
            }
            std::cout << "1. Modifier la valeur de la graine" << std::endl; ///Affichage menu
            std::cout << "2. Modifier la couleur de la forme" << std::endl;
            std::cout << "3. Modifier les variations de couleurs" << std::endl;
            std::cout << "4. Densite des blocs du Tetris" << std::endl;
            std::cout << "5. Mettre tout les blocs du Tetris de couleurs aleatoires" << std::endl;
            std::cout << "6. Mettre tout les blocs de la meme couleurs" << std::endl;
            do
            {
                std::cin >> choix2; ///Rceupération du choix
            }
            while(choix2<1 || choix2>6); ///blindage
            if(choix2==1) ///Si on veut modifier la valeur de la graine
            {
                std::cout << "Saisissez la valeur de la graine!" << std::endl; ///Saisie de la graine
                std::cin >> graine;
                choix=1;
                boucle=true; ///On quitte la boucle
            }
            if(choix2==2) ///Si on veut modifier la valeur de la forme
            {
                choix=2; ///On garde le choix
                boucle=true; ///On quitte la boucle
            }
            if(choix2==3) ///Si on veut modifier les variations de couleurs
            {
                choix=3; ///De même que précedemment
                boucle=true;
            }
            if(choix2==4) ///Si on modifie la densité des blocs
            {
                choix=4; ///Pareil
                boucle=true;
            }
            if(choix2==5) ///Si on modifie de facons aléatoires les couleurs
            {
                choix=5; ///Pareil
                boucle=true;
            }
            if(choix2==6) ///Si on modifie les couleurs par saisie
            {
                choix=6; ///Pareil
                boucle=true;
            }
        }
        if(choix1==3) ///Choix du plan tetris
        {
            system("CLS"); ///Affichage graphique
            for(int i =0; i<10; i++)
            {
                std::cout<<std::endl; ///Saut a la ligne 10 fois
            }
            std::cout << "1. Modifier la valeur de la graine" << std::endl; ///Affichage menu
            std::cout << "2. Modifier la couleur dominante du plan" << std::endl;
            std::cout << "3. Modifier la densite d'objets dans le plan" << std::endl;
            do
            {
                std::cin >> choix2; ///Rceupération du choix
            }
            while(choix2<1 || choix2>6); ///blindage
            if(choix2==1) ///Si on veut modifier la valeur de la graine
            {
                std::cout << "Saisissez la valeur de la graine!" << std::endl; ///Saisie de la graine
                std::cin >> graine;
                choix=1;
                boucle=true; ///On quitte la boucle
            }
            if(choix2==2) ///Si on veut modifier la valeur de la forme
            {
                choix=2; ///On garde le choix
                boucle=true; ///On quitte la boucle
            }
            if(choix2==3) ///Si on veut modifier les variations de couleurs
            {
                choix=3; ///De même que précedemment
                boucle=true;
            }
        }
        if(choix1==1) ///Choix du plan tetris
        {
            system("CLS"); ///Affichage graphique
            for(int i =0; i<10; i++)
            {
                std::cout<<std::endl; ///Saut a la ligne 10 fois
            }
            std::cout << "1. Modifier la valeur de la graine" << std::endl; ///Affichage menu
            std::cout << "2. Modifier la couleur dominante du plan" << std::endl;
            std::cout << "3. Modifier la densite d'objets dans le plan" << std::endl;
            do
            {
                std::cin >> choix2; ///Rceupération du choix
            }
            while(choix2<1 || choix2>6); ///blindage
            if(choix2==1) ///Si on veut modifier la valeur de la graine
            {
                std::cout << "Saisissez la valeur de la graine!" << std::endl; ///Saisie de la graine
                std::cin >> graine;
                choix=1;
                boucle=true; ///On quitte la boucle
            }
            if(choix2==2) ///Si on veut modifier la valeur de la forme
            {
                choix=2; ///On garde le choix
                boucle=true; ///On quitte la boucle
            }
            if(choix2==3) ///Si on veut modifier les variations de couleurs
            {
                choix=3; ///De même que précedemment
                boucle=true;
            }
        }
        if(choix1==2) ///Choix du plan tetris
        {
            system("CLS"); ///Affichage graphique
            for(int i =0; i<10; i++)
            {
                std::cout<<std::endl; ///Saut a la ligne 10 fois
            }
            std::cout << "1. Modifier la valeur de la graine" << std::endl; ///Affichage menu
            std::cout << "2. Modifier la couleur dominante du plan" << std::endl;
            std::cout << "3. Modifier la densite d'objets dans le plan" << std::endl;
            do
            {
                std::cin >> choix2; ///Rceupération du choix
            }
            while(choix2<1 || choix2>6); ///blindage
            if(choix2==1) ///Si on veut modifier la valeur de la graine
            {
                std::cout << "Saisissez la valeur de la graine!" << std::endl; ///Saisie de la graine
                std::cin >> graine;
                choix=1;
                boucle=true; ///On quitte la boucle
            }
            if(choix2==2) ///Si on veut modifier la valeur de la forme
            {
                choix=2; ///On garde le choix
                boucle=true; ///On quitte la boucle
            }
            if(choix2==3) ///Si on veut modifier les variations de couleurs
            {
                choix=3; ///De même que précedemment
                boucle=true;
            }
        }
    }
    while(boucle==false); ///Boucle de menu
    return graine; ///On renvoit la graine
}
