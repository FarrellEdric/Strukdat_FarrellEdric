#include <iostream>
#include <conio.h>
#include <iomanip>
using namespace std;

int data_array[7] = {1, 8, 2, 5, 4, 9, 7};
int cari;

void selection_sort()
{   
    int temp, min, i, j;
    for (i = 0; i < 7; i++)
    {
        min = i;
        for (j = i + 1; j < 7; j++)
        {
            if (data_array[j] < data_array[min])
            {
                min = j;
            }
        }
        temp = data_array[i];
        data_array[i] = data_array[min];
        data_array[min] = temp;
    }
}

void binary_search()
{
    int awal, akhir, tengah, b_flag = 0;
    awal = 0;
    akhir = 6;  
    while (b_flag == 0 && awal <= akhir)
    {
        tengah = (awal + akhir) / 2;
        if (data_array[tengah] == cari)
        {
            b_flag = 1;
            break;
        }
        else if (data_array[tengah] < cari)
            awal = tengah + 1;
        else
            akhir = tengah - 1;
    }
    if (b_flag == 1)
        cout << "\n Data ditemukan pada index ke- " << tengah << endl;
    else
        cout << "\n Data tidak ditemukan\n";
}

int main()
{
    cout << "\t BINARY SEARCH " << endl;
    cout << "\n Data : ";
    for (int x = 0; x < 7; x++)
        cout << setw(3) << data_array[x];
    cout << endl;
    cout << "\n Masukkan data yang ingin Anda cari: ";
    cin >> cari;
    cout << "\n Data diurutkan: ";

    selection_sort();
    for (int x = 0; x < 7; x++)
        cout << setw(3) << data_array[x];
    cout << endl;
    binary_search();
    _getche();
    return EXIT_SUCCESS;
}
