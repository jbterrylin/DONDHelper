#ifndef EVCALCULATOR_H
#define EVCALCULATOR_H
#include <vector>

using namespace std;

class EvCalculator{
	public:
		vector<float> oriboxsvalue;
		vector<float> boxsvalue;
		float boxsvaluetotal = 0;
		vector<float> possiblerevenue;
		float lastturnrevenue = 0;
		
		EvCalculator(vector<float> boxsvalue);
		float getSumBoxsValue();
		float getCurrentRevenue();
		void nextTurnEv(int nopen);
		void nextTurnDetail(float gap);
		void removeBox(int index);
		void setLastTurnRevenue();
};

#endif
