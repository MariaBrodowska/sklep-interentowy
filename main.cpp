#include <iostream>
#include "klient.h"
#include <vector>

using namespace std;

int main() {
    Klient klient;
    Klient *wsk = &klient;
    Klient *wsk1 = &klient;
    wsk->odczytKlientow();
    cout << "Sklep z akcesoriami dla zwierzat" << endl;
    cout << "Witaj! Wybierz opcje i zacznij zamawiac!" << endl;
    cout << "1. Jestem tu pierwszy raz\n2. Jestem stalym klientem\n3. Kontynuuj bez logowania" << endl;
    int w;
    cin >> w;
    //logowanie
    switch (w){
        case 1:
            wsk->zarejestruj(wsk);
            Klient::zapisZLogowaniem(*wsk);
            break;
        case 2:
            wsk = wsk->zaloguj();
            if (wsk == nullptr){
                cout << "Osiagnieto maksymalne proby logowania";
                exit(0);
            }
            break;
        default:
            wsk->nowyKlient(wsk);
            break;
    }
    //menu wyboru
    Zamowienie noweZamowienie;
    vector <Produkt> wszystkieProdukty;
    Produkt::pobierzProdukty(wszystkieProdukty);
    while (w!=4){
    cout << "MENU" << endl;
    cout << "1. Stworz nowe zamowienie\n2. Edytuj ostatnie zamowienie\n3. Wyswietl historie zamowien\n4. Zmień moje dane\n5. Zakoncz" << endl;
    cin >> w;
    switch(w){
        case 1:
            noweZamowienie.wyczyscZamowienie();
            noweZamowienie.dodajListeProduktow(wszystkieProdukty);
            noweZamowienie.pobierzDate();
            noweZamowienie.pobierzPlatnosc();
            wsk->dodajZamowienie(noweZamowienie);
            cout << "Dodano nowe zamowienie!" << endl;
            wsk->wyswietlZamowienia();
            break;
        case 2:
            if (!wsk->czySaZamowienia()){
                wsk->edytujZamowienie(noweZamowienie,wszystkieProdukty);
                wsk->wyswietlZamowienia();
            }
            else cout << "Brak ostatnich zamowien" << endl;
            break;
        case 3:
            if (!wsk->czySaZamowienia()) {
                wsk->wyswietlZamowienia();
            }
            else cout << "Brak ostatnich zamowien" << endl;
            break;
        case 4:
            wsk->modyfikacja(wsk);
            if (!wsk1->czyZalogowany()) wsk1->zapisWszystkich();
            else Klient::zapisDoTekstowego(*wsk);
            break;
        case 5:
            Produkt::aktualizujZapis(wszystkieProdukty);
            Klient::zapisDoBinarnego(*wsk);
            wsk->zapisTekstowyZamowien();
            wsk1->zapisBinarnyZamowien();
            return 0;
        default:
            cout << "Podano zly numer" << endl;
    }}
}