#ifndef PROJEKT_ZALICZENOWY__LAB_MARIA_BRODOWSKA_ZAMOWIENIE_H
#define PROJEKT_ZALICZENOWY__LAB_MARIA_BRODOWSKA_ZAMOWIENIE_H
#include <iostream>
using namespace std;
#include "produkty.h"
#include <bits/stdc++.h>
#include <ctime>
enum Platnosc{gotowka=1, karta=2, blik=3};

class Zamowienie{
private:
    vector <Produkt> produkty;
    string dataZamowienia;
    int iloscWszystkich = 0;
    float calaCena = 0;
    float calaCenaVAT = 0;
    Platnosc platnosc;
    void dodajProdukt(Produkt& p);
    void usunProdukt(Produkt& p);
public:
    void dodajListeProduktow(vector <Produkt>& w);
    void wyczyscZamowienie();
    void aktualizuj();
    void pobierzDate();
    void pobierzPlatnosc();
    friend class Klient;
};


#endif //PROJEKT_ZALICZENOWY__LAB_MARIA_BRODOWSKA_ZAMOWIENIE_H
