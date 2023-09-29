#pragma once
#include "Item.h"
#include "Catalog.h"

class Warehouse
{

protected:
	vector <Item> items;
	Catalog* catalog;
	//int totalStock = 0;
	int quantiteAchete = 0;
	int quantiteVendu = 0;
	double totalVente = 0.0;
	double totalDepenses = 0.0;
	double totalBenefices = 0.0;
	time_t last_pay_time;
	double total_employee_pay =0.0;


public:
	int getQuantiteAchete();
	int getQuantiteVendu();
	double getTotalDepenses();
	double getTotalBenefices();

	void set_quantite_achete(int qteAchete);
	void set_quantite_vendu(int qteVendu);
	void set_total_depense(double depnse);
	void set_total_benefice(double benefice);

	//Le constructeur
	Warehouse();

	//Autre methodes
	void ajouterItem(Item item);



	void ajouterCatalogItem(CatalogItem itemCatalog);
	/*void enleverItem(Item item) ;*/


	Item chercherItemParNom(string name);

	void venteDeStock2(Item item, double montant);

	void acheteDesStocks(Catalog catalog, int quantite);
	int obtenir_nombre_articles_vendus(string nom);
	int obtenir_nombre_articles_achetes(string nom);
	double payeEmployees(double minutes);


	void afficherWarehouse();


};

