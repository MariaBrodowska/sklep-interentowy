#ifndef PROJEKT_ZALICZENOWY__LAB_MARIA_BRODOWSKA_KLIENT_H
#define PROJEKT_ZALICZENOWY__LAB_MARIA_BRODOWSKA_KLIENT_H
#include <iostream>
#include <bits/stdc++.h>
#include "zamowienie.h"
#include <vector>
#include <fstream>
using namespace std;

class Klient {
public:
    vector <Klient> klienci;
    vector <Zamowienie> zamowienia;
    string imie, nazwisko, adresDostawy, plec, login, haslo;
    Klient();
    Klient(string i, string n, string adres, string p);
    void dodajKlienta(Klient k);
    Klient* zaloguj();
    void zarejestruj(Klient* klient);
    void modyfikacja(Klient* klient);
    void zapisWszystkich();
    void dodajZamowienie(Zamowienie z);
    void wyswietlZamowienia();
    void edytujZamowienie(Zamowienie& z,vector <Produkt> w);
    void zapisTekstowyZamowien();
    void zapisBinarnyZamowien();
};


#endif //PROJEKT_ZALICZENOWY__LAB_MARIA_BRODOWSKA_KLIENT_H
