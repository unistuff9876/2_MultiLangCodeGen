#include <QCoreApplication>

#include "consoleoutput.h"
#include "generateprogram.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    cout() << generateProgram();
    cout().flush();

    return a.exec();
}
