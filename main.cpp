#include <iostream>
#include <vector> 
#include "EvCalculator.h"
#include "InputHelper.h"
#include "GCD.h"
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

/* 
	For Deal or Not Deal
	GCD didn't use
	0.1,0.2,0.5,0.7,1,2,3,5,8,10,12,15,20,25,50,100
*/

int main(int argc, char** argv) {
	cout << "JBTERRYLIN" << endl;
	int noset = 1;
	vector<int> boxopenperturn = {3,4,4,3}; 
	
	vector<vector<float>> boxsvalues = boxsValuesReader();
	displayBoxsValues(boxsvalues);
	
	cout << "Which set you playing: " << endl;
	cin >> noset;

	vector<float> boxsvalue = boxsvalues[noset-1];
	editBoxsValues(boxsvalue);
	
	
	float aa = 0;
	for(int i=3;i<16;i++) {
		aa += boxsvalue[i];
	}
	cout << aa/13 << endl;
	
	EvCalculator evcalculator(boxsvalue);
	
	cout << endl;
	cout << "Current Revenue: " << evcalculator.getCurrentRevenue() << endl;

	bool isopened[] = {false,false,false,false,false,
						false,false,false,false,false,
						false,false,false,false,false,
						false};
	char next = 'a';
	for(int i=0; i<boxopenperturn.size(); i++){
		evcalculator.setLastTurnRevenue();
		cout << "which box been opened: " << endl;
		for(int j=0; j<boxopenperturn[i]; j++) {
			int index = 0;
			cout << "box " << j+1 << ": ";
			cin >> index;
			while(isopened[index]){
				cout << "Input before, Please input again: ";
				cin >> index;
			}
			isopened[index] = true;
			evcalculator.removeBox(index-1);
		}
		
		for (auto & element : evcalculator.boxsvalue) {
			cout << element << " "; 
		}
		cout << endl;
		
		evcalculator.nextTurnEv(boxopenperturn[i]);
		cout << "Do you want to get more specific inform?(Y/N): " << endl;
		while(getTrueFalse()){
			cout << "Gap: " << endl;
			float gap = 0;
			cin >> gap;
			evcalculator.nextTurnDetail(gap);
			cout << "Do you want to get more specific inform again?(Y/N): " << endl;
		}
		
		cout << "Type anything to continue... ";
		cin >> next;
		cout << endl << endl;
	}
	
	return 0;
}
