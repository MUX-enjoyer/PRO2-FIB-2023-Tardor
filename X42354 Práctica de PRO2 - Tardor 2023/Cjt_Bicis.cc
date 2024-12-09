/** @file Cjt_Bicis.cc
    @brief Codi de la classe Cjt_Bicis
*/
#include "Cjt_Bicis.hh"


//MODIFICADORES
void Cjt_Bicis::alta_bici(string idBici, string idEstacion) {
    Bici nova_bicicleta(idEstacion);
    bicis_estaciones.emplace(idBici, nova_bicicleta);
}

string Cjt_Bicis::baja_bici(string idBici) {
    map<string, Bici>::iterator it = bicis_estaciones.find(idBici);
    string idEstacio = it->second.consultar_estacio();
    bicis_estaciones.erase(it);
    return idEstacio;
}

void Cjt_Bicis::mover_bici(string idBici, string idEstacion) {
    map<string, Bici>::iterator it = bicis_estaciones.find(idBici);
    it->second.nuevo_viaje(idEstacion);
}

void Cjt_Bicis::canvi_bici(string idBici, string idEstacion) {
    map<string, Bici>::iterator it = bicis_estaciones.find(idBici);
    it->second.canvio_estacion(idEstacion);  
}

//CONSULTORES
bool Cjt_Bicis::existeix(string idBici) const {
    return bicis_estaciones.find(idBici) != bicis_estaciones.end();
}

bool Cjt_Bicis::esta_bici_estacio(string idBici, string idEstacion) const {
    map<string, Bici>::const_iterator it = bicis_estaciones.find(idBici);
    return it->second.consultar_estacio() == idEstacion;
}

string Cjt_Bicis::busca_estacio(string idBici) const {
    map<string, Bici>::const_iterator it = bicis_estaciones.find(idBici);
    return it->second.consultar_estacio();
}

void Cjt_Bicis::viatges(string idBici) const {
    map<string, Bici>::const_iterator it = bicis_estaciones.find(idBici);
    it->second.consultar_viajes();
}