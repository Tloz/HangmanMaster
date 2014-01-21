#include "algorithm.h"


// Dico 0 stands for french, 1 for english

// First part: position sort
QVector<QString> *positionSort(const QString word, int dico)
{
    // stores positions where you have a letter
    QVector<int> knownLetterPosition;
    for(int i = 0; i < word.size(); i++)
        if(word.at(i) != QChar('_'))
            knownLetterPosition.append(i);

    // open dictionary
    QString dictName(QString::number(word.size()) + ".");

    if (dico == 1)
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
    int nblines = 0;
    while(!ts.atEnd())
    {
        realDict.append(ts.readLine());
        nblines++;
    }
    dictionary.close();

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
    QVector<QString> *returnValue = new QVector<QString>(*words);
    for(int j = 0; j < words->size() -1; j++)
        // for each letter in a word
        for(int k = 0; k < words->at(j).size(); k++)
            // for each forbidden letter
            for(int i = 0; i < forbidenLetters->size(); i++)
                if(forbidenLetters->value(i) == words->value(j).at(k))
                {
                    returnValue->remove(j);
                    j++;
                    k = -1;
                }
    delete words;
    return returnValue;
}

// Third part: double sort
QVector<QString> *doubleSort(QVector<QString> *words)
{

}

// Final Call
QVector<QString> *solveWord(const QString word, int dico, QVector<QChar>* forbidenLetters)
{
    return doubleSort(missingSort(positionSort(word, dico), forbidenLetters));
}
