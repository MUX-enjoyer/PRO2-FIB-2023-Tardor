/** @file Bici.cc
    @brief Codi de la classe Bici
 */
#include "Bici.hh"

//CONSTRUCTORA
Bici::Bici(string idEstacio) {
    estacio_actual = idEstacio;
}

//MODIFICADORES
void Bici::nuevo_viaje(string idEstacio) {
    viajes.push_back(estacio_actual);
    estacio_actual = idEstacio;
    viajes.push_back(estacio_actual);
}

void Bici::canvio_estacion(string idEstacio) {
    estacio_actual = idEstacio;
}

//CONSULTORES
string Bici::consultar_estacio() const {
    return estacio_actual;
}
void Bici::consultar_viajes() const {
    if (!viajes.empty()) {
        list<string>::const_iterator it;
        for (it = viajes.begin(); it != viajes.end(); ++it) {
            cout << *it << " ";
            ++it;
            cout << *it << endl;
        }
    }
}