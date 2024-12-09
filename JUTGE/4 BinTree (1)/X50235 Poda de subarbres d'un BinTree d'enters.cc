#include "BinTree.hh"

bool poda_subarbre(BinTree<int> &a, int x) {
    if (a.empty()) return false;
    else if (a.value() == x) {
        a = BinTree<int>();
        return true;
    }
    else {
        bool resultat = false;
        BinTree<int> left, right;
        if (!a.left().empty()) {
            left = a.left();
            resultat = poda_subarbre(left, x);
        }
        if (!a.right().empty()) {
            right = a.right();
            resultat = poda_subarbre(right, x) || resultat;
        }
        if (resultat) a = BinTree<int>(a.value(), left, right);
        return resultat;
    }
}