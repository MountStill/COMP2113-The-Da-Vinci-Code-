# COMP2113-The-Da-Vinci-Code-
Course Project(2019-20) of COMP2113 at HKU

## Identification of the team members:
* Group77
* MountStill: Jiang Zhaochen 3035535042 zcjiang@connect.hku.hk
* SiannaZhu: Zhu Yanan 3035535133 zhuyanan@connect.hku.hk

## Game description with basic game rules:
   - We are going to write a generally two-person board game named The Da Vinci Code. In this game, there are 24 cards: 12 black and 12 white with numbers from 0 to 11. Each person starts with four cards sorted numerically(when two cards have the same number, the black one is considered smaller), but the numbers are only visible to himself. The players will take turns to draw a new card and guess the number of any one card of the other player. If he guesses right, his opponent should show the card and he can choose to guess another card or stop temporarily. If his answer is wrong, he should put the card he draws faced up and back into his line according to the previous rule. Whoever makes the opponent show all his cards wins the game. Sometimes, all of the cards are drawn before any one player showing all his cards. Under this special circumstance, whoever owns more cards hidden wins the game. We build the person-to-computer mode with adjustable difficulty as the group project. And the player can stop at each turn to have a rest by choosing not to continue the game. We will keep the progress archive for you to load at next time.

   
## List of features/functions:
1. Generation of random game sets or events
   - CardPool::Pick(): Pick a random card from the cardpool.(Also used when the player and the computer each gain four random cards at first.)
   - Gameplay(): When it is the computer's turn,the computer has different levels of possibility to guess the right answer.

2. Data structures for storing game status
   - struct Player: using string to store each player's name, and containing CardSet.
   - class CardPool: using class to store the remaining cards in the pool.
   - class CardSet: using class to store the condition of each player's card set, and containing Card.
   - struct Card: using string to store the value and color of one card, and using bool to store whether the card can be seen by the opponent.

3. Dynamic memory management
   - vector\<string\> cardpool: using vector to store the remaining cards in the pool as a private member of class CardPool.
   - vector\<Card\> cardset: using vector to store the player's card set as a private member of class CardSet.
   - int \*guessposition: temporarily storing the card position to be guessed. (in the function GamePlay)
   - int \*guesscard: temporarily storing the card number and color to be guessed. (in the function GamePlay)
   
4. File input/output (e.g., for loading/saving game status)
   - Introduction.txt: input the introduction of game rules and tips.
   - Progress.txt: output the rate of progress of the game and the condition of each card if the game is paused, and input it when the game starts again.
   - Summary.txt: output the summary results of each player in the game, including win rate, performance in each turn, etc.

5. Program codes in multiple files
   - main.cpp: writing the main program.
   - CardSet.h: class cardset interface.
   - CardSet.cpp: class cardset implementation.
   - CardPool.h: class cardpool interface.
   - CardPool.cpp: class cardpool implementation.

## Compilation and execution instructions:
1. Download all files (Including "Introduction.txt").

2. Two methods to run the program (Make sure the "Introduction.txt" is under the same path).
   - g++ -pedantic-errors -std=c++11 main.cpp CardPool.cpp CardSet.cpp -o main
   - ./main
   - OR simply run the "Da Vinci Code.exe"

3. Follow the instructions printed on the screen to input your choice.
