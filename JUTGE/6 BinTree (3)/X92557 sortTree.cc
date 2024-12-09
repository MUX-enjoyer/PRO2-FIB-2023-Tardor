#include "sortTree.hh"

BinTree<int> ordenar_arbre_sumes(BinTree<int> t, int& suma) {
    if (t.empty()) return BinTree<int>();
    
    BinTree<int> left, right;
    int suma_esq = 0;
    int suma_dreta = 0;
    suma = t.value();
    if (!t.left().empty()) left = ordenar_arbre_sumes(t.left(), suma_esq);
    if (!t.right().empty()) right = ordenar_arbre_sumes(t.right(), suma_dreta);
    suma += suma_esq + suma_dreta;

    if (suma_esq > suma_dreta) return BinTree<int>(t.value(), right, left);
    else return BinTree<int>(t.value(), left, right);
}


BinTree<int> sortTree(BinTree<int> t) {
    int suma = 0;
    return ordenar_arbre_sumes(t, suma);
}