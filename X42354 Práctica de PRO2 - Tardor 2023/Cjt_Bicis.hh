/** @file Cjt_Bicis.hh
    @brief Especificació de la classe Cjt_Bicis
*/

#ifndef _CJT_BICIS_HH_
#define _CJT_BICIS_HH_

#include "Bici.hh"

#ifndef NO_DIAGRAM
#include <map>
#endif

/** @class Cjt_Bicis
    @brief Gestiona un conjunt de bicicletes i les seves relacions amb estacions.
*/
class Cjt_Bicis {

private:
    map<string, Bici> bicis_estaciones; /** @brief Mapa que associa les bicicletes amb les estacions */

public:
    // MODIFICADORES

    /** @brief Alta d'una nova bicicleta a l'estació donada.
        @pre La bicicleta amb l'identificador idBici no existeix prèviament.
        @pre L'estació amb l'identificador idEstacion existeix i té espai lliure.
        @post S'afegeix una nova bicicleta amb l'identificador idBici a l'estació idEstacion.
        @cost constant.
    */
    void alta_bici(string idBici, string idEstacion);

    /** @brief Baixa d'una bicicleta.
        @pre La bicicleta amb l'identificador idBici existeix.
        @post La bicicleta amb l'identificador idBici és donada de baixa i eliminada de la col·lecció.
        @post Retorna l'identificador de l'estació on estava estacionada la bicicleta abans de la baixa.
        @cost constant.
    */
    string baja_bici(string idBici);

    /** @brief Moviment d'una bicicleta a una nova estació.
        @pre La bicicleta amb l'identificador idBici existeix.
        @pre L'estació amb l'identificador idEstacion existeix i té espai lliure.
        @post La bicicleta idBici es mou a idEstacion i es registra el viatge.
        @cost constant.
    */
    void mover_bici(string idBici, string idEstacion);

    /** @brief Canvi de la bicicleta de l'estació actual a una nova estació (No registra el viatge).
        @pre La bicicleta amb l'identificador idBici existeix.
        @pre L'estació amb l'identificador idEstacion existeix i té espai lliure.
        @post La estació asociada a idBici passa a ser idEstacion.
        @cost constant.
    */
    void canvi_bici(string idBici, string idEstacion);

    // CONSULTORES

    /** @brief Consulta si existeix una bicicleta amb l'identificador idBici.
        @pre Cert
        @post Retorna cert si la bicicleta amb idBici existeix; fals altrament.
        @cost constant.
    */
    bool existeix(string idBici) const;

    /** @brief Consulta si una bicicleta amb l'identificador donat es troba a l'estació especificada.
        @pre La bicicleta amb l'identificador idBici existeix.
        @pre L'estació amb l'identificador idEstacion existeix.
        @post Retorna cert si la bicicleta amb idBici es troba a l'estació idEstacion; fals altrament.
        @cost constant.
    */
    bool esta_bici_estacio(string idBici, string idEstacion) const;

    /** @brief Consulta l'estació a la qual pertany una bicicleta.
        @pre La bicicleta amb l'identificador idBici existeix a la col·lecció.
        @post Retorna l'identificador de l'estació a la qual pertany la bicicleta amb idBici.
        @cost constant.
    */
    string busca_estacio(string idBici) const;

    /** @brief Consulta els viatges realitzats per una bicicleta.
        @pre La bicicleta amb l'identificador idBici existeix.
        @post Imprimeix els viatges que ha fet la bici
        @cost lineal respecte al nombre de viatges realitzats per la bicicleta.
    */
    void viatges(string idBici) const;
};

#endif // CJT_BICIS_HH