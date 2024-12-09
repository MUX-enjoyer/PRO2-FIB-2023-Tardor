#include "Estudiant.hh"
#include <vector>



void redondear_e_a(Estudiant& est)
/* Pre: est tiene nota */
/* Post: est pasa a tener su nota original redondeada */
{
  est.modificar_nota(((int) (10. * (est.consultar_nota() + 0.05))) / 10.0);
}


void arrodonir_vector(vector<Estudiant>& v) {
    for (int i = 0; i < v.size(); ++i) {
        if (v[i].te_nota()) {
            redondear_e_a(v[i]);    
        }
    }
}