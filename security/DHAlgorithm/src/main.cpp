#include "dialogentry.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DialogEntry w;
    w.show();

    return a.exec();
}
