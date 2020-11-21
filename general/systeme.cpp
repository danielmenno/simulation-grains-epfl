#include "systeme.h"
#include <iostream>
#include <vector>
#include <cmath>
#include <utility>
using namespace std;


//=====La map qui associe à un Triplet les grains qui se trouvent dans la même "case" (donc à une distance où il existent des intéractions entre les grains

std::map<Triplet, std::vector<Grain*>> coord;

//===Opérateur d'ordre pour le Triplet qui est nécéssaire pour l'utilisation de la map

bool operator <(Triplet t1, Triplet const& t2) {
    if(t1.a == t2.a) {
        if(t1.b == t2.b) {
            if(t1.c == t2.c) return false;
            return (t1.c < t2.c);
        }
        return (t1.b < t2.b);
    }
    return (t1.a < t2.a);
}

//Constructeur et destructeur =========

Systeme::Systeme(SupportADessin* support,vector<Grain*> const& grain,
                 vector<Source*> const& source,
                 vector<Obstacle*> const& obstacle, size_t dim_)
    : Dessinable(support), dim(dim_)
{

    grains = grain;
    sources = source;
    obstacles = obstacle;

}

Systeme::~Systeme() {empty();}

//=======Méthodes d'affichage pour les éléments du système=========

std::ostream& Systeme::affiche_grains(std::ostream& out) const {
    out << "Grains du systeme :" << endl;
    for(auto const& e :grains) {
        e->affiche(out);
    }
    return out;
}

std::ostream& Systeme::affiche_sources(std::ostream& out) const {
    out << "Sources du systeme :" << endl;
    for(auto const& e :sources) {
        e->affiche(out);
    }
    return out;
}

std::ostream& Systeme::affiche_obstacles(std::ostream& out) const {
    out << "Obstacles du systeme :" << endl;
    for(auto const& e :obstacles) {
        e->affiche(out);
    }
    return out;
}

std::ostream& Systeme::affiche_eaux(std::ostream& out) const {
    out<< "Volumes d'eaux du systeme :" << endl;
    for(auto const& e : eaux) {
        e->affiche(out);
    }
    return out;
}

//=========Méthodes pour ajouter des éléments au système==========

void Systeme::ajoute_grain(Grain* grain) {
    grains.push_back(grain);
}

void Systeme::ajoute_obstacle(Obstacle* obstacle) {
    obstacles.push_back(obstacle);
}

void Systeme::ajoute_source(Source* source) {
    sources.push_back(source);
}

void Systeme::ajoute_eau(Eau *e) {
    eaux.push_back(e);
}

//=========Méthodes d'initialisation du système=======

void Systeme::initialisation(SupportADessin* support, int nb) {
    grains = {}; obstacles = {}; sources = {}; eaux = {};

    switch(nb) {
    case 1: initialisation1(support);
        break;
    case 2: initialisation2(support);
        break;
    case 3: initialisation3(support);
        break;
    default: initialisation0(support);
    }
}

void Systeme::initialisation0(SupportADessin* support) {

    GrainLJun un1(support, Vector3D (0,0,0), Vector3D (0,0,0), Vector3D (0,0,0), 0.4);
    GrainLJun un2(support, Vector3D (0,0,0), Vector3D (1,0,0), Vector3D (0,0,0), 0.4);
    GrainLJun un3(support, Vector3D (0,0,0), Vector3D (0.5, sqrt(3)/2, 0), Vector3D (0,0,0), 0.4);
    GrainLJdeux deux1(support,  Vector3D (0,0,0), Vector3D (0.5, sqrt(3)/6, sqrt(6)/3), Vector3D (0,0,0), 0.4);

    Plan plan(support, Vector3D (0,0,-0.9), Vector3D (0,0,1));
    plan.set_vitesse(Vector3D (0,0,-50)); plan.set_mouvement(false);
    ajoute_grain(new GrainLJun(un1));
    ajoute_grain(new GrainLJun(un2));
    ajoute_grain(new GrainLJun(un3));
    ajoute_grain(new GrainLJdeux(deux1));

    ajoute_obstacle(new Plan(plan));
}


void Systeme::initialisation1(SupportADessin *support) {

    GrainLJun un1(support, Vector3D (0,0,0), Vector3D(15,0,50), Vector3D (0,0,0), 0.5);
    GrainLJdeux deux1(support, Vector3D(0,0,0),Vector3D(0,0,50), Vector3D(0,0,0),0.4);

    Source s1(support,Vector3D (0,0,0), Vector3D (0,0,-10), 0.2, 0, 30,&un1,true);
    Source s2(support,Vector3D(0,0,0), Vector3D(0,0,-20), 0.3, 0, 20, &deux1,true);
    Source s3(support,Vector3D (0,0,0), Vector3D (0,0,-10), 0.2, 0, 30,&un1,true);

    Brique corps(support, Vector3D (0,0,30), 15, 10, 5, Vector3D (0,0,1), Vector3D (1,0,0));
    corps.set_vitesse(Vector3D (-75,0,0));
    Sphere tete(support, Vector3D (5,2.5,33.5),3.5);
    tete.set_vitesse(Vector3D (-75,0,0));

    Brique bras1(support, Vector3D(10,4,25),8,2,2,Vector3D(-1,0,-1),Vector3D(1,0,-1));
    bras1.set_vitesse(Vector3D(-75,0,0));
    Brique bras2(support, Vector3D(0,4,25),8,2,2,Vector3D(1,0,-1),Vector3D(-1,0,-1));
    bras2.set_vitesse(Vector3D(-75,0,0));
    Brique jambe1(support, Vector3D(6.5,2,15),13.5,2,2,Vector3D(0,0,1),Vector3D(1,0,0));
    jambe1.set_vitesse(Vector3D(-75,0,0));
    Brique jambe2(support, Vector3D(1.5,2,15),13.5,2,2,Vector3D(0,0,1),Vector3D(1,0,0));
    jambe2.set_vitesse(Vector3D(-75,0,0));

    Pyramide boob1(support, Vector3D(6,5,25),Vector3D(0,1,0),3,3,Vector3D(0,0,1),2.5);
    boob1.set_vitesse(Vector3D(-75,0,0));
    Pyramide boob2(support, Vector3D(1,5,25),Vector3D(0,1,0),3,3,Vector3D(0,0,1),2.5);
    boob2.set_vitesse(Vector3D(-75,0,0));

    Cylindre douche1(support, Vector3D(15,3,51),3,1,Vector3D(0,0,1));
    Cylindre douche2(support, Vector3D(0,3,51),3,1,Vector3D(0,0,1));
    Cylindre douche3(support, Vector3D(7.5,3,51),3,1,Vector3D(0,0,1));

    Eau e1(support,Vector3D(0,0,-5),5);

    ajoute_source(new Source (s1,Vector3D (15,3,50))); ajoute_source(new Source (s2,Vector3D(7.5,3,50)));
    ajoute_source(new Source(s3,Vector3D (0,3,50)));
    ajoute_obstacle(new Brique (corps)); ajoute_obstacle(new Sphere(tete));
    ajoute_obstacle(new Brique(bras1)); ajoute_obstacle(new Brique(bras2));
    ajoute_obstacle(new Brique(jambe1)); ajoute_obstacle(new Brique(jambe2));
    ajoute_obstacle(new Pyramide(boob1)); ajoute_obstacle(new Pyramide(boob2));
    ajoute_obstacle(new Cylindre(douche1)); ajoute_obstacle(new Cylindre(douche2)); ajoute_obstacle(new Cylindre(douche3));

    ajoute_eau(new Eau(e1));
}

void Systeme::initialisation2(SupportADessin* support) {
    GrainLJun un1(support, Vector3D (0,0,0), Vector3D(0,0,0), Vector3D (0,0,0), 0.5);
    GrainLJdeux deux1(support, Vector3D (0,0,0), Vector3D(0,0,0), Vector3D (0,0,0), 0.5);

    Source source1(support, Vector3D (-3, 3, 55), Vector3D (-100, 0, 0), 0.2, 0, 30, &un1, true);
    Source source2(support, Vector3D (-32, 3, 55), Vector3D (100, 0, 0), 0.2, 0, 30, &deux1, true);


    Dalle main_dalle(support, Vector3D (0,0,0), Vector3D (0,1,0), 35, 60, Vector3D (-1,0,0));
    Dalle main_dalle2(support, Vector3D (0,0,0), Vector3D (0,1,0), 35, 60, Vector3D (-1,0,0));

    Dalle sub_dalle1(support, Vector3D (0,0,50), Vector3D (-1,0,2), 10, 15, Vector3D(0,1,0));
    Dalle sub_dalle2(support, Vector3D (-35, 0, 50), Vector3D(-1, 0, -2), 10, 15, Vector3D (0,1,0));

    Cylindre cylindre1(support, Vector3D (-11, 5, 35), 2, 10, Vector3D (0,1,0));
    Cylindre cylindre2(support, Vector3D (-17.5, 5, 35), 2, 10, Vector3D (0,-1,0));
    Cylindre cylindre3(support, Vector3D (-24, 5, 35), 2, 10, Vector3D (0,1,0));

    Cylindre cylindre4(support, Vector3D (-7, 5, 30), 2, 10, Vector3D (0,1,0));
    Cylindre cylindre5(support, Vector3D(-14, 5, 30), 2, 10, Vector3D (0,-1,0));
    Cylindre cylindre6(support, Vector3D (-21, 5, 30), 2, 10, Vector3D (0, -1, 0));
    Cylindre cylindre7(support, Vector3D (-28, 5, 30), 2, 10, Vector3D (0, 1, 0));

    Cylindre cylindre8(support, Vector3D (-8.75, 5, 25), 2, 10, Vector3D (0,1,0));
    Pyramide pyramide(support, Vector3D (-14.5, 0, 20), Vector3D (0, 1, 0), 6, 6, Vector3D(-1, 0, 0), 10);
    Cylindre cylindre9(support, Vector3D (-26.25, 5, 25), 2, 10, Vector3D (0,1,0));

    Eau water(support, Vector3D(0,0,0));

    ajoute_obstacle(new Dalle(main_dalle));
    ajoute_obstacle(new Dalle(main_dalle2));
    ajoute_obstacle(new Dalle(sub_dalle1));
    ajoute_obstacle(new Dalle(sub_dalle2));
    ajoute_obstacle(new Cylindre(cylindre1));
    ajoute_obstacle(new Cylindre(cylindre2));
    ajoute_obstacle(new Cylindre(cylindre3));
    ajoute_obstacle(new Cylindre(cylindre4));
    ajoute_obstacle(new Cylindre(cylindre5));
    ajoute_obstacle(new Cylindre(cylindre6));
    ajoute_obstacle(new Cylindre(cylindre7));
    ajoute_obstacle(new Cylindre(cylindre8));
    ajoute_obstacle(new Cylindre(cylindre9));
    ajoute_obstacle(new Pyramide(pyramide));

    ajoute_eau(new Eau(water));

    ajoute_source(new Source(source1, Vector3D (-3, 3, 55)));
    ajoute_source(new Source(source2, Vector3D (-32, 3, 55)));
}

void Systeme::initialisation3(SupportADessin* support) {
    GrainLJun un1(support, Vector3D (0,0,0), Vector3D(0,0,0), Vector3D (0,0,0), 0.5);
    GrainLJdeux deux1(support, Vector3D (0,0,0), Vector3D(0,0,0), Vector3D (0,0,0), 0.5);

    Source source1(support, Vector3D (0, 0, 0), Vector3D (-10, 10, 100), 0.8, 0, 30, &un1, true);
    Source source2(support, Vector3D (0, 0, 0), Vector3D (0, 0, 0), 0.2, 0, 30, &deux1, true);
    Source source3(support, Vector3D (0, 0, 0), Vector3D (-10, 10, 100), 0.2, 0, 30, &deux1, true);



    Dalle main_dalle(support, Vector3D (0,0,0), Vector3D (0,0,1), 50, 50, Vector3D (1,0,0));
    Dalle sub_dalle1(support, Vector3D (0,0,0), Vector3D (1,0,0), 50, 10, Vector3D (0,1,0));
    Dalle sub_dalle2(support, Vector3D (0,0,0), Vector3D (0,-1,0), 50, 10, Vector3D (1,0,0));
    Dalle sub_dalle3(support, Vector3D (50,0,0), Vector3D (1,0,0), 50, 10, Vector3D (0,1,0));
    Dalle sub_dalle4(support, Vector3D (0,50,0), Vector3D (0,-1,0), 50, 10, Vector3D (1,0,0));

    Eau water(support, Vector3D (0,0,5), 5, 50, 50);

    Sphere sphere(support, Vector3D (25, 25, 5), 5);
    Brique brique1(support, Vector3D (13, 42, 0), 7, 7, 5, Vector3D(1, 1, 0), Vector3D (0,0,1));

    Pyramide pyramide1(support, Vector3D (40,5,0), Vector3D(0,0,1), 5, 7, Vector3D (1,1,0), 10);

    ajoute_obstacle(new Dalle(main_dalle));
    ajoute_obstacle(new Dalle(sub_dalle1));
    ajoute_obstacle(new Dalle(sub_dalle2));
    ajoute_obstacle(new Dalle(sub_dalle3));
    ajoute_obstacle(new Dalle(sub_dalle4));

    ajoute_obstacle(new Sphere(sphere));

    ajoute_obstacle(new Brique(brique1));

    ajoute_obstacle(new Pyramide(pyramide1));

    ajoute_source(new Source(source1, Vector3D (25, 25, 15)));
    ajoute_source(new Source(source2, pyramide1.get_sommet() + Vector3D (0,0,5)));
    ajoute_source(new Source(source3, Vector3D (12, 38, 15)));

    ajoute_eau(new Eau(water));
}


//====Méthode qui ajoute un grain à la case associée===

void Systeme::remplir_case(Grain* g) {

     int a = g->get_po().get_x()/2;
     int b = g->get_po().get_y()/2;
     int c = g->get_po().get_z()/2;

     Triplet t = {a,b,c};
     coord[t].push_back(g);
}

//===Méthode qui enleve enleve un grain du tableau de sa case

void remove_grain(Triplet const& t, Grain* g) {
    size_t next(0);
    for(size_t i = 0; i < coord[t].size(); i = next) {
       if(coord[t][i] == g) coord[t].erase(coord[t].begin() + i);
       else { ++next;}
    }
}

//===Rentre dans un case et appelle la fonction remove_grain()

void Systeme::vider_case(Grain* g) {
    int a = g->get_po().get_x()/2;
    int b = g->get_po().get_y()/2;
    int c = g->get_po().get_z()/2;
    Triplet t = {a,b,c};

    remove_grain(t,g);

}

//===Mets à jour les case, c-a-d: on enleve le grain de sa vieille case, si le grain est toujours dans le systeme ( < la distance max)
//===on l'ajoute à sa nouvelle case. Sinon, on l'enleve de l'ensemble des grains dans le systeme.

//==Cette fonction existe pour éviter qu'un grain qui est déplacé parce qu'il est "trop proche" à un autre grain, soit après encore bougé par la fonciton move()
//==elle envoye true si le grain reste dans le systeme, sinon false
bool Systeme::update_cases(Grain* g, Triplet const& t, size_t& i) {

    remove_grain(t,g);
    if(g->get_po().norme() < dim) {
        remplir_case(g);
        return true;
    }
    delete grains[i]; grains[i] = nullptr;
    grains.erase(grains.begin()+i);
    --i;
    return false;
}

//====Vérifie si le grain est dans un volume d'eau ou simplement dans l'air.

void Systeme::update_milieu(Grain* g) {
    g->set_milieu(true);
    for(auto e : eaux) {
        if(e->inside(g->get_po())) g->set_milieu(false);
    }
}

//======FONCTION EVOLUE=====


void Systeme::evolue(double& dt) {

    if (dt <= 0.0) return;
    double dt_2(dt); double dt_tmp(0); //necessaire pour l'adaptation du dt

    for(auto& s : sources) {
        s->creation(grains,2*dt); //creation de grains par la source
    }

    for(auto const& e : grains) { //remplir les cases avec les grains du systeme
        remplir_case(e);
    }

    for(size_t i(0); i < grains.size(); ++i) {      //boucler sur les grains du systeme
        double dx;
        grains[i]->add_f();   //ajout de la force "perso"
        int a = grains[i]->get_po().get_x()/2;
        int b = grains[i]->get_po().get_y()/2;          // Triplet associé à la postion du grain
        int c = grains[i]->get_po().get_z()/2;
        Triplet t0 = {a,b,c};
        for(auto const& obstacle : obstacles) {  //boucler sur les obstacles et ajouter leur force sur le grain
            grains[i]->add_f(obstacle);
            if(!update_cases(grains[i],t0,i)) goto label;       //verifie si le grain est sorti du systeme -> label saute le reste de l'evolution
        }

        for(int k = 0; k < 3; ++k) {
            for(int l = 0; l < 3; ++l) {
                for(int m = 0; m < 3; ++m) {                            //Boucler sur les cases adjacentes au moyen de 3 boucles "for"
                    Triplet t = {a+k-1,b+l-1,c+m-1};
                    for(size_t j(0); j < coord[t].size(); ++j) {        //Boucler dans la case donnée par le triplet t
                        if(coord[t][j] != grains[i]) {
                            grains[i]->add_f(coord[t][j]);                  //ajouter la force entre les grains
                            if (!update_cases(grains[i],t0,i)) goto label;  // verifier que le grain soit encore dans le systeme, sinon passe au label
                        }
                    }
                }
            }
        }

        dx = (grains[i]->get_v()*dt).norme();
        dt_tmp = ((grains[i]->get_r()/2)/dx) * dt;          //recalculer le dt en fonction du futur demplacement dx
        if(dt_tmp < dt_2 && dt_tmp != 0) dt_2 = dt_tmp;

        if((grains[i]->get_po()).norme() > dim) {
            delete grains[i];
            grains[i] = nullptr;                        //enleve le grain du tableau au cas où il soit sorti du systeme
            grains.erase(grains.begin()+i);
            --i;
        }
    }

    label:
    coord.clear(); // vider toutes les cases
    for(auto e : grains) {
        e->move(dt_2);          //bouger tous les grains
        update_milieu(e);       //verifier si le grain est dans l'eau ou l'air et mettre à jour son état en fonction de cela
    }
    for(auto o : obstacles) {
        o->move(dt_2);
    }
}

//=====Méthode qui désalloue tous les pointeurs et vide les tableaux - > utilisée dans le destructeur

void Systeme::empty() {
    for(auto& e : grains) {delete e; e = nullptr;}
    for(auto& e : sources) {delete e; e = nullptr;}
    for(auto& e : obstacles) {delete e; e = nullptr;}
    for(auto& e : eaux) { delete e; e = nullptr; }
    grains.clear(); sources.clear(); obstacles.clear(); eaux.clear();
}

//======Surcharge d'operateur pour afficher en mode texte les elements du systeme à un moment donné=====
ostream& operator<<(ostream& out, Systeme const& systeme) {
    systeme.affiche_grains(out);
    systeme.affiche_sources(out);
    systeme.affiche_obstacles(out);
    systeme.affiche_eaux(out);
    out << endl;
    return out;

}


//fonction dessine qui appelle le support à dessin
void Systeme::dessine() {
    if(support != nullptr) return support->dessine(*this);
}


