#include <QtGui/QApplication>
#include "imgtest.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    imgtest w;
    w.show();
    
    return a.exec();
}
