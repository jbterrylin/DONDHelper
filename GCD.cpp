#include "GCD.h"
#include <vector>
using namespace std;


// Function to return gcd of a and b
int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}
  
// Function to find gcd of array of
// numbers
int findGCD(vector<int> arr, int n)
{
    int result = arr[0];
    for (auto & element : arr)
        result = gcd(element, result);
  
    return result;
}
