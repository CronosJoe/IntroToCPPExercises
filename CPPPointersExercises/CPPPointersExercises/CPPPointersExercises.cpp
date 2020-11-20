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
    int* arr;
    std::cout << "How many numbers would you like to type? ";
    std::cin >> maxNum;
    arr = new int[maxNum];
    
        for (n = 0; n < maxNum; n++)
        {
            std::cout << "what is one of your favorite numbers?: ";
            std::cin >> arr[n];
        }
        std::cout << "Your number(s): ";
        for (n = 0; n < maxNum; n++)
        {
            std::cout << arr[n] << ", ";
        }
        delete[] arr;
    
}
int* duplicateArray(int* origArray, size_t size)
{
    int* dupArr = new int[size];
    for(int i = 0; i < size; ++i)
    {
        dupArr[i] = origArray[i];
    }
    return dupArr;
}
int* getIntSubArr(int* arr, size_t size, int startPoint)
{
    //should probably put an exception in case startpoint entered is greater then array size but I'm skipping that.
    int* subArr = new int[size - startPoint];
    int count = 0; //made this to count up the original arrays element slot 
    for(int i = startPoint;i<size;++i)
    {
        subArr[count] == arr[i];
    }
    return subArr;
}
void swap(int* pointOne, int* pointTwo)
{
    int tmp = *pointOne;
    *pointOne = *pointTwo;
    *pointTwo = tmp;
}
char* getPointer(char* arr, size_t size, bool caseSense, char search)
{
    if(caseSense)
    {
        for(int i =0; i<size; ++i)
        {
            if(tolower(arr[i])==search)
            {
                return &arr[i];
            }
        }
    }else
    {
        for (int i = 0; i < size; ++i)
        {
            if (arr[i] == search)
            {
                return &arr[i];
            }
        }
    }
    return nullptr;
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
    //std::cout << "Check" << std::endl; used for debug stop points
    int* dynZero = zeroArray(5);
   // printInt(dynZero, 5);
    delete[] dynZero;
    //favoriteNumbers();

    int* dynOrig = new int[4];
    dynOrig[0] = 1; dynOrig[1] = 2; dynOrig[2] = 1; dynOrig[3] = 2;
    int* dynDup = duplicateArray(dynOrig, 4);
    //printInt(dynDup, 4);
    delete[] dynOrig;
    delete[] dynDup;


}
