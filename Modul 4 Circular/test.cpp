#include <iostream>
#include <iomanip>
using namespace std;

struct Node
{   
    string NAMA;
    double NIM;
    Node* next;

};
Node* head=NULL;
Node* tail=NULL;
void tambahDepan (string Mhs , double Nim){
    Node* baru = new Node;
    baru->NAMA = Mhs;
    baru->NIM = Nim;
    baru->next= NULL;

    if (head==NULL)
    {
        head = tail = baru;
    }
    else {
        baru->next= head;
        head = baru;
    }
    
}
void Tampilkan (){
    if (head==nullptr && tail==nullptr){
        return;
    }
    else {
        Node* bantu;
        bantu = head;
        while (bantu !=nullptr)
        {
            cout << "Data anda adalah " << bantu ->NAMA << " dengan NIM " << setprecision(0) << fixed << bantu ->NIM << ends;
            bantu = head->next;
        }
        
    }
}

int main (){
    double nim;
    string mhs;
    cout << "masukan nama: ";
    cin >> mhs;
    cout << "masukan umur: ";
    cin >> nim;
    tambahDepan(mhs,nim);
    Tampilkan();
}