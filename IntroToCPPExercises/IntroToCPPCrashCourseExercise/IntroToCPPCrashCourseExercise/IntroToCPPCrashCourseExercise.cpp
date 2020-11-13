// IntroToCPPCrashCourseExercise.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{

    std::cout << "Welcome to the number guessing game! I will secretly choose a number between 1-100 and you will make guesses to try and figure out our number!\n";
    int min = 0;
    int max = 100;
    srand(time(NULL));
    bool solved = false;
     int randnum = 1 + std::rand() % ((max - min+1) + min);
     int guess;
   //main game loop
    while(!solved)
    {
        std::cout << "what is your guess?\n";
        std::cin >> guess;
        if(guess<randnum)
        {
            std::cout << "That is a little bit low\n";
        }else if(guess>randnum)
        {
            std::cout << "That is a little bit high\n";
        }else
        {
            std::cout << "You guessed it!";
            solved = true;
        }
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
