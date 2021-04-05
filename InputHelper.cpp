#include "InputHelper.h"
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

vector<vector<float>> boxsValuesReader() {
	vector<vector<float>> boxsvalues;
	string line;
	ifstream myfile ("boxsvalues.txt");
	if (myfile.is_open())
	{
		while ( getline (myfile,line) ) {
			vector<float> boxsvalue;
			string value;
			
			for(int i=0;i<line.length();++i){
				if(line[i]==','){
					boxsvalue.push_back(stof(value));
					value = "";
				}
				else{
					value.push_back(line[i]);
				}
			}
			boxsvalue.push_back(stof(value));
			
			boxsvalues.push_back(boxsvalue);
		}
		myfile.close();
	} else cout << "Unable to open file";
	return boxsvalues;
}

void displayBoxsValues(vector<vector<float>> boxsvalues){
	cout << "Set: " << endl;
	for (int i=0; i<boxsvalues.size(); i++) {
		cout << "\t" << i+1 << ": ";
	    for (auto & boxvalue : boxsvalues[i]) {
		    cout << boxvalue << " ";
		}
		cout << endl;
	}
}

vector<float> editBoxsValues(vector<float> boxsvalue){
	cout << "Any different?(Y/N): " << endl;
	if(getTrueFalse()){
		do{
			int boxno;
			float tempvalue;
			cout << "Which box: ";
			cin >> boxno;
			cout << "To value: ";
			cin >> boxsvalue[boxno];
			
			fflush(stdin);
			cout << "Want to cont?(Y/N): ";
		}while(getTrueFalse());
	}
	return boxsvalue;
}

bool getTrueFalse(){
	char diff = 'N';
	cin >> diff;
	if(diff == 'Y' || diff == 'y' || diff == 'T' || diff == 't')
		return true;
	return false;
	
}
