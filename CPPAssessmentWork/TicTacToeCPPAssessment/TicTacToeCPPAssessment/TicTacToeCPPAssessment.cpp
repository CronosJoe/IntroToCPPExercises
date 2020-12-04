// TicTacToeCPPAssessment.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
//this is the board that we will be using
char matrix[3][3] = { '1','2','3','4','5','6','7','8','9' };
//this is the setup for the players I'm making these public variable for simplicity
char player = 'X';
//finally this variable is for the main game loop to see if the game is over
bool finishedGame;
//this method will be called whenever I want to draw the matrix
void draw()
{
    std::cout << "Tic Tac Toe assessment v1.0" << std::endl;
    for(int i =0; i<3; ++i)
    {
        for(int j = 0; j<3; ++j)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
//this method will take the player's input so they can play
void input()
{
    //setting up the variables for input
    char playerInput;
    bool turnFinished = false;
    while (!turnFinished)
    {
        //this count will let me know when we are through the array so we know if the player's input is invalid
        int count = 0;

        std::cout << "enter the number for the space you'd like to use? (An unoccupied space of 1-9)" << std::endl;
        std::cin >> playerInput;
        //this will iterate through the array and find the spot the player would like the occupy if the spot has been taken then they will have to choose again
        for(int i =0; i<3; ++i)
        {
            for(int j =0; j<3; ++j)
            {
                if(matrix[i][j]==playerInput)
                {
                    matrix[i][j] = player;
                    turnFinished = true;
                }
                count++;
                //I'm checking to see if turnfinished is still false just as a precaution in case something goes wrong
                if(count == 9 && !turnFinished)
                {
                    std::cout << "That space has been taken please choose another." << std::endl;
                }
            }

        }
    }
}//end of input
//this switches the active player
void togglePlayer()
{
    if(player == 'X')
    {
        player = 'O';
    }else
    {
        player = 'X';
    }
}
//this method will check if a player has won
bool checkWinner()
{
    //once again bringing back count so I can know if a player has gotten 3 spaces in a row
    int countXColumn = 0;
    int countOColumn = 0;
    int countXRow = 0;
    int countORow = 0;
    //standard iteration through the multi dimensional array to see if a player has won
    for(int i = 0; i <3; ++i)
    {
        for(int j =0; j<3; ++j)
        {
            //check columns
            if(matrix[i][j] == 'X')
            {
                countXColumn++;
            }else if(matrix[i][j] == 'O')
            {
                countOColumn++;
            }
            //check rows
            if (matrix[j][i] == 'X')
            {
                countXRow++;
            }
            else if (matrix[j][i] == 'O')
            {
                countORow++;
            }
        }
        //checking to see if a player has gotten three in this row/column
        if(countXColumn==3)
        {
            std::cout << "X player has won!" << std::endl;
            return true;
        }else if(countOColumn==3)
        {
            std::cout << "O player has won!" << std::endl;
            return true;
        }
        else if (countXRow == 3)
        {
            std::cout << "X player has won!" << std::endl;
            return true;
        }
        else if (countORow == 3)
        {
            std::cout << "O player has won!" << std::endl;
            return true;
        }
        //resets the variables after the inner iteration for the next row/column check
        countXColumn = 0;
        countOColumn = 0;
        countXRow = 0;
        countORow = 0;
    }
    //I couldn't figure out how to squeeze in diagonals into my method since I was resetting the counts with each iteration so I'll just do them manually here
    if(matrix[0][0] == 'X' && matrix[1][1] == 'X' && matrix[2][2] == 'X')
    {
        std::cout << "X player has won!" << std::endl;
        return true;
    }else if(matrix[2][0] == 'X' && matrix[1][1] == 'X' && matrix[0][2] == 'X')
    {
        std::cout << "X player has won!" << std::endl;
        return true;
    }else if (matrix[0][0] == 'O' && matrix[1][1] == 'O' && matrix[2][2] == 'O')
    {
        std::cout << "O player has won!" << std::endl;
        return true;
    }
    else if (matrix[2][0] == 'O' && matrix[1][1] == 'O' && matrix[0][2] == 'O')
    {
        std::cout << "O player has won!" << std::endl;
        return true;
    }
   
    return false;
}
int main()
{
    finishedGame = false;
    draw();
    while(!finishedGame)
    {
        //basic loop asks for input draws the board then it switches player
        input();
        draw();
        togglePlayer();
        finishedGame = checkWinner();
    }
    std::cout << "Thank you for playing!" << std::endl;
    return 0;
}


