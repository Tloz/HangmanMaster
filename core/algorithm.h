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
QVector<QString> *positionSort(const QString word, QVector<QString> dico);

//Second part: missing sort
QVector<QString> *missingSort(QVector<QString>* listOfWord, QVector<QChar>* bannedLetters);

//Third part: double sort
QVector<QString> *doubleSort(const QString word, QVector<QString>* words);

//Final Call
QVector<QString> *solveWord(const QString, int, QVector<QChar>*);

#endif // ALGORITHM_H
