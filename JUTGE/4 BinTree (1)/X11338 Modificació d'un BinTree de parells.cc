#include "BinTree.hh"

#include "ParInt.hh"

 /*Pre: a = A */
 /*Post: a es com a A amb k sumat al segon component de cada node */
void sumak(BinTree<ParInt>& a, int k) {
    if (!a.empty()) {
        ParInt valor(a.value().primer(), a.value().segon() + k);
        BinTree<ParInt> left(), right();
        if (!a.left().empty()) {
            left = a.left();
            sumak(left, k);
        }
        if (!a.left().empty()) {
            right = a.left();
            sumak(right,k);
        }
        a = BinTree<ParInt>(valor, left, right);
        }
}