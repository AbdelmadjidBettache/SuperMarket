#include "Warehouse.h"

int Warehouse::getQuantiteAchete() { return quantiteAchete; };
int Warehouse::getQuantiteVendu() { return quantiteVendu; };
double Warehouse::getTotalDepenses() { return totalDepenses; };
double Warehouse::getTotalBenefices() { return totalBenefices; };

void Warehouse::set_quantite_achete(int qteAchete) { qteAchete = quantiteAchete; };
void Warehouse::set_quantite_vendu(int qteVendu) { qteVendu = quantiteVendu; };
void Warehouse::set_total_depense(double depnse) { depnse = totalDepenses; };
void Warehouse::set_total_benefice(double benefice) { benefice = totalBenefices; };

//Le constructeur
Warehouse::Warehouse() {};

//Autre methodes
void Warehouse::ajouterItem(Item item) {
	items.push_back(item);
};



void Warehouse::ajouterCatalogItem(CatalogItem itemCatalog) {
	catalog->ajouterItemCatalog(itemCatalog);
};
/*void Warehouse::enleverItem(Item item) {
	items.erase(remove(items.begin(), items.end(), items), items.end());
};*/


Item Warehouse::chercherItemParNom(string name) {
	Item itemTrouve, unItem;
	vector<Item>::iterator it;
	for (it = items.begin(); it != items.end(); ++it) {
		unItem = *it;
		if (unItem.getNomItem() == name) {
			itemTrouve = unItem;
		}
	}
	return itemTrouve;
};

void Warehouse::venteDeStock2(Item item, double montant) {
	int quantiteTotale = 0;
	double beneficeTotal = 0.0;

	// Vérifier que l'item existe et calculer la quantité totale
	for (int i = 0; i < items.size(); i++) {
		if (item.getNomItem() == items[i].getNomItem()) {
			quantiteTotale += items[i].getQuantiteItem();
			beneficeTotal += items[i].getQuantiteItem() * (montant - items[i].getPrixItem());
		}
	}

	// Vérifier que la quantité totale est suffisante pour effectuer la vente
	if (quantiteTotale == 0) {
		cout << "Il n'y a pas assez d'articles disponibles." << endl;
	}

	// Vendre les articles et mettre à jour les totaux
	for (int i = 0; i < items.size(); i++) {
		if (item.getNomItem() == items[i].getNomItem()) {
			int qutVendue = min(items[i].getQuantiteItem(), quantiteTotale);
			quantiteVendu += qutVendue;
			totalBenefices += qutVendue * (montant - items[i].getPrixItem());
			items[i].enleverDuStock(qutVendue);
			quantiteTotale -= qutVendue;
			if (quantiteTotale == 0);
		}
	}

	cout << "Vente de : " << quantiteVendu << " " << item.getNomItem() << "  pour un benefice total de: " << totalBenefices << " $" << endl;
};

void Warehouse::acheteDesStocks(Catalog catalog, int quantite) {

	string name = "";
	int qte = 0;
	double cout_achat = 0.0;
	CatalogItem itemcatalog;

	cout << "Entrer le nom de l'item a achete: " << endl;
	cin >> name;

	itemcatalog = catalog.rechercheCatalogItemParNom(name);
	Item item(itemcatalog.getNom(), itemcatalog.getPrix(), 0);

	if (itemcatalog.getNom()._Equal(chercherItemParNom(name).getNomItem()))
	{
		cout_achat = quantite * (itemcatalog.getPrix());
		totalDepenses += cout_achat;

		for (int i = 0; i < items.size(); i++)
		{
			if (items[i].getNomItem() == chercherItemParNom(name).getNomItem())
				items[i].ajouterAuStock(quantite);
		}


		quantiteAchete += quantite;
		chercherItemParNom(name).afficherItem();

	}
	else {
		cout << "**************** Ajout de nouveau Item ***************" << endl;
		for (int i = 0; i < items.size(); i++)
		{
			if (items[i].getNomItem() == chercherItemParNom(name).getNomItem())
				items[i].ajouterAuStock(quantite);
		}

		ajouterItem(item);
		cout_achat = quantite * (itemcatalog.getPrix());
		totalDepenses += cout_achat;
		for (int i = 0; i < items.size(); i++)
		{
			if (items[i].getNomItem() == chercherItemParNom(name).getNomItem()) {
				items[i].ajouterAuStock(quantite);
			}
		}
		quantiteAchete += quantite;
	}

	cout << "Achat de : " << quantite << " " << itemcatalog.getNom() << "  pour un cout total de: " << totalDepenses << " $" << endl;

}

//Obtenir le nombre d'articles vendus d'un certain type
int Warehouse::obtenir_nombre_articles_vendus(string nom) {
	int nombre_vendus = 0;
	for (Item a : items) {
		if (a.getNomItem() == nom) {
			nombre_vendus += quantiteVendu;
		}
	}
	return nombre_vendus;
};

int Warehouse::obtenir_nombre_articles_achetes(string nom) {
	int nombre_achetes = 0;
	for (Item a : items) {
		if (a.getNomItem() == nom) {
			nombre_achetes += quantiteAchete;
		}
	}
	return nombre_achetes;
};


double Warehouse::payeEmployees(double minutes)
{
	double  cout_salaire = minutes * 2600;
	total_employee_pay += cout_salaire;

	return cout_salaire;
};




void Warehouse::afficherWarehouse() {
	cout << endl;
	cout << "===============================================================" << endl;
	cout << "|              Liste des Items dans le WAREHOUSE              | " << endl;
	cout << "===============================================================" << endl;
	for (int i = 0; i < items.size(); i++)
	{
		cout << i + 1 << ". " << items[i].getNomItem() << " - Prix : " << items[i].getPrixItem() << " $ - Quantite en stock : " << items[i].getQuantiteItem() << endl;
	}
	cout << "===============================================================" << endl;
	cout << endl;
};
