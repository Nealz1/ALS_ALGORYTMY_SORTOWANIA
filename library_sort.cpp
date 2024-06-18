//============================================================================
//                  Algorytmy i Struktury Danych
// Zadanie 9.2
//  Library Sort
//
//============================================================================

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

//FUNKCJA NA LIBRARY SORT
void BibliotecznySort(int tablica[], int n)
{
    int min = tablica[0];
    int max = tablica[0];
    
    //SZUKANIE MIN I MAXA
    for (int i = 1; i < n; i++)
    {
        if (tablica[i] < min)
        {
        	min = tablica[i];
		}
        if (tablica[i] > max)
        {
        	max = tablica[i];	
		}
    }
    
    int zakres = max - min + 1;
    int temp[zakres];
    for (int i = 0; i < zakres; i++)
    {
    	temp[i] = 0;	
	}
        
    for (int i = 0; i < n; i++)
    {
    	temp[tablica[i] - min]++;
	}
    int index = 0;
    for (int i = 0; i < zakres; i++)
    {
    	for (int j = 0; j < temp[i]; j++)
    	{
    		tablica[index++] = i + min;
		}    
	}
}

//FUNKCJA NA GENEROWANIE LICZB
void GenerujLosowe(int n, int tab[], int a, int b)
{
    srand(time(0));
    
    if(a<b) //SPRAWDZANIE ABY A BYLO MNIEJSZE OD B, ZEBY POPRAWNIE WYKONAC ZAKRES <a;b>
	{
    	for (int i = 0; i < n; i++)
    	{
    		tab[i] = (rand() % (b - a + 1)) + a;
		}
	}
	else if(a>b) //IF DLA PRZYPADKU A>B, WTEDY ZOSTAJE ZAMIENIANA WARTOSC PRZEDZIALU tzn. TRAKTUJEMY PRZEDZIAL <b;a>
	{
    	for (int i = 0; i < n; i++)
    	{
    		tab[i] = (rand() % (a - b + 1)) + b;
		}
	}
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

//MAIN
int main()
{
	int n;
    cout << "Podaj ilosc elementow do losowego wygenerowania:" << endl;
    cin >> n;
    int tablica[n];
    
    int a,b;
    cout << "Podaj przedzial liczbowy z ktorego chcesz losowac liczby <a;b>:" << endl;
    cin >> a >> b;
    GenerujLosowe(n, tablica, a, b);	

    cout << "Wygenerowane liczby:" << endl;
    Wypisz(n, tablica);

    cout << endl << "Wygenerowane posortowane liczby:" << endl;
    BibliotecznySort(tablica, n);
    Wypisz(n, tablica);
	
	//ZAPIS DANYCH DO PLIKU
   	ofstream plik;
	plik.open("wynik2.txt");
	for(int i = 0; i<n; i++)
	{
		plik << tablica[i] << endl;
	}
	plik.close();
	cout << endl << "Plik zostal zapisany o nazwie 'wynik2.txt'" << endl;
	
    return 0;
}
