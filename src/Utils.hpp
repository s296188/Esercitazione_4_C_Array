#pragma once

#include <iostream>

using namespace std;

// Importare i dati
bool ImportData(const string& filename, double& S, int& n, double*& w, double*& r);

// Calcolo del Rate of Return totale
double ComputeRateOfReturn(int n, const double* w, const double* r);

// Calcolo della Somma finale
double ComputeFinalValue(double S, double rate);

// Esportare i risultati
void ExportResults(const string& filename, double S, int n, const double* w, const double* r, double rate, double V);
