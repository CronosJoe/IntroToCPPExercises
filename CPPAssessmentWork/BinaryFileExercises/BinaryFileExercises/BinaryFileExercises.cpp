// BinaryFileExercises.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
void digitalPrint()
{
    //setup
    std::ifstream file;
    bool end = false;
    while (!end)
    {
        //asking for a filepath
        std::cout << "Please enter a file path to open. Or enter e to quit" << std::endl;
        //saving the filepath to a string
        std::string input;
        std::cin >> input;
        //an exit so the loop can end
        if(input == "e")
        {
            return;
        }
        //std::cout << input << std::endl; //to test the filepath make sure everything is saving correctly
        //opening the file
        file.open(input, std::ios::in);
        //checking if the file can be read from/written too here we only want to read though so I don't think I need .is_open()
        if (!file.good())
        {
            std::cerr << "Inputed file path could not be opened." << std::endl;
            return;
        }
        //prints out the file
        std::string buffer;
        while (std::getline(file, buffer)) // repeats until end of file or something breaks so I shouldn't need to check here
        {
            // print the line after it is buffered
            std::cout << buffer << std::endl;
        }
    }//end of while
    return;
}//end of digital print
void myInformation()
{
    //creating an ofstream to write to
    std::ofstream file;
    std::cout << "Please provide a name for your file." << std::endl;
    std::string input;
    std::cin >> input;
    file.open(input, std::ios::out);
    // verify that the file stream is open
    if(!file.is_open())
    {
        std::cerr << "Output file could not be opened for write." << std::endl;
        return;
    }
    // verify that the file is open
    if (!file.good())
    {
        std::cerr << "Output file is unable to be opened." << std::endl;
        return;
    }
    //writing to the file
    //name
    std::cout << "What is your name?" << std::endl;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, input);
    file << "Name: " + input << std::endl; //still wanna move to next line
    
        //age
        std::cout << "What is your age?" << std::endl;
        std::getline(std::cin, input);
        file << "Age: " + input << std::endl;
       
    
        //color
        std::cout << "What is your favorite color?" << std::endl;
        std::getline(std::cin, input);
        file << "Color: " + input << std::endl;
    
    file.flush(); // flush the output buffer, making sure all outputs are sent
    file.close();

    std::cout << "Thank you check your file for the inputed information" << std::endl;
}
int main()
{
    //digitalPrint();
    myInformation();
    return 0;
}


