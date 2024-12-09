#include "SumBelowAtEvenDepth.hh"

BinTree<int> suma_senars(BinTree<int> t, int &suma, int profunditat) {
    if (t.empty()) return BinTree<int>();
    
    BinTree<int> left, right;
    int suma_esq = 0;
    int suma_dreta = 0;
    if (!t.left().empty()) left = suma_senars(t.left(), suma_esq, profunditat+1);
    if (!t.right().empty()) right = suma_senars(t.right(), suma_dreta, profunditat+1);
    suma = t.value() + suma_esq + suma_dreta;

    if (profunditat%2 == 0) return BinTree<int>(t.value(), left, right);
    else return BinTree<int>(suma, left, right);
}


BinTree<int> SumBelowAtEvenDepth(BinTree<int> t) {
    int suma = 0;
    return suma_senars(t, suma, 1);
}