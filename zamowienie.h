#ifndef PROJEKT_ZALICZENOWY__LAB_MARIA_BRODOWSKA_ZAMOWIENIE_H
#define PROJEKT_ZALICZENOWY__LAB_MARIA_BRODOWSKA_ZAMOWIENIE_H
#include <iostream>
using namespace std;
#include "produkty.h"
#include <bits/stdc++.h>
enum Platnosc{gotowka, karta, blik};

class Zamowienie{
    int ilosc;
    float stawkaVAT, cena, calaCena;
    string dataZamowienia;
    Platnosc platnosc;
    vector <Produkt> produkt;

};


#endif //PROJEKT_ZALICZENOWY__LAB_MARIA_BRODOWSKA_ZAMOWIENIE_H
