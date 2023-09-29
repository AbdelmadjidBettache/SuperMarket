#include <iostream>
#include <vector>
#include "Item.h"
#include "Warehouse.h"
#include<time.h>
#include <chrono>

using namespace std;
using namespace std::chrono;


void AfficherMenu() {

	cout << "===================================" << endl;
	cout << "******** Menu Principale **********" << endl;
	cout << "===================================" << endl;
	cout << "1. Vente de stock    : " << endl;
	cout << "2. Acheter des stocks : " << endl;
	cout << "3. Le nombre de cet article vendu : " << endl;
	cout << "4. Le nombre de cet article acheté : " << endl;
	cout << "5. Payer les employés : " << endl;

}

void demarrer() {
	string again = "oui";

	time_point<system_clock> end_time;
	double  time_since_last_payment = 0;
	auto start_time = system_clock::now();
	auto last_payment_time = start_time;

	int choix = 0;

	vector<Item> listEnStock;
	Item item1("Laptop", 500.0, 100);
	Item item2("DVD", 80.0, 100);
	Item item3("Souris", 50.0, 150);
	Item item4("Clavier", 60.0, 200);
	Item item5("Flash drive", 10.0, 300);

	//ajouter items au stock de warehouse
	Warehouse warehouse;
	warehouse.ajouterItem(item1);
	warehouse.ajouterItem(item2);
	warehouse.ajouterItem(item3);
	warehouse.ajouterItem(item4);
	warehouse.ajouterItem(item5);

	//warehouse.afficherWarehouse();

	//ajouter des  quantitees 
	item1.ajouterAuStock(20);
	item2.ajouterAuStock(100);
	item3.ajouterAuStock(40);
	item4.ajouterAuStock(50);
	item5.ajouterAuStock(60);







	warehouse.chercherItemParNom("Laptop");

	//remplir le catalog avec 6 articles 
	//Catalog catalog;
	CatalogItem item1_catalog("Laptop", 300.0, 90);
	CatalogItem item2_catalog("Frigo", 600.0, 60);
	CatalogItem item3_catalog("SmartTv", 900.0, 20);
	CatalogItem item4_catalog("Secheuse", 500.0, 40);
	CatalogItem item5_catalog("Cafetiere", 100.0, 70);
	CatalogItem item6_catalog("Aspirateur", 250.0, 10);
	vector<CatalogItem> catalog_item = { item1_catalog,item2_catalog,item3_catalog,item4_catalog,item5_catalog,item6_catalog };
	Catalog catalog(catalog_item);
	/*catalog.ajouterItemCatalog(item1_catalog);
	catalog.ajouterItemCatalog(item2_catalog);
	catalog.ajouterItemCatalog(item3_catalog);
	catalog.ajouterItemCatalog(item4_catalog);
	catalog.ajouterItemCatalog(item5_catalog);
	catalog.ajouterItemCatalog(item6_catalog);*/

	
	do {

		do {

			AfficherMenu();
			cout << "Entrer votre choix : " << endl;
			cin >> choix;

			switch (choix)
			{

			case 1:
				
				//vente du stock 
				warehouse.venteDeStock2(item2, 120.0);
				cout << "****** Affichage de warehouse apres la vente **********" << endl;
				warehouse.afficherWarehouse();
				break;
			case 2:
				catalog.afficherCatalogue();
				warehouse.acheteDesStocks(catalog, 30);
				cout << "****** Affichage de warehouse apres l'achat  **********" << endl;
				warehouse.afficherWarehouse();

				break;
			case 3:
				//afficher la quantitee vendu
				cout << "Quantites vendu : " << warehouse.obtenir_nombre_articles_vendus("DVD") << endl;

				break;
			case 4:
				cout << "Quantites achete : " << warehouse.obtenir_nombre_articles_achetes("Laptop") << endl;
				break;
			case 5:
				end_time = system_clock::now();
				time_since_last_payment = duration_cast<duration<double, ratio<60>>>(end_time - last_payment_time).count();
				cout << "temps depuis le dernier payment:" << time_since_last_payment << endl;
				cout << " payer employe: " << warehouse.payeEmployees(time_since_last_payment) << " $" << endl;
				last_payment_time = end_time;

				break;
			default:
				cout << "Choix Invalide!" << endl;
				break;
			}


			cout << "Voulez-vous faire un autre choix : (oui/non)" << endl;
			cin >> again;


		} while (choix != 1 && choix != 2 && choix != 3 && choix != 4 && choix != 5);

	} while (again == "oui");






	

}


int main()
{

	demarrer();
	return 0;
}

