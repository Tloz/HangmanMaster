#ifndef ALGORITHM_H
#define ALGORITHM_H

#include <QVector>
#include <QString>
#include <QFile>
#include <QDebug>
#include <QPair>
#include <QTextStream>

enum lang{FR, EN};

QVector<QString> openDict(int length, lang l);

//First part: position sort
QVector<QString> *positionSort(const QString, QVector<QString>);

//Second part: missing sort
QVector<QString> *missingSort(QVector<QString>*, QVector<QChar>*);

//Third part: double sort
QVector<QString> *doubleSort(const QString word, QVector<QString>*);

//Final Call
QVector<QString> *solveWord(const QString, int, QVector<QChar>*);

#endif // ALGORITHM_H
