/** @file Estacion.cc
    @brief Codi de la classe Estacion
 */

#include "Estacion.hh"

    // CONSTRUCTORES

Estacion::Estacion() {}

Estacion::Estacion(int capacidad) {
    this->capacidad = capacidad;
    espais_ocupats = 0;
}

    // MODIFICADORES

bool Estacion::afegir_bici(string idBici) {
    if (espais_ocupats+1 > capacidad) return false;
    bicis.emplace(idBici);
    ++espais_ocupats;
    return true;
}

void Estacion::treure_bici(string idBici) {
    bicis.erase(idBici);
    --espais_ocupats;
}

string Estacion::treure_primera() {
    set<string>::iterator it = bicis.begin();
    string idBici = *it;
    bicis.erase(it);
    --espais_ocupats;
    return idBici;
}

bool Estacion::modificar_cap(int cap) {
    if (cap < espais_ocupats) return false;
    capacidad = cap;
    return true;
}

    // CONSULTORES

int Estacion::consultar_espais_lliures() const {
    return capacidad-espais_ocupats;
}

int Estacion::consultar_espais_ocupats() const {
    return espais_ocupats;
}

string Estacion::consultar_id_primera() const {
    return *bicis.begin();
}

    // ENTRADA / SORTIDA

void Estacion::consultar_bicis_estacion() const {
    for (set<string>::const_iterator it = bicis.begin(); it != bicis.end(); ++it) {
        cout << *it << endl;
    }
}