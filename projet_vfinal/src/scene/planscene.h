#ifndef PLANSCENE_H_INCLUDED
#define PLANSCENE_H_INCLUDED

class PlanScene :public Plan///Plan herite de Plan
{
    protected :
    std::vector<Element*> mesElements;///vecteur d element
    public :
    PlanScene(std::mt19937 r);///constructeur
    void dessiner(Svgfile& svgout);///dessiner le plan
    void supprimer();///supprimer le plan
    void modifiercol(int choix);///modifier la couleur du plan
};


#endif // PLANSCENE_H_INCLUDED
