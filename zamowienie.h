#ifndef PROJEKT_ZALICZENOWY__LAB_MARIA_BRODOWSKA_ZAMOWIENIE_H
#define PROJEKT_ZALICZENOWY__LAB_MARIA_BRODOWSKA_ZAMOWIENIE_H
#include <iostream>
using namespace std;
#include "produkty.h"
#include <bits/stdc++.h>
#include <ctime>
enum Platnosc{gotowka, karta, blik};

class Zamowienie{
public:
    vector <Produkt> produkty;
    void dodajProdukt(Produkt p);
    int iloscWszystkich;
    float calaCena;
    string dataZamowienia;
    //void pobierzDate();
    Platnosc platnosc;
};


#endif //PROJEKT_ZALICZENOWY__LAB_MARIA_BRODOWSKA_ZAMOWIENIE_H
