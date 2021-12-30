// ompLab.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <omp.h>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
using namespace std;

int vec[10];
int resVec[10];
int arr[10][10];

void display();

int main()
{
    setlocale(0, "");
    
    srand(time(NULL));

    
    for (int i = 0; i < 10; i++)
    {
        for (int u = 0; u < 10; u++)
        {
            arr[i][u] = rand() % 20 - 6;
            
        }
        
    }
    
    for (int i = 0; i < 10; i++)
    {
        vec[i] = rand() % 20 - 6;
        
    }
    omp_set_num_threads(4);
    display();
    unsigned int start_time = clock();
    #pragma omp parallel
    {
        int temp = 0;
        for (int e = 0; e < 10; e++)
        {
            #pragma omp critical
            for (int r = 0; r < 10; r++)
            {
                temp += arr[e][r]*vec[r];
            }
            resVec[e] = temp;
        }
    }
    unsigned int end_time = clock();
    cout << "\n";
    for (int i = 0; i < 10; i++)
    {
        cout << resVec[i]<<"\n";
    }
    cout << end_time - start_time;
    cout << " ms";
}

void display() {
    for (int i = 0; i < 10; i++)
    {
        for (int u = 0; u < 10; u++)
        {
            
            cout << arr[i][u] << "\t";
        }
        cout << "\n";
    }
    cout << "\n";
    for (int i = 0; i < 10; i++)
    {
        
        cout << vec[i];
        cout << "\n";
    }
}



