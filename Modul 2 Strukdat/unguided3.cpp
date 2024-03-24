#include <iostream>

using namespace std;

int main (){
    int d;
    int pilih;
    cout << "Masukan berapa banyak data: ";
    cin >> d;
    int *arr = new int[d];
  
    for (int i = 0;i<d;i++)
    {
        cout << "Masukan angka: ";
        cin >> arr [i];
    }
    
    cout << "Data yang dimasukan: "; 
    for (int i=0;i<d;i++)
    {
        cout << arr[i] << ", ";

    }
    char perulangan='y';
    while (perulangan=='y'){
    cout << endl;
    int maximum = arr[0];
    int minimum = arr[0];
    int sum;
    cout << "Pilih: \n";
    cout << "1.Mencari maksimum\n";
    cout << "2.Mencari minimum\n";
    cout << "3.Mencari Rata - Rata\n";
    cout << "Masukan (1,2,3): ";
    cin >> pilih;
    
    if (pilih == 1)
    {
        for (int i=0;i<d;i++)
    {
       if (arr[i] > maximum)
       {
        maximum = arr[i];
       
       }

    } cout << "Hasil Maximum: " << maximum;
    }
    else if (pilih == 2)
    {   for (int i=0;i<d;i++)
    {
       if (arr[i] < minimum)
       {
         arr[i]=minimum;
         
       }
    }
        cout << "Hasil Minimum : " << minimum;
        }
  else if (pilih == 3){
    for (int i=0;i<d;i++)
    {
       sum += arr[i];
       
    }
    double average = static_cast<double>(sum) / d;
    cout << "rata - rata: " << average;
  }
  else {cout << "salah pilih";}
  cout << "\nUlangi (y/n): ";
  cin >> perulangan;
}
}