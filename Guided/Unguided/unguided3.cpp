#include <iostream>
#include <map>
#include <string>
#include <array>

using namespace std;

int main () {
    map<string , string>laprak1;
    map<string , array<string,2>>lihataray;
    laprak1.insert (pair <string ,string >("Modul 1","Nugas dulu"));
    laprak1.insert (pair <string ,string>("Modul 2","Berotak senku"));
    
    lihataray["1"] = {"GG gimang","cobak - cobak"};
    
    cout << "menggunakan map biasa : \n";
    for (auto pair : laprak1)
        {
            cout << pair.first << " itu " << pair.second << endl;

        }
        cout << "menggunakan map array: \n";
    for ( const auto& element : lihataray["1"])
    {
        cout << element << " " << endl;
    }
    
}