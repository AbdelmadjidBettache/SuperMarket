#include "CatalogItem.h"


//getters
string CatalogItem::getNom() { return nom; };
double CatalogItem::getPrix() { return prix; };
int CatalogItem::getQuantite() { return quantite; };
//setters
void CatalogItem::set_nom(string name) { nom = name; };
void CatalogItem::set_prix(double price) { prix = price; };
void CatalogItem::set_quantite(int Qte) { quantite = Qte; };

//le constructeur
CatalogItem::CatalogItem() {};
CatalogItem::CatalogItem(string nom, double prix, int quantite) {
	this->nom = nom;
	this->prix = prix;
	this->quantite = quantite;
};
