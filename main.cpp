#include <iostream>

using namespace std;

class kolejka {
private:

    int id_pierwszy=0;
    int l_el=0;
    int max_l_el;

public:

    float * element;


    kolejka(int max_rozmiar)
    {
        element= new float[max_rozmiar];
        max_l_el=max_rozmiar;
    }

    int podaj_rozmiar (void);
    float pobierz (void);
    int czy_pusta (void);
    int czy_pelna (void);
    void dodaj_nadpisz (float);
    void dodaj_bez_nadpisu (float);

    kolejka operator+(kolejka&);
    void operator+=(kolejka&);
    bool operator==(kolejka&);
    bool operator!=(kolejka&);
    friend ostream& operator<<(ostream&, kolejka&);



};


    ostream& operator<< (ostream &wyjscie, kolejka &x)
    {
        for (int i=0; i<x.l_el; i++)
        {
            wyjscie << x.element[(x.id_pierwszy+i)%x.max_l_el] << " ";
        }
         wyjscie << endl;
        return wyjscie;
    }


    kolejka kolejka::operator+(kolejka &kol2)
    {
        class kolejka nowa_kolejka(max_l_el+kol2.max_l_el);
        for(int i=0; i<l_el; i++) nowa_kolejka.dodaj_nadpisz(element[(id_pierwszy+i)%max_l_el]);
        for(int i=0; i<kol2.l_el; i++) nowa_kolejka.dodaj_nadpisz(kol2.element[(kol2.id_pierwszy+i)%kol2.max_l_el]);
        return nowa_kolejka;
    }

    bool kolejka::operator==(kolejka &kol2)
    {
        if(l_el!=kol2.l_el) return false;
        for (int i=0; i<l_el; i++)
        {
            if(element[i]!=kol2.element[i]) return false;
        }
        return true;
    }

    bool kolejka::operator!=(kolejka& kol2)
    {
        return !(operator==(kol2));
    }

    void kolejka::operator+=(kolejka &kol2)
    {

        int tmp_l_el=l_el;
        float tmp[l_el];
        for(int i=0; i<l_el; i++) tmp[i]=element[(id_pierwszy+i)%max_l_el];

        element= new float[max_l_el+kol2.max_l_el];
        max_l_el+=kol2.max_l_el;
        l_el=0;

        for(int i=0; i<tmp_l_el; i++) dodaj_bez_nadpisu(tmp[i]);
        for(int i=0; i<kol2.l_el; i++) dodaj_bez_nadpisu(kol2.element[(kol2.id_pierwszy+i)%kol2.max_l_el]);

    }



    int kolejka::podaj_rozmiar (void)
    {
        return l_el;
    }

    int kolejka::czy_pusta (void)
    {
        return l_el==0;
    }

    int kolejka::czy_pelna (void)
    {
        return l_el==max_l_el;
    }


    void kolejka::dodaj_nadpisz (float nowy_el)
    {
        element[(id_pierwszy+l_el)%max_l_el]=nowy_el;
        if(!czy_pelna()) l_el++;
        else id_pierwszy=(id_pierwszy+1)%max_l_el;
    }

    void kolejka::dodaj_bez_nadpisu (float nowy_el)
    {
        if(!czy_pelna())
        {
            element[(id_pierwszy+l_el)%max_l_el]=nowy_el;
            l_el++;
        }
        else cout << "Brak mozliwosci dodania kolejnego elementu"<<endl;
    }



    float kolejka::pobierz (void)
    {
        float pobrany_element;
        pobrany_element=element[id_pierwszy];
        id_pierwszy=(id_pierwszy+1)%max_l_el;
        l_el--;
        return pobrany_element;
    }


void menu(kolejka &x,kolejka &y){

int wybor=0;
float liczba;
char kolejka;
cout << "WYBIERZ:" << endl << "1. Wstaw element do kolejki x (z nadpisaniem przy przekroczeniu rozmiaru)" << endl;
cout << "2. Wstaw element do kolejki y (z brakiem mozliwosci wstawienia przy przekroczeniu rozmiaru)" << endl;
cout << "3. Pobierz pierwszy element z kolejki" << endl;
cout << "4. Podaj aktualny rozmiar kolejki" << endl;
cout << "5. Sprawdz, czy kolejka jest pelna" << endl;
cout << "6. Sprawdz, czy kolejka jest pusta" << endl;
cout << "7. Utworz nowa kolejke, dodajac kolejki x i y" << endl;
cout << "8. Dodaj kolejke y do kolejki x" << endl;
cout << "9. Porownaj, czy kolejki sa takie same" << endl;
cout << "10. Porownaj, czy kolejki sa rozne" << endl;
cout << "11. Wydrukuj kolejke" << endl;

    while(wybor!=10)
    {
        cin >> wybor;
        switch (wybor)
        {
            case 1: {
                float liczba;
                cout << "Podaj nowy element (liczbe rzeczywista): ";
                cin >> liczba;
                x.dodaj_nadpisz(liczba);
                break;
                }

            case 2: {
                float liczba;
                cout << "Podaj nowy element (liczbe rzeczywista): ";
                cin >> liczba;
                y.dodaj_bez_nadpisu(liczba);
                break;
                }

            case 3: {
                cout << "Wybierz kolejke (x, y): ";
                cin >> kolejka;
                cout << "Pobrana liczba to: ";
                if(kolejka=='x') cout << x.pobierz();
                else if(kolejka=='y') cout << y.pobierz();
                else cout << "Taka kolejka nie istnieje.";
                break;
                }

            case 4: {
                cout << "Aktualny rozmiar kolejki x to: " << x.podaj_rozmiar() << " a kolejki y: " << y.podaj_rozmiar() << endl;
                break;
                }

            case 5:  {


                break;
                }       //konczenie dzialania programu

            default: cout << "Bledna liczba" << endl;                       //jesli podano dowolny inny znak
        }
    }
}



int main()
{
    int rozm_x, rozm_y;
    cout << "Podaj rozmiar kolejek x i y: ";
    cin >> rozm_x >> rozm_y;
    class kolejka x(rozm_x);
    class kolejka y(rozm_y);

    menu(x, y);

    y.dodaj_nadpisz(11);
    y.dodaj_nadpisz(12);
    y.dodaj_nadpisz(13);
    y.dodaj_nadpisz(14);
    y.dodaj_nadpisz(15);
    y.dodaj_nadpisz(16);

    if(x!=y) cout << "dupa" << endl;
    else cout << "niedupa" << endl;

    cout << x.pobierz() << endl << endl;

    cout << "operator<<: ";
    cout << x;





    //cout << y.pobierz() << endl;
    //cout << y.pobierz() << endl;



    x+=y;

    cout << "operator<<: ";
    cout << x;

   cout << x.pobierz() << endl << endl;
   cout << x.pobierz() << endl << endl;

   cout << "operator<<: ";
    cout << x;

   cout << x.pobierz() << endl << endl;
   cout << x.pobierz() << endl << endl;
   cout << x.pobierz() << endl << endl;
   cout << x.pobierz() << endl << endl;

   cout << "operator<<: ";
    cout << x;

   cout << x.pobierz() << endl << endl;
   cout << x.pobierz() << endl << endl;

   cout << "operator<<: ";
    cout << x;



    return 0;
}

