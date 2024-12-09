#include <vector>
using namespace std;
 
struct parint {int prim, seg;};

parint max_min1(const vector<int>& v)
/* Pre: v.size()>0 */
/* Post: el primer componente del resultado es el valor maximo de v;
el segundo componente del resultado es el valor minimo de v */
{
    parint max_min = {v[0], v[0]};
    int mida = v.size();
    for (int i = 1; i < mida; ++i) {
        if (v[i] > max_min.prim) max_min.prim = v[i];
        else if (v[i] < max_min.seg) max_min.seg = v[i];
    }
    return max_min;
}

pair<int,int> max_min2(const vector<int>& v)
/* Pre: v.size()>0 */
/* Post: el primer componente del resultado es el valor maximo de v;
el segundo componente del resultado es el valor minimo de v */
{
    pair<int,int> max_min = {v[0], v[0]};
    int mida = v.size();
    for (int i = 1; i < mida; ++i) {
        if (v[i] > max_min.first) max_min.first = v[i];
        else if (v[i] < max_min.second) max_min.second = v[i];
    }
    return max_min;
}

void max_min3(const vector<int>& v, int& x, int& y)
/* Pre: v.size()>0 */
/* Post: x es el valor maximo de v;  y es el valor minimo de v */
{
    int mida = v.size();
    x = v[0];
    y = v[0];
    for (int i = 1; i < mida; ++i) {
        if (v[i] > x) x = v[i];
        else if (v[i] < y) y = v[i];
    }
    return;
}