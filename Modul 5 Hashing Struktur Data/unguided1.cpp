#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

class Mahasiswa
{
public:
    string nama;
    long long int NIM;
    int nilai;

    Mahasiswa(string nama, long long int NIM, int nilai) : nama(nama), NIM(NIM), nilai(nilai) {}
};

class HashNode
{
public:
    vector<Mahasiswa> mahasiswas;

    void insert(Mahasiswa mahasiswa)
    {
        mahasiswas.push_back(mahasiswa);
    }

    void remove(long long int NIM)
    {
        for (auto it = mahasiswas.begin(); it != mahasiswas.end(); ++it)
        {
            if (it->NIM == NIM)
            {
                mahasiswas.erase(it);
                return;
            }
        }
    }

    Mahasiswa *pencarianmhs(long long int NIM)
    {
        for (auto &mahasiswa : mahasiswas)
        {
            if (mahasiswa.NIM == NIM)
            {
                return &mahasiswa;
            }
        }
        return nullptr;
    }

    vector<Mahasiswa *> rentanNilai(int minNilai, int maxNilai)
    {
        vector<Mahasiswa *> result;
        for (auto &mahasiswa : mahasiswas)
        {
            if (mahasiswa.nilai >= minNilai && mahasiswa.nilai <= maxNilai)
            {
                result.push_back(&mahasiswa);
            }
        }
        return result;
    }
};

class HashMap
{
private:
    static const int TABLE_SIZE = 20;
    HashNode *table[TABLE_SIZE];

public:
    HashMap()
    {
        for (int i = 0; i < TABLE_SIZE; ++i)
        {
            table[i] = new HashNode();
        }
    }

    int hashFunc(long long int NIM)
    {
        return NIM % TABLE_SIZE;
    }

    void insert(Mahasiswa mahasiswa)
    {
        int hash_val = hashFunc(mahasiswa.NIM);
        table[hash_val]->insert(mahasiswa);
    }

    void remove(long long int NIM)
    {
        int hash_val = hashFunc(NIM);
        table[hash_val]->remove(NIM);
    }

    Mahasiswa *pencarianmhs(long long int NIM)
    {
        int hash_val = hashFunc(NIM);
        return table[hash_val]->pencarianmhs(NIM);
    }

    vector<Mahasiswa *> rentanNilai(int minNilai, int maxNilai)
    {
        vector<Mahasiswa *> result;
        for (int i = 0; i < TABLE_SIZE; ++i)
        {
            vector<Mahasiswa *> temp = table[i]->rentanNilai(minNilai, maxNilai);
            result.insert(result.end(), temp.begin(), temp.end());
        }
        return result;
    }

    void display() {
        
        cout << "               Data Mahasiswa                " << endl;

        for (int i = 0; i < TABLE_SIZE; ++i) {
            if (!table[i]->mahasiswas.empty()) {
                cout << "Slot " << setw(3) << i << " | ";
                for (auto& mahasiswa : table[i]->mahasiswas) {
                    cout << "Nama: " << setw(15) << mahasiswa.nama << " | "
                         << "NIM: " << setw(10) << mahasiswa.NIM << " | "
                         << "Nilai: " << setw(3) << mahasiswa.nilai << " | ";
                }
                cout << endl;
            }
            
        }
        
    }
};

int main()
{
    HashMap hashTable;
    int pilih;
    while (true)
    {
        cout << "\nMenu Pilihan \n\n";
        cout << "1. Tambah Data Mahasiswa \n";
        cout << "2. Menghapus Data Mahasiswa \n";
        cout << "3. Mencari Mahasiswa \n";
        cout << "4. Mencari Rentan Nilai \n";
        cout << "5. Display \n";
        cout << "0. Exit \n";
        cout << "Pilih: ";
        cin >> pilih;

        switch (pilih)
        {
        case 1:
        {
            string nama;
            long long int NIM;
            int nilai;
            cout << "Masukkan Nama Mahasiswa: ";
            cin.ignore();
            getline(cin, nama);
            cout << "Masukkan NIM Mahasiswa: ";
            cin >> NIM;
            cout << "Masukkan Nilai Mahasiswa: ";
            cin >> nilai;
            Mahasiswa mahasiswa(nama, NIM, nilai);
            hashTable.insert(mahasiswa);
            cout << "Mahasiswa telah ditambahkan! " << endl;
            break;
        }
        case 2:
        {
            long long int NIM;
            cout << "Masukan NIM mahasiswa yang ingin dihapus: ";
            cin >> NIM;
            hashTable.remove(NIM);
            cout << "Data Mahasiswa Telah Dihapus! " << endl;
            break;
        }
        case 3:
        {
            long long int NIM;
            cout << "Masukkan NIM Mahasiswa: ";
            cin >> NIM;
            Mahasiswa *mahasiswa = hashTable.pencarianmhs(NIM);
            if (mahasiswa != nullptr)
            {
                cout << "Data Mahasiswa:" << endl;
                cout << "Nama: " << mahasiswa->nama << endl;
                cout << "NIM: " << mahasiswa->NIM << endl;
                cout << "Nilai: " << mahasiswa->nilai << endl;
            }
            else
            {
                cout << "Mahasiswa tidak ditemukan." << endl;
            }
            break;
        }
        case 4:
        {
            int minNilai, maxNilai;
            cout << "Masukkan rentang nilai min: ";
            cin >> minNilai;
            cout << "Masukan rentang nilai max: ";
            cin >> maxNilai;
            vector<Mahasiswa *> mahasiswas = hashTable.rentanNilai(minNilai, maxNilai);
            if (mahasiswas.empty())
            {
                cout << "Tidak ada mahasiswa dengan nilai dalam rentang tersebut." << endl;
            }
            else
            {
                cout << "Mahasiswa dengan nilai dalam rentang " << minNilai << " - " << maxNilai << " adalah:" << endl;
                for (auto mahasiswa : mahasiswas)
                {
                    cout << "Nama: " << mahasiswa->nama << ", NIM: " << mahasiswa->NIM << ", Nilai: " << mahasiswa->nilai << endl;
                }
            }
            break;
        }
        case 5:
            hashTable.display();
            break;
        case 0:
            return 0;
        default:
            cout << "Pilihan tidak valid." << endl;
            break;
        }
    }
    return 0;
}
