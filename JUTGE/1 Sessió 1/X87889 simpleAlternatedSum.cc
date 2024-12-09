#include <iostream>
using namespace std;
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

// Pre: n >= 1
// Post: Retorna 1-2+3-4+...+(-1)^(n+1)*n
int simpleAlternatedSum(int n) {
    if (n == 1) return 1;
    int m;
    if (n%2 == 0) m = -n;
    else m = n;
    return (m + simpleAlternatedSum(n-1));
}

int main() {
    int n;
    cin >> n;
    cout << simpleAlternatedSum(n) << endl;
}