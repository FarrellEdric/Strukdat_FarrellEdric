#include <iostream>

using namespace std;

int main (){
 int a,b,c;
 cout << "Masukan jumlah kolom: ";
 cin >> a;
 cout << "Masukan Jumlah Baris: ";
 cin >> b;
 cout << "Masukan kolom dari kolom dan baris: ";
 cin >> c;
 int ***num = new int** [a]; 
   for (int i = 0; i < a; i++) {
        num[i] = new int*[b];
        for (int j = 0; j < b; j++) {
            num[i][j] = new int[c];
        }
    }
    for (int i=0;i<a;i++)
    {
        for (int j=0;j<b;j++){
            for (int k=0;k<c;k++){
                cout << "Masukan Nilai [" << i << "]" << "[" << j << "]" << "[" << k << "]: ";
                cin >> num[i][j][k];
            }
        }
    }
    for (int i=0;i<a;i++)
    {
        for (int j=0;j<b;j++){
            for (int k=0;k<c;k++){
               cout << num[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

}
