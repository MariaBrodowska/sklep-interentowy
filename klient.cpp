#include "klient.h"
Klient :: Klient()
{}
Klient :: Klient(string i, string n, string adres, string p)
        :imie(i),nazwisko(n),adresDostawy(adres),plec(p)
{}
void Klient :: dodajKlienta(Klient k){
    klienci.push_back(k);
}
Klient* Klient :: zaloguj(){
    for(int i=3;i>0;i--){
        string l,h;
        cout << "Podaj login: ";
        cin >> l;
        cout << "Podaj hasło: ";
        cin >> h;
        for (auto& klient : klienci){
            if (l == klient.login && h == klient.haslo && l != "" && h != ""){
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
    for (auto& klient : klienci){
        plik << klient.imie << ";" << klient.nazwisko << ";" << klient.plec << ";" << klient.adresDostawy << ";" << klient.login<< ";" << klient.haslo << "\n";
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
        if (im=="" || nazw=="" || log=="" || has=="" || adres=="" || pl==""){
            cout << "Nie podano: ";
            if (im=="") cout << "imienia ";
            if (nazw=="") cout << "nazwiska ";
            if (log=="") cout << "loginu ";
            if (has=="") cout << "hasla ";
            if (adres=="") cout << "adresu dostawy ";
            if (pl=="") cout << "plci ";
            cout << endl;
        }
        else {
            cout << "Podane dane: " << im << " " << nazw << ", " << pl << "\n" << adres << endl;
            cout << "Czy chcesz zmodyfikowac dane(tak/nie): ";
            cin >> z;
        }
    }
    klient->imie = im;
    klient->nazwisko = nazw;
    klient->login = log;
    klient->haslo = has;
    klient->adresDostawy = adres;
    klient->plec = pl;
    dodajKlienta(*klient);
}

void Klient :: modyfikacja(Klient* klient){
    cout << "Zapisane dane: " << endl;
    cout << klient->imie << " " << klient->nazwisko << endl;
    cout << klient->plec << " " << klient->adresDostawy << endl;
    if (klient->login != ""){
        cout << klient->login << " " << klient->haslo << endl;
    }
    string czy;
    cout << "Czy chcesz zmodyfikować swoje obecne dane?(tak/nie) ";
    cin >> czy;
    if (czy=="tak"){
        cout << "imie: ";
        fflush(stdin);
        getline(cin,klient->imie);
        cout << "nazwisko: ";
        getline(cin,klient->nazwisko);
        cout << "adres dostawy: ";
        getline(cin,klient->adresDostawy);
        cout << "plec: ";
        cin >> klient->plec;
        if (klient->login != "") {
            cout << "login: ";
            cin >> klient->login;
            cout << "haslo: ";
            cin >> klient->haslo;
        }
        cout << "Zapisane dane: " << endl;
        cout << klient->imie << " " << klient->nazwisko << endl;
        cout << klient->plec << " " << klient->adresDostawy << endl;
        if (klient->login != ""){
            cout << klient->login << " " << klient->haslo << endl;
        }
    }
}
void Klient :: dodajZamowienie(Zamowienie z){
    zamowienia.push_back(z);
}
void Klient :: wyswietlZamowienia(){
    cout << "-----------Historia zamowien-------------" << endl;
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
        cout << "---------------------------------------" << endl;
    }
}
void Klient :: zapisTekstowyZamowien() {
    ofstream plik;
    plik.open("C:\\Users\\VivoBook\\Desktop\\projekt zaliczenowy  lab Maria Brodowska\\zapisTekstowyZamowien.csv",ios_base::app);
    for (auto& z : zamowienia){
    plik << "Data zamowienia:" << ";" << z.dataZamowienia << "\n";
    plik << "Ilosc wszystkich produktow:" << ";" << z.iloscWszystkich << "\n";
    plik << "Cena z VATem:" << ";" << z.calaCenaVAT << "\n";
    plik << "Cena bez VATu:" << ";" << z.calaCena << "\n";
    plik << "Cena bez VATu:" << ";" << z.platnosc << "\n";
    for (auto &p: z.produkty) {
        plik << p.nazwa << ";" << p.cenaVAT << ";" << p.ilePozostalo << "\n";
    }
    plik.close();
}
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
void Klient :: edytujZamowienie(Zamowienie& z, vector <Produkt> wszystkieProdukty){
    cout << "Ostatnie zamowienie: " << z.dataZamowienia << endl;
    cout << "Wybierz co chcesz zmienic:" << endl;
    cout << "1. sposob platnosci\n2. ilosc produktow\n3. usuniecie produktu\n4. dodanie nowego produktu" << endl;
    int w, i = 1, ile;
    cin >> w;
    auto iplat = zamowienia.end()-1;
    if ( iplat->dataZamowienia == z.dataZamowienia){
        zamowienia.erase(iplat);
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
            z.usunProdukt(z.produkty[i-1]);
            break;
        case 4:
            z.dodajListeProduktow(wszystkieProdukty);
            break;
    }
    if(w!=1){
        z.aktualizuj();
    }
    zamowienia.push_back(z);
}