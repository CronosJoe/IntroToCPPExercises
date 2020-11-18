// CPPArrayExercisesRedo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
void printNumbers(int numbers[], size_t size) 
{
    for(int i = 0; i<size; ++i)
    {
        std::cout << numbers[i]<<std::endl;
    }
}
int sumNumbers(int numbers[], size_t size)
{
    int sum = 0;
    for(int i =0; i<size; ++i)
    {
        sum += numbers[i];
    }
    return sum;
}
int largestValue(int numbers[], size_t size)
{
    int largest = INT32_MIN;
    for(int i = 0; i<size; ++i)
    {
        if(numbers[i]>largest)
        {
            largest = numbers[i];
        }
    }
    return largest;
}
int findValue(int numbers[], size_t size, int value, int start)
{
    int index = -1; //this is the default return in case it fails.
    for(int i = start; i<size;++i)
    {
        if(value == numbers[i])
        {
            return i;
        }
    }
    return index;
}
int countElement(int numbers[], size_t size, int value)
{
    int count = 0;
    for(int i=0; i<size; ++i)
    {
        if(numbers[i]==value)
        {
            count++;
        }
    }
    return count;
}
int main()
{
    int numb[] = { 1,2,3,4};
    int arrSize = sizeof(numb) / sizeof(numb[0]);
    //printNumbers(numb, arrSize);
    int sum = sumNumbers(numb, arrSize);
    //std::cout << sum << std::endl;
    int largest = largestValue(numb, arrSize);
    //std::cout << largest << std::endl;
    int foundIndex = findValue(numb, arrSize, 2, 0);
    //std::cout << foundIndex << std::endl;
    int occurance = countElement(numb, arrSize, 1);
    //std::cout << occurance << std::endl;

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
