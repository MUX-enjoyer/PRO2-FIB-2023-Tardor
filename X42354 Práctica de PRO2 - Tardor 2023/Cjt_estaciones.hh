/** @file Cjt_estaciones.hh
    @brief Especificació de la classe Cjt_estaciones
*/

#ifndef CJT_ESTACIONES_HH
#define CJT_ESTACIONES_HH

#include "Estacion.hh"
#include "Cjt_Bicis.hh"

#ifndef NO_DIAGRAM
#include <iostream>
using namespace std;
#include "BinTree.hh"
#include <map>
#endif


/** @class Cjt_estaciones
    @brief Gestiona la informació de l'arbre d'estacions i les operacions relacionades amb les estacions.
 */
class Cjt_estaciones {
private:
    map<string, Estacion> mapa_estaciones;  /** @brief Mapa d'estacions identificades pel seu id. */
    BinTree<string> cjt_estaciones;         /** @brief Arbre binari d'estacions */
    
    BinTree<string> crear_estacions();

    /** @brief Busca l'estació amb una major desviació estàndard en quant a places lliures.
        @pre Cert
        @post Retorna l'identificador de l'estació amb major coeficient de desocupació, "error" si l'arbre és buit.
        des conté el coeficient de desocupació de la estació amb major desocupació
        pl conté el nombre de places lliures de la branca
        n conté el nombre de nodes de la branca
        
        @cost lineal respecte al nombre total d'estacions en l'arbre.
    */
    string busca_estacion(const BinTree<string>& arbre, float& des, float& pl, float& n);

    /** @brief Puja una bicicleta des de l'estació d'origen fins a l'estació de destí.
        @pre L'estació d'origen té almenys una bicicleta i l'estació de destí té almenys un espai lliure.
        @post S'ha mogut una bicicleta des de l'estació d'origen fins a l'estació de destí.
        @cost constant.
    */
    void pujo_bici(Cjt_Bicis& bicicletes, string idEstacion_previ, string idEstacion_post);

    /** @brief Omple les estacions amb les bicicletes disponibles segons un arbre binari.
        @pre Cert
        @post Les estacions del sistema (`mapa_estaciones`) s'omplen amb bicicletes disponibles segons l'arbre donat
        i el cjt_Bicis bicicletes s'actualitza amb els canvis d'estacions.
        @cost lineal en la quantitat total d'estacions i bicicletes a moure.
    */
    void llenar_estaciones(Cjt_Bicis& bicicletes, BinTree<string> arbre);

public:
    // CONSTRUCTORA

    /** @brief Constructora de la classe Cjt_estaciones.
        @pre Cert
        @post Crea un BinTree d'estacions a partir de la lectura de dades de l'entrada.
        @cost lineal respecte al nombre d'estacions llegides.
    */
    Cjt_estaciones();
    
    // MODIFICADORES

    /** @brief Dona d'alta una bicicleta a una estació.
        @pre La bicicleta amb l'identificador idBici no existeix prèviament.
        @pre L'estació amb l'identificador idEstacion existeix.
        @return Retorna cert si s'ha donat d'alta la bicicleta amb èxit, fals si no hi cabia a l'estació.
        @cost constant.
    */
    bool alta_bici(string idBici, string idEstacion);
    
    /** @brief Dona de baixa una bicicleta d'una estació.
        @pre La bicicleta amb l'identificador idBici existeix i es troba a l'estació idEstacion.
        @post S'ha donat de baixa la bicicleta de idEstacion.
        @cost constant.
    */
    void baja_bici(string idBici, string idEstacion);
    

    /** @brief Mou una bicicleta d'una estació a una altra.
        @pre La bicicleta amb l'identificador idBici existeix.
        @pre L'estació amb l'identificador idEstacion existeix.
        @post La bicicleta idBici es mou a idEstacion i es registra el viatge.
        @cost constant.
    */
    int mover_bici(string idBici, string idEstacion, Cjt_Bicis& bicicletes);
    
    /** @brief Modifica la capacitat total d'una estació.
        @return Retorna cert si la capacitat s'ha modificat amb èxit, fals si no hi ha prou espai.
        @cost constant.
    */
    bool mod_cap(string idEstacion, int cap);
    
    // CONSULTORES

    /** @brief Consulta les bicicletes emmagatzemades a l'estació.
        @pre Cert.
        @post Imprimeix les bicicletes emmagatzemades a l'estació, per ordre d'id.
        @cost Cost lineal respecte al nombre de bicicletes emmagatzemades a l'estació.
    */
    void imprimir_bicis(string idEstacio);
    
    /** @brief Puja les bicicletes a les estacions superiors de l'arbre per ordre
        d'ocupació i en cas d'empat per identificador de bicis.
        @pre L'arbre d'estacions i el conjunt de bicicletes han estat inicialitzats.
        @post S'han mogut les bicicletes segons els criteris esmentats fins a omplir les
        estacions o haver pujat totes les bicis.
        @cost lineal respecte al nombre total de bicicletes i estacions.
    */
    void subir_bicis(Cjt_Bicis& bicicletes);

    /** @brief Assigna una estació a una bicicleta segons el coeficient de desocupació general.
        (numero total de places lliures estacio + estacions següents)/n_estacions.
        En cas d'empat es tria la estació amb identificador més petit
        @post S'ha assignat una estació a la bicicleta segons els criterits esmentats.
        Retorna l'identificador de l'estació assignada a la bicicleta, o "error" si no es pot assignar cap estació.
        @cost lineal respecte al nombre total de places lliures i nombre total d'estacions.
     */    
    string asignar_estacion(Cjt_Bicis& bicicletes, string idBici);

    // CONSULTORES

    /** @brief Consulta el nombre total de places lliures disponibles a totes les estacions.
        @pre Cert
        @post Retorna el nombre total de places lliures disponibles a totes les estacions.
        @cost lineal respecte al nombre total de places lliures.
    */
    int plazas_libres() const;
    
    /** @brief Consulta si una estació amb l'identificador especificat existeix.
        @pre Cert
        @post Retorna cert si l'estació amb l'identificador especificat existeix, fals altrament.
        @cost constant.
    */
    bool existeix(string idEstacion) const;    
};

#endif // CJT_ESTACIONS_HH