#include <iostream>
#include <fstream>
using namespace std;

const int SIZE = 200;
ifstream in("dane_obrazki.txt");
char tab[21][21];

void readPicture() 
{
    for (int i = 0; i < 21; i++) 
    {
        for (int j = 0; j < 21; j++) 
        {
            if (i == 20 && j == 20) return; in >> tab[i][j];
        }
    }
}

void displayPicture() {
    for (int i = 0; i < 21; i++) 
    {
        for (int j = 0; j < 21; j++) 
        {
            cout << tab[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

bool isRecurent() 
{
    for (int i = 0; i < 10; i++) 
    {
        for (int j = 0; j < 10; j++) 
        {
            if (tab[i][j] != tab[i][j + 10] || tab[i][j] != tab[i + 10][j] || tab[i][j] != tab[i + 10][j + 10]) 
            {
                return false;
            }
        }
    }
    return true;
}

void displayTaskTwo() 
{
    for (int i = 0; i < 20; i++) 
    {
        for (int j = 0; j < 20; j++) 
        {
            cout << tab[i][j];
        }
        cout << "\n";
    }
    cout << "\n";
}

int main() {
    int recurentCtr = 0;
    bool recurentFlag = true;
    for (int n = 0; n < SIZE; n++) 
    {
        readPicture();
        if (isRecurent() && recurentFlag) {
            cout << "Obrazek do zadania 2: " << "\n";
            displayTaskTwo();
            recurentFlag = false;
        }
        if (isRecurent()) recurentCtr++;
    }
    cout << "Liczba obrazkow rekurencyjnych: " << recurentCtr << "\n" << "\n";
    return 0;
}
