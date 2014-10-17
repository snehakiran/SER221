//
//  rps.cpp
//  Assign1
//
//  Created by Derek R Castile on 10/12/14.
//  Copyright (c) 2014 DRC Ventures. All rights reserved.
//

/*
 2. Rock, Paper, Scissor (30 points)
Write a program to score the paper-rock-scissor game. Each of the two players
type in either P, R, or S.
     The program then announces the winner based on the rule:
        Paper covers Rock, Rock breaks Scissors, Scissors cut Paper, or Nobody
wins.
     Be sure to allow the players to use lowercase as well as uppercase letters.
     Your program should allow the users to play repeatedly until they say they
are done.
     Your program should also keep a score for each player and display that
after each play.

        Sample run:
            > Player 1: Please enter either (R)ock, (P)aper, or (S)cissors: P
            > Player 2: Please enter either (R)ock, (P)aper, or (S)cissors: s
            > Player 2 wins.
            > Scores after this play:
            > Player 1: 0
            > Player 2: 1
            > Thanks!!
            > Play again? Y/y continues, other quits: n
 */

//      P,R,S

#include <iostream>
#include <cctype>
#include <string>

using namespace std;

enum Sign { PAPER, ROCK, SCISSORS };

class Player {
private:
  Sign sign;
  int totalPoints = 0;
  string name;

  Sign setSign(char c) {
    c = tolower(c);
    switch (c) {
    case 'p':
      sign = PAPER;
      break;
    case 'r':
      sign = ROCK;
      break;
    case 's':
      sign = SCISSORS;
      break;
    }
    return sign;
  };

public:
  Player(string pName) { name = pName; };
  int incrementTotalPoints() {
    totalPoints += 1;
    cout << "\n" << name << " wins.";
    return totalPoints;
  }
  void takeTurn() {
    string s;
    cout << "\n" << name
         << ": Please enter either (R)ock, (P)aper, or (S)cissors: ";
    cin >> s;
    setSign(tolower(s[0]));
  };
  Sign getSign() { return sign; }
  int compareSign(Sign signToCompare) {
    switch (sign) {
    case PAPER:
      switch (signToCompare) {
      case PAPER:
        return 0;
      case ROCK:
        return 1;
      case SCISSORS:
        return -1;
      }
    case ROCK:
      switch (signToCompare) {
      case PAPER:
        return -1;
      case ROCK:
        return 0;
      case SCISSORS:
        return 1;
      }
    case SCISSORS:
      switch (signToCompare) {
      case PAPER:
        return 1;
      case ROCK:
        return -1;
      case SCISSORS:
        return 0;
      }
    }
  };
};

class RockPaperScissors {
  Player playerOne{"Player 1"}, playerTwo{"Player 2"};

public:
  void playRockPaperScissors() {
    playerOne.takeTurn();
    playerTwo.takeTurn();
    switch (playerOne.compareSign(playerTwo.getSign())) {
    case 1:
      playerOne.incrementTotalPoints();
      break;
    case 0:
      cout << "\n"
           << "Tie.";
      break;
    case -1:
      playerTwo.incrementTotalPoints();
      break;
    }
  };
  bool playAgain() {
    string s;
    cout << "\n"
         << "Thanks!";
    cout << "\n"
         << "Play again? Y/y continues, other quits: ";
    cin >> s;
    for (int i = 0; i < s.length(); i++) {
      if (tolower(s[i]) == 'y') {
        return true;
      }
    }
    return false;
  }
};

int rps() {
  RockPaperScissors rps;
  do {
    rps.playRockPaperScissors();
  } while (rps.playAgain());
  return 1;
}