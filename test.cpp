#include "test.h"
#include "core/algorithm.h"

void test()
{
    QString mysteryWord("________________________S");
    QVector<QString> dictionary (openDict(mysteryWord.size(), FR));
    QVector<QChar> *miss = new QVector<QChar>();
    //miss->append('G');
    //miss->append('E');
    qDebug() << mysteryWord << endl << dictionary << endl << *miss << endl;

    QVector<QString> *output = new QVector<QString>(*solveWord(mysteryWord, dictionary, miss));
    qDebug() << *output;

    mysteryWord = "D_";
    dictionary = (openDict(mysteryWord.size(), FR));

    output = solveWord(mysteryWord, dictionary, miss);
    qDebug() << *output;

    mysteryWord = "__A_A";
    dictionary = (openDict(mysteryWord.size(), FR));

    output = solveWord(mysteryWord, dictionary, miss);
    qDebug() << *output;

    qDebug() << "THE END";
}
