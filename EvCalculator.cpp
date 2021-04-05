#include "EvCalculator.h"
#include "Combination.h"
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

EvCalculator:: EvCalculator(vector<float> boxsvalue){
	this->oriboxsvalue = boxsvalue;
	this->boxsvalue = boxsvalue;
	for (auto & boxvalue : boxsvalue) {
		boxsvaluetotal +=boxvalue;
	}
}

float EvCalculator:: getSumBoxsValue(){
	float total = 0;
	for (auto & boxvalue : boxsvalue) {
		total +=boxvalue;
	}
	return total;
}

float EvCalculator:: getCurrentRevenue(){
	return (getSumBoxsValue()/boxsvalue.size());
}

void EvCalculator:: nextTurnEv(int nopen){
	
	Combination combinationhelper(boxsvalue.size(), nopen);
	vector<int> combinations = combinationhelper.returnCombinations();
	
	float ev = 0;
	int losecounter = 0;
	possiblerevenue.clear();
	for(int i=0; i<combinations.size(); i++){
		if(i % (nopen+1) == nopen){ 
			float tempavg = getSumBoxsValue();
			for(int j=1; j<(nopen+1); j++){
				tempavg -= boxsvalue[combinations[i-j]];
			}
			tempavg = tempavg / (boxsvalue.size() - nopen);
			ev += tempavg/(combinations.size()/(nopen+1));
			if(tempavg < getCurrentRevenue()) {
				losecounter++;
			}
			
			possiblerevenue.push_back(tempavg);
		}
	}
	cout << "Next Turn Possible Combination: " << (combinations.size()/(nopen+1)) << endl;
	cout << "Next Turn Ev: " << ev << endl;
	cout << "Number of combination that lose money: " << losecounter << endl;
	cout << endl;
}

void EvCalculator:: nextTurnDetail(float gap){
	vector<int> times;
	for(int i=0; i<(possiblerevenue[0]/gap)+1;i++) {
		times.push_back(0);
	}
	for (auto & element : possiblerevenue) {
		bool next = true;
		int counter = 0; 
		do{
			if(element > gap*counter){
				counter++;
			} else{
				times[counter-1] += 1;
				next = false;
			}
		}while(next); 
	}
	
	for (int i=0; i<times.size(); i++) {
		if(i != 0){
			if(times[i] == times[i-1] && !(times[i] == times[i-1] && times[i] == times[i-2])) {
				cout << "  ." << endl;
				cout << "  ." << endl;
			}
		}
		if(times[i] != times[i+1] || i == 0){
			cout << i*gap << ": " << times[i] << endl;
			if(i*gap <= getCurrentRevenue() && (i+1)*gap >= getCurrentRevenue()){
				cout << "Current Revenue:-----------------------------------------" << endl;
			}
		}
		if(i*gap <= lastturnrevenue && (i+1)*gap >= lastturnrevenue){
			cout << "Last Turn Revenue:---------------------------------------" << endl;
		}
	}
}

void EvCalculator:: removeBox(int index) {
	float boxvalue = oriboxsvalue[index];
	auto it = remove(boxsvalue.begin(), boxsvalue.end(), boxvalue);
	boxsvalue.erase(it, boxsvalue.end());
}

void EvCalculator:: setLastTurnRevenue() {
	lastturnrevenue = getCurrentRevenue();
}
