#include <iostream>
#include <iomanip>
using namespace std;


struct Node {
    double NIM;
    string namaMhs;
    Node* next;
};

Node* head = nullptr;
Node* tail = nullptr;

void tambahDepan(string mhs, double NIM) {
    Node* baru = new Node;
    baru->namaMhs = mhs;
    baru->NIM = NIM;
    baru->next = nullptr;

   
    if (head == nullptr) {
        head = tail = baru;
    } else {
   
        baru->next = head;
        head = baru;
    }
   
}

void tambahBelakang(string mhs, double NIM) {
    Node* baru = new Node;
    baru->namaMhs = mhs;
    baru->NIM = NIM;
    baru->next = nullptr;

 
    if (head == nullptr) {
        head = tail = baru;
    } else {
        tail->next = baru;
        tail = baru;
    }
  
}

void tambahTengah(string mhs, double NIM, int posisi) {
    if (posisi <= 0) {
        cout << "Posisi tidak valid." << endl;
        return;
    }

    Node* baru = new Node;
    baru->namaMhs = mhs;
    baru->NIM = NIM;
    baru->next = nullptr;

    
    if (posisi == 1) {
        tambahDepan(mhs, NIM);
        return;
    }

    Node* current = head;
    Node* prev = nullptr;
    int count = 1;

    while (current != nullptr && count < posisi) {
        prev = current;
        current = current->next;
        count++;
    }

  
    if (current == nullptr && count != posisi) {
        cout << "Posisi tidak valid." << endl;
        return;
    }

    prev->next = baru;
    baru->next = current;
}


void ubahDepan(string mhs, double NIM) {
    if (head == nullptr) {
        cout << "List kosong." << endl;
        return;
    }
    head->namaMhs = mhs;
    head->NIM = NIM;
    cout << "Data mahasiswa pertama berhasil diubah." << endl;
}


void ubahBelakang(string mhs, double NIM) {
    if (head == nullptr) {
        cout << "List kosong." << endl;
        return;
    }
    Node* current = tail;

    tail->namaMhs = mhs;
    tail->NIM = NIM;
    cout << "Data Berhasil diubah" << endl;
}

void ubahTengah(double nim, string mhsBaru, double nimBaru) {
    if (head == nullptr) {
        cout << "List kosong." << endl;
        return;
    }

    Node* current = head;

    while (current != nullptr && current->NIM != nim) {
        current = current->next;
    }
    if (current == nullptr) {
        cout << "Data dengan NIM tersebut tidak ditemukan." << endl;
        return;
    }

    current->namaMhs = mhsBaru;
    current->NIM = nimBaru;
    cout << "Data mahasiswa dengan NIM " << nim << " berhasil diubah." << endl;
}



void hapusDepan() {
    if (head == nullptr) {
        cout << "List kosong." << endl;
        return;
    }

    Node* temp = head;
    head = head->next;
    delete temp;

}

void hapusBelakang() {
    if (head == nullptr) {
        cout << "List kosong." << endl;
        return;
    }

    if (head == tail) {
        delete head;
        head = tail = nullptr;
        cout << "Data mahasiswa terakhir berhasil dihapus." << endl;
        return;
    }

    Node* current = head;
    while (current->next != tail) {
        current = current->next;
    }

    delete tail;
    tail = current;
    tail->next = nullptr;
   
}

void hapusTengah(double nim) {
    if (head == nullptr) {
        cout << "List kosong." << endl;
        return;
    }

    Node* current = head;
    Node* prev = nullptr;

    while (current != nullptr && current->NIM != nim) {
        prev = current;
        current = current->next;
    }

   
    if (current == nullptr) {
        cout << "Data dengan NIM tersebut tidak ada dalam daftar" << endl;
        return;
    }

    
    if (prev == nullptr) {
        head = head->next;
        delete current;
        cout << "Data mahasiswa dengan NIM " << setprecision(0)<< fixed << nim << " Dengan atas nama" << current->namaMhs << " berhasil dihapus." << endl;
        return;
    }

    if (current == tail) {
        tail = prev;
    }

    prev->next = current->next;
    delete current;
 cout << "Data mahasiswa dengan NIM " << setprecision(0)<< fixed << nim << " Dengan atas nama " << current->namaMhs << " berhasil dihapus." << endl;
}



void hapusList() {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    tail = nullptr;
    cout << "Semua data mahasiswa berhasil dihapus." << endl;
}




void tampilkan() {
    if (head == nullptr) {
        cout << "List kosong." << endl;
        return;
    }

   
    int maxNamaLength = 0;
    Node* current = head;
    while (current != nullptr) {
        int namaLength = current->namaMhs.length();
        if (namaLength > maxNamaLength) {
            maxNamaLength = namaLength;
        }
        current = current->next;
    }

    cout << "\n------------------------------------------------------------------------------------------------" << endl;
    cout << "| No |       NIM        | " << setw(maxNamaLength + 4) << "Nama Mahasiswa" << " |" << endl;
    cout << "------------------------------------------------------------------------------------------------" << endl;

    int count = 1;
    current = head;
    while (current != nullptr) {
        cout << "| " << setw(2) << count << " | " << setw(17) << fixed << setprecision(0) << current->NIM
             << " | " << setw(maxNamaLength + 4) << current->namaMhs << " |" << endl;
        current = current->next;
        count++;
    }
    cout << "------------------------------------------------------------------------------------------------" << endl;
}



int main() {
    tambahDepan ("Jawad",23300001);
    tambahBelakang("Farrel",23300003);
    tambahBelakang("Denis",23300005);
    tambahBelakang("Anis",23300008);
    tambahBelakang("Bowo",23300015);
    tambahBelakang("Gahar",23300040);
    tambahBelakang("Udin",23300048);
    tambahBelakang("Ucok",23300050);
    tambahBelakang("Budi",23300099);
     tambahTengah("Farrell Edric Kelvianto",2311102079,2);

    cout << "PROGRAM SINGLE LINKED LIST NON CIRCULAR" << endl;
    int choice;
    while (true) {

        cout << "\nMenu:" << endl;
        cout << "1. Tambah Data di Depan" << endl;
        cout << "2. Tambah Data di Belakang" << endl;
        cout << "3. Tambah Data di Tengah" << endl;
        cout << "4. Ubah Data Pertama" << endl;
        cout << "5. Ubah Data Terakhir" << endl;
        cout << "6. Ubah Data di Tengah" << endl;
        cout << "7. Hapus Data Pertama" << endl;
        cout << "8. Hapus Data Terakhir" << endl;
        cout << "9. Hapus Data di Tengah" << endl;
        cout << "10. Hapus Semua Data" << endl;
        cout << "11. Tampilkan Data" << endl;
        cout << "0. Keluar" << endl;

        cout << "Masukkan pilihan: ";
        cin >> choice;

    
        switch (choice) {
            case 1: {
                string nama;
                double nim;
                cout << "-Tambah Depan" << endl;
                cout << "Masukkan nama mahasiswa: ";
                cin >> nama;
                cout << "Masukkan NIM mahasiswa: ";
                cin >> nim;
                tambahDepan(nama, nim);
                  cout << "Data telah ditambahkan";
                break;
            }
            case 2: {
                string nama;
                double nim;
                cout << "-Tambah Belakang" << endl;
                cout << "Masukkan nama mahasiswa: ";
                cin >> nama;
                cout << "Masukkan NIM mahasiswa: ";
                cin >> nim;
                tambahBelakang(nama, nim);
                cout << "Data telah ditambahkan";
                break;
            }
            case 3: {
                string nama;
                double nim;
                int posisi;
                cout << "-Tambah Tengah" << endl;
                cout << "Masukkan nama mahasiswa: ";
                cin >> nama;
                cout << "Masukkan NIM mahasiswa: ";
                cin >> nim;
                cout << "Masukkan posisi: ";
                cin >> posisi;
                tambahTengah(nama, nim, posisi);
                cout << "Data telah ditambahkan";
                break;
            }
            case 4: {
                string nama;
                double nim;
                cout << "-Ubah Depan" << endl;
                cout << "Masukkan nama baru untuk mahasiswa pertama: ";
                cin >> nama;
                cout << "Masukkan NIM baru untuk mahasiswa pertama: ";
                cin >> nim;
                ubahDepan(nama, nim);
                cout << "Data Telah Diubah" << endl;
                break;
            }
            case 5: {
                string nama;
                double nim;
                cout << "-Ubah Belakang" << endl;
                cout << "Masukkan nama baru untuk mahasiswa terakhir: ";
                cin >> nama;
                cout << "Masukkan NIM baru untuk mahasiswa terakhir: ";
                cin >> nim;
                ubahBelakang(nama, nim);
               
                break;
            }
            case 6: {
                double NIM;
                string mhs;
                double nimBar;
                cout << "-Mengubah Data Tengah" << endl;
                cout << "Masukkan NIM lama untuk diubah: ";
                cin >> NIM;
                cout << "Masukkan Nama Data Mahasiswa Baru: ";
                cin >> mhs;
                cout << "Masukkan NIM baru: ";
                cin >> nimBar;
                ubahTengah(NIM, mhs, nimBar);
                break;
            }
            case 7:
                hapusDepan();
                cout << "Data Depan Telah Dihapus";
                break;
            case 8:
                hapusBelakang();
                   cout << "Data Belakang Telah Dihapus";
                break;
            case 9: {
                double NIM;
                cout << "-Hapus Tengah" << endl;
                cout << "Masukkan NIM mahasiswa yang ingin dihapus: ";
                cin >> NIM;
                hapusTengah(NIM);
                break;
            }
            case 10:
                hapusList();
                cout << "Semua data telah dihapus " << endl;
                break;
            case 11:
                tampilkan();
                break;
            case 0:
                cout << "=======Program Was Returned======" << endl;
                return 0;
            default:
                cout << "Anda salah input,silahkan pilih kembali." << endl;
        }
    }
    return 0;
}
