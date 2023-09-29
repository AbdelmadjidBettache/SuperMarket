#pragma once
#include "CatalogItem.h"
#include <vector>
#include <iostream>

class Catalog
{

protected:
	vector<CatalogItem> catalog_item;

public:
	Catalog();
	Catalog(vector<CatalogItem> catalog);

	//Autre methodes
	CatalogItem rechercheCatalogItemParNom(string name);

	void ajouterItemCatalog(CatalogItem catItems);


	/*void afficherCatalog();
	}*/

	void afficherCatalogue();



};

