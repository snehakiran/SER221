//
//  rps.cpp
//  Assign1
//
//  Created by Derek R Castile on 10/12/14.
//  Copyright (c) 2014 DRC Ventures. All rights reserved.
//



/*
 2. Rock, Paper, Scissor (30 points)
Write a program to score the paper-rock-scissor game. Each of the two players type in either P, R, or S.
     The program then announces the winner based on the rule: 
        Paper covers Rock, Rock breaks Scissors, Scissors cut Paper, or Nobody wins.
     Be sure to allow the players to use lowercase as well as uppercase letters.
     Your program should allow the users to play repeatedly until they say they are done.
     Your program should also keep a score for each player and display that after each play.
        
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
#include <string.h>

using namespace std;

void rps() {
    int playAgain = 0;

    unsigned int playerOneScore = 0;
    unsigned int playerTwoScore = 0;

    char input1;
    char input2;

    do {
        cout << "\nPlayer 1: Please enter either (R)ock, (P)aper, or (S)cissors: ";
        cin >> input1;
        input1 = tolower(input1);
        cout << "\nPlayer 2: Please enter either (R)ock, (P)aper, or (S)cissors: ";
        cin >> input2;
        input2 = tolower(input2);
    switch (input1) {
        case 'p':
            switch (input2) {
                    case 'r':
                        cout << "Player 1 wins.";
                        playerOneScore += 1;
                        break;
                    case 's':
                        cout << "Player 2 wins.";
                        playerTwoScore += 1;
                        break;
                case 'p':
                    cout << "Tie.";
                    break;
                default:
                        break;
            }
            break;
        case 'r':
            switch (input2) {
                case 's':
                    cout << "Player 1 wins.";
                    playerOneScore += 1;
                    break;
                case 'p':
                    cout << "Player 2 wins.";
                    playerTwoScore += 1;
                    break;
                case 'r':
                    cout << "Tie.";
                    break;
                default:
                    break;
            }
            break;
        case 's':
            switch (input2) {
                case 'p':
                    cout << "Player 1 wins.";
                    playerOneScore += 1;
                    break;
                case 'r':
                    cout << "Player 2 wins.";
                    playerTwoScore += 1;
                    break;
                case 's':
                    cout << "Tie.";
                    break;
                default:
                    break;
            }
            break;
        default:
            cout << "Invalid entry\n";
            break;
    }
        cout << "\nThanks!";
        cout << "\nPlay again? Y/y continues, other quits: ";
        cin >> input1;
        input1 = tolower(input1);
        switch (input1) {
                case 'y':
                    playAgain = 1;
                    break;
                default:
                return;
        }
    } while(playAgain);
}

