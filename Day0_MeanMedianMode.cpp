// THE PROBLEM
// ***************************
// Given an array, X , of N integers, calculate and print the respective mean, median, and mode on separate lines. 
// If your array contains more than one modal value, choose the numerically smallest one.
// Note: Other than the modal value (which will always be an integer), your answers should be in decimal form, 
// rounded to a scale of  decimal place (i.e., ,  format).
// ***************************

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

double calculateMean(int n, int mean)
{
    return ((double)mean/n);
}

double calculateMedian(int n, vector<int> arr)
{
    sort(arr.begin(),arr.end(), greater<int>());

    double middle = n/2;
    double median;
    double left = arr[(int)middle];
    double right = arr[(int)middle-1];
    median = (left + right)/2;
    return median;
}

int calculateMode(int n, vector<int> arr)
{
    int largestNum = 0, largestCount = 0;
 
    int* upperLimit = std::max_element(&arr[0], &arr[n]);
    int* lowerLimit = std::min_element(&arr[0], &arr[n]);
    for (int i = *lowerLimit; i <= *upperLimit; ++i)
    {
        int currentCount = std::count(&arr[0], &arr[n], i);
        if (currentCount > largestCount)
        {
            largestCount = currentCount;
            largestNum = i;
        }
    }
    return largestNum;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    vector<int> arr;
    cin >> n;

    int x;
    while(cin >> x)
    {
        arr.push_back(x);
    }

    double mean;
    if(n >= 10 && n <= 2500)
    {
        for(size_t i=0, max = arr.size();i != max;i++)
        {
            if(arr[i] > 0 && arr[i] <= 100000)
            {
                mean += arr[i];
            }
        }
    }

    int mode = calculateMode(n,arr);

    cout << calculateMean(n,mean) << fixed << setprecision(1) << endl;
    cout << calculateMedian(n,arr) << fixed << setprecision(1) <<endl;
    cout << mode << fixed << setprecision(0) << endl;

    return 0;
}
