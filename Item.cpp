#include "Item.h"


//getters
string Item::getNomItem() { return nom_item; };
double Item::getPrixItem() { return prix_item; };
int Item::getQuantiteItem() { return quantite_item; }


//setters
void Item::set_nom_item(string nom) { nom_item = nom; };
void Item::set_prix_item(double prix) { prix_item = prix; };
void Item::set_quantite_item(int quantite) { quantite_item = quantite; };


//le constructeur

Item::Item() {};
Item::Item(string nom, double prix, int quantite) {
	this->nom_item = nom;
	this->prix_item = prix;
	this->quantite_item = quantite;
};

//autre methodes
//ajouter au stock la quantite recu en parametre
void Item::ajouterAuStock(int quantite) {
	quantite_item+= quantite;
};
//enlever du stock la quantite recu en parametre
void Item::enleverDuStock(int quantite) {
	quantite_item -= quantite;
};

void Item::afficherItem() {
	cout << "Liste des items : " << endl;

	cout << this->nom_item << " - Prix : " << this->prix_item << " $ - Quantite en stock : " << this->quantite_item << endl;

	cout << endl;
};
