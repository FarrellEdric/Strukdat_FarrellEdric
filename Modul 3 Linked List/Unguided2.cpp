#include <iostream>
#include <iomanip>

using namespace std;

class Node {
public:
    string produk;
    int daftarHarga;
    Node* prev;
    Node* next;
};

class doubLinked {
public:
    Node* head;
    Node* tail;
    doubLinked() {
        head = NULL;
        tail = NULL;
    }

    void pushFront(string produk, int daftarHarga) {
        Node* baru = new Node;
        baru->produk = produk;
        baru->daftarHarga = daftarHarga;
        baru->prev = NULL;
        baru->next = head;

        if (head != NULL) {
            head->prev = baru;
        }
        else {
            tail = baru;
        }
        head = baru;
    }

    void pushAtPosition(string produk, int daftarHarga, int pos) {
        Node* temp = head;
        int count = 1;

        while (temp != NULL && count < pos) {
            temp = temp->next;
            count++;
        }

        if (temp == NULL) {
            cout << "Posisi melebihi panjang list." << endl;
            return;
        }

        Node* baru = new Node;
        baru->produk = produk;
        baru->daftarHarga = daftarHarga;

        baru->prev = temp;
        baru->next = temp->next;

        if (temp->next != NULL) {
            temp->next->prev = baru;
        }
        else {
            tail = baru;
        }
        temp->next = baru;
    }

   void DeleteFront() {
    if (head == NULL) {
        cout << "Tidak ada List" << endl;
        return;
    }

    Node* temp = head;

    head = head->next;
    if (head != NULL) {
        head->prev = NULL;
    } else {
        tail = NULL;
    }

    delete temp;
    cout << "Node Telah Dihapus" << endl;
}
    void UpdateDATA(string produkLAMA, int NewPRICE, string newProduk) {
        Node* temp = head;
        while (temp != NULL && temp->produk != produkLAMA) {
            temp = temp->next;
        }
        if (temp == NULL) {
            cout << "Produk tidak ada." << endl;
            return;
        }
        temp->produk = newProduk;
        temp->daftarHarga = NewPRICE;
    }

    void DeleteAtPosition(int pos) {
        Node* temp = head;
        int count = 1;

        while (temp != NULL && count < pos) {
            temp = temp->next;
            count++;
        }

        if (temp == NULL || temp->next == NULL) {
            cout << "Posisi melebihi panjang list." << endl;
            return;
        }

        Node* toDelete = temp->next;
        temp->next = toDelete->next;

        if (toDelete->next != NULL) {
            toDelete->next->prev = temp;
        }
        else {
            tail = temp;
        }
        delete toDelete;
    }

    void DeleteAll() {
        Node* current = head;
        while (current != NULL) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
        head = NULL;
        tail = NULL;
    }

    void Display() {
        Node* temp = head;

        cout << "+------------------------+----------+" << endl;
        cout << "|       Nama Produk      |  Harga   |" << endl;
        cout << "+------------------------+----------+" << endl;

        while (temp != NULL) {
            cout << "| " << left << setw(23) << temp->produk << "| " << right << setw(8) << temp->daftarHarga << " |" << endl;
            cout << "+------------------------+----------+" << endl; // Tambahkan garis setiap kali memproses entri
            temp = temp->next;
        }
    }
};

int main() {
    int pilih;
    doubLinked list;

    list.pushFront("Hanasui", 60000);
    list.pushFront("Wardah", 150000);
    list.pushFront("Skintific", 100000);
    list.pushFront("Somethinc", 50000);
    list.pushFront("Orginote", 30000);

    while (true) {
        cout << "Natasha Skincare: " << endl;
        cout << "1. Tambah Data" << endl;
        cout << "2. Hapus Data" << endl;
        cout << "3. Update Data" << endl;
        cout << "4. Tambah Data Urutan Tertentu" << endl;
        cout << "5. Hapus Data Urutan Tertentu" << endl;
        cout << "6. Hapus Seluruh Data" << endl;
        cout << "7. Tampilkan Data " << endl;
        cout << "8. Exit" << endl;
        cout << "Pilih: ";
        cin >> pilih;

        switch (pilih) {
            case 1: {
                string nP;
                int dH; 
                cout << "Nama Produk: ";
                cin >> nP;
                cout << "Masukan Harga: ";
                cin >> dH;
                list.pushFront(nP, dH);
                break;
            }
            case 2: {
                 
                    list.DeleteFront();
                break;
            }
            case 3: {
                string produkLAMA, newProduk;
                int NewPRICE;
                cout << "Nama Produk yang ingin diubah: ";
                cin >> produkLAMA;
                cout << "Masukkan Nama Baru: ";
                cin >> newProduk;
                cout << "Masukkan Harga Baru: ";
                cin >> NewPRICE;
                list.UpdateDATA(produkLAMA, NewPRICE, newProduk);
                break;
            }
            case 4: {
                int pos;
                string product;
                int Dh;
                cout << "Masukan Nama Product: ";
                cin >> product;
                cout << "Masukan Daftar Harga: ";
                cin >> Dh;
                cout << "Masukkan posisi Yang Ingin Diinginkan: ";
                cin >> pos;
                list.pushAtPosition(product,Dh,pos);
                break;
            }
            case 5: {
                int pos;
                cout << "Masukkan posisi yang ingin dihapus: ";
                cin >> pos;
                list.DeleteAtPosition(pos);
                break;
            }
            case 6: {
                list.DeleteAll();
                cout << "Semua data telah dihapus." << endl;
                break;
            }
            case 7: {
                list.Display();
                break;
            }
            case 8:
                cout << "Program selesai." << endl;
                return 0;
            default: 
                cout << "Salah Input" << endl;
                break;
        }
    }

    return 0;
}
