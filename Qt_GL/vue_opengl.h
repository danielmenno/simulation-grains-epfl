#ifndef VUEOPENGL_H
#define VUEOPENGL_H

#include <QGLShaderProgram> // Classe qui regroupe les fonctions OpenGL liées aux shaders
#include <QMatrix4x4>
#include "supportadessin.h"
#include "dessinable.h"
#include "glsphere.h"
#include "systeme.h"
#include "sphere.h"
#include "plan.h"
#include "pyramide.h"
#include "Brique.h"
#include "cylindre.h"
#include "eau.h"
#include "source.h"



class VueOpenGL : public SupportADessin {
 public:
  // méthode(s) de dessin (héritée(s) de SupportADessin)
    virtual void dessine(Systeme const&) override;
    virtual void dessine(const GrainLJun &) override;
    virtual void dessine(const GrainLJdeux &) override;
    virtual void dessine(Pyramide const&) override;
    virtual void dessine(Triangle const&) override;
    virtual void dessine(Plan const&) override;
    virtual void dessine(Dalle const&) override;
    virtual void dessine(Cylindre const&) override;
    virtual void dessine(Brique const&) override;
    virtual void dessine(Eau const&) override;
    virtual void dessine(Source const&) override;
    virtual void dessine(Sphere const&) override;

  // méthodes de (ré-)initialisation
  void init();
  void initializePosition();

  // méthode set
  void setProjection(QMatrix4x4 const& projection)
  { prog.setUniformValue("projection", projection); }

  // Méthodes set
  void translate(double x, double y, double z);
  void rotate(double angle, double dir_x, double dir_y, double dir_z);

  // méthode utilitaire offerte pour simplifier
  void dessineCube(QMatrix4x4 const& point_de_vue = QMatrix4x4() );
  void dessineSphere(QMatrix4x4 const& point_de_vue,
                     double rouge = 1.0, double vert = 1.0, double bleu = 1.0);
  void dessineAxes(QMatrix4x4 const& point_de_vue, bool en_couleur = true);

private:
  // Un shader OpenGL encapsulé dans une classe Qt
  QGLShaderProgram prog;
  GLSphere sphere;

  // Caméra
  QMatrix4x4 matrice_vue;
};

#endif
