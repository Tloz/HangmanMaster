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

bool hasBannedLetter(const QString word, QVector<QChar>* ban);

QVector<QString> *solveWord(const QString, QVector<QString> realDict, QVector<QChar>*);

#endif // ALGORITHM_H
