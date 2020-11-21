#include <QApplication>
#include "form.h"

int main(int argc, char* argv[])
{

    QApplication a(argc, argv);
    Form f;
    f.showMaximized();

  return a.exec();
}
