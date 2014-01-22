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

###Algorithm
Originally, to identify matching words for one word to find, I had to do three things:
1. Take all words in the dictionary with the same length than the word to find that have matching letters.
For example, if you have _ _ A _ _, and this dictionary (very small, for example puposes):
>PLACE

>PLAZA

>PIZZA

>TRACE

>GLACE

You take every words except PIZZA, as the third letter must be a A.
2. Remove all words that contains letter that you know they aren't in the phrase.
Let's say that you know there are no G and T, you can get rid of TRACE and GLACE.
3. Finally, you remove words having double letters missing in the word to find.
In PLAZA, there are two A, nevertheless, in your word to find, there is only one. So remove PLAZA

There is no other way to remove words and being sure that they are not the one that we're looking for.
Or at least, I haven't found it yet ;)

###Improvements

* For the moment, the algorithm does 2 passes on each word to find. Hack to make it 1
* The part that checks if there is no unwanted double works only on a word. Make it work on the whole sentence
