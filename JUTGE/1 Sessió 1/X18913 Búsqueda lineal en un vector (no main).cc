#include <iostream>
using namespace std;
#include <vector>
#include <string>

 int busqueda_lin(const vector<int>& v, int x) {
 /* Pre: cierto */
 /* Post: si el resultado es v.size(), x no esta en v;
    en caso contrario, indica la posicion de la primera aparicion de x en v */
    int mida = v.size();
    for (int i = 0; i < mida; ++i) {
        if (v[i] == x) return i;
    }
    return mida;
 }