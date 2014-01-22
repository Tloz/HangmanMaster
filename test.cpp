#include "test.h"
#include "core/algorithm.h"

void test()
{
    const QString mysteryWord("__A__");
    QVector<QString> dictionary (openDict(mysteryWord.size(), FR));
    QVector<QChar> *miss = new QVector<QChar>();
    miss->append('T');
    miss->append('X');
    QVector<QString> *output = new QVector<QString>();


    output = positionSort(mysteryWord, dictionary);
    qDebug() << "partie 1";
    for(int i = 0; i < output->size(); i++)
        qDebug() << output->at(i);

    /*
    output = missingSort(output, miss);
    qDebug() << endl << "partie 2";
    for(int i = 0; i < output->size(); i++)
        qDebug() << output->at(i);
    qDebug() << endl << endl;
    */

    /*
    output = doubleSort(mysteryWord, output);
    qDebug() << endl << "partie 3";
    for(int i = 0; i < output->size(); i++)
        qDebug() << output->at(i);
    */
    qDebug() << endl << "THE END";
}
