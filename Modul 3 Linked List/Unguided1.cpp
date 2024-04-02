#include <iostream>
using namespace std;

// Struct
struct node {
    string iNPName;
    int Age;
    node* next;
};

node* head;
node* tail;

void inisial (){
    head = NULL;
    tail = NULL;
}

bool kosong(){
    return head == NULL;
}

void insert_front(string nama, int Age){
    node* baru = new node;
    baru->iNPName = nama;
    baru->Age = Age;
    baru->next = NULL;

    if (kosong()){
        head = tail = baru;
    } else {
        baru->next = head;
        head = baru;
    }
}

void insert_back(string iNPName, int Age){
    node* baru = new node;
    baru->iNPName = iNPName;
    baru->Age = Age;
    baru->next = NULL;

    if (head == NULL){
        head = tail = baru;
    } else {
        tail->next = baru;
        tail = baru;
    }
}

void insertCenter(string iNPName, int Age, int posisi){
    node* baru = new node;
    baru->iNPName = iNPName;
    baru->Age = Age;
    baru->next = NULL;

    if (head == NULL) { 
        head = baru;
        tail = baru;
    } else {
        node* temp = head;
        int count = 1;

        while (temp != NULL && count < posisi - 1) {
            temp = temp->next;
            count++;
        }

        if (temp == NULL || posisi <= 0) { 
            cout << "Posisi tidak valid." << endl;
            delete baru; 
            return;
        }

        baru->next = temp->next; 
        temp->next = baru;

        if (baru->next == NULL) { 
            tail = baru;
        }
    }
}

void Delete(string iNPName) {
    if (head == NULL) {
        cout << "Data kosong" << endl;
        return;
    }

    if (head->iNPName == iNPName) {
        node* hapus = head;
        head = head->next;
        delete hapus;
        if (head == NULL) { 
            tail = NULL;
        }
        return;
    }

    node* temp = head;
    while (temp->next != NULL && temp->next->iNPName != iNPName) {
        temp = temp->next;
    }

    if (temp->next != NULL) {
        node* hapus = temp->next;
        temp->next = hapus->next;
        delete hapus;
        if (temp->next == NULL) {
            tail = temp; 
        }
    } else {
        cout << "Data tidak ada" << endl;
        return;
    }
}

void changeData(string oldName, string newName, int newAge){
    node* temp = head;
    while (temp != NULL && temp->iNPName != oldName) {
        temp = temp->next;
    }
    if (temp != NULL){
        temp->iNPName = newName;
        temp->Age = newAge;
    } else {
        cout << "Data Tidak Ada" << endl;
    }
}

void Display (){
    if (head == NULL){
        cout << "List tidak ada" << endl;
        return;
    }
    node* temp = head;
    cout << "[Nama] " << "\t[Usia] " << endl;
    while (temp != NULL){
        cout << temp->iNPName << "\t" << temp->Age << endl;
        temp = temp->next;
    }
}

int main (){
    inisial();
    insert_front("John", 19);
    insert_back("Jane", 20);
    insert_back("Michael", 18);
    insert_back("Yusuke", 19);
    insert_back("Akechi", 20);
    insert_back("Hoshino", 20);
    insert_back("Karin", 18);

    int pilih;
    string nama, posisi, NewName;
    int usia, UsiaBaru;

    while (true){
        cout << "List Perintah: \n";
        cout << "1. Menampilkan Data" << endl;
        cout << "2. Menambahkan Data Dibelakang" << endl;
        cout << "3. Menghapus Data" << endl;
        cout << "4. Mengubah Data" << endl;
        cout << "5. Menambahkan Data Tertentu" << endl;
        cout << "6. Menambahkan Data Di Depan" << endl;
        cout << "7. Exit" << endl;
        cout << "Pilih: ";
        cin >> pilih;

        switch (pilih){
            case 1: 
                Display();
                break;
            case 2: {
                cout << "Masukan Nama: ";
                cin >> nama;
                cout << "Masukan Usia: ";
                cin >> usia;
                insert_back(nama, usia);
                break;
            }
            case 3: {
                cout << "Nama yang ingin dihapus: ";
                cin >> nama;
                Delete(nama);
                break;
            }
            case 4:{ 
                cout << "Masukan nama lama: ";
                cin >> nama;
                cout << "Masukan nama baru: ";
                cin >> NewName;
                cout << "Masukan Usia Baru: ";
                cin >> UsiaBaru;
                changeData(nama, NewName, UsiaBaru);
                break;
            }
            case 5:{
                string Name;
                int umur, posisi; 
                cout << "Masukan Nama: ";
                cin >> Name;
                cout << "Masukan Umur: ";
                cin >> umur;
                cout << "Posisi: ";
                cin >> posisi;
                insertCenter(Name, umur, posisi);
                break;
            }
            case 6:
            {
                string nM;
                int uMr;
                cout << "Masukan Nama: ";
                cin >> nM;
                cout << "Masukan Umur: ";
                cin >> uMr;
                insert_front(nM, uMr);
                break;
            }
            case 7:
                return 0;
            default:
                cout << "Anda salah input " << endl;
                break;
        }
    }   
}
