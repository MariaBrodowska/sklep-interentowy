#include "zamowienie.h"

void Zamowienie :: dodajProdukt(Produkt p){
    produkty.push_back(p);
    iloscWszystkich += p.ileZamowiono;
    calaCena += p.ileZamowiono * p.cena;
    calaCenaVAT += p.ileZamowiono * p.cenaVAT;
}
void Zamowienie :: aktualizuj(){
    iloscWszystkich=0;
    calaCena=0;
    calaCenaVAT=0;
    for (auto p : produkty){
        iloscWszystkich += p.ileZamowiono;
        calaCena += p.ileZamowiono * p.cena;
        calaCenaVAT += p.ileZamowiono * p.cenaVAT;
    }
}
void Zamowienie :: usunProdukt(Produkt p){
    auto i = produkty.begin();
    while (i != produkty.end()){
        if ( i->nazwa == p.nazwa){
            produkty.erase(i);
        }
        else i++;
    }
}

void Zamowienie :: dodajListeProduktow(vector <Produkt> wszystkieProdukty){
    string czy = "tak";
    int numer, ile, i;
    while(czy=="tak"){
        cout << "Wybierz produkt jaki chcesz dodać: " << endl;
        i = 1;
        for (auto &produkt : wszystkieProdukty) {
            cout << i << ". " << produkt.nazwa << ", cena: " << produkt.cenaVAT << " zl, pozostalo: "
                 << produkt.ilePozostalo << " sztuk" << endl;
            i++;
        }
        cin >> numer;
        cout << "liczba sztuk: ";
        cin >> ile;
        if (ile<=wszystkieProdukty[numer - 1].ilePozostalo){
            wszystkieProdukty[numer - 1].ileZamowiono += ile;
            wszystkieProdukty[numer-1].ilePozostalo -= ile;
            dodajProdukt(wszystkieProdukty[numer-1]);
            cout << "Dodano produkt " << wszystkieProdukty[numer - 1].nazwa << ", ilosc: "
                 << wszystkieProdukty[numer - 1].ileZamowiono << endl;
            cout << "Czy chcesz dodac kolejny produkt?(tak/nie) ";
            cin >> czy;
        }
        else cout << "Zbyt mala ilosc sztuk" << endl;
    }
}

void Zamowienie :: pobierzDate(){
    time_t czas = time(nullptr);
    dataZamowienia = ctime(&czas);
    //cout << dataZamowienia << endl;
}

void Zamowienie :: pobierzPlatnosc(){
    int p;
    bool w = false;
    while (!w){
    cout << "Wybierz platnosc (1-gotowka, 2-karta, 3-blik): ";
    cin >> p;
    switch(p){
        case 1:
            platnosc = gotowka;
            w = true;
            break;
        case 2:
            platnosc = karta;
            w = true;
            break;
        case 3:
            platnosc = blik;
            w = true;
            break;
        default:
            cout << "nieprawidlowy wybor" << endl;
    }}
}