#include <QDebug>
#include <QString>

#include "core/algorithm.h"

int main()
{
    QVector<QString> *output = new QVector<QString>();
    QVector<QChar> *miss = new QVector<QChar>();
    miss->append('C');
    output = positionSort("__A__", 0);

    qDebug() << "partie 1";
    for(int i = 0; i < output->size(); i++)
        qDebug() << output->at(i);

    output = missingSort(output, miss);

    qDebug() << endl << "partie 2";
    for(int i = 0; i < output->size(); i++)
        qDebug() << output->at(i);

    qDebug() << endl << "THE END";
    return 0;
}
