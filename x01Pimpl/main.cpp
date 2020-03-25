#include <QCoreApplication>
#include <QDebug>
#include "autotimer.h"
#include <iostream>

void foo()
{
    Autotimer test("test timer");
    for (int i=1; i<=1000000000; i++)
        if (i % 100000000 == 0) std::cout << i << std::endl;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qDebug("Hello!\n");
    foo();

    return a.exec();
}
