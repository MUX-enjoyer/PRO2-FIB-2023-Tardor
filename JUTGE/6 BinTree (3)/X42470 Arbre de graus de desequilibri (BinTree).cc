#include "BinTreeIOint.hh"
#include "BinTree.hh"


int calc_desequilibri(const BinTree<int> &a, BinTree<int> &agd) {
    if (a.empty()) {
        agd = BinTree<int>();
        return 0;
    }
    else {
        BinTree<int> left, right;
        int altura_esq = 0;
        int altura_dreta = 0;
        if (!a.left().empty()) {
            altura_esq = calc_desequilibri(a.left(), left) + 1;
        }
        if (!a.right().empty()) {
            altura_dreta = calc_desequilibri(a.right(), right) + 1;
        }
        agd = BinTree<int>(altura_esq-altura_dreta, left, right);

        if (altura_esq > altura_dreta) return altura_esq;
        else return altura_dreta;
    }
}

void arbre_graus_desequilibri(const BinTree<int> &a, BinTree<int> &agd) {
    calc_desequilibri(a, agd);
}