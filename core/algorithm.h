#ifndef ALGORITHM_H
#define ALGORITHM_H

#include <QVector>
#include <QString>
#include <QFile>
#include <QDebug>
#include <QTextStream>

//First part: position sort
QVector<QString> *positionSort(const QString, int);

//Second part: missing sort
QVector<QString> *missingSort(QVector<QString>*, QVector<QChar>*);

//Third part: double sort
QVector<QString> *doubleSort(QVector<QString>*);

//Final Call
QVector<QString> *solveWord(const QString, int, QVector<QChar>*);

#endif // ALGORITHM_H
