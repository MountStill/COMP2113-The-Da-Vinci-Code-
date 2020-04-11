# COMP2113-The-Da-Vinci-Code-
Course Project(2019-20) of COMP2113 at HKU

## Identification of the team members:
* Group77
* MountStill: Jiang Zhaochen 3035535042 zcjiang@connect.hku.hk
* SiannaZhu: Zhu Yanan 3035535133 zhuyanan@connect.hku.hk

## Game description with basic game rules:
   - We are going to write a generally two-person board game named The Da Vinci Code. In this game, there are 24 cards: 12 black and 12 white with numbers from 0 to 11. Each person starts with four cards sorted numerically(when two cards have the same number, the black one is considered smaller), but the numbers are only visible to himself. The players will take turns to grab a new card and guess the number of any one card of the other player. If he guesses right, his opponent should show the card and he can choose to guess another card or stop temporarily. If his answer is wrong, he should put the card he grabs faced up and back into his line according to the previous rule. Whoever shows all the numbers of his cards will lose the game. We will first build the person-to-computer mode with adjustable difficulty. If we have time, we will then build the person-to-person mode, four-person mode, special rule mode, etc.
   
## List of features/functions:
1. Generation of random game sets or events
   - deal(): The player and the computer each gain four random cards at first.
   - difficulty(string level): The computer have different levels of ability to guess the right answer.

2. Data structures for storing game status
   - struct player: using string to store each player's name, and using class cardset to store the condition of each player's card set.
   - class cardset: contained in the struct above.
   - class cardpool: using class to store the remaining cards in the pool.

3. Dynamic memory management
   - int \*position: temporarily storing the card position to be guessed.
   - int \*number: temporarily storing the card number to be guessed.
   - bool \*judge: temporarily storing outcome of a guess.
   All the above dynamic variables will be cleaned at the end of each guess turn.
   
4. File input/output (e.g., for loading/saving game status)
   - initiator.txt: input the game mode and the difficulty settings.
   - progress.txt: output the rate of progress of the game and the condition of each card if the game is paused and input it when the game starts again.
   - summary.txt: output the summary results of each player in the game, including win rate, performance in each turn, etc.

5. Program codes in multiple files
   - main.cpp: writing the main program.
   - cardset.h: class cardset interface.
   - cardset.cpp: class cardset implementation.
   - cardpool.h: class cardpool interface.
   - cardpool.cpp: class cardpool implementation.
