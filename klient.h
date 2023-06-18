#ifndef PROJEKT_ZALICZENOWY__LAB_MARIA_BRODOWSKA_KLIENT_H
#define PROJEKT_ZALICZENOWY__LAB_MARIA_BRODOWSKA_KLIENT_H
#include <iostream>
#include <bits/stdc++.h>
#include "zamowienie.h"
#include <vector>
#include <fstream>
using namespace std;

class Klient {
private:
    vector <Klient> klienci;
    vector <Zamowienie> zamowienia;
    string imie, nazwisko, adresDostawy, plec, login, haslo;
public:
    Klient();
    Klient(string i, string n, string adres, string p);
    void nowyKlient(Klient *wsk);
    void dodajKlienta(Klient& k);
    //zapis klientow
    static void zapisDoTekstowego(Klient& klient);
    static void zapisZLogowaniem(Klient& klient);
    static void zapisDoBinarnego(Klient& klient);
    void odczytKlientow();
    void zapisWszystkich();
    //logowanie
    Klient* zaloguj();
    void zarejestruj(Klient* klient);
    void modyfikacja(Klient* klient);
    //sprawdzenia
    bool czySaZamowienia();
    bool czyZalogowany();
    //zamowienia
    void dodajZamowienie(Zamowienie& z);
    void wyswietlZamowienia();
    void edytujZamowienie(Zamowienie& z,vector <Produkt>& w);
    void zapisTekstowyZamowien();
    void zapisBinarnyZamowien();
};


#endif //PROJEKT_ZALICZENOWY__LAB_MARIA_BRODOWSKA_KLIENT_H
