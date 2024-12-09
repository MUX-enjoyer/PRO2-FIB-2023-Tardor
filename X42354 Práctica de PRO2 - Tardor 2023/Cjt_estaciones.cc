/** @file Cjt_estaciones.cc
    @brief Codi de la classe Cjt_estaciones
*/

#include "Cjt_estaciones.hh"

BinTree<string> Cjt_estaciones::crear_estacions() {
    string idEstacion;
    cin >> idEstacion;
    if (idEstacion != "#") {
        int capacitat;
        cin >> capacitat;
        Estacion estacio(capacitat);
        mapa_estaciones.emplace(idEstacion, estacio);
        BinTree<string> left = crear_estacions();
        BinTree<string> right = crear_estacions();
        return BinTree<string>(idEstacion, left, right);
    }
    else return BinTree<string>();
}

Cjt_estaciones::Cjt_estaciones() {
    cjt_estaciones = crear_estacions();
}

bool Cjt_estaciones::existeix(string idEstacion) const {
    return mapa_estaciones.find(idEstacion) != mapa_estaciones.end();
}

int Cjt_estaciones::plazas_libres() const {
    int suma = 0;
    for (map<string, Estacion>::const_iterator it = mapa_estaciones.begin(); it != mapa_estaciones.end(); ++it) {
        suma += it->second.consultar_espais_lliures();
    }
    return suma;
}

bool Cjt_estaciones::alta_bici(string idBici, string idEstacion) {
    return (mapa_estaciones[idEstacion].afegir_bici(idBici));
}

void Cjt_estaciones::baja_bici(string idBici, string idEstacion) {
    map<string, Estacion>::iterator it = mapa_estaciones.find(idEstacion);
    it->second.treure_bici(idBici);
}

int Cjt_estaciones::mover_bici(string idBici, string idEstacion, Cjt_Bicis& bicicletes) {
    if (bicicletes.esta_bici_estacio(idBici, idEstacion)) return 1;
    if (!mapa_estaciones[idEstacion].afegir_bici(idBici)) return 2;
    string idEstacion_abans = bicicletes.busca_estacio(idBici);
    mapa_estaciones[idEstacion_abans].treure_bici(idBici);
    bicicletes.mover_bici(idBici, idEstacion);
    return 0;
}

void Cjt_estaciones::imprimir_bicis(string idEstacion) {
    mapa_estaciones[idEstacion].consultar_bicis_estacion();
}

bool Cjt_estaciones::mod_cap(string idEstacion, int cap) {
    return mapa_estaciones[idEstacion].modificar_cap(cap);
}

void Cjt_estaciones::subir_bicis(Cjt_Bicis& bicicletes) {
    llenar_estaciones(bicicletes, cjt_estaciones);
}

void Cjt_estaciones::pujo_bici(Cjt_Bicis& bicicletes, string idEstacion_previ, string idEstacion_post) {
    string idBici = mapa_estaciones[idEstacion_previ].treure_primera();
    mapa_estaciones[idEstacion_post].afegir_bici(idBici);
    bicicletes.canvi_bici(idBici, idEstacion_post);
}

void Cjt_estaciones::llenar_estaciones(Cjt_Bicis& bicicletes, BinTree<string> arbre) {
    if (!arbre.left().empty() && !arbre.right().empty()) {
        string left = arbre.left().value();
        string right = arbre.right().value();
        int ocupats_left = mapa_estaciones[left].consultar_espais_ocupats();
        int ocupats_right = mapa_estaciones[right].consultar_espais_ocupats();
        /* Inv: ocupats_left + ocupats_right + ocupats_estacio sempre es mantindrà constant*/

        while (mapa_estaciones[arbre.value()].consultar_espais_lliures() > 0 && ocupats_left + ocupats_right != 0) {
            if (ocupats_left > ocupats_right) {
                pujo_bici(bicicletes, left, arbre.value());
            }
            else if (ocupats_left < ocupats_right) {
                pujo_bici(bicicletes, right, arbre.value());
            }
            else if (mapa_estaciones[left].consultar_id_primera() < mapa_estaciones[right].consultar_id_primera()) {
                pujo_bici(bicicletes, left, arbre.value());
            }
            else pujo_bici(bicicletes, right, arbre.value());
            ocupats_left = mapa_estaciones[left].consultar_espais_ocupats();
            ocupats_right = mapa_estaciones[right].consultar_espais_ocupats();
        }
        llenar_estaciones(bicicletes, arbre.left());
        llenar_estaciones(bicicletes, arbre.right());
    }
}

string Cjt_estaciones::asignar_estacion(Cjt_Bicis& bicicletes, string idBici) {
    float maxDes = -1;
    float pl = 0;
    float n = 0;
    string idEstacion = busca_estacion(cjt_estaciones, maxDes, pl, n);
    if (idEstacion != "error") {
        mapa_estaciones[idEstacion].afegir_bici(idBici);
        bicicletes.alta_bici(idBici, idEstacion);
    }
    return idEstacion;
}

string Cjt_estaciones::busca_estacion(const BinTree<string>& arbre, float& des, float& pl, float& n) {
    //CAS SENZILL 1
    if (arbre.empty()) {    
        des = -1;
        return "error";
    }
    //CAS SENZILL 2
    if (arbre.left().empty() && arbre.right().empty()) {
        n = 1;
        des = pl = mapa_estaciones[arbre.value()].consultar_espais_lliures();
        return arbre.value();
    }

    //CAS RECURSIU
    float des_left, des_right, pl_left, pl_right, n_left, n_right;
    pl_left = pl_right = n_left = n_right = 0;
    string id_left = busca_estacion(arbre.left(), des_left, pl_left, n_left);
    string id_right = busca_estacion(arbre.right(), des_right, pl_right, n_right);
    pl = pl_left + pl_right + mapa_estaciones[arbre.value()].consultar_espais_lliures();
    n = n_left + n_right + 1;
    des = pl / n;
    if (des_left > des_right || (des_left == des_right && id_left < id_right)) {
        if (des_left > des || (des_left == des && id_left < arbre.value())) {
            des = des_left;
            return id_left;
        }
        else return arbre.value();
    }
    else if (des_right > des || (des_right == des && id_right < arbre.value())) {
            des = des_right;
            return id_right;
    }
    else return arbre.value();
}