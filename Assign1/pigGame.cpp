//
//  pigGame.cpp
//  Assign1
//
//  Created by Derek R Castile on 10/13/14.
//  Copyright (c) 2014 Derek R Castile. All rights reserved.
//

/*
 3. Pig game (50 points)
 The game of Pig is a simple two player dice game in which the first player to
 reach 100 or more points wins.
 Players take turns. On each turn a player rolls a six-sided die. After each
 roll:
    • If the player rolls a 2-6 then he can either: • ROLL AGAIN or
    • HOLD. At this point the sum of all rolls made this turn is added to the
 player’s total score and it becomes the other player’s turn.
    • If the player rolls a 1 then the player loses his turn. He gets no new
 points and it becomes the opponent’s turn.
 If a player reaches 100 or more points after holding then the player wins.

 Write a program that plays the game of Pig, where one player is a human and the
 other is the computer.
    Allow the human to input ‘r’ (or ‘R’) to roll again or ‘h’ (or ‘H’) to hold.
    The computer program should play according to the following rule: Keep
 rolling on the computer’s turn until it has accumulated 20 or more points, then
 hold. Of course, if the computer wins or rolls a 1 then the turn ends
 immediately. Allow the human to roll first.

    Write your program using at least two functions:
        - int humanTurn(int humanTotalScore);
        - int computerTurn(int computerTotalScore);
    These functions should perform the necessary logic to handle a single turn
 for either the com- puter or the human. The input parameter is the total score
 for the human or computer. The functions should return the turn total to be
 added to the total score upon completion of the turn. For example, if the human
 rolls a 3 and 6 and then holds, then humanTurn should re- turn 9. However, if
 the human rolls a 3 and 6 and then a 1, then the function should return 0.

 HINTS:
        Note that the description of the humanTurn and computerTurn functions
 indicate that an outside variable must keep track of the total score by adding
 to itself the value re- turned by the functions at the completion of each
 player’s turn.
        Also, to implement roll of a dice you can use the srand(int) and rand()
 functions from <cstdlib>.
        A random num- ber between M and N (both inclusive, where M < N) is equal
 to ((rand() % (N-M+1)) + M).
 */

#include <iostream>
#include <cstdlib>
#include <cctype>

using namespace std;

int rollDice() { return rand() % (6 - 1 + 1) + 1; }

enum PlayerType { USER, COMPUTER };
class Player {
private:
  int totalPoints = 0;
  PlayerType playerType;
  int humanTurn() {
    int points = 0;
    char currentRoll = 0;
    do {
      currentRoll = rollDice();
      switch (currentRoll) {
      case 1:
        cout << "\tYou rolled a 1, and lost your turn.\n";
        return 0;
      default:
        cout << "\tYou rolled a ";
        cout << (int)currentRoll << ".\n";
        points += currentRoll;
        break;
      }
      cout << "\tEnter (R)oll or (H)old:\t";
      string input;
      cin >> input;
      if (tolower(input.front()) == 'h') {
        return points;
      }
    } while (true);
  }
  int computerTurn() {
    int points = 0;
    char currentRoll = 0;
    do {
      currentRoll = rollDice();
      switch (currentRoll) {
      case 1:
        cout << "\tComputer rolled a 1, and lost it's turn.\n";
        return 0;
      default:
        cout << "\tComputer rolled a ";
        cout << (int)currentRoll << ".\n";
        points += currentRoll;
        break;
      }
    } while (points < 20);
    return points;
  };

public:
  Player(PlayerType pPlayerType) { playerType = pPlayerType; };
  int getTotalPoints() { return totalPoints; };
  int takeTurn() {
    int newPoints = 0;
    switch (playerType) {
    case USER:
      newPoints = humanTurn();
      totalPoints += newPoints;
      return newPoints;
    case COMPUTER:
      newPoints = computerTurn();
      totalPoints += newPoints;
      return newPoints;
    }
  };

  bool winner() {
    if (totalPoints > 100) {
      return true;
    } else {
      return false;
    }
  };
};

int pigGame() {
  Player one(USER);
  Player two(COMPUTER);
  int turnIndex = 0;

  while (true) {
    turnIndex += 1;

    cout << "Turn " << turnIndex << "\n";

    cout << "\nPlayer's turn:\n";
    cout << one.takeTurn();
    cout << "\nPlayer's total: ";
    cout << one.getTotalPoints() << "\n";

    cout << "\nComputer's turn:\n";
    two.takeTurn();
    cout << "\nComputer's total: ";
    cout << two.getTotalPoints() << "\n";

    cout << "\nEnd of turn " << turnIndex << "\n\n\n";

    if (one.winner()) {
      cout << "\n\nPlayer won with:\t" << one.getTotalPoints();
      return 1;
    }
    if (two.winner()) {
      cout << "\n\nComputer won with:\t" << two.getTotalPoints() << "\n";
      return 1;
    }
  }
}
