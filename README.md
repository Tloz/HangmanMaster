HangmanMaster
=============

A programm to solve hangman games
You have an input like this

> _ _ A _ _
>
> _ _
>
> R A _ _ _ S
>
> _ _ _ _ E

And for each words, the algorithm gives the possibles words that matches the input

##Algorithm
###Overall
Originally, to identify matching words for one word to find, I had to do three things:

1. Take all words in the dictionary with the same length than the word to find that have matching letters.
For example, if you have _ _ A _ _, and this dictionary below.
You take every words except PIZZA, as the third letter must be a A.

2. Remove all words that contains letter that you know they aren't in the phrase.
Let's say that you know there are no G and T, you can get rid of TRACE and GLACE.

3. Finally, you remove words having double letters missing in the word to find.
In PLAZA, there are two A, nevertheless, in your word to find, there is only one. So remove PLAZA

There is no other way to remove words and being sure that they are not the one that we're looking for.
Or at least, I haven't found it yet ;)

Dictionary (very small, for example puposes)

>PLACE PLAZA PIZZA TRACE GLACE

##Implementation
Hangman master uses Qt 5.0.2. Visit [Qt website](http://qt-project.org/) to learn more.
###Word to find, Words in dictionary
A simple QString.

###Original Phrase
Starts as a QString, then becomes a QVector of QString after parsing.

###Dictionary
As of today, a QVector of QString. There is one dictionary for each length of word. They are named like this "length"."lang". So for example, the file that contains the french words of five letters is named 5.fr

##Roadmap
1. Create dictionaries
2. Minimalist GUI 

##Improvements
* Manage dictionary with a tree, and check wether it's faster or not (also I doubt it)
* For the moment, the algorithm does 2 passes on each word to find. Hack to make it 1
* The part that checks if there is no unwanted double works only on a word. Make it work on the whole sentence
* Sentence analysis: instead of finding words that matches the input, try to obfuscate a whole phrase, and check if it is relevant: number of words, of letter, punctuation, ...
* When the GUI will be functional to solve the hangman, add a function to add words in a dictionary. As of today, because of how the algorithm works, we dont need to sort the dictionary, or store it an tree instead of a vector

##Known Bugs
