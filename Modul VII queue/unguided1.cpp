#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

const int maksimalQueue = 5; // maksimal

class linkedMhs {
public:
    string mahasiswa;
    long long int nim;
    linkedMhs* next;
    linkedMhs* prev;
};

class node {
private:
    linkedMhs* front;
    linkedMhs* back;
    int size;

public:
    node() {
        front = nullptr;
        back = nullptr;
        size = 0;
    }

    bool isFull() {
        return size == maksimalQueue;
    }

    bool isEmpty() {
        return size == 0;
    }

    void enqueueAntrian(string namaMhs, long long int nim) {
        if (isFull()) {
            cout << "Antrian penuh" << endl;
            return;
        }

        linkedMhs* NewList = new linkedMhs;
        NewList->mahasiswa = namaMhs;
        NewList->nim = nim;
        NewList->next = nullptr;
        NewList->prev = back;

        if (isEmpty()) {
            front = NewList;
        } else {
            back->next = NewList;
        }
        back = NewList;
        size++;
    }

    void dequeueAntrian() {
        if (isEmpty()) {
            cout << "Antrian Kosong " << endl;
            return;
        }

        linkedMhs* temp = front;

        if (front == back) {
            front = back = nullptr;
        } else {
            front = front->next;
            front->prev = nullptr;
        }

        delete temp;
        size--;
    }

    int countQueue() {
        return size;
    }

    void clearQueue() {
        while (!isEmpty()) {
            dequeueAntrian();
        }
    }

    void displayQueue() {
    if (isEmpty()) {
        cout << "Antrian Kosong" << endl;
        return;
    }

    linkedMhs* current = front;
    cout << left << setw(25) << "Nama Mahasiswa" << setw(15) << "NIM" << endl;
    cout << "---------------------------------------------------" << endl;
    while (current != nullptr) {
        cout << left << setw(25) << current->mahasiswa << setw(15) << current->nim << endl;
        current = current->next;
    }
    cout << "---------------------------------------------------" << endl;
}

};



int main() {
    node antrian;
    int pilih;

    while (true) {
        cout << "Menu Tampilan " << endl;
        cout << "1. Menambahkan Antrian " << endl;
        cout << "2. Mengeluarkan Antrian " << endl;
        cout << "3. Menghapus Semua Antrian " << endl;
        cout << "4. Display " << endl;
        cout << "0. Return " << endl;
        cout << "Pilih menu: ";
        cin >> pilih;

        switch (pilih) {
            case 0:
                return 0;
            case 1: {
                string mhs;
                long long int nim;
                cout << "Nama Mahasiswa: ";
                cin.ignore();
                getline(cin,mhs);
                cout << "Nim Mahasiswa: ";
                cin >> nim;
                antrian.enqueueAntrian(mhs, nim);
                break;
            }
            case 2:
                antrian.dequeueAntrian();
                cout << "Antrian Kurang " << antrian.countQueue() << " lagi" << endl;
                break;
            
                break;
            case 3:
                antrian.clearQueue();
                cout << "Semua antrian telah dihapus" << endl;
                break;
            case 4:
                antrian.displayQueue();
                break;
            default:
                cout << "Pilihan Kembali" << endl;
                break;
        }
    }

    return 0;
}
