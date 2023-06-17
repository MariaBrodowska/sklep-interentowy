#include "produkty.h"

void Produkt :: aktualizujZapis(vector <Produkt> wszystkie){
    ofstream plik;
    plik.open("C:\\Users\\VivoBook\\Desktop\\projekt zaliczenowy  lab Maria Brodowska\\zapisTekstowyZLogowaniem.csv", ios_base::out);
    if (!plik.is_open()) {
        cout << "Nie udalo sie otworzyc pliku"<< endl;
        exit(0);
    }
    for (auto& p : wszystkie){
        plik << p.nazwa << ";" << p.cena << ";" << p.ilePozostalo << "\n";
    }
    plik.close();
}