QMAKE_CXXFLAGS += -std=c++11

TEMPLATE = lib

CONFIG = staticlib

SOURCES += \
    grain.cpp \
    vector3d.cpp \
    #testvector3d.cpp \
    plan.cpp \
    dalle.cpp \
    #testgrain.cpp \
    source.cpp \
    obstacle.cpp \
    #testobstacles.cpp \
    aleatoire.cpp \
    #testsource.cpp \
    sphere.cpp \
    brique.cpp \
    grainLJ.cpp \
    cylindre.cpp \
    systeme.cpp \
    dessinable.cpp \
    supportadessin.cpp \
    #testsysteme.cpp \
    grainLJsub.cpp \
    pyramide.cpp \
    eau.cpp

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

HEADERS += \
    grain.h \
    vector3d.h \
    plan.h \
    dalle.h \
    source.h \
    obstacle.h \
    aleatoire.h \
    sphere.h \
    brique.h \
    grainLJ.h \
    cylindre.h \
    systeme.h \
    dessinable.h \
    supportadessin.h \
    grainLJsub.h \
    pyramide.h \
    eau.h
