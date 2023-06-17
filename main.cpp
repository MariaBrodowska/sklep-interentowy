#include <iostream>
#include "klient.h"
#include "zamowienie.h"
#include <bits/stdc++.h>
#include <vector>
#include <stdio.h>
#include <fstream>
using namespace std;
void zapisDoTekstowego(Klient klient){
    ofstream plik;
    plik.open("C:\\Users\\VivoBook\\Desktop\\projekt zaliczenowy  lab Maria Brodowska\\zapisTekstowyBezLogowania.csv", ios_base::app);
    plik << klient.imie << ";" << klient.nazwisko << ";" << klient.plec << ";" << klient.adresDostawy << "\n";
    plik.close();
}
void zapisZLogowaniem(Klient klient){
    ofstream plik;
    plik.open("C:\\Users\\VivoBook\\Desktop\\projekt zaliczenowy  lab Maria Brodowska\\zapisTekstowyZLogowaniem.csv", ios_base::app);
    plik << klient.imie << ";" << klient.nazwisko << ";" << klient.plec << ";" << klient.adresDostawy << ";" << klient.login<< ";" << klient.haslo << "\n";
    plik.close();
}
void zapisDoBinarnego(Klient klient){
    ofstream plik;
    plik.open("C:\\Users\\VivoBook\\Desktop\\projekt zaliczenowy  lab Maria Brodowska\\zapisBinarny.bin", ios_base::out|ios_base::binary);
    plik.write(reinterpret_cast<char*>(&klient.imie),sizeof(klient.imie));
    plik.write(reinterpret_cast<char*>(&klient.nazwisko),sizeof(klient.nazwisko));
    plik.write(reinterpret_cast<char*>(&klient.plec),sizeof(klient.plec));
    plik.write(reinterpret_cast<char*>(&klient.adresDostawy),sizeof(klient.adresDostawy));
    plik.close();
}
void odczytKlientow(Klient *wsk){
    ifstream plik;
    plik.open("C:\\Users\\VivoBook\\Desktop\\projekt zaliczenowy  lab Maria Brodowska\\zapisTekstowyZLogowaniem.csv", ios_base::in);
    if (!plik.is_open()) {
        cout << "Nie udalo sie otworzyc pliku"<< endl;
        exit(0);}
    Klient klient;
    while (getline(plik,klient.imie,';')){
        getline(plik,klient.nazwisko,';');
        getline(plik,klient.plec,';');
        getline(plik,klient.adresDostawy,';');
        getline(plik,klient.login,';');
        getline(plik,klient.haslo);
        wsk->dodajKlienta(klient);
    }
    plik.close();
}
int main() {
    Klient *wsk = nullptr;
    Klient *wsk1 = nullptr;
    Klient klient;
    wsk = &klient;
    wsk1 = &klient;
    odczytKlientow(wsk);
    cout << "Sklep zoologiczny" << endl;
    cout << "Witaj! Wybierz opcje i zacznij zamawiac!" << endl;
    cout << "1. Jestem tu pierwszy raz\n2. Jestem stalym klientem\n3. Kontynuuj bez logowania" << endl;
    int w;
    cin >> w;
    string im, naz, adres, pl, login, haslo;
    string z = "tak";
    switch (w){
        case 1:
            wsk->zarejestruj(wsk);
            zapisZLogowaniem(*wsk);
            break;
        case 2:
            wsk = wsk->zaloguj();
            if (wsk == nullptr){
                cout << "Osiagnieto maksymalne proby logowania";
                exit(0);
            }
            break;
        case 3:
            while (z=="tak"){
                cout << "imie: ";
                fflush(stdin);
                getline(cin,im);
                cout << "nazwisko: ";
                getline(cin,naz);
                cout << "adres dostawy: ";
                getline(cin,adres);
                cout << "plec: ";
                cin >> pl;
                if (im=="" || naz=="" || adres=="" || pl==""){
                    cout << "Nie podano: ";
                    if (im=="") cout << "imienia ";
                    if (naz=="") cout << "nazwiska ";
                    if (adres=="") cout << "adresu dostawy ";
                    if (pl=="") cout << "plci ";
                    cout << endl;
                }
                else {
                    cout << "Podane dane: " << im << " " << naz << ", " << pl << "\n" << adres << endl;
                    cout << "Czy chcesz zmodyfikowac dane(tak/nie): ";
                    cin >> z;
                }
            }
            wsk->imie = im;
            wsk->nazwisko = naz;
            wsk->adresDostawy = adres;
            wsk->plec = pl;
            wsk->dodajKlienta(*wsk);
            zapisDoTekstowego(*wsk);
            break;
    }
    while (w!=4){
    cout << "MENU" << endl;
    cout << "1. Stworz nowe zamowienie\n2. Edytuj ostatnie zamowienie" << endl;
    if(wsk->login!=""){
        cout << "3. Zmień moje dane" << endl;
    }
    cout << "4. Zakoncz" << endl;
    cin >> w;
    switch(w){
        case 1:

            break;
        case 2:

            break;
        case 3:
            wsk->modyfikacja(wsk);
            wsk1->zapisWszystkich();
            break;
        case 4:
            zapisDoBinarnego(*wsk);
            return 0;
    }}
}