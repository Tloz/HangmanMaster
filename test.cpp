#include "test.h"
#include "core/algorithm.h"

void test()
{

    QVector<QString> *output = new QVector<QString>();
    QVector<QChar> *miss = new QVector<QChar>();
    miss->append('T');
    miss->append('X');
    lang l = FR;
    //solveWord(QString("__A__"), 0, miss);
    output = positionSort("__A__", 0);

    qDebug() << "partie 1";
    for(int i = 0; i < output->size(); i++)
        qDebug() << output->at(i);

    output = missingSort(output, miss);
/*
    qDebug() << endl << "partie 2";
    for(int i = 0; i < output->size(); i++)
        qDebug() << output->at(i);
    qDebug() << endl << endl;
    */

    output = doubleSort("__A__", output);

    qDebug() << endl << "partie 3";
    for(int i = 0; i < output->size(); i++)
        qDebug() << output->at(i);

    qDebug() << endl << "THE END";
}
