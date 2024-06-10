#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

vector<string> simpul;
vector<vector<int>> busur;

void tampilGraph() {
    cout << endl;
    cout << "    ";
    for (const auto& s : simpul) {
        cout << setw(10) << s;
    }
    cout << endl;

    for (size_t baris = 0; baris < simpul.size(); baris++) {
        cout << setw(10) << simpul[baris];
        for (size_t kolom = 0; kolom < simpul.size(); kolom++) {
            cout << setw(10) << busur[baris][kolom];
        }
        cout << endl;
    }
}

int main() {
    int FarrellEdricKelvianto_2311102079;
    cout << "Silakan masukan jumlah simpul: ";
    cin >> FarrellEdricKelvianto_2311102079;

    simpul.resize(FarrellEdricKelvianto_2311102079);
    busur.resize(FarrellEdricKelvianto_2311102079, vector<int>(FarrellEdricKelvianto_2311102079, 0));

    cin.ignore(); 

    for (int i = 0; i < FarrellEdricKelvianto_2311102079; i++) {
        cout << "Simpul " << i + 1 << ": ";
        getline(cin, simpul[i]);
    }

    cout << "Silakan masukkan bobot antar simpul" << endl;
    for (int i = 0; i < FarrellEdricKelvianto_2311102079; i++) {
        for (int j = 0; j < FarrellEdricKelvianto_2311102079; j++) {
            cout << simpul[i] << "--> " << simpul[j] << " = ";
            cin >> busur[i][j];
        }
    }

    tampilGraph();

    return 0;
}