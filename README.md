# COMP2113-The-Da-Vinci-Code-
Course Project(2019-20) of COMP2113 at HKU

## Identification of the team members:
* Group77
* MountStill: Jiang Zhaochen 3035535042 zcjiang@connect.hku.hk
* SiannaZhu: Zhu Yanan 3035535133 zhuyanan@connect.hku.hk

## Game description with basic game rules:
   - We are going to write a game named The Da Vinci Code. In this game,there are 24 cards, 12 black and 12 white with numbers from 0 to 11.Each person starts with four cards sorted numerically(when two cards have the same number, the black one is considered smaller), but the numbers are only visible to himself.The player will take turns to grab a new card and guess the number of the other player. If he guesses right,his opponent should show the position of the card and he can choose to guess another number or stop temporarily. If his answer is wrong, he should put the card he grabs faced up and back into his line according to the previous rule. Whoever shows all the numbers of his cards will lose the game.
## List of features/functions:
1. Generation of random game sets or events
   - deal():The player and the computer each gain 4 random cards 
   - complay(int pro):The computer have the probability of pro to give the right answer

2. Data structures for storing game status
   - class card:using class to store the condition of each card

3. Dynamic memory management

4. File input/output (e.g., for loading/saving game status)
   - progress.txt:output the rate of progress of the game and the data of each cards and input it when the game starts again

5. Program codes in multiple files
   - main.cpp:writing the main program
   - card.h:class interface
   - card.cpp:class implementation
