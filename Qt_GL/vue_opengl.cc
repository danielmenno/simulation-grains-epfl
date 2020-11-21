#include "vue_opengl.h"
#include "vertex_shader.h" // Identifiants Qt de nos différents attributs
#include <cmath>
#include <algorithm>

// Notez que avec glDisabel(GL_CULL_FACE) (glwidget : paintgl()), les élément déssinés se dessinent 'double face'

// ======================================================================
void VueOpenGL::dessine(Systeme const &a_dessiner) {
    // Dessin des axes, puis dessin de chaques éléments du système
    QMatrix4x4 matrice;
    matrice.setToIdentity();
    dessineAxes(matrice, true);
    if(a_dessiner.getSource().size() != 0) {
        for(auto const& source: a_dessiner.getSource()) {
            source->dessine();
        }
    }
    if(a_dessiner.getObstacle().size() != 0) {
        for(auto const& ob: a_dessiner.getObstacle()) {
            ob->dessine();
        }
    }
    if(a_dessiner.getGrain().size() != 0) {
        for(auto const& grains: a_dessiner.getGrain()) {
            grains->dessine();
        }
    }
    if(a_dessiner.getEau().size() != 0) {
        for(auto const& e : a_dessiner.getEau()) {
            e->dessine();
        }
    }
}

void VueOpenGL::dessine(const Source & a_dessiner) {
    QMatrix4x4 matrice;
    matrice.translate(a_dessiner.get_position().get_x(),
                      a_dessiner.get_position().get_y(),
                      a_dessiner.get_position().get_z());
    prog.setUniformValue("vue_modele", matrice_vue*matrice);
    glBegin(GL_LINES);
    prog.setAttributeValue(CouleurId, 1.0, 1.0, 1.0);
    prog.setAttributeValue(SommetId, -1.0, 0.0, 0.0);
    prog.setAttributeValue(SommetId, 1.0, 0.0, 0.0);
    prog.setAttributeValue(SommetId, 0.0, -1.0, 0.0);
    prog.setAttributeValue(SommetId, 0.0, 1.0, 0.0);
    prog.setAttributeValue(SommetId, 0.0, 0.0, -1.0);
    prog.setAttributeValue(SommetId, 0.0, 0.0, 1.0);

    glEnd();
}

void VueOpenGL::dessine(const Sphere &a_dessiner) {
    // On se place à la postitin de la sphère, puis on 'rescale' à la valeur de son rayon. On la dessine ensuite
    QMatrix4x4 matrice;
    matrice.translate((a_dessiner.get_position()).get_x(),
                      a_dessiner.get_position().get_y(),
                      a_dessiner.get_position().get_z());
    matrice.scale(a_dessiner.get_r());
    dessineSphere(matrice, 1.0, 1.0, 1.0);
}

void VueOpenGL::dessine(const GrainLJun &a_dessiner) {
    // On se place à la postitin du grain, puis on 'rescale' à la valeur de son rayon. On le dessine ensuite
    QMatrix4x4 matrice;
    matrice.translate((a_dessiner.get_po()).get_x(),
                      a_dessiner.get_po().get_y(),
                      a_dessiner.get_po().get_z());
    matrice.scale(a_dessiner.get_r());
    if (a_dessiner.get_v().norme() > 1000)  dessineSphere(matrice, 0, 1, 1);
    else dessineSphere(matrice, 0.0, 0.7, a_dessiner.get_v().norme()/1000);

}

void VueOpenGL::dessine(const GrainLJdeux &a_dessiner) {
    // On se place à la postitin du grain, puis on 'rescale' à la valeur de son rayon. On le dessine ensuite
    QMatrix4x4 matrice;
    matrice.translate((a_dessiner.get_po()).get_x(),
                      a_dessiner.get_po().get_y(),
                      a_dessiner.get_po().get_z());
    matrice.scale(a_dessiner.get_r());
    if (a_dessiner.get_v().norme() > 1000)  dessineSphere(matrice, 0, 1, 1);
    else dessineSphere(matrice, 1, a_dessiner.get_v().norme()/1000, 0);

}

void VueOpenGL::dessine(const Triangle &a_dessiner) {
    // Dessin différent des autres. Ici, on ne se place pas à la position du triangle. On reste à l'origine, puis on dessine simplement les 3 somment avec leurs coordonnées
    QMatrix4x4 matrice;

    prog.setUniformValue("vue_modele", matrice_vue * matrice);
    glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
    glBegin(GL_TRIANGLES);

    prog.setAttributeValue(CouleurId, 0.0, 0.5, 1.0);
    prog.setAttributeValue(SommetId,    a_dessiner.get_position().get_x(),
                                        a_dessiner.get_position().get_y(),
                                        a_dessiner.get_position().get_z());

    prog.setAttributeValue(CouleurId, 1.0, 1.0, 0.0);
    prog.setAttributeValue(SommetId,    a_dessiner.get_p2().get_x(),
                                        a_dessiner.get_p2().get_y(),
                                        a_dessiner.get_p2().get_z());

    prog.setAttributeValue(CouleurId, 0.0, 1.0, 0.0);
    prog.setAttributeValue(SommetId,    a_dessiner.get_p3().get_x(),
                                        a_dessiner.get_p3().get_y(),
                                        a_dessiner.get_p3().get_z());
    glEnd();
}

void VueOpenGL::dessine(const Pyramide &a_dessiner) {
    // On dessine les éléments qui composent la pyramide, à savoir une dalle et quatre triangles
    dessine(a_dessiner.get_base());
    //On définit les points à dessiner
    Vector3D p2(a_dessiner.get_position() + a_dessiner.get_base().get_largeur()*a_dessiner.get_base().get_larg_unit());
    Vector3D p3(a_dessiner.get_position() + a_dessiner.get_base().get_longueur()*a_dessiner.get_base().get_long_unit());
    Vector3D p4(p3 + a_dessiner.get_base().get_largeur()*a_dessiner.get_base().get_larg_unit());

    Triangle t1(this,a_dessiner.get_position(),p2,a_dessiner.get_sommet());
    Triangle t2(this,a_dessiner.get_position(),p3,a_dessiner.get_sommet());
    Triangle t3(this,p2,p4,a_dessiner.get_sommet());
    Triangle t4(this,p3,p4,a_dessiner.get_sommet());

    dessine(t1); dessine(t2); dessine(t3); dessine(t4);
}

void VueOpenGL::dessine(const Plan &a_dessiner) {
    int size(60);

    QMatrix4x4 point_de_vue;
    point_de_vue.setToIdentity();
    double x = a_dessiner.get_position().get_x();
    double y = a_dessiner.get_position().get_y();
    double z = a_dessiner.get_position().get_z();

    double x_n = a_dessiner.get_normale().get_x();
    double y_n = a_dessiner.get_normale().get_y();
    double z_n = a_dessiner.get_normale().get_z();

    //On se place d'abord à la position du plan
    point_de_vue.translate(x, y, z);

    //On résoud le produit scalaire avec la normale, afin d'avoir au moins un vecteur directeur du plan, pour considérer son orientation
    if(x_n == 0) { x=0; y=-z_n; z=y_n; }
    else if(y_n == 0) { y=0; x=-z_n; z=x_n; }
    else { z=0; x=-y_n; y=x_n; }

    //Le deuxième vecteur directeur est trouvé avec un produit vectoriel
    Vector3D unit_1((Vector3D (x, y, z)).normalise());
    Vector3D unit_2((a_dessiner.get_normale() ^ unit_1).normalise());
    prog.setUniformValue("vue_modele", matrice_vue*point_de_vue);

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glBegin(GL_QUADS);

    //On fait ensuite le dessin du plan
    prog.setAttributeValue(CouleurId, 0.0, 0.97, 0.6);
    prog.setAttributeValue(SommetId, unit_1.get_x()*size, unit_1.get_y()*size, unit_1.get_z()*size);
    prog.setAttributeValue(SommetId, unit_2.get_x()*size, unit_2.get_y()*size, unit_2.get_z()*size);
    prog.setAttributeValue(SommetId, -unit_1.get_x()*size, -unit_1.get_y()*size, -unit_1.get_z()*size);
    prog.setAttributeValue(SommetId, -unit_2.get_x()*size, -unit_2.get_y()*size, -unit_2.get_z()*size);

    glEnd();

}

void VueOpenGL::dessine(const Dalle &a_dessiner) {

    QMatrix4x4 point_de_vue;
    point_de_vue.setToIdentity();
    double x = (a_dessiner.get_position()).get_x();
    double y = (a_dessiner.get_position()).get_y();
    double z = (a_dessiner.get_position()).get_z();

    double x_unit_long = a_dessiner.get_long_unit().get_x()*(a_dessiner.get_longueur());
    double y_unit_long = a_dessiner.get_long_unit().get_y()*(a_dessiner.get_longueur());
    double z_unit_long = a_dessiner.get_long_unit().get_z()*(a_dessiner.get_longueur());

    double x_unit_larg = a_dessiner.get_larg_unit().get_x()*(a_dessiner.get_largeur());
    double y_unit_larg = a_dessiner.get_larg_unit().get_y()*(a_dessiner.get_largeur());
    double z_unit_larg = a_dessiner.get_larg_unit().get_z()*(a_dessiner.get_largeur());

    // On se place à la position de la dalle
    point_de_vue.translate(x, y, z);

    prog.setUniformValue("vue_modele", matrice_vue*point_de_vue);

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glBegin(GL_QUADS);


    prog.setAttributeValue(CouleurId, 0.2, 0.0, 0.0);
    // On dessine ensuite la dalle, avec les coordonnées de ses points que nous avons trouvé ci-dessus
    prog.setAttributeValue(SommetId, 0.0, 0.0, 0.0);
    prog.setAttributeValue(CouleurId, 0.2, 0.4, 0.6);

    prog.setAttributeValue(SommetId, x_unit_long, y_unit_long, z_unit_long);
    prog.setAttributeValue(CouleurId, 0.2, 0.0, 0.0);

    prog.setAttributeValue(SommetId, x_unit_long + x_unit_larg, y_unit_long + y_unit_larg, z_unit_long + z_unit_larg);
    prog.setAttributeValue(CouleurId, 0.2, 0.4, 0.6);

    prog.setAttributeValue(SommetId, x_unit_larg, y_unit_larg, z_unit_larg);

    glEnd();

}

void VueOpenGL::dessine(Brique const& a_dessiner) {
    // On dessine simplement les six dalles qui composent la brique
    std::vector<Dalle*> faces = a_dessiner.get_faces();

    for(auto const face: faces) {
        face->dessine();
    }

    for(auto face : faces) {delete face; face = nullptr;}
    faces.clear();
}

void VueOpenGL::dessine(const Cylindre & a_dessiner) {

    QMatrix4x4 point_de_vue;
    point_de_vue.setToIdentity();
    double x(0);
    double y(0);
    double z(0);

    double x_n = a_dessiner.get_normale().get_x();
    double y_n = a_dessiner.get_normale().get_y();
    double z_n = a_dessiner.get_normale().get_z();

    // On résoud le produit scalaire avec la normale, afin d'avoir au moins un vecteur directeur des cercles qui composent le cylindre, pour considérer son orientation
    if(x_n == 0) { x=0; y=-z_n; z=y_n; }
    else if(y_n == 0) { y=0; x=-z_n; z=x_n; }
    else { z=0; x=-y_n; y=x_n; }
    // Le deuxième vecteur directeur est trouvé avec un produit vectoriel
    Vector3D unit_1((Vector3D (x, y, z)).normalise());
    Vector3D unit_2((a_dessiner.get_normale() ^ unit_1).normalise());
    std::vector<Vector3D> points = {};

    unsigned int div(60);

    // Avec les deux vecteurs directeur, on consstruit un tableau de points composant les cercles afin de pourvoir les construire. 60 points suffisent.
    // On en prend cependant 61, afin de 'fermer' les cercles et le liens entre les cercles (un GL_QUAD_STRIP)
    for(size_t i(0); i <= div; ++i) {
        points.push_back(unit_1*cos((2*M_PI/div)*i) + unit_2*sin((2*M_PI/div)*i));
    }

    x = (a_dessiner.get_position()).get_x();
    y = (a_dessiner.get_position()).get_y();
    z = (a_dessiner.get_position()).get_z();

    // On se place à la position du premier cercle
    point_de_vue.translate(x, y, z);
    point_de_vue.translate(x_n*a_dessiner.get_hauteur()/2, y_n*a_dessiner.get_hauteur()/2, z_n*a_dessiner.get_hauteur()/2);

    prog.setUniformValue("vue_modele", matrice_vue*point_de_vue);

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glBegin(GL_POLYGON);

    prog.setAttributeValue(CouleurId, 1.0, 0.0, 0.0);

    // On dessine le premier cercle, un polygone à 60 côtés
    for(auto pts : points) {
        prog.setAttributeValue(SommetId, pts.get_x()*a_dessiner.get_rayon(), pts.get_y()*a_dessiner.get_rayon(), pts.get_z()*a_dessiner.get_rayon());
    }

    glEnd();

    point_de_vue.setToIdentity();

    // On se place à la position du deuxième cercle
    point_de_vue.translate(x, y, z);
    point_de_vue.translate(-x_n*a_dessiner.get_hauteur()/2, -y_n*a_dessiner.get_hauteur()/2, -z_n*a_dessiner.get_hauteur()/2);

    prog.setUniformValue("vue_modele", matrice_vue*point_de_vue);

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glBegin(GL_POLYGON);

    prog.setAttributeValue(CouleurId, 0.0, 1.0, 0.0);

    // On dessine le deuxième cercle, un polygone à 60 côtés
    for(double i(points.size() -1); i >= 0; --i) {
        prog.setAttributeValue(SommetId, points[i].get_x()*a_dessiner.get_rayon(), points[i].get_y()*a_dessiner.get_rayon(), points[i].get_z()*a_dessiner.get_rayon());
    }

    glEnd();


    prog.setUniformValue("vue_modele", matrice_vue*point_de_vue);

    glBegin(GL_QUAD_STRIP);
    // On dessine ensuite le liens entre les deux cercles
    for(auto pts : points) {
        prog.setAttributeValue(CouleurId, 0.0, 1.0, 0.0);
        prog.setAttributeValue(SommetId, pts.get_x()*a_dessiner.get_rayon(), pts.get_y()*a_dessiner.get_rayon(), pts.get_z()*a_dessiner.get_rayon());
        prog.setAttributeValue(CouleurId, 1.0, 0.0, 0.0);
        prog.setAttributeValue(SommetId, pts.get_x()*a_dessiner.get_rayon() + x_n*a_dessiner.get_hauteur()
                               , pts.get_y()*a_dessiner.get_rayon() + y_n*a_dessiner.get_hauteur()
                               , pts.get_z()*a_dessiner.get_rayon() + z_n*a_dessiner.get_hauteur());
    }

    glEnd();
}

void VueOpenGL::dessine(const Eau &a_dessiner) {
    QMatrix4x4 matrice;
    double hauteur(a_dessiner.get_height());
    double largeur(a_dessiner.get_width());
    double longueur(a_dessiner.get_length());

    // Il y a plusieurs constructions possibles pour l'eau. On vérifie d'abord si c'est une surface infinie (cf classe "Eau")
    if(a_dessiner.get_length() == 0 && a_dessiner.get_width() == 0) {
        // Si ça l'est on dessine un plan. On n'utilise cependant pas la fonction dessine du plan, car celui ici est quadrillé, ce n'est pas le cas du plan
        longueur = 60;
        //On se place au centre de notre surface d'eau
        matrice.translate(a_dessiner.get_position().get_x(),
                          a_dessiner.get_position().get_y(),
                          a_dessiner.get_position().get_z());

        prog.setUniformValue("vue_modele", matrice_vue*matrice);

        glBegin(GL_LINES);

        // On dessine ensuite le plan
        for(double i(-longueur); i <= longueur; ++i) {
                prog.setAttributeValue(CouleurId, 0.0, 0.0, 1.0);
                prog.setAttributeValue(SommetId, -longueur, i, 0.0);
                prog.setAttributeValue(SommetId, longueur, i, 0.0);
                prog.setAttributeValue(SommetId, i, -longueur, 0.0);
                prog.setAttributeValue(SommetId, i, longueur, 0.0);

                // Si la hauteur n'est pas nulle, on dessine le deuxième plan à la hauteur définie
                if(hauteur != 0) {
                    prog.setAttributeValue(CouleurId, 0.0, 0.0, 1.0);
                    prog.setAttributeValue(SommetId, -longueur, i, -hauteur);
                    prog.setAttributeValue(SommetId, longueur, i, -hauteur);
                    prog.setAttributeValue(SommetId, i, -longueur, -hauteur);
                    prog.setAttributeValue(SommetId, i, longueur, -hauteur);
                }
        }
        glEnd();
    }
    // Si c'est une surface finie, on dessine un cube quadrillé
    else {
        matrice.translate(a_dessiner.get_position().get_x(),
                          a_dessiner.get_position().get_y(),
                          a_dessiner.get_position().get_z());

        prog.setUniformValue("vue_modele", matrice_vue*matrice);
        glBegin(GL_LINES);

        // On dessine ensuite les elements du cube, avec le moins d'itérations possibles
        for(double i(0); i <= std::max(longueur, largeur); ++i) {
            if(i <= longueur) {
                prog.setAttributeValue(CouleurId, 0.0, 0.0, 1.0);
                prog.setAttributeValue(SommetId, i, 0.0, 0.0);
                prog.setAttributeValue(SommetId, i, largeur, 0.0);
                if(hauteur != 0) {
                    prog.setAttributeValue(SommetId, i, 0.0, -hauteur);
                    prog.setAttributeValue(SommetId, i, largeur, -hauteur);
                    prog.setAttributeValue(SommetId, i, 0.0, 0.0);
                    prog.setAttributeValue(SommetId, i, 0.0, -hauteur);
                    prog.setAttributeValue(SommetId, i, largeur, 0.0);
                    prog.setAttributeValue(SommetId, i, largeur, -hauteur);
                }
            }
            if(i <= largeur) {
                prog.setAttributeValue(CouleurId, 0.0, 0.0, 1.0);
                prog.setAttributeValue(SommetId, 0.0, i, 0.0);
                prog.setAttributeValue(SommetId, longueur, i, 0.0);
                if(hauteur != 0) {
                    prog.setAttributeValue(SommetId, 0.0, i, -hauteur);
                    prog.setAttributeValue(SommetId, longueur, i, -hauteur);
                    prog.setAttributeValue(SommetId, 0.0, i, 0.0);
                    prog.setAttributeValue(SommetId, 0.0, i, -hauteur);
                    prog.setAttributeValue(SommetId, longueur, i, 0.0);
                    prog.setAttributeValue(SommetId, longueur, i, -hauteur);
                }
            }
        }
        glEnd();
    }



}

// ======================================================================
void VueOpenGL::init()
{
  /* Initialise notre vue OpenGL.
   * Dans cet exemple, nous créons et activons notre shader.
   *
   * En raison du contenu des fichiers *.glsl, le shader de cet exemple
   * NE permet QUE de dessiner des primitives colorées
   * (pas de textures, brouillard, reflets de la lumière ou autres).
   *
   * Il est séparé en deux parties VERTEX et FRAGMENT.
   * Le VERTEX :
   * - récupère pour chaque sommet des primitives de couleur (dans
   *     l'attribut couleur) et de position (dans l'attribut sommet)
   * - multiplie l'attribut sommet par les matrices 'vue_modele' et
   *     'projection' et donne le résultat à OpenGL
   *   - passe la couleur au shader FRAGMENT.
   *
   * Le FRAGMENT :
   *   - applique la couleur qu'on lui donne
   */

  prog.addShaderFromSourceFile(QGLShader::Vertex,   ":/vertex_shader.glsl");
  prog.addShaderFromSourceFile(QGLShader::Fragment, ":/fragment_shader.glsl");

  /* Identifie les deux attributs du shader de cet exemple
   * (voir vertex_shader.glsl).
   *
   * L'attribut identifié par 0 est particulier, il permet d'envoyer un
   * nouveau "point" à OpenGL
   *
   * C'est pourquoi il devra obligatoirement être spécifié et en dernier
   * (après la couleur dans cet exemple, voir plus bas).
   */

  prog.bindAttributeLocation("sommet",  SommetId);
  prog.bindAttributeLocation("couleur", CouleurId);

  // Compilation du shader OpenGL
  prog.link();

  // Activation du shader
  prog.bind();

  /* Activation du "Test de profondeur" et du "Back-face culling"
   * Le Test de profondeur permet de dessiner un objet à l'arrière-plan
   * partielement caché par d'autres objets.
   *
   * Le Back-face culling consiste à ne dessiner que les face avec ordre
   * de déclaration dans le sens trigonométrique.
   */
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_CULL_FACE);

  sphere.initialize();
  initializePosition();
}

// ======================================================================
void VueOpenGL::initializePosition()
{
    // Position initiale
    matrice_vue.setToIdentity();
    matrice_vue.translate(0,0,-10);
    matrice_vue.rotate(90, 0, 1, 0);
    matrice_vue.rotate(90, -1, 0, 0);
    matrice_vue.rotate(20, 0, -1, 0);
    matrice_vue.rotate(120, 0, 0, 1);
    matrice_vue.scale(0.1);
}

// ======================================================================
void VueOpenGL::translate(double x, double y, double z)
{
  /* Multiplie la matrice de vue par LA GAUCHE.
   * Cela fait en sorte que la dernière modification apportée
   * à la matrice soit appliquée en dernier (composition de fonctions).
   */
  QMatrix4x4 translation_supplementaire;
  translation_supplementaire.translate(x, y, z);
  matrice_vue = translation_supplementaire * matrice_vue;
}

// ======================================================================
void VueOpenGL::rotate(double angle, double dir_x, double dir_y, double dir_z)
{
  // Multiplie la matrice de vue par LA GAUCHE
  QMatrix4x4 rotation_supplementaire;
  rotation_supplementaire.rotate(angle, dir_x, dir_y, dir_z);
  matrice_vue = rotation_supplementaire * matrice_vue;
}

//=====================================================================
void VueOpenGL::dessineSphere (QMatrix4x4 const& point_de_vue,
                               double rouge, double vert, double bleu)
{
  glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
  prog.setUniformValue("vue_modele", matrice_vue * point_de_vue);
  prog.setAttributeValue(CouleurId, rouge, vert, bleu);
  sphere.draw(prog, SommetId);
}

void VueOpenGL::dessineAxes (QMatrix4x4 const& point_de_vue, bool en_couleur)
{
  prog.setUniformValue("vue_modele", matrice_vue * point_de_vue);

  glBegin(GL_LINES);
  glLineWidth(2);

  // axe X
  if (en_couleur) {
    prog.setAttributeValue(CouleurId, 1.0, 0.0, 0.0);
  } else {
    prog.setAttributeValue(CouleurId, 1.0, 1.0, 1.0);
  }
  prog.setAttributeValue(SommetId, 0.0, 0.0, 0.0);
  prog.setAttributeValue(SommetId, 230, 0.0, 0.0);

  // axe Y
  if (en_couleur) prog.setAttributeValue(CouleurId, 0.0, 1.0, 0.0);
  prog.setAttributeValue(SommetId, 0.0, 0.0, 0.0);
  prog.setAttributeValue(SommetId, 0.0, 230, 0.0);

  // axe Z
  if (en_couleur) prog.setAttributeValue(CouleurId, 0.0, 0.0, 1.0);
  prog.setAttributeValue(SommetId, 0.0, 0.0, 0.0);
  prog.setAttributeValue(SommetId, 0.0, 0.0, 230);
  glEnd();
}

