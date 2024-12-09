/** @file Estacion.hh
    @brief Especificació de la classe Estacion
*/

#ifndef ESTACION_HH
#define ESTACION_HH

#ifndef NO_DIAGRAM
#include <iostream>
using namespace std;
#include <set>
#include <string>
#endif

/** @class Estacion
    @brief Gestiona la informació d'una estació, incloent la seva capacitat i les bicicletes emmagatzemades.
*/
class Estacion {
private:
    int capacidad;          /** @brief nº màx de Bicis a l'estació */
    int espais_ocupats;     /** @brief nº de Bicis a l'estació */
    set<string> bicis;      /** @brief Vector per emmagatzemar les bicicletes d'aquesta estació */
public:
    // CONSTRUCTORES

    /** @brief Constructora per defecte de la classe Estacion.
        @pre Cert.
        @post Crea una estació sense cap paràmetre específic.
        @cost constant.
    */
    Estacion();

    /** @brief Constructora de la classe Estacion amb paràmetres.
        @pre Cert.
        @post Crea una estació amb la capacitat especificada i amb 0 espais ocupats.
        @cost constant.
    */
    Estacion(int capacidad);
    
    // MODIFICADORES

    /** @brief Afegeix una bicicleta a l'estació.
        @pre Cert.
        @post Retorna cert si s'ha afegit la bicicleta, fals si no hi cap.
        @cost constant.
    */
    bool afegir_bici(string idBici);
    
    /** @brief Treu una bicicleta de l'estació.
        @pre L'estació té una bicicleta amb idBici.
        @post S'elimina la bicicleta amb l'identificador especificat de l'estació.
        @cost constant.
    */
    void treure_bici(string idBici);

    /** @brief Treure la primera bicicleta emmagatzemada a l'estació.
        @pre L'estació té almenys una bicicleta emmagatzemada.
        @post S'elimina la primera bicicleta emmagatzemada de l'estació i retorna l'id d'aquesta.
        @cost constant.
    */
    string treure_primera();
    
    /** @brief Modifica la capacitat total de l'estació.
        @pre Cert.
        @post Si hi ha menys bicis que la nova capacitat modifica la capacitat i retorna cert, retorna fals altrament si no hi ha prou espai.
        @cost constant.
    */
    bool modificar_cap(int cap);

    // CONSULTORES

    /** @brief Consulta el nombre d'espais lliures disponibles a l'estació.
        @pre Cert.
        @post Retorna el nombre d'espais lliures disponibles a l'estació.
        @cost constant.
    */
    int consultar_espais_lliures() const;
    
    /** @brief Consulta el nombre d'espais actualment ocupats a l'estació.
        @pre Cert.
        @post Retorna el nombre d'espais actualment ocupats a l'estació.
        @cost constant.
    */
    int consultar_espais_ocupats() const;
    
    /** @brief Consulta l'identificador de la primera bicicleta emmagatzemada a l'estació.
        @pre L'estació té almenys una bicicleta emmagatzemada.
        @post Retorna l'identificador de la primera bicicleta emmagatzemada a l'estació.
        @cost constant.
     */
    string consultar_id_primera() const;

    // ENTRADA / SORTIDA

    /** @brief Consulta les bicicletes emmagatzemades a l'estació.
        @pre Cert.
        @post Imprimeix les bicicletes emmagatzemades a l'estació, per ordre d'id.
        @cost Cost lineal respecte al nombre de bicicletes emmagatzemades a l'estació.
    */
    void consultar_bicis_estacion() const;
};

#endif // ESTACION_HH