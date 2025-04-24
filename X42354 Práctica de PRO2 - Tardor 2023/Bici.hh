/** @file Bici.hh
    @brief Especificació de la classe Bici
 */
sfkwEASDHFUIAESHGUIEAhfguikae
#ifndef BICI_HH
#define BICI_HH

#ifndef NO_DIAGRAM
using namespace std;
#include <iostream>
#include <string>
#include <list>
#endif


/** @class Bici
    @brief Gestiona la informació d'una bicicleta, incloent els viatges realitzats.
*/
class Bici {

private:
    string estacio_actual;  /** @brief Identificador de l'estació actual de la bicicleta. */
    list<string> viajes;    /** @brief Llista que emmagatzema els viatges realitzats per la bicicleta. */

public:
    // CONSTRUCTORA
    /** @brief Constructora de la classe Bici.
        @pre Cert.
        @post Crea una bicicleta amb l'estació inicial especificada.
        @cost constant.
    */
    Bici(string idEstacio);

    // MODIFICADORES
    
    /** @brief Afegeix un nou viatge a la bicicleta.
        @pre La bicicleta té una estació actual vàlida diferent a idEstacio.
        @post S'afegeix un nou viatge a la bicicleta, des de l'estació actual a idEstacio i canvia l'estació actual a idEstacio.
        @cost constant.
    */
    void nuevo_viaje(string idEstacio);
 
    /** @brief Canvi d'estació de l'actual a una nova estació.
        @pre La bicicleta té una estació actual vàlida diferent a idEstacio.
        @post La bicicleta canvia l'estació actual a la nova estació especificada, no registra el viatge.
        @cost constant.
    */ 
    void canvio_estacion(string idEstacio);
    
    //CONSULTORES

    /** @brief Consulta l'estació actual de la bicicleta.
        @pre La bicicleta té una estació actual vàlida.
        @post Retorna l'estació actual.
        @cost constant.
    */
    string consultar_estacio() const;
    
    /** @brief Imprimeix els viatges realitzats per la bicicleta.
        @pre Cert.
        @post Imprimeix els viatges realitzats per la bicicleta.
        @cost lineal respecte al nombre de viatges realitzats per la bicicleta.
    */
    void consultar_viajes() const;
};

#endif // BICI_HH