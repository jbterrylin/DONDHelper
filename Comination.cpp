#include "Combination.h"
#include <algorithm>

using namespace std;

Combination:: Combination(int N, int K){
	this->N = N;
	this->K = K;
	this->combinate();
}

vector<int> Combination:: returnCombinations(){
	return combinations;
}

void Combination:: combinate()
{
    string bitmask(K, 1); // K leading 1's
    bitmask.resize(N, 0); // N-K trailing 0's
 
    // print integers and permute bitmask
    do {
        for (int i = 0; i < N; ++i) // [0..N-1] integers
        {
            if (bitmask[i])
				combinations.push_back(i);
        }
        combinations.push_back(-1);
    } while (prev_permutation(bitmask.begin(), bitmask.end()));
}
