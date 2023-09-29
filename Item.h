#pragma once
#include <string>
#include <iostream>
using namespace std;

class Item
{
	//les donnees
protected:
	string nom_item = "";
	double prix_item = 0;
	int quantite_item = 0;
	int quantite_item_instock = 0;


public:
	//getters
	string getNomItem();
	double getPrixItem();
	int getQuantiteItem();
	
	//setters
	void set_nom_item(string nom);
	void set_prix_item(double prix);
	void set_quantite_item(int quantite);


	//le constructeur
	Item();
	Item(string nom, double prix, int quantite);

	//autre methodes
	void ajouterAuStock(int quantite);
	void enleverDuStock(int quantite);
	void afficherItem();
};

