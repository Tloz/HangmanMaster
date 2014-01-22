#include "test.h"
#include "core/algorithm.h"

void test()
{
    const QString mysteryWord("__A__");
    QVector<QString> dictionary (openDict(mysteryWord.size(), FR));
    QVector<QChar> *miss = new QVector<QChar>();
    miss->append('T');
    miss->append('X');
    qDebug() << mysteryWord << endl << dictionary << endl << *miss;
    QVector<QString> *output = new QVector<QString>();


    output = positionSort(mysteryWord, dictionary);
    qDebug() << "partie 1" << endl << *output << endl;


    /*
    output = missingSort(output, miss);
    qDebug() << "partie 2" << endl << *output << endl;
    */

    /*
    output = doubleSort(mysteryWord, output);
    qDebug() << "partie 3" << endl << *output << endl;
    */
    qDebug() << endl << "THE END";
}
