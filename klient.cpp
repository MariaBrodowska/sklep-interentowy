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
    cout << "Podano zły login lub hasło\nPozostało " << i-1 << " próby logowania" << endl;
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