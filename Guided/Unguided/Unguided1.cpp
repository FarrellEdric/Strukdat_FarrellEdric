#include <iostream>
#include <string>

using namespace std;

int fungsi_penjumlahan(int x,int y){
    return x+y;
}
int fungsi_pengurangan (int a , int b)
{
    return a-b;
}

int main (){
int penjumlahan,x,y;
int pengurangan,a,b;
string pilih;
char loop = 'y';
while (loop=='y'){
cout << "Masukan Operator penjumlahan atau pengurangan (+/-): ";
cin >> pilih;
if (pilih=="+")
    {   
        cout << "Masukan Bilangan Pertama: ";
        cin >> x;
        cout << "Masukan Bilangan kedua: ";
        cin >> y;
        cout << "Hasil penjumlahannya adalah " << fungsi_penjumlahan(x,y);
    }

else if (pilih=="-")
    {
        cout << "Masukan Bilangan Pertama: ";
        cin >> a;
        cout << "Masukan Bilangan kedua: ";
        cin >> b;
        cout << "Hasil penjumlahannya adalah " << fungsi_pengurangan(a,b);
        }
    cout << "\nloop: y/t: ";
    cin >> loop;
    system ("cls");
    }
}