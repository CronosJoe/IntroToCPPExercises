// NumbersGuessingGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
    std::cout << "Welcome to The Number Guessing Game! This was designed by Joseph for his C++ assessment!\n let's begin! Please select a number between 1 and 100, but don't tell me!\n";
    //Setup phase before the main game loop
    int lowestNum = 1;
    int largestNum = 100;
    bool solved = false;
    int tries = 0;
    //main game loop
    while(!solved)
    {
        int guess = (lowestNum + largestNum) / 2;
        std::cout << "\nIs your number: "<< std::endl;
        std::cout << guess << std::endl;
        std::cout << "Please reply with High/H, Low/L, or Yes/Y"<<std::endl;
        //taking input 
        std::string input;
        std::cin >> input;
        //iterating through the char array that is input to set it all to lower case
        int i = 0;
        while(input[i])
        {
            input[i] = tolower(input[i]);
            ++i;
        }
        //std::cout << input << std::endl;// This is so I can print the input whenever I need for testing
        if(input == "high" || input == "h")
        {
            largestNum = guess; //I am setting the largest number to the guess because if it gets to 1 or 100 then the round off of converting to in will set 1,1 in the large,small
            ++tries;
        }
        else if (input == "low" || input == "l") 
        {
            lowestNum = guess;
            ++tries;
        }else if(input =="yes" || input == "y")
        {
            ++tries;
            std::cout << "Good game!" << std::endl;
            std::cout << "I took ";
            std::cout << tries;
            std::cout << " guesses to guess your number! Thank you for playing";
            solved = true;
        }else
        {
            std::cout << "Sorry I don't understand your input try again?";
        }
        
    }//end of main game loop
    return 0;
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
