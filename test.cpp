#include "test.h"
#include "core/algorithm.h"

void test()
{
    const QString mysteryWord("__A_E");
    QVector<QString> dictionary (openDict(mysteryWord.size(), FR));
    QVector<QChar> *miss = new QVector<QChar>();
    miss->append('T');
    miss->append('X');
    miss->append('I');
    qDebug() << mysteryWord << endl << dictionary << endl << *miss << endl;
    QVector<QString> *output = new QVector<QString>();

    qDebug() << "partie 1",
    output = positionSort(mysteryWord, dictionary);
    qDebug() << *output << endl;

    qDebug() << "partie 2";
    output = missingSort(output, miss);
    qDebug() << *output << endl;

    /*
    output = doubleSort(mysteryWord, output);
    qDebug() << "partie 3" << endl << *output << endl;
    */
    qDebug() << endl << "THE END";
}
