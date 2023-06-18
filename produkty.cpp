#include "produkty.h"

void Produkt :: aktualizujZapis(vector <Produkt>& wszystkie){
    ofstream plik;
    plik.open("C:\\Users\\VivoBook\\Desktop\\projekt zaliczenowy  lab Maria Brodowska\\produktyWSklepie.csv", ios_base::out);
    if (!plik.is_open()) {
        cout << "Nie udalo sie otworzyc pliku"<< endl;
        exit(0);
    }
    for (auto& p : wszystkie){
        plik << p.nazwa << ";" << p.cena << ";" << p.ilePozostalo << "\n";
    }
    plik.close();
}
void Produkt :: pobierzProdukty(vector <Produkt>& wszystkie){
    ifstream plik;
    plik.open("C:\\Users\\VivoBook\\Desktop\\projekt zaliczenowy  lab Maria Brodowska\\produktyWSklepie.csv", ios_base::in);
    if (!plik.is_open()) {
        cout << "Nie udalo sie otworzyc pliku"<< endl;
        exit(0);}
    Produkt produkt;
    string pcena, pile;
    while (getline(plik,produkt.nazwa,';')){
        getline(plik,pcena,';');
        getline(plik,pile);
        produkt.cena = stof(pcena);
        produkt.ilePozostalo = stoi(pile);
        produkt.cenaVAT = produkt.cena * 1.23;
        produkt.ileZamowiono = 0;
        wszystkie.push_back(produkt);
    }
}