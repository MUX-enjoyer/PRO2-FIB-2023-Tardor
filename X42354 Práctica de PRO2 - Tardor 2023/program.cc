/** @file program.cc

    @brief Programa principal
*/

#include "Cjt_estaciones.hh"
#include "Cjt_Bicis.hh"

int main() {
    // Inicialització de les estructures de dades
    Cjt_estaciones estaciones;
    Cjt_Bicis bicicletes;

    // Variables per a les operacions d'entrada
    string idBici, idEstacion, op;
    cin >> op; // Lectura primera operació
    while (op != "fin") {
        // Gestió de les diferents operacions
        if (op == "alta_bici" || op == "ab") {
            cin >> idBici >> idEstacion;
            cout << "#ab " << idBici << " " << idEstacion << endl;
            if (bicicletes.existeix(idBici)) cout << "error: la bici ya existe" << endl;
            else if (!estaciones.existeix(idEstacion)) cout << "error: la estacion no existe" << endl;
            else {
                if (!estaciones.alta_bici(idBici, idEstacion)) cout << "error: la bici no cabe" << endl;
                else bicicletes.alta_bici(idBici, idEstacion);
            }
        }
        else if (op == "baja_bici" || op == "bb") {
            cin >> idBici;
            cout << "#bb " << idBici << endl;
            if (!bicicletes.existeix(idBici)) cout << "error: la bici no existe" << endl;
            else {
                string idEstacion = bicicletes.baja_bici(idBici);
                estaciones.baja_bici(idBici, idEstacion);
            }
        }
        else if (op == "estacion_bici" || op == "eb") {
            cin >> idBici;
            cout << "#eb " << idBici << endl;
            if (!bicicletes.existeix(idBici)) cout << "error: la bici no existe" << endl;
            else cout << bicicletes.busca_estacio(idBici) << endl;
        }
        else if (op == "viajes_bici" || op == "vb") {
            cin >> idBici;
            cout << "#vb " << idBici << endl;
            if (!bicicletes.existeix(idBici)) cout << "error: la bici no existe" << endl;
            else bicicletes.viatges(idBici);
        }
        else if (op == "mover_bici" || op == "mb") {
            cin >> idBici >> idEstacion;
            cout << "#mb " << idBici << " " << idEstacion << endl;
            if (!bicicletes.existeix(idBici)) cout << "error: la bici no existe" << endl;
            else if (!estaciones.existeix(idEstacion)) cout << "error: la estacion no existe" << endl;
            else {
                int error = estaciones.mover_bici(idBici, idEstacion, bicicletes);
                if (error == 1) cout << "error: la bici ya esta en el sitio" << endl;
                else if (error == 2) cout << "error: la bici no cabe" << endl;
            }
        }
        else if (op == "bicis_estacion" || op == "be") {
            cin >> idEstacion;
            cout << "#be " << idEstacion << endl;
            if (!estaciones.existeix(idEstacion)) cout << "error: la estacion no existe" << endl;
            else estaciones.imprimir_bicis(idEstacion);
        }
        else if (op == "modificar_capacidad" || op == "mc") {
            int n;
            cin >> idEstacion >> n;
            cout << "#mc " << idEstacion << " " << n << endl;
            if (!estaciones.existeix(idEstacion)) cout << "error: la estacion no existe" << endl;
            else if (!estaciones.mod_cap(idEstacion, n)) cout << "error: capacidad insuficiente" << endl;
        }
        else if (op == "plazas_libres" || op == "pl") {
            cout << "#pl" << endl << estaciones.plazas_libres() << endl;
        }
        else if (op == "subir_bicis" || op == "sb") {
            cout << "#sb" << endl;
            estaciones.subir_bicis(bicicletes);
        }
        else if (op == "asignar_estacion" || op == "ae") {
            cin >> idBici;
            cout << "#ae " << idBici << endl;
            if (bicicletes.existeix(idBici)) cout << "error: la bici ya existe" << endl;
            else if (estaciones.plazas_libres() < 1) cout << "error: no hay plazas libres" << endl;
            else cout << estaciones.asignar_estacion(bicicletes, idBici) << endl;
        }
        cin >> op; //Llegir la següent operació
    }
}