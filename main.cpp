#include <QDebug>
#include <QString>

#include "test.h"


#include "core/algorithm.h"

int main()
{
    QVector<QString> *output = new QVector<QString>();
    QVector<QChar> *miss = new QVector<QChar>();
    miss->append('T');
    miss->append('X');
    lang l = FR;
    output = positionSort("__A__", 0);
    qDebug() << endl << "partie 1";
    for(int i = 0; i < output->size(); i++)
        qDebug() << output->at(i);

    output = doubleSort("__A__", output);
    qDebug() << endl << "partie 3";
    for(int i = 0; i < output->size(); i++)
        qDebug() << output->at(i);


    return 0;
}
