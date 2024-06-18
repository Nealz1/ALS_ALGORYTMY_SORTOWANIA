//============================================================================
//                  Algorytmy i Struktury Danych
// Zadanie 10.4
// Radix sort
//
//  WCY21IX4S0  Miksiewicz Pawel
//============================================================================

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

//FUNKCJA NA RADIX SORT
void radixSort(int tablica[], int n) 
{
    int max = tablica[0];
    for (int i = 1; i < n; i++) 
	{
        if (tablica[i] > max) 
		{
            max = tablica[i];
        }
    }
    for (int exp = 1; max/exp > 0; exp *= 10) 
	{
        int licznik[10] = {0};
        for (int i = 0; i < n; i++) 
		{
            licznik[(tablica[i]/exp) % 10]++;
        }
        for (int i = 1; i < 10; i++) 
		{
            licznik[i] += licznik[i - 1];
        }
        int wynik[n];
        for (int i = n - 1; i >= 0; i--)
		{
            wynik[licznik[(tablica[i]/exp) % 10] - 1] = tablica[i];
            licznik[(tablica[i]/exp) % 10]--;
        }
        for (int i = 0; i < n; i++) 
		{
            tablica[i] = wynik[i];
        }
    }
}

//FUNKCJA NA LOSOWANIE LICZBY Z PRZEDZIALU <a;b>
int LosowanieLiczb(int a, int b)
{
    int losowa;
	if(a<b) //SPRAWDZANIE ABY A BYLO MNIEJSZE OD B, ZEBY POPRAWNIE WYKONAC ZAKRES <a;b>
	{
    	losowa = (rand() % (b - a + 1)) + a;
	}
	else if(a>b) //IF DLA PRZYPADKU A>B, WTEDY ZOSTAJE ZAMIENIANA WARTOSC PRZEDZIALU tzn. TRAKTUJEMY PRZEDZIAL <b;a>
	{
    	losowa = (rand() % (a - b + 1)) + b;
	}	
	return losowa;
}

//FUNKCJA NA WYPISANIE LICZB DO KONSOLI
void Wypisz(int n, int tab[])
{
    for (int i = 0; i < n; i++)
    {
        cout << tab[i] << " ";
        if ((i + 1) % 10 == 0)
        {
        	cout << endl;
		}
    }
}

int main()
{
    srand(time(0));
    int n;
    
    cout << "Podaj ilosc elementow do losowego wygenerowania:" << endl;
    cin >> n;
    int tablica[n];
    
    int a,b;
    cout << "Podaj przedzial liczbowy z ktorego chcesz losowac liczby <a;b>:" << endl;
    cin >> a >> b;
    
    for(int i=0; i<n; i++)
    {
        tablica[i] = LosowanieLiczb(a,b);
    }

    cout << endl << "Wygenerowane liczby:" << endl;
    Wypisz(n, tablica);
    radixSort(tablica, n);
    
    cout << endl << "Wygenerowane posortowane liczby:" << endl;
    Wypisz(n, tablica);

	//ZAPIS DANYCH DO PLIKU
	ofstream plik;
	plik.open("wynik4.txt");
	for(int i = 0; i<n; i++)
	{
		plik << tablica[i] << " ";
		if ((i + 1) % 10 == 0)
        {
        	plik << endl;
		}
	}
	plik.close();
	cout << endl << "Plik zostal zapisany o nazwie 'wynik4.txt'" << endl;
	
    return 0;
}
