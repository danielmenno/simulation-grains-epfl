QMAKE_CXXFLAGS += -std=c++11

TARGET = projet_text

LIBS += -L../general -lgeneral
PRE_TARGETDEPS += ../general/libgeneral.a

INCLUDEPATH = ../general

SOURCES += \
    main_text.cc \
    text_viewer.cc
    
HEADERS += \
    text_viewer.h \
    ../general/dessinable.h \
    ../general/supportadessin.h
