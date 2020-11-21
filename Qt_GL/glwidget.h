#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QGLWidget>        // Classe pour faire une fenêtre OpenGL
#include <QTime>            // Classe pour gérer le temps
#include "supportadessin.h"
#include "vue_opengl.h"
#include "dessinable.h"
#include "systeme.h"

class GLWidget : public QGLWidget
/* La fenêtre hérite de QGLWidget ;
 * les événements (clavier, souris, temps) sont des méthodes virtuelles à redéfinir.
 */
{
public:
  GLWidget(int nb,QWidget* parent = nullptr)
    : QGLWidget(parent)
    , c(&vue)
    , nb_simulation(nb)
  {
      c.initialisation(&vue, nb);

  }
  virtual ~GLWidget() {}

private:
  // Les 3 méthodes clés de la classe QGLWidget à réimplémenter
  virtual void initializeGL()                  override;
  virtual void resizeGL(int width, int height) override;
  virtual void paintGL()                       override;

  // Méthodes de gestion d'évènements
  virtual void keyPressEvent(QKeyEvent* event) override;
  virtual void timerEvent(QTimerEvent* event)  override;
  virtual void mousePressEvent(QMouseEvent* event) override;
  virtual void mouseMoveEvent(QMouseEvent* event)  override;

  // Méthodes de gestion interne
  void pause();

  // Vue : ce qu'il faut donner au contenu pour qu'il puisse se dessiner sur la vue
  VueOpenGL vue;

  // Timer
  int timerId;

  // pour faire évoluer les objets avec le bon "dt"
  QTime chronometre;

  // position de la souris
  QPoint lastMousePosition;

  // objets à dessiner, faire évoluer
  Systeme c;

  //Numero de simulation
  int nb_simulation;
};

#endif // GLWIDGET_H
