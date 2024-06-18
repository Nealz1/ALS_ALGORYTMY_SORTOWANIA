//============================================================================
//                  Algorytmy i Struktury Danych
// Zadanie 10.2
// Counting sort
//
//============================================================================

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

//FUNCKJA NA SZUKANIE MAX LICZBY W TABLICY
int SzukajMax(int tablica[], int n) 
{
    int max = tablica[0];
    for (int i = 1; i < n; i++) 
	{
        if (tablica[i] > max) 
		{
            max = tablica[i];
        }
    }
    return max;
}

//FUNKCJA NA COUNTING SORT
void countingSort(int tablica[], int n, int max) 
{
    int licznik[max + 1];
    for (int i = 0; i <= max; i++) 
	{
        licznik[i] = 0;
    }
    for (int i = 0; i < n; i++) 
	{
        licznik[tablica[i]]++;
    }
    int k = 0;
    for (int i = 0; i <= max; i++) 
	{
        for (int j = 0; j < licznik[i]; j++) 
		{
            tablica[k++] = i;
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
    
    int max; 
	max = SzukajMax(tablica, n);
    
    cout << endl << "Wygenerowane liczby:" << endl;
    Wypisz(n, tablica);
    countingSort(tablica, n, max);
    
    cout << endl << "Wygenerowane posortowane liczby:" << endl;
    Wypisz(n, tablica);
    
    //ZAPIS DANYCH DO PLIKU
	ofstream plik;
	plik.open("wynik2.txt");
	for(int i = 0; i<n; i++)
	{
		plik << tablica[i] << " ";
		if ((i + 1) % 10 == 0)
        {
        	plik << endl;
		}
	}
	plik.close();
	cout << endl << "Plik zostal zapisany o nazwie 'wynik2.txt'" << endl;
	
    return 0;
}
