#include "algorithm.h"


QVector<QString> openDict(int length, lang l)
{
    QString dictName(QString::number(length) + ".");

    if (l == EN)
        dictName.append("en");
    else
        dictName.append("fr");
    QFile dictionary(dictName);
    if(!dictionary.open(QIODevice::ReadOnly))
    {
        //TODO:throw error
    }

    QTextStream ts(&dictionary);
    QVector<QString> realDict;
    while(!ts.atEnd())
        realDict.append(ts.readLine());
    dictionary.close();
    return realDict;
}

// First part: position sort
QVector<QString> *positionSort(const QString word, QVector<QString> realDict)
{
    // stores positions where you have a letter
    QVector<int> knownLetterPosition;
    for(int i = 0; i < word.size(); i++)
        if(word.at(i) != '_')
            knownLetterPosition.append(i);

    // take words with matching letters
    QVector<QString> *matchingWords = new QVector<QString>();
    foreach(QString w, realDict)
    {
        int totalMatch = 0;
        for(int i =0; i < knownLetterPosition.size(); i++)
        {
            if(w[knownLetterPosition[i]] == word[knownLetterPosition[i]])
                totalMatch += 1;
            else
                i += knownLetterPosition.size();
        }
        if(totalMatch == knownLetterPosition.size())
            matchingWords->append(w);
    }
    return matchingWords;
}

// Second part: missing sort
QVector<QString> *missingSort(QVector<QString> *words, QVector<QChar>* forbidenLetters)
{

}

// Third part: double sort
QVector<QString> *doubleSort(const QString word, QVector<QString> *words)
{
    QString iEmeMot;
    QChar jEmeLettre; //du mot à trouver
    QChar kEmeLettre; //du mot à comparer (ième mot)
    QVector<QString> *words2 = new QVector<QString>(*words);
    for(int i = 0; i < words2->size(); i++)
    {

    }
}

// Final Call
QVector<QString> *solveWord(const QString word, lang dico, QVector<QChar>* bannedLetters)
{
    /*
    //return doubleSort(word, missingSort(positionSort(word, dico), bannedLetters));
    //return doubleSort(word, positionSort(word, dico));

    // stores positions where you have a letter
    QVector<int> knownLetterPosition;
    for(int i = 0; i < word.size(); i++)
        if(word.at(i) != '_')
            knownLetterPosition.append(i);

    //Step 1
    qDebug() << "Step 1";
    QVector<QString> dictionary(openDict(word.length(), dico));
    QVector<QString> *matchingWords = new QVector<QString>();
    foreach(QString w, dictionary)
    {
        int totalMatch = 0;
        for(int i =0; i < knownLetterPosition.size(); i++)
        {
            if(w[knownLetterPosition[i]] == word[knownLetterPosition[i]])
                totalMatch += 1;
            else
                i += knownLetterPosition.size();
        }
        if(totalMatch == knownLetterPosition.size())
            matchingWords->append(w);
    }

    //Step 2
    qDebug() << "Step 2";
    QVector<QString> *secondMatch = new QVector<QString>(*matchingWords);

    for(int i = 0; i < secondMatch->size(); i++)
    {
        for(int j = 0; j < secondMatch[i].size(); j++)
        {
            for(int k = 0; k < bannedLetters->size(); k++)
            {
                if(secondMatch[i][j] == bannedLetters->at(k))
                {
                    matchingWords->remove(i);
                }
            }
        }
    }

    return matchingWords;
    */
}
