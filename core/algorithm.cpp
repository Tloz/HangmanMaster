#include "algorithm.h"
#include "error.h"


QVector<QString> openDict(int length, lang l) // Working. TODO: throw error
{
    QString dictName(QString::number(length) + ".");
    switch (l)
    {
    case EN:
        dictName.append("en");
        break;
    case FR:
        dictName.append("fr");
        break;
    default:
        dictName.append("fr");
        break;
    }

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

bool hasBannedLetter(const QString word, QVector<QChar>* ban)
{
    foreach(QChar c, *ban)
        if(word.contains(c))
            return true;
}

QVector<QString> *solveWord(const QString word, QVector<QString> realDict, QVector<QChar>* bannedLetters)
{
    // Step 1
    // stores positions where you have a letter
    QString subString1;
    QString subString2;
    QVector<QString> *words = new QVector<QString>();
    QVector<int> knownLetterPosition;
    for(int i = 0; i < word.size(); i++)
        if(word.at(i) != '_')
            knownLetterPosition.append(i);

    // take words with matching letters and no unspecified copy of the letter
    // as long as they don't contains a forbidden letter

    foreach(QString dicoWord, realDict)
    {
        //qDebug() << "Looking at" << dicoWord;
        if(hasBannedLetter(dicoWord, bannedLetters))
        {
            //qDebug() << dicoWord << "has a forbidden letter, thus, moving to the next word" << endl;
            continue;
        }
        int totalMatch = 0;
        for(int i = 0; i < knownLetterPosition.size(); i++)
        {
            int p = knownLetterPosition[i];
            if(dicoWord[p] == word[p])
                totalMatch += 1;
            else
                i += knownLetterPosition.size();
        }
        if((totalMatch == knownLetterPosition.size()))
        {
            //qDebug() << dicoWord << "fits, adding it" << endl;
            words->append(dicoWord);
        }
        else
        {
            //qDebug() << dicoWord << "doesn't match" << endl;
        }
        // Looking for a way to do step 3 in a single pass instead of a second one
        /*
          subString1 = w.left(i + 1);
          subString2 = w.right(w.size() - i);
          qDebug() << subString1 << subString2;
          && (!((subString1.contains(p)) || subString2.contains(p)))
        */
    }

    /*
    // Step 3
    for(int i = 0; i < word.size(); i++)
        if(word.at(i) != QChar('_'))
            for(int j = 0; j < words->size(); j++)
            {
                QString subString1(words->at(j).left(i));
                QString subString2(words->at(j).right(words->at(j).size() - i - 1));
                if((subString1.contains(word[i])) || subString2.contains(word[i]))
                {
                    words->remove(j);
                    j--;
                }
            }
    */
    return words;
}
