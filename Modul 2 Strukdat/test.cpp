#include <iostream>

using namespace std;

int main () {
    int array[3][3][4];
    cout << "Gambaran array Multidimensi: " << endl;
    for (int i =0;i<3;i++)
    {
        for (int j=0;j<3;j++)
        {
            for (int k=0;k<4;k++)
            {
                cout << "Masukan Baris Dan Kolom: ";
                cin >> array[i][j][k];
                
            }
                    cout << endl;

        }
        }
        for (int i =0;i<3;i++)
    {
        for (int j=0;j<3;j++)
        {
            for (int k=0;k<4;k++)
            {
                cout << array [i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    
}