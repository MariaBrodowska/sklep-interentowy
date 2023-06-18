#include "klient.h"
Klient :: Klient()
{}
Klient :: Klient(string i, string n, string adres, string p)
        :imie(i),nazwisko(n),adresDostawy(adres),plec(p)
{}
void Klient :: dodajKlienta(Klient& k){
    klienci.push_back(k);
}
void Klient :: zapisDoTekstowego(Klient& klient){
    ofstream plik;
    plik.open("C:\\Users\\VivoBook\\Desktop\\projekt zaliczenowy  lab Maria Brodowska\\zapisTekstowyBezLogowania.csv", ios_base::app);
    plik << klient.imie << ";" << klient.nazwisko << ";" << klient.plec << ";" << klient.adresDostawy << "\n";
    plik.close();
}
void Klient :: zapisZLogowaniem(Klient& klient){
    ofstream plik;
    plik.open("C:\\Users\\VivoBook\\Desktop\\projekt zaliczenowy  lab Maria Brodowska\\zapisTekstowyZLogowaniem.csv", ios_base::app);
    plik << klient.imie << ";" << klient.nazwisko << ";" << klient.plec << ";" << klient.adresDostawy << ";" << klient.login<< ";" << klient.haslo << "\n";
    plik.close();
}
void Klient :: zapisDoBinarnego(Klient& klient){
    ofstream plik;
    plik.open("C:\\Users\\VivoBook\\Desktop\\projekt zaliczenowy  lab Maria Brodowska\\zapisBinarny.bin", ios_base::out|ios_base::binary);
    plik.write(reinterpret_cast<char*>(&klient.imie),sizeof(klient.imie));
    plik.write(reinterpret_cast<char*>(&klient.nazwisko),sizeof(klient.nazwisko));
    plik.write(reinterpret_cast<char*>(&klient.plec),sizeof(klient.plec));
    plik.write(reinterpret_cast<char*>(&klient.adresDostawy),sizeof(klient.adresDostawy));
    plik.close();
}
void Klient :: odczytKlientow(){
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
        dodajKlienta(klient);
    }
    plik.close();
}
void Klient :: nowyKlient(Klient *wsk){
    string im, naz, adres, pl, login, haslo;
    string z = "tak";
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
        if (im.empty() || naz.empty() || adres.empty() || pl.empty()){
            cout << "Nie podano: ";
            if (im.empty()) cout << "imienia ";
            if (naz.empty()) cout << "nazwiska ";
            if (adres.empty()) cout << "adresu dostawy ";
            if (pl.empty()) cout << "plci ";
            cout << endl;
        }
        else {
            cout << "Podane dane: " << im << " " << naz << ", " << pl << "\n" << adres << endl;
            cout << "Czy chcesz zmodyfikowac dane(tak/nie): ";
            cin >> z;
        }
    }
    Klient k(im,naz,adres,pl);
    wsk = &k;
    dodajKlienta(*wsk);
    zapisDoTekstowego(*wsk);
}
Klient* Klient :: zaloguj(){
    for(int i=3;i>0;i--){
        string l,h;
        cout << "Podaj login: ";
        cin >> l;
        cout << "Podaj hasło: ";
        cin >> h;
        for (auto& klient : klienci){
            if (l == klient.login && h == klient.haslo && !l.empty() && !h.empty()){
                cout << "Witaj ponownie " << klient.imie << " " << klient.nazwisko << "!" << endl;
                return &klient;
            }
        }
        if(i!=1) cout << "Podano zły login lub hasło\nPozostało " << i-1 << " próby logowania" << endl;
    }
    return nullptr;
}
void Klient :: zapisWszystkich(){
    ofstream plik;
    plik.open("C:\\Users\\VivoBook\\Desktop\\projekt zaliczenowy  lab Maria Brodowska\\zapisTekstowyZLogowaniem.csv", ios_base::out);
    if (!plik.is_open()) {
        cout << "Nie udalo sie otworzyc pliku"<< endl;
        exit(0);
    }
    for (auto& k : klienci){
        plik << k.imie << ";" << k.nazwisko << ";" << k.plec << ";" << k.adresDostawy << ";" << k.login<< ";" << k.haslo << "\n";
    }
    plik.close();
}
void Klient :: zarejestruj(Klient *klient){
    string im, nazw, log, has, adres, pl;
    string z = "tak";
    while (z=="tak"){
        cout << "imie: ";
        fflush(stdin);
        getline(cin,im);
        cout << "nazwisko: ";
        getline(cin,nazw);
        cout << "login: ";
        cin >> log;
        cout << "hasło: ";
        cin >> has;
        cout << "adres dostawy: ";
        fflush(stdin);
        getline(cin,adres);
        cout << "plec: ";
        cin >> pl;
        if (im.empty() || nazw.empty() || log.empty() || has.empty() || adres.empty() || pl.empty()){
            cout << "Nie podano: ";
            if (im.empty()) cout << "imienia ";
            if (nazw.empty()) cout << "nazwiska ";
            if (log.empty()) cout << "loginu ";
            if (has.empty()) cout << "hasla ";
            if (adres.empty()) cout << "adresu dostawy ";
            if (pl.empty()) cout << "plci ";
            cout << endl;
        }
        else {
            cout << "Podane dane: " << im << " " << nazw << ", " << pl << "\n" << adres << endl;
            cout << "Czy chcesz zmodyfikowac dane(tak/nie): ";
            cin >> z;
        }
    }
    Klient k(im,nazw,adres,pl);
    k.login = log;
    k.haslo = has;
    klient = &k;
    dodajKlienta(*klient);
}

void Klient :: modyfikacja(Klient* k){
    cout << "Zapisane dane: " << endl;
    cout << k->imie << " " << k->nazwisko << endl;
    cout << k->plec << " " << k->adresDostawy << endl;
    if (!k->login.empty()){
        cout << k->login << " " << k->haslo << endl;
    }
    string czy;
    cout << "Czy chcesz zmodyfikować swoje obecne dane?(tak/nie) ";
    cin >> czy;
    if (czy=="tak"){
        cout << "imie: ";
        fflush(stdin);
        getline(cin,k->imie);
        cout << "nazwisko: ";
        getline(cin,k->nazwisko);
        cout << "adres dostawy: ";
        getline(cin,k->adresDostawy);
        cout << "plec: ";
        cin >> k->plec;
        if (!k->login.empty()) {
            cout << "login: ";
            cin >> k->login;
            cout << "haslo: ";
            cin >> k->haslo;
        }
        cout << "Zapisane dane: " << endl;
        cout << k->imie << " " << k->nazwisko << endl;
        cout << k->plec << " " << k->adresDostawy << endl;
        if (!k->login.empty()){
            cout << k->login << " " << k->haslo << endl;
        }
    }
}
void Klient :: dodajZamowienie(Zamowienie& z){
    zamowienia.push_back(z);
}
void Klient :: wyswietlZamowienia(){
    cout << "------------Historia zamowien-------------" << endl;
    for (auto& z : zamowienia){
        cout << "\t\t" << z.dataZamowienia << endl;
        cout << "lista produktów: " << endl;
        for (auto& p : z.produkty){
            cout << p.nazwa << ", " << p.ileZamowiono << " sztuk, cena za sztuke(VAT): " << p.cenaVAT << ", cena za sztuke(bez VATu): " << p.cena << endl;
        }
        cout << "ilosc wszystkich produktow: " << z.iloscWszystkich << endl;
        string pl;
        switch(z.platnosc){
            case gotowka:
                pl = "gotowka";
                break;
            case karta:
                pl = "karta";
                break;
            case blik:
                pl = "blikiem";
                break;
        }
        cout << "platnosc: " << pl << endl;
        cout << "razem bez VATu: " << z.calaCena << endl;
        cout << "razem z VATem: " << z.calaCenaVAT << endl;
        cout << "------------------------------------------" << endl;
    }
}
void Klient :: zapisTekstowyZamowien(){
    ofstream plik;
    plik.open("C:\\Users\\VivoBook\\Desktop\\projekt zaliczenowy  lab Maria Brodowska\\zapisTekstowyZamowien.csv",ios_base::app);
    for (auto& z : zamowienia){
    plik << "Data zamowienia:" << ";" << z.dataZamowienia;
    plik << "Dane klienta:" << ";" << imie << ";" << nazwisko << ";" << adresDostawy << "\n";
    plik << "Ilosc wszystkich produktow:" << ";" << z.iloscWszystkich << "\n";
    plik << "Cena z VATem:" << ";" << z.calaCenaVAT << "\n";
    plik << "Cena bez VATu:" << ";" << z.calaCena << "\n";
    string pl;
    switch(z.platnosc){
        case 1:
            pl = "gotowka";
            break;
        case 2:
            pl = "karta";
            break;
        case 3:
            pl = "blik";
            break;
    }
    plik << "Platnosc:" << ";" << pl << "\n";
    for (auto &p: z.produkty) {
        plik << p.nazwa << ";" << p.cena << ";" << p.ileZamowiono  << " sztuk" << "\n";
    }}
    plik.close();
}
void Klient :: zapisBinarnyZamowien(){
    ofstream plik;
    plik.open("C:\\Users\\VivoBook\\Desktop\\projekt zaliczenowy  lab Maria Brodowska\\zapisBinarnyZamowien.bin", ios_base::out|ios_base::binary);
    for (auto& z : zamowienia){
    plik.write(reinterpret_cast<char*>(&z.dataZamowienia),sizeof(z.dataZamowienia));
    plik.write(reinterpret_cast<char*>(&z.iloscWszystkich),sizeof(z.iloscWszystkich));
    plik.write(reinterpret_cast<char*>(&z.calaCenaVAT),sizeof(z.calaCenaVAT));
    plik.write(reinterpret_cast<char*>(&z.calaCena),sizeof(z.calaCena));
    plik.write(reinterpret_cast<char*>(&z.platnosc),sizeof(z.platnosc));
    for (auto& p : z.produkty){
        plik.write(reinterpret_cast<char*>(&p.nazwa),sizeof(p.nazwa));
        plik.write(reinterpret_cast<char*>(&p.cenaVAT),sizeof(p.cenaVAT));
        plik.write(reinterpret_cast<char*>(&p.ilePozostalo),sizeof(p.ilePozostalo));
    }
    plik.close();
}
}
void Klient :: edytujZamowienie(Zamowienie& z, vector <Produkt>& wszystkieProdukty){
    cout << "Ostatnie zamowienie: " << z.dataZamowienia << endl;
    cout << "Wybierz co chcesz zmienic:" << endl;
    cout << "1. sposob platnosci\n2. ilosc produktow\n3. usuniecie produktu\n4. dodanie nowego produktu" << endl;
    int w, i = 1, ile;
    cin >> w;
    auto in = zamowienia.end()-1;
    if ( in->dataZamowienia == z.dataZamowienia){
        zamowienia.erase(in);
    }
    switch(w){
        case 1:
            z.pobierzPlatnosc();
            break;
        case 2:
            cout << "Wybierz produkt: " << endl;
            for (auto& p : z.produkty){
                cout << i << ". " << p.nazwa << ", " << p.ileZamowiono << " sztuk" << endl;
                i++;
            }
            cin >> i;
            cout << "Podaj ilosc: ";
            cin >> ile;
            for (auto& wp : wszystkieProdukty){
                if (z.produkty[i-1].nazwa == wp.nazwa){
                    wp.ilePozostalo += z.produkty[i-1].ileZamowiono;
                    wp.ilePozostalo -= ile;
                }
            }
            z.produkty[i-1].ileZamowiono = ile;
            break;
        case 3:
            i = 1;
            cout << "Wybierz produkt: " << endl;
            for (auto& p : z.produkty){
                cout << i << ". " << p.nazwa << ", " << p.ileZamowiono << " sztuk" << endl;
                i++;
            }
            cin >> i;
            for (auto& wp : wszystkieProdukty){
                if (z.produkty[i-1].nazwa == wp.nazwa){
                    wp.ilePozostalo += z.produkty[i-1].ileZamowiono;
                }
            }
            z.usunProdukt(z.produkty[i-1]);
            break;
        case 4:
            z.dodajListeProduktow(wszystkieProdukty);
            break;
        default:
            cout << "Nieprawidlowy numer" << endl;
            return;
    }
    if(w!=1){
        z.aktualizuj();
    }
    zamowienia.push_back(z);
}
bool Klient :: czySaZamowienia(){
    return zamowienia.empty();
}
bool Klient ::czyZalogowany(){
    return login.empty();
}