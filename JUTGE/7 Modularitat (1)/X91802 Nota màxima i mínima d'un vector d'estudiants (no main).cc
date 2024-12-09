using namespace std;
#include <iostream>

#include <vector>
#include <algorithm>
#include "Estudiant.hh"


 /* Pre: v no conte repeticions de dni  */
 /* Post: si existeix a v algun estudiant amb nota, la primera component del
    resultat es la posicio de l'estudiant de nota maxima de v i la segona
    component es la posicio de l'estudiant de nota minima de v (si hi ha
    empats, s'obte en cada cas la posicio de l'estudiant amb minim DNI); si no
    hi ha cap estudiant amb nota, totes dues components valen -1 */
pair<int,int> max_min_vest(const vector<Estudiant>& v) {
    pair<int, int> parell = {-1,-1};
    double max = -1;
    double min = 11;
    for (int i = 0; i < v.size(); ++i) {
        if (v[i].te_nota()) {
            double nota = v[i].consultar_nota();
            
            if (nota >= max) {
                if (nota > max) {
                    max = nota;
                    parell.first = i;
                }
                else if (v[parell.first].consultar_DNI() > v[i].consultar_DNI()) parell.first = i;
            }
            
            if (nota <= min) {
                if (nota < min) {
                    min = nota;
                    parell.second = i;
                }
                else if (v[parell.second].consultar_DNI() > v[i].consultar_DNI()) parell.second = i;
            }
        }
    }
    return parell;
}