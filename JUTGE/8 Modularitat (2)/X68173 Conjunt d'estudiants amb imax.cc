#include "Cjt_estudiants.hh"
#include <algorithm>

Cjt_estudiants::Cjt_estudiants() {
  nest = 0;
  vest = vector<Estudiant>(MAX_NEST);
  imax = -1;
}

void Cjt_estudiants::afegir_estudiant(const Estudiant& est) {
  if (nest >= MAX_NEST) throw PRO2Excepcio("Conjunt ple");
  int i = nest-1;
  bool b = false;
  int dni = est.consultar_DNI();

  bool recalcular = false;
  if (imax == -1 && est.te_nota()) recalcular = true;
  else if (est.te_nota() && est.consultar_nota() >= vest[imax].consultar_nota()) recalcular = true;

  while (i >= 0 and not b) {  
    if ( dni> vest[i].consultar_DNI()) b = true;
    else {
      vest[i+1]=vest[i];
      --i;
    }
  }
  // i es la posicio mes avancada amb el DNI mes petit que dni, si n'hi ha;
  // si no, i=-1 
  vest[i+1] = est;
  ++nest;
  if (recalcular) recalcular_posicio_imax();
  else if (imax > i) ++imax;
}

int Cjt_estudiants::cerca_dicot(const vector<Estudiant>& vest, int left, int right, int x) {
/* Pre: vest esta ordenat */
  int i;
  bool found = false;
  while (left <= right and not found) { 
    i = (left + right)/2;
    if (x < vest[i].consultar_DNI()) right = i - 1;
    else if (x > vest[i].consultar_DNI()) left = i + 1; 
    else found = true;
  }
  // i es la posicio, si l'element existeix
  if (found) return i; 
  else return -1;  
}  

void Cjt_estudiants::modificar_estudiant(const Estudiant& est) {
  /* Pre: existeix un estudiant al parametre implicit amb el dni d'est  */
  int x = est.consultar_DNI();
  int i = cerca_dicot(vest,0,nest-1,x);
  
  bool recalcular = false;
  if (imax == -1) recalcular = true;
  else if (vest[i].te_nota() && vest[i].consultar_nota() == vest[imax].consultar_nota()) recalcular = true;
  else if (est.te_nota() && est.consultar_nota() >= vest[imax].consultar_nota()) recalcular = true;

  vest[i] = est;
  
  if (recalcular) recalcular_posicio_imax();
}    
  		
void Cjt_estudiants::modificar_iessim(int i, const Estudiant& est) {
  if (i < 1 or i > nest) throw PRO2Excepcio("Index no valid per a modificar_iessim");
  
  bool recalcular = false;
  if (imax == -1) recalcular = true;
  else if (vest[i-1].te_nota() && vest[i-1].consultar_nota() == vest[imax].consultar_nota()) recalcular = true;
  else if (est.te_nota() && est.consultar_nota() >= vest[imax].consultar_nota()) recalcular = true;
  
  vest[i-1] = est;

  if (recalcular) recalcular_posicio_imax();
}
  
int Cjt_estudiants::mida() const {
  return nest;
}
  
int Cjt_estudiants::mida_maxima() {
  return MAX_NEST;
}

bool Cjt_estudiants::existeix_estudiant(int dni) const {
  int i= cerca_dicot(vest,0,nest-1,dni);
  return (i != -1);
}

Estudiant Cjt_estudiants::consultar_estudiant(int dni) const {
  int i=cerca_dicot(vest,0,nest-1,dni);
  return vest[i];
}
 
Estudiant Cjt_estudiants::consultar_iessim(int i) const {
 if (i < 1 or i > nest) throw PRO2Excepcio("Index no valid per a consultar_iessim");
  return vest[i-1];
}

bool comp(const Estudiant& e1, const Estudiant& e2){
  return (e1.consultar_DNI() < e2.consultar_DNI());
}

void Cjt_estudiants::ordenar_cjt_estudiants() {
  sort(vest.begin(),vest.begin()+nest,comp);
  recalcular_posicio_imax();
}

void Cjt_estudiants::llegir() {
  cin >> nest;
  if (nest > MAX_NEST) throw PRO2Excepcio("El conjunt no pot ser mes gran que la mida maxima");
  for (int i = 0; i < nest; ++i)
    vest[i].llegir();
  ordenar_cjt_estudiants();
}


void Cjt_estudiants::escriure() const {
  for (int i = 0; i < nest; ++i)
    vest[i].escriure();
}

Estudiant Cjt_estudiants::estudiant_nota_max() const {
    if (imax == -1) throw PRO2Excepcio("Cap estudiant tÃ© nota");
    return vest[imax];
}

void Cjt_estudiants::esborrar_estudiant(int dni) {
    int i = cerca_dicot(vest, 0, nest-1, dni);
    if (i == -1) throw PRO2Excepcio("No existeix estudiant");

    bool recalcular = false;
    if (i == imax) recalcular = true; 

    for (int j = i; j < nest - 1; ++j) vest[j] = vest[j+1];
	--nest;

    if (recalcular) ordenar_cjt_estudiants();
    else if (imax > i) --imax;
}

void Cjt_estudiants::recalcular_posicio_imax() {
    imax = -1;
    for (int i = 0; i < nest; ++i) {
        if (imax == -1 && vest[i].te_nota()) imax = i;
        else if (vest[i].te_nota() && vest[i].consultar_nota() > vest[imax].consultar_nota()) imax = i;
    }
}