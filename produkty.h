#ifndef PROJEKT_ZALICZENOWY__LAB_MARIA_BRODOWSKA_PRODUKTY_H
//#define PROJEKT_ZALICZENOWY__LAB_MARIA_BRODOWSKA_PRODUKTY_H
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class Produkt{
private:
    string nazwa;
    float cena, cenaVAT;
    int ilePozostalo, ileZamowiono;
public:
    static void aktualizujZapis(vector <Produkt>& produkty);
    static void pobierzProdukty(vector <Produkt>& produkty);
    friend class Zamowienie;
    friend class Klient;
};

#endif //PROJEKT_ZALICZENOWY__LAB_MARIA_BRODOWSKA_PRODUKTY_H
