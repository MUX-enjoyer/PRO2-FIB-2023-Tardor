#include "treeOfHeights.hh"


BinTree<int> treeOfHeights(BinTree<int> t) {
    if (t.empty()) return BinTree<int>(); // Retorna un arbre buit
    BinTree<int> left, right;
    if(!t.left().empty()) left = treeOfHeights(t.left());
    if(!t.right().empty()) right = treeOfHeights(t.right());

    int altura;
    if (left.empty() && right.empty()) altura = 0;
    else if (left.empty()) altura = right.value();
    else if (right.empty() || left.value() > right.value()) altura = left.value();
    else altura = right.value();

    return BinTree<int>(++altura, left, right);
}

