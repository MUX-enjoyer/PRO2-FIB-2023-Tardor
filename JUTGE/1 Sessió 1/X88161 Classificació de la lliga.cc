#include <iostream>
using namespace std;
#include <vector>
#include <string>
#include <algorithm>

struct equip {
    int n_equip;
    int punts = 0;
    int gols_marcats = 0;
    int gols_rebuts = 0;
};

typedef vector<equip> Matriu_structs;

bool cmp (equip a, equip b) {
    if (a.punts != b.punts) return a.punts > b.punts;
    else if (a.gols_marcats - a.gols_rebuts != b.gols_marcats - b.gols_rebuts) {
        return a.gols_marcats - a.gols_rebuts > b.gols_marcats - b.gols_rebuts;
    }
    else return a.n_equip < b.n_equip;
}

int main() {
    int m, x, y;
    cin >> m;
    Matriu_structs classificacio(m);

    for (int i = 0; i < m ; ++i) {
        classificacio[i].n_equip = i+1;
        for (int j = 0; j < m; ++j) {
            cin >> x >> y;
            if (i != j) {
                if (x > y) classificacio[i].punts += 3;
                else if (x < y) classificacio[j].punts += 3;
                else {
                    classificacio[i].punts += 1;
                    classificacio[j].punts += 1;
                }
                classificacio[i].gols_marcats += x;
                classificacio[i].gols_rebuts += y;
                classificacio[j].gols_marcats += y;
                classificacio[j].gols_rebuts += x;
            }
        }
    }

    sort (classificacio.begin(), classificacio.end(), cmp);

    for (int i = 0; i < m; ++i) {
        cout << classificacio[i].n_equip << ' ' << classificacio[i].punts << ' ' << classificacio[i].gols_marcats << ' ' << classificacio[i].gols_rebuts << endl; 
    }

}