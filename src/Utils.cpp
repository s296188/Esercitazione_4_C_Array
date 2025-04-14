#include "Utils.hpp"

#include "iostream"
#include "fstream"
#include "sstream"
#include "iomanip"

using namespace std;


bool ImportData(const string& filename, double& S, int& n, double*& w, double*& r) {
    ifstream file(filename);
    if (!file.is_open()) return false;

    string line;
    getline(file, line);
    S = stod(line.substr(line.find(';') + 1));

    getline(file, line);
    n = stoi(line.substr(line.find(';') + 1));

    getline(file, line); // skip the header line "w;r"

    w = new double[n];
    r = new double[n];

    for (int i = 0; i < n; ++i) {
        getline(file, line);
        istringstream ss(line);
        string w_str, r_str;
        getline(ss, w_str, ';');
        getline(ss, r_str);
        w[i] = stod(w_str);
        r[i] = stod(r_str);
    }

    file.close();
    return true;
}

double ComputeRateOfReturn(int n, const double* w, const double* r) {
    double total = 0;
    for (int i = 0; i < n; ++i)
        total += w[i] * r[i];
    return total;
}

double ComputeFinalValue(double S, double rate) {
    return (1 + rate) * S;
}

void ExportResults(const string& filename, double S, int n, const double* w, const double* r, double rate, double V) {
    ofstream file(filename);
    file << fixed << setprecision(2);
    file << "S = " << S << ", n = " << n << endl;

    file << "w = [ ";
    for (int i = 0; i < n; ++i)
    	file << w[i] << " ";
    file << "]" << endl;

    file << "r = [ ";
    for (int i = 0; i < n; ++i)
    	file << r[i] << " ";
    file << "]" << endl;

    file << setprecision(4) << "Rate of return of the portfolio: " << rate << endl;
    file << setprecision(2) << "V: " << V << endl;

    file.close();
}
