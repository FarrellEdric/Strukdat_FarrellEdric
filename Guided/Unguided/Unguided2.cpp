#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
int n;
int main () {
    int i;
    struct genshinImpact{
        string character[3];
    };
    class laprak1 {
        public:
        string buff="What 3 favorite your character in genshin impact?"; 
        
    };
    genshinImpact karakter;
    laprak1 roll;

    cout << roll.buff << endl;
   for ( i=0;i<3;i++)
   {
    cout << "Name: ";
    cin >> karakter.character[i];
      
   }
   for ( i=0;i<3;i++)
   { 
    cout << "your characters is " << karakter.character[i] << endl;
   
      
   }
   

}