// THE PROBLEM
// ***************************
// Given an array, X , of N integers and an array, W , representing the respective weights of X's elements, 
// calculate and print the weighted mean of X's elements. 
// Your answer should be rounded to a scale of 1 decimal place (i.e., 12.3 format).
// Solution Created By: Dustin Kaban
// Date: May 31st, 2020
// ***************************

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

double calculateMean(vector<int> xArray, vector<int> wArray, int size)
{
    if(size >= 5 && size <= 50)
    {
        double numerator = 0;
        double denominator = 0;
        for(int i=0;i<size;i++)
        {
            double val = (double)xArray[i];
            double val2 = (double)wArray[i];
            numerator += (val*val2);
            denominator += wArray[i];
        }
        return numerator / denominator;
    }
    else
    {
        return 0; //size is wrong
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> xArray;
    vector<int> wArray;
    int x;
    int count = 0;
    while(cin >> x)
    {
        if(count < n)
        {
            xArray.push_back(x);
        }
        else
        {
            wArray.push_back(x);
        }
        count++;
    }
    double mean = calculateMean(xArray,wArray,n);

    cout << fixed <<  setprecision(1) << mean << endl;
    return 0;
}
