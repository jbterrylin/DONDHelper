#ifndef COMBINATION_H
#define COMBINATION_H
#include <vector>

using namespace std;

class Combination{
	public:
		Combination(int N, int K);
		vector<int> returnCombinations();
		
	private:
		vector<int> combinations;
		int N;
		int K;
		
		void combinate();
};

#endif
