#include <iostream>
#include <array>
#include <cstdlib>

using namespace std;
class Miejsce
{
    virtual void NowaGaleriaWMiescie()=0;
    virtual void wypiszNazweMiasta()=0;
    virtual void pelnaNazwaMiejsca()=0;
    virtual void wypiszInformacjeMiasta()=0;
    virtual void wypiszRokZalozenia()=0;
};
class InformacjeBiura
{
    virtual void infoOPolozeniuBiura()=0;
    virtual void informacjeOPrezesie()=0;
    virtual void pracownicyZwolnieni()=0;
    virtual void nowiPracownicy()=0;
    virtual void kontaktBiura()=0;
};
class InformacjeOsobowe
{
    virtual void daneOsobowe()=0;
    virtual void dataIMiejsceUrodzenia()=0;
    virtual void miejsceZamieszkania()=0;
    virtual void majatek()=0;
    virtual void wyksztalcenie()=0;
};
class InformacjeProduktu
{
    virtual void wypiszDzial()=0;
    virtual void wypiszKategorie()=0;
    virtual void wypiszRodzaj()=0;
    virtual void wypiszModel()=0;
    virtual void wypiszRozmiar()=0;
    virtual void pelneInformacje()=0;
};
class Miasto : public Miejsce
{
    public:
        friend class Galeria;
        string nazwaMiasta, wojewodztwo, kraj, informacje;
        int populacja, rokZalozenia;
        Miasto(string kraj, string wojewodztwo, string miasto, string informacje, int populacja, int rokZalozenia)
        {
            this->nazwaMiasta=miasto;
            this->informacje=informacje;
            this->kraj=kraj;
            this->wojewodztwo=wojewodztwo;
            this->populacja=populacja;
            this->rokZalozenia=rokZalozenia;
        }
        friend void ileGalerii(Miasto &);
    private:
        int liczbaGalerii=0;
    public:
        void NowaGaleriaWMiescie()
        {
            this->liczbaGalerii++;
        }
        void wypiszNazweMiasta()
        {
            cout<<"\nMiasto: "<<this->nazwaMiasta;
        }
        /// @brief 
        void wypiszInformacjeMiasta()
        {
            cout<<"Informacje o: "<<this->nazwaMiasta<<":\n "<<this->informacje;
        }
        void pelnaNazwaMiejsca()
        {
            cout<<"Miasto "<<this->nazwaMiasta<<", polozone w "<<this->kraj<<" w wojewodztwie "<<this->wojewodztwo;
        }
        void wypiszRokZalozenia()
        {
            this->wypiszNazweMiasta();
            cout<<", zostalo zalozone w roku "<<this->rokZalozenia;
        }
    friend class Galeria;
    ~Miasto()
    {
        cout<<"\nnie ma juz takiego miejsca\n";
    }
};
void ileGalerii(Miasto &miejsce)
{
    cout<<"W miescie: "<<miejsce.nazwaMiasta<<", liczba galerii= "<<miejsce.liczbaGalerii<<"\n";
}
class Galeria
{
    
    public:
        friend class Miasto;
        string nazwa;
        string ulica;
        string nazwaMiasta;
        int numer;
        Miasto *miastoGal;
        Galeria(Miasto *miasto, string nazwaGalerii, string ulica, int numerMiejsca, string wlasciciel)
        {
            nazwa=nazwaGalerii;
            ulica=ulica;
            this->numer=numerMiejsca;
            miastoGal=miasto;
            this->wlasciciel=wlasciciel;
            DodanoNowaGalerie(miasto);
        }
        friend void InfoGalerii(Galeria &);


        void LiczbaSklepow()
        {
            cout<<"\nW galerii "<<this->nazwa<<", znajdujacej sie w miescie "<<miastoGal->nazwaMiasta<<", jest "<<this->liczbaSklepowWGalerii<<" sklepow";
        }
        void operator+=(int value)
        {
            liczbaSklepowWGalerii+=value;
        }
        void operator-=(int value)
        {
            liczbaSklepowWGalerii-=value;
        }
    private:
        string wlasciciel;
        int liczbaSklepowWGalerii=0;
        void NowySklepWGalerii()
        {
            liczbaSklepowWGalerii++;
        }
        void DodanoNowaGalerie(Miasto *miasto)
        {
            miasto->NowaGaleriaWMiescie();
        }
    friend class Sklep;
    public:
    ~Galeria()
    {
        cout<<"\nNie ma już takiej galerii\n";
    }

};
void infoGalerii(Galeria &galeria)
{
    cout<<"\nGaleria "<<galeria.nazwa<<", znajduje się w mieście "<<galeria.miastoGal->nazwaMiasta<<", na ulicy "<<galeria.ulica<<" "<<galeria.numer;
}
class Biuro: public InformacjeBiura
{
    public:
        friend class Marka;
        Biuro(string miasto, string kraj, string prezes, int liczbaPracownikow, string ulica, int numerTel)
        {
            this->miastoM=miasto;
            this->krajM=kraj;
            this->prezesM=prezes;
            this->ulicaM=ulica;
            this->pracownicy=liczbaPracownikow;
            this->numerTel=numerTel;
        }
    private:    
        void infoOPolozeniuBiura()
        {
            cout<<"\nBiuro znajduje sie w "<<this->miastoM<<" w "<<this->krajM<<", na ulicy "<<this->ulicaM;
        }
        void informacjeOPrezesie()
        {
            cout<<"\nPrezesem jest "<<this->prezesM;
        }
        string miastoM, krajM, prezesM, ulicaM;
        int pracownicy, numerTel;
    public:
        void pracownicyZwolnieni()
        {
            int value;
            cout<<"\nPodaj liczbe zwolnionych pracownikow biura: ";
            cin>>value;
            pracownicy-=value;
        }
        void nowiPracownicy(){
            int value;
            cout<<"\nPodaj liczbe nowych pracownikow Biura: ";
            cin>>value;
            pracownicy+=value;
        }
        void kontaktBiura()
        {
            cout<<"\nTelefon do biura to: "<<this->numerTel;
        }


    ~Biuro()
    {
        cout<<"\nNie ma już takiego Biura\n";
    }
};
class Zalozyciel : public InformacjeOsobowe
{
    public:
        friend class Marka;
        string imie, nazwisko, dataUrodzenia, wyksztalcenieZalozyciela;
        int majatekZalozyciela;
        Zalozyciel(string imie, string nazwisko, string dataUrodzenia, string miejsceZamieszkaniaZalozyciela, string miejsceUrodzenia, int majatek, string wyksztalcenie)
        {
            this->imie=imie;
            this->nazwisko=nazwisko;
            this->dataUrodzenia=dataUrodzenia;
            this->miejsceZamieszkaniaZalozyciela=miejsceZamieszkaniaZalozyciela;
            this->miejsceUrodzenia=miejsceUrodzenia;
            this->majatekZalozyciela=majatek;
            this->wyksztalcenieZalozyciela=wyksztalcenie;
        }
        string miejsceZamieszkaniaZalozyciela, miejsceUrodzenia;
    private:
        void daneOsobowe()
        {
            cout<<"\nImie: "<<this->imie<<", nazwisko: "<<this->nazwisko;
        }
        void miejsceZamieszkania()
        {
            this->daneOsobowe();
            cout<<", zamieszkaly w: "<<this->miejsceZamieszkaniaZalozyciela;

        }
    public:
        void majatek()
        {
            this->daneOsobowe();
            cout<<", posiada majatek= "<<this->majatekZalozyciela;
        }
        void dataIMiejsceUrodzenia()
        {
            cout<<"\nData: "<<this->dataUrodzenia<<", urodzony w "<<this->miejsceUrodzenia;
        }
        void wyksztalcenie()
        {
            this->daneOsobowe();
            cout<<", "<<this->wyksztalcenieZalozyciela;
        }
};
class Marka : public Biuro
{
    public:
    
        string nazwaMarki;
        int rokUtworzenia, liczbaPracownikowSklepu;
        friend class Sklep;
        Biuro *biuroM;
        Marka(string nazwaMarki, string wlasciciel, int liczbaSklepowMarki, int rokUtworzenia, int liczbaPracownikowSklepu, string miastoM, string krajM, string prezesM, int pracownicy, string ulicaM, int numerTel) : Biuro(miastoM, krajM, prezesM, pracownicy, ulicaM, numerTel)
        {
            this->nazwaMarki=nazwaMarki;
            this->wlasciciel=wlasciciel;
            this->liczbaSklepowMarki=liczbaSklepowMarki;
            this->rokUtworzenia=rokUtworzenia;
            this->liczbaPracownikowSklepu=liczbaPracownikowSklepu;
        }
        void InfoMarki()
        {
            cout<<"\nMarka sklepow "<<this->nazwaMarki<<", zostala utworzona w "<<this->rokUtworzenia<<" przez "<<this->wlasciciel<<". Jej ";
            biuroM->infoOPolozeniuBiura();
            cout<<"\nOraz\nMarka sklepow "<<this->nazwaMarki<<", zostala utworzona w "<<this->rokUtworzenia<<" przez "<<this->wlasciciel<<". Jej Biuro znajduje sie w "<<this->miastoM<<" w "<<this->krajM<<", na ulicy "<<this->ulicaM;
        }
        void wypiszWlasc(Zalozyciel *zalozyciel)
        {
            zalozyciel->daneOsobowe();
        }
        void nowiPracownicy()
        {
            int value;
            cout<<"\nPodaj liczbe nowych pracownikow Sklepu: ";
            cin>>value;
            liczbaPracownikowSklepu+=value;
        }
        void pracownicyZwolnieni()
        {
            int value;
            cout<<"\nPodaj liczbe zwolnionych pracownikow sklepu: ";
            cin>>value;
            liczbaPracownikowSklepu-=value;
        }
        friend class Zalozyciel;
    private:
        string wlasciciel;
        int liczbaSklepowMarki;
    ~Marka()
    {
        cout<<"\nNie ma już takiej Marki\n";
    }

};
class HistoriaMarki
{
    public:
        Marka *markaHi;
        string historia;
        
        HistoriaMarki(Marka *marka, string historia)
        {
            markaHi=marka;
            this->historia=historia;
        }
        friend void wypisanieHistorii(HistoriaMarki &);
};

void wypisanieHistorii(HistoriaMarki &hiMark)
{
    cout<<"\nHistoria Marki "<<hiMark.markaHi->nazwaMarki<<": "<<hiMark.historia;

}

class Sklep
{
    public:
        string nazwaMarki;
        string nazwaSklepu;
        Galeria *gal;
        Marka *markaSk;
        Sklep(Galeria *galeria, Marka *marka, string nazwaMiejscaSklepu, int numerPietra)
        {
            markaSk=marka;
            this->nazwaSklepu=marka->nazwaMarki;
            this->nazwaMiejscSklepu=nazwaMiejscaSklepu;
            this->numerPietra=numerPietra;
            gal=galeria;
            gal->NowySklepWGalerii();
        }
        void InfoGalerii(Galeria *galeria)
        {
            infoGalerii(*galeria);
        }
        void infoSklepu()
        {
            cout<<"\nSklep "<<markaSk->nazwaMarki<<" znajduje się w miescie "<<gal->miastoGal->nazwaMiasta<<", w galerii "<<gal->nazwa<<" na "<<this->numerPietra<<" piętrze";
        }
    private:
        int numerPietra;
        string nazwaMiejscSklepu;
    ~Sklep()
    {
        cout<<"\nNie ma już takiego Sklepu\n";
    }
};
class Dzial : public InformacjeProduktu
{
    public:
        string nazwaDzialu;
        Sklep *sklep;
        Dzial(Sklep *sklep, string nazwaDzialu)
        {
            sklep=sklep;
            this->nazwaDzialu=nazwaDzialu;
        }
        
        void wypiszDzial()
        {
            cout<<"\nDzial to: "<<this->nazwaDzialu;
        }
        void pelneInformacje()
        {
            cout<<"\nInformacje o produkcie:\n"<<"Dzial: "<<this->nazwaDzialu;
        }
        
        ~Dzial()
        {
            cout<<"\nNie ma już takiego dzialu\n";
        }
};
class Kategoria : public Dzial
{
    public:
        string nazwaKategorii;
        Kategoria(Sklep *sklep, string nazwaKategorii, string nazwaDzialu) : Dzial(sklep, nazwaDzialu)
        {
            this->nazwaDzialu=nazwaDzialu;
            this->nazwaKategorii=nazwaKategorii;
        }
        
        void wypiszDzial()
        {
            cout<<"\nDzial to: "<<this->nazwaDzialu;
        }
        void wypiszKategorie()
        {
            cout<<"\nKategoria to: "<<this->nazwaKategorii;
        }
        void pelneInformacje()
        {
            cout<<"\nInformacje o produkcie:\n"<<"Dzial: "<<this->nazwaDzialu<<"\nKategoria: "<<this->nazwaKategorii;
        }
        
    ~Kategoria()
    {
        cout<<"\nNie ma już takiej Kategorii\n";
    }
};
class Rodzaj : public Kategoria
{
    public:
        string nazwaRodzaju;
        Rodzaj(Sklep *sklep, string nazwaRodzaju, string nazwaDzialu, string nazwaKategorii) : Kategoria(sklep, nazwaKategorii, nazwaDzialu)
        {
            this->nazwaRodzaju=nazwaRodzaju;
            this->nazwaKategorii=nazwaKategorii;
        }
        
        void wypiszDzial()
        {
            cout<<"\nDzial to: "<<this->nazwaDzialu;
        }
        void wypiszKategorie()
        {
            cout<<"\nKategoria to: "<<this->nazwaKategorii;
        }
        void wypiszRodzaj()
        {
            cout<<"\nRodzaj: "<<this->nazwaRodzaju;
        }
        void pelneInformacje()
        {
            cout<<"\nInformacje o produkcie:\n"<<"Dzial: "<<this->nazwaDzialu<<"\nKategoria: "<<this->nazwaKategorii<<"\nRodzaj: "<<this->nazwaRodzaju;
        }
        
    ~Rodzaj()
    {
        cout<<"\nNie ma już takiego rodzaju\n";
    }
};
class Model : public Rodzaj
{
    public:
        string nazwaModelu;
        Model(Sklep *sklep, string nazwaModelu, string nazwaRodzaju, string nazwaKategorii, string nazwaDzialu) : Rodzaj(sklep, nazwaRodzaju, nazwaDzialu, nazwaKategorii)
        {
            this->nazwaDzialu=nazwaDzialu;
            this->nazwaKategorii=nazwaKategorii;
            this->nazwaRodzaju=nazwaRodzaju;
            this->nazwaModelu=nazwaModelu;
        }
        
        void wypiszDzial()
        {
            cout<<"\nDzial to: "<<this->nazwaDzialu;
        }
        void wypiszKategorie()
        {
            cout<<"\nKategoria to: "<<this->nazwaKategorii;
        }
        void wypiszRodzaj()
        {
            cout<<"\nRodzaj: "<<this->nazwaRodzaju;
        }
        void wypiszModel()
        {
            cout<<"\nModel: "<<this->nazwaModelu;
        }
        void pelneInformacje()
        {
            cout<<"\nInformacje o produkcie:\n"<<"Dzial: "<<this->nazwaDzialu<<"\nKategoria: "<<this->nazwaKategorii<<"\nRodzaj: "<<this->nazwaRodzaju<<"\nModel: "<<this->nazwaModelu;
        }
        
    ~Model()
    {
        cout<<"\nNie ma już takiego modelu\n";
    }
};
class Rozmiar : public Model
{
    public:
        string nazwaRozmiaru;
        Rozmiar(Sklep *sklep, string nazwaRozmiaru, string nazwaDzialu, string nazwaKategorii, string nazwaRodzaju, string nazwaModelu):Model(sklep, nazwaModelu, nazwaRodzaju, nazwaKategorii, nazwaDzialu)
        {
            this->nazwaDzialu=nazwaDzialu;
            this->nazwaKategorii=nazwaKategorii;
            this->nazwaRodzaju=nazwaRodzaju;
            this->nazwaModelu=nazwaModelu;
            this->nazwaRozmiaru=nazwaRozmiaru;
        }
        
        void wypiszDzial()
        {
            cout<<"\nDzial to: "<<this->nazwaDzialu;
        }
        void wypiszKategorie()
        {
            cout<<"\nKategoria to: "<<this->nazwaKategorii;
        }
        void wypiszRodzaj()
        {
            cout<<"\nRodzaj: "<<this->nazwaRodzaju;
        }
        void wypiszModel()
        {
            cout<<"\nModel: "<<this->nazwaModelu;
        }
        void wypiszRozmiar()
        {
            cout<<"\nRozmiar: "<<this->nazwaRozmiaru;
        }
        void pelneInformacje()
        {
            cout<<"\nInformacje o produkcie:\n"<<"Dzial: "<<this->nazwaDzialu<<"\nKategoria: "<<this->nazwaKategorii<<"\nRodzaj: "<<this->nazwaRodzaju<<"\nModel: "<<this->nazwaModelu<<"\nRozmiar: "<<this->nazwaRozmiaru;
        }
        
    ~Rozmiar()
    {
        cout<<"\nNie ma już takiego rozmiaru\n";
    }
};
class Material
{
    public:
        string  pochodzenie;
        Rozmiar *rozmiarU;
        Material(Rozmiar *rozmiar, string nazwa, int ilosc, string pochodzenie)
        {
            rozmiarU=rozmiar;
            pochodzenie=pochodzenie;
            iloscMaterialu=ilosc;
            nazwaMaterialu=nazwa;
        }
        void wypiszMaterial()
        {
            cout<<"\nprodukt"<<rozmiarU->nazwaRodzaju<<" "<<rozmiarU->nazwaModelu<<" jest z "<<nazwaMaterialu<<"i potrzeba do wykoanania go "<<iloscMaterialu<<" i pochodzi z "<<pochodzenie;
        }
    private:
        int iloscMaterialu;
        string nazwaMaterialu;
    

};
class Kolor
{
    public:
        string nazwaKoloru;
        Rozmiar *rozmiarU;
        Kolor(Rozmiar *rozmiar, string nazwa)
        {
            rozmiarU=rozmiar;
            nazwaKoloru=nazwa;
        }
    friend class Status;
};
class Status
{
    public:
        Kolor *kolorU;
        Status(Kolor *kolor, string status)
        {
            kolorU=kolor;
            this->status=status;
        }
        friend void informacjeOStatucie(Status &);
    private:
        string status;
        void zmienStatus(Status *status, string zmiana)
        {
            cout<<"\nPodaj nowy status "<<status->kolorU->rozmiarU->nazwaRodzaju<<" "<<status->kolorU->rozmiarU->nazwaModelu<<", w kolorze "<<status->kolorU->nazwaKoloru<<": ";
            cin>>zmiana;
            status->status=zmiana;
        }
    friend class Cena;
    
};
void informacjeOStatucie(Status &status)
{
   cout<<"\n"<<status.kolorU->rozmiarU->nazwaRodzaju<<" "<<status.kolorU->rozmiarU->nazwaModelu<<", w kolorze "<<status.kolorU->nazwaKoloru<<", ma status: "<<status.status;
}
class Cena
{
    public:
        float cena;
        string waluta;
        Status *statusU;
        Cena(Status *status, float cena, string waluta)
        {
            this->cena=cena;
            waluta=waluta;
            statusU=status;
        }
        void ustawPromocje(Status *status)
        {
            this->statusU->zmienStatus(status, "promocja");
            cout<<"Nowa cena: ";
            float cenaPromo;
            cin>>cenaPromo;
            this->cena=cenaPromo;
        }
        void wypiszStatus(Cena &cena)
        {
            cout<<cena.statusU->status;
        }
        void operator+=(float value)
        {
            cena+=value;
        }
        void operator-=(float value)
        {
            cena-=value;

        }
        void operator*=(int value)
        {
            cena*=value;
        }
        friend void infoOProdukcie(Cena &);
};
void infoOProdukcie(Cena &cena)
{
    cout<<"\n"<<cena.statusU->kolorU->rozmiarU->nazwaRodzaju<<" "<<cena.statusU->kolorU->rozmiarU->nazwaModelu<<" w kolorze "<<cena.statusU->kolorU->nazwaKoloru<<" kosztuje: "<<cena.cena;
}

int main()
{
    //powolanie obiektow dwoch miast
    Miasto *warszawa= new Miasto("Polska", "Mazowieckie", "Warszawa", " stolica Polski i województwa mazowieckiego, największe miasto w kraju, położone w jego centralnej części[6], na Nizinie Środkowomazowieckiej, na Mazowszu, nad Wisłą.", 1765000, 1262);
    Miasto *poznan=new Miasto("Polska", "Wielkopolskie", "Poznań", "miasto na prawach powiatu w zachodniej Polsce, położone na Pojezierzu Wielkopolskim, nad rzeką Wartą, u ujścia Cybiny. Historyczna stolica Wielkopolski, od 1999 r. siedziba władz województwa wielkopolskiego i powiatu poznańskiego.", 546859, 1253);
    //sprawdzenie liczby galerii w nich przed dodaniem
    ileGalerii(*warszawa);
    ileGalerii(*poznan);
    //Dodanie 3 galerii
    Galeria *arkadia= new Galeria(warszawa, "Arkadia", "al. Jana Pawła II", 82, "Kowalski Jan");
    Galeria *zloteTarasy=new Galeria(warszawa, "Złote Tarasy", "Złota", 59, "Michalska Joanna");
    Galeria *malta=new Galeria(poznan, "Malta", "Maltańska", 1, "Kostrzewski Michał");

    //sprawdzenie liczby galerii w danym miescie
    ileGalerii(*warszawa);
    ileGalerii(*poznan);

    //wypisanie informacji o galerii
    infoGalerii(*malta);
    infoGalerii(*zloteTarasy);
    cout<<"\n"<<zloteTarasy->nazwa;
    delete zloteTarasy;
    //powolanie obiektow biura firmy nike
    Biuro *nikeBiuro=new Biuro("Nowy Jork", "USA", "John Donahoe", 4321, "abc", 123456789);
    //powolanie obiektu marki
    Marka *nike=new Marka("Nike", "Phil Knight", 1000, 1990, 35, "Waszyngton", "USA", "ja", 32, "def", 987654321);
    //przypisanie biura marki do biura
    nike->biuroM=nikeBiuro;
    //sprawdzenie informacji o marce
    nike->InfoMarki();
    //powolanie sklepu marki
    Sklep *nikeArkadia=new Sklep(arkadia, nike, "A3", 1);
    Sklep *nikeMalta=new Sklep(malta, nike, "G4", 3);
    //sprawdzenie informacji o sklepie
    nikeArkadia->infoSklepu();
    //sprawdzenie liczby sklepow w galerii po dodaniu jednego
    arkadia->LiczbaSklepow();
    
    //sprawdzenie dzialania przeciazonego operatora dodajacego sklepy w galerii
    *malta+=5;
    malta->LiczbaSklepow();
    //powolanie obiektu rozmiaru ktory jest powiazany hierarchia dziedziczenia
    Rozmiar *r1=new Rozmiar(nikeArkadia, "M", "Męski", "Odzież", "Bluza", "Tech fleece" );
    Rozmiar *r2=new Rozmiar(nikeArkadia, "L", "Męski", "Obuwie", "Sneakerse", "air force 1");
    Rozmiar *r3=new Rozmiar(nikeMalta, "S", "Damski", "Akcesoria", "Skarpety", "long");
    //powolanie obiektu materialu dla danego obiektu artykulu
    Material *m1=new Material(r1, "poliester", 1000, "Chiny");
    Material *m2=new Material(r2, "skóra", 2189, "Bangladesz");
    Material *m3=new Material(r3, "Bawełna", 250, "USA");
    //powolanie koloru artuykulu
    Kolor *RedR1 =new Kolor(r1, "Czerwony");
    Kolor *Br2 = new Kolor(r2, "Biały");
    Kolor *Br3=new Kolor(r3, "Białe");
    //powolanie w jakim statusie znajduje sie artykul w sklepie
    Status *SRr1=new Status(RedR1, "Promocja");
    Status *SRr2=new Status(Br2, "Na stanie");
    Status *SRr3=new Status(Br3, "Wyprzedane");
    //sprawdzenie informacji o statusie
    informacjeOStatucie(*SRr1);
    //powolanie ceny artykulu
    Cena *CSRr1=new Cena(SRr1, 75.99, "dolar");
    Cena *CSRr2=new Cena(SRr1, 599.99, "złoty");
    Cena *CSRr3=new Cena(SRr3, 49.99, "złoty");
    //sprawdzenie informacji o produkcie
    infoOProdukcie(*CSRr1);
    //ustawienie promocji na artykul
    CSRr1->ustawPromocje(SRr1);
    //sprawdzenie informacji po wprowadzeniu promocji
    infoOProdukcie(*CSRr1);
    //sprawdzenie dzialania przeciazonych operatorow dla ceny artykulu
    *CSRr1+=4.05;
    infoOProdukcie(*CSRr1);
    *CSRr1-=15.99;
    infoOProdukcie(*CSRr1);
    *CSRr1*=2;
    infoOProdukcie(*CSRr1);
    //powolanie historii marki i wypisanie jej
    HistoriaMarki *hm1=new HistoriaMarki(nike, "jakas historia");

    wypisanieHistorii(*hm1);
    //wprowadzenie informacji o zalozycielu marki i wypisanie ich
    Zalozyciel *z1=new Zalozyciel("Philip", "Knight", "3.10.2022", "Hilsboro", "Portland", 214124, "jest absolwentem University of Oregon i Stanford Graduate School of Business .");
    nike->wypiszWlasc(z1);
    //wypisanie pelnych informacji o produkcie
    r1->pelneInformacje();
    return 0;
}