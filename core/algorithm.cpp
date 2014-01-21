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
QVector<QString> *positionSort(const QString word, int dico)
{
    // stores positions where you have a letter
    QVector<int> knownLetterPosition;
    for(int i = 0; i < word.size(); i++)
        if(word.at(i) != '_')
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
    while(!ts.atEnd())
        realDict.append(ts.readLine());
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
QVector<QString> *doubleSort(const QString word, QVector<QString> *words)
{
    QVector<QPair<QChar, int> > *map = new QVector<QPair<QChar, int> >();
    for(int i = 0; i < word.size(); i++)
        if(word[i] != QChar('_'))
            map->append(QPair(word[i], i));
    /*
    QString iEmeMot;
    QChar jEmeLettre; //du mot à trouver
    QChar kEmeLettre; //du mot à comparer (ième mot)
    QVector<QString> *returnValue = new QVector<QString>(*words);
    for(int i = 0; i < words->size(); i++)
    {
        qDebug() << "";
        iEmeMot = returnValue->at(i);
        qDebug() << "i=" << i << "   " << iEmeMot;
        for(int j = 0; j < returnValue[i].size(); j++)
        {
            jEmeLettre = word[j];
            qDebug() << "j=" << j << "   " << jEmeLettre;
            if(jEmeLettre != QChar('_'))
            {
                for(int k = j + 1; k < returnValue[i].size(); k++)
                {
                    kEmeLettre = word[k];
                    qDebug() << "k=" << k << "   " << kEmeLettre << "VS" << returnValue->at(i)[j];
                    if(kEmeLettre == returnValue->at(i).at(j))
                    {
                        qDebug() << words[i] << "retiré";
                        words->remove(i);
                    }
                }
            }
        }
    }
    delete returnValue;
    return words;
    */
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
