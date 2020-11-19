// CPPPointersExercises.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
void printFloats(float* arr, int size)
{
    for(int i =0;i<size; ++i)
    {
        std::cout << arr[i] << std::endl;
    }
}
int arraySum(int* arr, int size)
{
    int sum = 0;
    for(int i =0; i<size; ++i)
    {
        sum += arr[i];
    }
    return sum;
}
int main()
{
    float numbers[] = { 1.2,1.3,1.4,1.5 };
    int arrSize = sizeof(numbers) / sizeof(numbers[0]);
    //printFloats(numbers, arrSize);

    int numbs[] = { 1,2,3,4 };
    int intArrSize = sizeof(numbs) / sizeof(numbs[0]);
    int sum = arraySum(numbs, intArrSize);
    //std::cout << sum << std::endl;


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
