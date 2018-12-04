#include "PlanTetris.h"

PlanTetris::PlanTetris(std::mt19937 graine) : Plan{graine}
{

}


void static remplirTetris(Svgfile &svgout,std::mt19937 rg1,int choix)
{
    std::vector<int> regul;
    int pour;
    uint8_t r,g,b;
    int r1,g1,b1;
    if(choix==4)
    {
        do
        {
            std::cout << "Saisissez la probabilite de remplissage de la grille de Tetris (par ex si saisie 2 donne 1/2)" << std::endl;
            std::cin >> pour;
        }
        while(pour <0);
        std::cout << pour << std::endl;
    }
    else
    {
        pour=2;
    }
    if(choix==6)
    {
        do
        {
            std::cout << "Saisie de r"<<std::endl;
            std::cin >> r1;
        }
        while(r1<0 || r1>255);
        do
        {
            std::cout << "Saisie de g"<< std::endl;
            std::cin >>g1;
        }
        while(g1<0 || g1>255);
        do
        {
            std::cout << "Saisie de b" << std::endl;
            std::cin >>b1;
        }
        while(b1<0 || b1>255);
    }
    int taille = util::alea(2,17,rg1);
    for(int j=0; j<taille; j++)
    {
        for(int i=0; i<20; i++)
        {
            int actif = util::alea(0,pour,rg1);
            regul.push_back(actif);
            if(i==19)
            {
                actif=1;
                for(unsigned int k=0; k<regul.size(); k++)
                {
                    if(regul[k]==1)
                    {
                        actif=0;
                        k=regul.size();
                    }
                }
            }
            if(actif!=1)
            {
                if(choix==5)
                {
                    r = util::alea(0,255,rg1);
                    g = util::alea(0,255,rg1);
                    b = util::alea(0,255,rg1);
                    std::string nC=Couleur(r,g,b);
                    svgout.addSquare(300+20*i,580-20*j,320+20*i,580-20*j,300+20*i,600-20*j,320+20*i,600-20*j,nC);
                }
                if(choix==6)
                {
                    r=r1;
                    g=g1;
                    b=b1;
                    std::string nC=Couleur(r,g,b);
                    svgout.addSquare(300+20*i,580-20*j,320+20*i,580-20*j,300+20*i,600-20*j,320+20*i,600-20*j,nC);
                }
                if(choix!= 5 && choix!=6)
                {
                    svgout.addSquare(300+20*i,580-20*j,320+20*i,580-20*j,300+20*i,600-20*j,320+20*i,600-20*j,"lime");
                }
                svgout.addLine(320+20*i,580-20*j,320+20*i,600-20*j,"gold");
                svgout.addLine(300+20*i,580-20*j,300+20*i,600-20*j,"gold");
                svgout.addLine(300+20*i,580-20*j,320+20*i,580-20*j,"gold");
                svgout.addLine(300+20*i,600-20*j,320+20*i,600-20*j,"gold");
            }
        }
    }
    regul.clear();
}


void static creerC(std::vector<Carre*> &mesCarres,std::vector<Sommet*> &mSommet, Svgfile &svgout,std::mt19937 rg1,int x1,int x2,int y1,int y2)
{
    std::vector<Sommet*> mesSommets;
    double x=util::alea(x1,x2,rg1);
    double y=util::alea(y1,y2,rg1);
    uint8_t r = util::alea(0,255,rg1);
    uint8_t g = util::alea(0,255,rg1);
    uint8_t b = util::alea(0,255,rg1);
    Sommet *posBase=new Sommet{x,y};
    mesSommets.push_back(posBase);
    mSommet.push_back(posBase);
    Sommet *s2=new Sommet{posBase->getm_position().getX()+20,posBase->getm_position().getY()};
    mesSommets.push_back(s2);
    mSommet.push_back(s2);
    Sommet *s3=new Sommet{posBase->getm_position().getX(),posBase->getm_position().getY()+20};
    mesSommets.push_back(s3);
    mSommet.push_back(s3);
    Sommet *s4=new Sommet {posBase->getm_position().getX()+20,posBase->getm_position().getY()+20};
    mesSommets.push_back(s4);
    mSommet.push_back(s4);
    Carre *c= new Carre {mesSommets,r,g,b};
    mesCarres.push_back(c);
}



void static choixCarre(std::vector<Carre*> &mesCarres,std::vector<Sommet*> &mSommet, Svgfile &svgout,std::mt19937 rg1,int x1,int x2,int y1,int y2,uint8_t r,uint8_t g,uint8_t b,int mutation)
{
    int position=util::alea(1,5,rg1);
    if(position==1)
    {
        Couleur c{r,g,b};
        if(mutation!=0)
        {
            c.muter(mutation);
        }
        creerC(mesCarres,mSommet,svgout,rg1,x1,x2,y1,y2);
        TeCarre tc{mSommet};
        tc.dessiner(svgout,c);
    }
    if(position==2)
    {
        Couleur c{r,g,b};
        if(mutation!=0)
        {
            c.muter(mutation);
        }
        creerC(mesCarres,mSommet,svgout,rg1,x1,x2,y1,y2);
        LigneC Lc{mSommet};
        Lc.dessiner(svgout,c);
    }
    if(position==3)
    {
        Couleur c{r,g,b};
        if(mutation!=0)
        {
            c.muter(mutation);
        }
        creerC(mesCarres,mSommet,svgout,rg1,x1,x2,y1,y2);
        Carre4 Crt(mSommet);
        Crt.dessiner(svgout,c);
    }
    if(position==4)
    {
        Couleur c{r,g,b};
        if(mutation!=0)
        {
            c.muter(mutation);
        }
        creerC(mesCarres,mSommet,svgout,rg1,x1,x2,y1,y2);
        LettreCarre lct(mSommet);
        lct.dessiner(svgout,c);
    }
    if(position==5)
    {
        Couleur c{r,g,b};
        if(mutation!=0)
        {
            c.muter(mutation);
        }
        creerC(mesCarres,mSommet,svgout,rg1,x1,x2,y1,y2);
        SCarre Sc{mSommet};
        Sc.dessiner(svgout,c);
    }
}


void PlanTetris::creerPlan(Svgfile& svgout,int& choix)
{
    std::vector<Carre*> mesCarres;
    std::vector<Sommet*> mSommet;
    int r,g,b;
    int mutation=0;
    if(choix==2)
    {
        do
        {
            std::cout << "Saisie de r"<<std::endl;
            std::cin >> r;
        }
        while(r<0 || r>255);
        do
        {
            std::cout << "Saisie de g"<< std::endl;
            std::cin >>g;
        }
        while(g<0 || g>255);
        do
        {
            std::cout << "Saisie de b" << std::endl;
            std::cin >>b;
        }
        while(b<0 || b>255);
    }
    if(choix==3)
    {
        do
        {
            std::cout << "Quelle est la valeur de l'amplitude de couleur desiree?" << std::endl;
            std::cin >> mutation;
        }
        while(mutation<0 || mutation>255);
    }
    if(choix!=2 && choix!=3)
    {
        r=util::alea(0,255,this->rg1);
        g=util::alea(0,255,this->rg1);
        b=util::alea(0,255,this->rg1);
    }

    uint8_t r1 = r;
    uint8_t g1 = g;
    uint8_t b1 = b;
    svgout.addLine(300,600,300,100,"gold");
    svgout.addLine(300,600,700,600,"gold");
    svgout.addLine(700,100,700,600,"gold");
    int score=util::alea(0,9999,rg1);
    int niveau=util::alea(0,20,rg1);
    svgout.addText(720,550,"score: ","gold");
    svgout.addText(770,550,score,"gold");
    svgout.addText(720,580,"niveau: ","gold");
    svgout.addText(770,580,niveau,"gold");
    remplirTetris(svgout,rg1,choix);
    for(int i=0; i<4; i++)
    {
        choixCarre(mesCarres,mSommet,svgout,rg1,720,720,100+100*i,100+100*i,r1,g1,b1,mutation);
        mesCarres.clear();
        mSommet.clear();
    }
    choixCarre(mesCarres,mSommet,svgout,rg1,400,600,100,200,r1,g1,b1,mutation);
    choix=-1;
    mutation=0;
    while(!mSommet.empty())
    {
        delete mSommet.back();
        mSommet.pop_back();
    }
    while(!mesCarres.empty())
    {
        delete mesCarres.back();
        mesCarres.pop_back();
    }
}
