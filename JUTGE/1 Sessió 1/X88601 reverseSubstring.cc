#include <iostream>
using namespace std;
#include <string>

// Pre: 0 <= i <= j < s.size()
// Post: el substring s[i..j] s'ha revessat. La resta de s no ha canviat.
void reverseSubstring(string &s, int i, int j) {
    if (i >= j) return;
    else swap(s[i],s[j]);
    reverseSubstring(s,i+1,j-1);
}

int main() {
    string a;
    int x, y;
    cin >> a >> x >> y;
    reverseSubstring(a, x, y);
    cout << a << endl;
}