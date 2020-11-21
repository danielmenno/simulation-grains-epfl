#ifndef SYSTEME_H
#define SYSTEME_H
#include <vector>
#include <map>
#include "source.h"
#include "plan.h"
#include "pyramide.h"
#include "brique.h"
#include "cylindre.h"
#include "eau.h"
#include "grainLJsub.h"
#include "sphere.h"


struct Triplet {
    int a; int b;  int c;
};

bool operator <(Triplet,Triplet const&);


class Systeme : public Dessinable
{
private:
    std::vector<Grain*> grains;
    std::vector<Source*> sources;
    std::vector<Obstacle*> obstacles;
    std::vector<Eau*> eaux;
    Systeme(Systeme const&) = delete;
    void operator=(Systeme const&) = delete;
    unsigned int dim;

public:
    //Constructeur et destructeur ======
    Systeme(SupportADessin*,std::vector<Grain*> const& = {}, std::vector<Source*> const& = {},
            std::vector<Obstacle*> const& = {}, size_t dim = 100);
    ~Systeme();
    //Methodes =========
    std::ostream& affiche_grains(std::ostream&) const;
    std::ostream& affiche_sources(std::ostream&) const;
    std::ostream& affiche_obstacles(std::ostream&) const;
    std::ostream& affiche_eaux(std::ostream&) const;
    void ajoute_grain(Grain*);
    void ajoute_source(Source*);
    void ajoute_obstacle(Obstacle*);
    void ajoute_eau(Eau*);
    //GETTERS===============
    std::vector<Grain*> getGrain() const { return grains; }
    std::vector<Source*> getSource() const { return sources; }
    std::vector<Obstacle*> getObstacle() const { return obstacles; }
    std::vector<Eau*> getEau() const { return eaux; }
    //re-Methodes==========
    void evolue(double&);
    void empty();
    void initialisation(SupportADessin*, int nb = 0);
    void initialisation0(SupportADessin*);
    void initialisation1(SupportADessin*);
    void initialisation2(SupportADessin*);
    void initialisation3(SupportADessin*);
    void remplir_case(Grain*);
    void vider_case(Grain*);
    void dessine() override;
    void update_milieu(Grain*);
    bool check_indices(int const&,int const&,int const&,size_t const&,size_t const&,size_t const&);
    bool update_cases(Grain*,Triplet const&, size_t& i);


};

std::ostream& operator<<(std::ostream&, Systeme const&);

#endif // SYSTEME_H
