#include <iostream>
#include "kolejka.h"
#include "kolejka.cpp"


void menu(kolejka &x,kolejka &y)
{
    int wybor=0;
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
    cout << "12. Zakoncz dzialanie programu" << endl;

    while(wybor!=12)
    {
        cout << "PODAJ WYBOR: ";
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
                if(kolejka=='x' && !x.czy_pusta()) cout << "Pobrana liczba to: " << x.pobierz() << endl; //jezeli wybrano kolejke x i nie jest ona pusta
                else if(kolejka=='y' && !y.czy_pusta()) cout << "Pobrana liczba to: " << y.pobierz() << endl; //jezeli wybrano y i nie jest ona pusta
                else if(kolejka=='x' || kolejka=='y') cout << "Kolejka jest pusta." << endl;
                else cout << "Taka kolejka nie istnieje." << endl;
                break;
                }

            case 4: {
                cout << "Aktualny rozmiar kolejki x to: " << x.podaj_rozmiar() << " a kolejki y: " << y.podaj_rozmiar() << endl;
                break;
                }

            case 5:  {
                cout << "Kolejka x ";
                if (x.czy_pelna()) cout << "jest pelna" << endl;
                else cout << "nie jest pelna" << endl;

                cout << "Kolejka y ";
                if (y.czy_pelna()) cout << "jest pelna" << endl;
                else cout << "nie jest pelna" << endl;

                break;
                }

            case 6:  {
                cout << "Kolejka x ";
                if (x.czy_pusta()) cout << "jest pusta" << endl;
                else cout << "nie jest pusta" << endl;

                cout << "Kolejka y ";
                if (y.czy_pusta()) cout << "jest pusta" << endl;
                else cout << "nie jest pusta" << endl;

                break;
                }

            case 7: {
                class kolejka z(0);
                z=x+y;
                cout << "Utworzono nowa kolejke: ";
                cout << z; //wypisywanie nowoutworzonej kolejki

                break;
            }

            case 8: {
                x+=y;
                cout << "Dodano kolejke y do kolejki x, nowa kolejka x to: ";
                cout << x;

                break;
            }

            case 9: {
                if (x==y) cout << "Kolejki x i y sa takie same." << endl;
                else cout << "Kolejki x i y nie sa takie same." << endl;
                break;
            }

            case 10: {
                if (x!=y) cout << "Kolejki x i y sa rozne." << endl;
                else cout << "Kolejki x i y nie sa rozne." << endl;
                break;
            }

            case 11: {
                cout << "Kolejka x: ";
                cout << x;
                cout << "Kolejka y: ";
                cout << y;
                break;

            }

            case 12: break;

            default: cout << "Bledna liczba" << endl;      //jesli podano dowolny inny znak
        }
    }
}



int main()
{
    int rozm_x, rozm_y;
    cout << "Podaj rozmiar kolejek x i y: ";
    cin >> rozm_x >> rozm_y;
    kolejka x(rozm_x); //tworzenie kolejki x o podanym rozmiarze
    kolejka y(rozm_y); //tworzenie kolejki y o podanym rozmiarze

    menu(x, y); //wywolanie menu

    return 0;
}
