#ifndef INPUTHELPER_H    // To make sure you don't declare the function more than once by including the header multiple times.
#define INPUTHELPER_H
#include <vector>

using namespace std;

vector<vector<float>> boxsValuesReader();
void displayBoxsValues(vector<vector<float>> boxsvalues);
vector<float> editBoxsValues(vector<float> boxsvalue);
bool getTrueFalse();

#endif

