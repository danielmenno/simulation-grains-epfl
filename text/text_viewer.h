#ifndef TEXT_VIEWER_H
#define TEXT_VIEWER_H

#include <iostream>
#include "supportadessin.h"

class TextViewer : public SupportADessin {
 public:
 TextViewer(std::ostream& flot)
    : flot(flot)
  {}
  virtual ~TextViewer() {}

    virtual void dessine(Systeme const&) override;
    virtual void dessine(const Dalle &) override;
    virtual void dessine(const Plan &) override;
    virtual void dessine(const Sphere &) override;
    virtual void dessine(const Triangle &) override;
    virtual void dessine(const Pyramide &) override;
    virtual void dessine(GrainLJun const&) override;
    virtual void dessine(GrainLJdeux const&) override;
    virtual void dessine(Cylindre const&) override;
    virtual void dessine(Brique const&) override;
    virtual void dessine(Eau const&) override;
    virtual void dessine(Source const&) override;



 private:
  std::ostream& flot;
};

#endif
