// THE PROBLEM
// ***************************
// The probability that a machine produces a defective product is 1/3. 
// What is the probability that the  defect is found during the 5th inspection?
// Solution Created By: Dustin Kaban
// Date: June 4th, 2020
// ***************************

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;


int main() {
    int numerator;
    int denominator;
    cin >> numerator >> denominator;
    int defect;
    cin >> defect;

    double probability = (double)numerator/denominator;
    double geoDist = pow(1-probability,defect-1)*(probability);
    cout << fixed << setprecision(3) << geoDist << endl;
    
    return 0;
}
