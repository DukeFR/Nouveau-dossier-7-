#include "plan.h"
#include "planscene.h"
#include <random>
#include "../util/util.h"

PlanScene::PlanScene(std::mt19937 r)///constucteur
:Plan{r}
{}

void PlanScene::dessiner(Svgfile& svgout)///Dessin du plan
{
    for(size_t i=0;i<mesElements.size();i++)///on parcourt les elements et on les affiche un par un
    {
        mesElements[i]->dessiner(svgout);
    }
}

void PlanScene::supprimer()///on desalloue l espace memoire
{
    for(size_t i=0; i<mesElements.size();i++)///on parcourt les elements et on les supprime
    {
        mesElements[i]->supprimer();
        delete mesElements[i];
        mesElements.erase(mesElements.begin()+i);
    }
}


void PlanScene::modifiercol(int choix)///Modifie la couleur
{
    for(size_t i=0;i<mesElements.size();i++)//on parcourt tous les elements et on modifie leur couleur
    {
        mesElements[i]->modifiercol(choix);
    }
}

