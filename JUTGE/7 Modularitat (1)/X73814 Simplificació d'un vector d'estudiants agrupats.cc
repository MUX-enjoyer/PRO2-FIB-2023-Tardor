using namespace std;
#include <iostream>

#include <vector>
#include <algorithm>
#include "Estudiant.hh"

struct estud {
    int dni;
    double nota;
};


int main() {
    int n;
    cin >> n;
    vector<estud> entrada(n+1);
    for (int i = 0; i < n; ++i) {
        double n;
        cin >> entrada[i].dni >> n;
        if (n <= 10 and n >= 0) entrada[i].nota = n;
        else entrada[i].nota = -1;
    }
    entrada[n].dni = 0;
    entrada[n].nota = 0;

    int comp_dni = entrada[0].dni;
    double nota_max = entrada[0].nota;

    for (int i = 1; i <= n; ++i) {
        if (comp_dni != entrada[i].dni) {
            cout << comp_dni << ' ';
            if (nota_max != -1) cout << nota_max;
            else cout << "NP";
            cout << endl;
            comp_dni = entrada[i].dni;
            nota_max = entrada[i].nota;
        }
        else if (nota_max < entrada[i].nota) nota_max = entrada[i].nota;
    }
}