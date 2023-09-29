#include "Catalog.h"


Catalog::Catalog() {};
Catalog::Catalog(vector<CatalogItem> catalog) {
	this->catalog_item = catalog;
};

//Autre methodes
CatalogItem Catalog::rechercheCatalogItemParNom(string name) {
	CatalogItem itemTrouve, unItem;
	vector<CatalogItem>::iterator it;
	for (it = catalog_item.begin(); it != catalog_item.end(); ++it) {
		unItem = *it;
		if (unItem.getNom() == name) {
			itemTrouve = unItem;
		}
	}
	return itemTrouve;
};

void Catalog::ajouterItemCatalog(CatalogItem catItems) {
	catalog_item.push_back(catItems);
};


/*void afficherCatalog() {
	cout << endl;
	cout << "Catalog des Items: " << endl;
	for (int i = 0; i < catalog_item.size(); i++)
	{
		cout << catalog_item[i].getNom() <<" ";
		cout << catalog_item[i].getPrix() <<" ";
		cout << catalog_item[i].getQuantite() << endl;
	}
}*/

void Catalog::afficherCatalogue() {
	cout << endl;
	cout << "===========================================================" << endl;
	cout << "|              Liste des Item dans le CATALOG             | " << endl;
	cout << "===========================================================" << endl;
	for (int i = 0; i < catalog_item.size(); i++) {
		cout << i + 1 << ". " << catalog_item[i].getNom() << " - Prix : " << catalog_item[i].getPrix() << " $ - Quantite en stock : " << catalog_item[i].getQuantite() << endl;
	}
	cout << "===========================================================" << endl;
	cout << endl;
};


