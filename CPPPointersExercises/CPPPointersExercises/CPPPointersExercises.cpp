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
void printInt(int* arr, int size)
{
    for (int i = 0; i < size; ++i)
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
void initBools(bool * arr, int size, bool defaultValue)
{
    for(int i =0; i<size; ++i)
    {
        arr[i] = defaultValue;
    }
}
int* zeroArray(size_t size)
{
  
    int* dynZero = new int [size];
    for(int i = 0; i<size; ++i)
    {
       dynZero[i] = 0;
    }
    return dynZero;
}
void favoriteNumbers()
{
    int maxNum, n;
    int* p;
    std::cout << "How many numbers would you like to type? ";
    std::cin >> maxNum;
    p = new int[maxNum];
    
        for (n = 0; n < maxNum; n++)
        {
            std::cout << "what is one of your favorite numbers?: ";
            std::cin >> p[n];
        }
        std::cout << "Your number(s): ";
        for (n = 0; n < maxNum; n++)
        {
            std::cout << p[n] << ", ";
        }
        delete[] p;
    
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

    bool check[5];
    initBools(check, 5, false);
//  std::cout << "Check" << std::endl; used for debug stop points
    int* dynZero = zeroArray(5);
   // printInt(dynZero, 5);
    delete[] dynZero;
    favoriteNumbers();

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
