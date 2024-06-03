#include <iostream>
using namespace std;

int main() {
    int n = 10;
    int data[10] = {9, 4, 1, 4, 7, 10, 5, 4, 12, 4};
    int cari = 4;
    int jumlah = 0;

    for (int i = 0; i < n; ++i) {
        if (data[i] == cari) {
            jumlah++;
        }
    }

    cout << "\t Program Sequential Search Sederhana \n" << endl;
    cout << "Data: {9, 4, 1, 4, 7, 10, 5, 4, 12, 4}" << endl;
    cout << "\nAngka " << cari << " muncul sebanyak " << jumlah << " kali dalam data." << endl;

    return 0;
}
