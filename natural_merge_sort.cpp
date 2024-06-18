//============================================================================
//                  Algorytmy i Struktury Danych
// Zadanie 11.2
// Natural merge sort
//
//============================================================================

#include <iostream>
#include <fstream>
#include <algorithm>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

using namespace std;

//DEKLARACJA FUNKCJI KTORE BEDA UZYWANE
void Zmiana(int *zmien);
void Zapis();
void PolaczSerie(char *nazwapliku2);
void naturalny(char *nazwapliku2);
int Czyposortowany();

//ZMIENNE GLOBALNE DLA PLIKOW
FILE *wejscie;
FILE *pomocniczy[2];
FILE *wyjscie;

//MAIN
int main()
{
	char nazwapliku[50];
	char nazwapliku2[50];
	int liczba, licznik = 1;
    cout << "Podaj nazwe pliku do odczytu danych (koniecznie wraz z rozszerzeniem)." << endl;
    cin >> nazwapliku;
    wejscie = fopen(nazwapliku, "rt");
    if(wejscie == NULL)
	{
		cout << "Nie otworzono pliku. Sprobuj ponownie." << endl;
		return 0;
	}
	
	cout << "Podaj nazwe pliku do zapisu (koniecznie wraz z rozszerzeniem)." << endl;
    cin >> nazwapliku2;
    cout << endl;
    
    pomocniczy[0] = fopen("temp1.txt", "w+t");
    pomocniczy[1] = fopen("temp2.txt", "w+t");
    wyjscie = fopen(nazwapliku2, "w+t");

    cout << "Pobrane liczby z pliku wejsciowego:" << endl;
    while(fscanf(wejscie, "%d", &liczba) > 0)
	{
		cout << liczba << " ";
		if(licznik % 10 == 0)
		{
			cout << endl;
		}
        fprintf(wyjscie, "%d\n", liczba);
        licznik++;
    }
    
    rewind(wyjscie);
    naturalny(nazwapliku2);
    
    licznik = 1;
    cout << endl << "Dane z pliku po posortowaniu:" << endl;
	while(fscanf(wyjscie, "%d", &liczba) > 0)
	{
		cout << liczba << " ";
		if(licznik % 10 == 0)
		{
			cout << endl;
		}
		licznik++;
    }
    cout << endl << "Dane zostaly zapisane do pliku o nazwie '" << nazwapliku2 << "'." << endl;
    
    fclose(wejscie);
    fclose(wyjscie);
    fclose(pomocniczy[0]);
    fclose(pomocniczy[1]);
    remove("temp1.txt");
    remove("temp2.txt");
    return 0;
}

//WARUNEK ZMIANY NA KTORYM PLIKU POMOCNICZYM FUNKCJA BEDZIE SIE OPIERAC
void Zmiana(int *zmien)
{
    *zmien = (*zmien == 0) ? 1 : 0 ;
}

//FUNCKJA W CELU ZAPISU DANYCH DO PLIKU
void Zapis()
{
    freopen("temp1.txt", "w+t", pomocniczy[0]);
    freopen("temp2.txt", "w+t", pomocniczy[1]);
    int liczba;
    int zmien = 0;
    int najmniejszy = INT_MIN;
    while(fscanf(wyjscie, "%d", &liczba)>0)
	{
        if(liczba < najmniejszy) Zmiana(&zmien);
        fprintf(pomocniczy[zmien], "%d\n", liczba);
        najmniejszy = liczba;
    }
    rewind(pomocniczy[0]);
    rewind(pomocniczy[1]);
}

//FUNKCJA ABY LACZYC SERIE Z DANEGO PLIKU
void PolaczSerie(char *nazwapliku2)
{
    freopen(nazwapliku2, "w+t", wyjscie);
    int liczba0, liczba1;
    int plik1wartosc = fscanf(pomocniczy[0], "%d", &liczba0);
    int plik2wartosc = fscanf(pomocniczy[1], "%d", &liczba1);

    while(plik1wartosc > 0 && plik2wartosc > 0)
	{
        if(liczba0 <= liczba1)
		{
            fprintf(wyjscie, "%d\n", liczba0);
            plik1wartosc = fscanf(pomocniczy[0], "%d", &liczba0);
        }
        else
		{
            fprintf(wyjscie, "%d\n", liczba1);
            plik2wartosc = fscanf(pomocniczy[1], "%d", &liczba1);
        }
    }

    while(plik1wartosc > 0)
	{
        fprintf(wyjscie, "%d\n", liczba0);
        plik1wartosc = fscanf(pomocniczy[0], "%d", &liczba0);
    }
    
    while(plik2wartosc > 0)
	{
        fprintf(wyjscie, "%d\n", liczba1);
        plik2wartosc = fscanf(pomocniczy[1], "%d", &liczba1);
    }
    rewind(wyjscie);
}

//FUNKCJA SPRAWDZA CZY PLIK JEST POSORTOWANY POPRAWNIE
int Czyposortowany()
{
    int liczba;
    int najmniejszy = INT_MIN;
    while (fscanf(wyjscie, "%d", &liczba) > 0)
    {
        if (liczba < najmniejszy)
		{
            rewind(wyjscie);
            return 0;
        }
        najmniejszy = liczba;
    }
    rewind(wyjscie);
    return 1;
}

//GLOWNA FUNKCJA W CELU SORTOWANIA METODA LACZENIA NATURALNEGO
void naturalny(char *nazwapliku2)
{
    int wskaznikPosortowania = Czyposortowany();
    while(!wskaznikPosortowania)
	{
        Zapis();
        PolaczSerie(nazwapliku2);
        wskaznikPosortowania = Czyposortowany();
    }
}
