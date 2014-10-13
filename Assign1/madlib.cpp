//
//  madlib.cpp
//  Assign1
//
//  Created by Derek R Castile on 10/12/14.
//  Copyright (c) 2014 DRC Ventures. All rights reserved.

//  1. Madlib (20 points)
//  Write a program that plays the game of Mad Lib. Your program should prompt the user to enter the following strings:
//    • The first or last name of your Instructor
//    • Your name
//    • A food
//    • A number between 100 and 120
//    • An adjective
//    • A color
//    • An animal
//  After getting the strings as input, they should be substituted into the story below. The resulting story should be displayed as the output.

//        Dear Professor [Instructor Name],
//    I am sorry that I am unable to turn in my homework at this time.
//    First, I ate a rotten [Food], which made me turn [Color] and
//    extremely ill. I came down with a fever of [Number 100-120].
//    Next, my [Adjective] pet [Animal] must have smelled the remains
//    of the [Food] on my homework, because he ate it. I am currently
//    rewriting my homework and hope you will accept it late.
//        Sincerely,
//        [Your Name]
//
//    Filename: madlib.cpp


#include <iostream>

using namespace std;

int main() {

    string instructorName, userName, food, number, adjective, color, animal;

    cout<<"Ready for a madlib?\n\n";

//    cout<<"\nFirst or Last name of your Instructor:\t";
//    cin>>instructorName;
//
//    cout<<"\nYour name:\t";
//    cin>>userName;
//
//    cout<<"\nA food:\t";
//    cin>>food;
//
//    cout<<"\nA number between 100 and 120:\t";
//    cin>>number;
//
//    cout << "\nAn adjective:\t";
//    cin >> adjective;
//
//    cout << "\nA color:\t";
//    cin >> color;
//
//    cout << "\nAn animal:\t";
//    cin >> animal;

    instructorName = "Bansal";
    userName = "Derek";
    food = "clam chowder";
    number = "420";
    adjective = "flaming";
    color = "rainbow";
    animal= "goat";



    cout << "\tDear Professor " <<instructorName <<",\nI am sorry that I am unable to turn in my homework at this time.\n" << "First, I ate a rotten "<< food <<", which made me turn " << color << " and\nextremely ill. I came down with a fever of " << number << ".\nNext, my "<< adjective << " pet " << animal << " must have smelled the remains\nof the " << food << " on my homework, because he ate it.\nI am currently rewriting my homework\n and hope you will accept it late.\n\tSincerely,\n\t" <<userName << "\n\n\n";

}
