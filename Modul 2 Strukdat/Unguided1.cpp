#include <iostream>

using namespace std;

int main (){
   char loop = 'y';
    while (loop=='y'){
    int a,i;
    cout << "Jumlah data: ";
    cin >> a;
    int *num = new int[a];
    int data,pengulangan;
    

    
    for ( i=0;i<a;i++)
    {   cout << "Masukan Angka: ";  
         cin >> num[i];
         
    }
    system("cls");
    cout << "Hasil datanya adalah \n";
      cout << "inputan user: ";
      for (i=0;i<a;i++)
      {
        cout << num[i] << ", ";
      }
      cout << endl;
      
      cout  << "Bilangan Genap: ";
      for ( i=0;i<a;i++) {
        if (num[i]%2==0)
        cout << num[i] << ", ";
     
       }
       cout << endl;
      
      cout << "Bilangan Ganjil: ";
      for ( i=0;i<a;i++) {
        
     if (num[i]%2 != 0)
            cout << num[i] << ", ";
       
      }
       cout << endl;
      
      cout << "Loop?(y/n): ";
      cin >> loop;
     
   }
  return 0;
} 

