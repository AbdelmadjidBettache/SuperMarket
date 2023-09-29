#pragma once
#include <string>
using namespace std;

class CatalogItem
{

protected:
	string nom = "";
	double prix = 0;
	int quantite = 0;

public:
	//getters
	string getNom();
	double getPrix();
	int getQuantite();
	//setters
	void set_nom(string name);
	void set_prix(double price);
	void set_quantite(int Qte);

	//le constructeur
	CatalogItem();
	CatalogItem(string nom, double prix, int quantite);





};

