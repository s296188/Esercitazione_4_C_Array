#include <iostream>

#include "src/Utils.hpp"

using namespace std;

int main()
{
	double S;
	int n;
	double* w = nullptr;
	double* r = nullptr;

	if (!ImportData("data.txt", S, n, w, r)) {
		cerr << "Errore nell'apertura del file" << endl;
		return 1;
	}

	double rate = ComputeRateOfReturn(n, w, r);
	double V = ComputeFinalValue(S, rate);

	ExportResults("result.txt", S, n, w, r, rate, V);

	delete[] w;
	delete[] r;

	return 0;
}

