#include <iostream>
#include <string>

using namespace std;

string arrayPalindrom[5];
int maksimal = 5, top = 0;

// Mengecek apakah stack penuh
bool isFull()
{
    return (top == maksimal);
}

// Mengecek apakah stack kosong
bool isEmpty()
{
    return (top == 0);
}

// Menambahkan elemen ke stack
void pushPalindrom(string Palindrom)
{
    if (isFull())
    {
        cout << "Data Telah Penuh" << endl;
    }
    else
    {
        arrayPalindrom[top] = Palindrom;
        top++;
    }
}

// Menghapus elemen dari stack
void popPalindrom()
{
    if (isEmpty())
    {
        cout << "Tidak ada data yang dihapus" << endl;
    }
    else
    {
        arrayPalindrom[top - 1] = "";
        top--;
    }
}

// Melihat elemen pada posisi tertentu dari stack
void peekPalindrom(int posisi)
{
    if (isEmpty())
    {
        cout << "Suku Kata Palindrom Tidak Ditemukan" << endl;
    }
    else
    {
        int index = top;
        for (int i = 1; i <= posisi; i++)
        {
            index--;
        }
        cout << "Posisi ke " << posisi << " adalah " << arrayPalindrom[index] << endl;
    }
}

// Menghitung jumlah elemen dalam stack
int countstack()
{
    return top;
}

// Mengubah elemen pada posisi tertentu dari stack
void changePalindrome(int posisi, string palindrome)
{
    if (posisi > top)
    {
        cout << "Posisi melebihi jangkauan " << endl;
    }
    else 
    {
        int index = top;
        for (int i = 1; i <= posisi; i++)
        {
            index--;
        }
        arrayPalindrom[index] = palindrome;
    }
}

// Menghapus semua elemen dalam stack
void destroyArraybuku()
{
    for (int i = top; i >= 0; i--)
    {
        arrayPalindrom[i] = "";
    }
    top = 0;
}


bool isPalindrome(const string& word)
{
    int left = 0;
    int right = word.length() - 1;

    while (left < right)
    {
        if (word[left] != word[right])
        {
            return false;
        }
        left++;
        right--;
    }
    return true;
}


bool Palindrome(const string& sentence)
{
    string pembersihKata;
    
    for (char c : sentence)
    {
        if (isalpha(c))
        {
            pembersihKata += tolower(c);
        }
    }

    return isPalindrome(pembersihKata);
}

int main()
{
    
    string kalimat1 = "Killin of demand";
    string kalimat2 = "ini";
    
    cout << "Kalimat 1: " << kalimat1 << "||"<< (Palindrome(kalimat1) ? "Palindrom" : "Bukan Palindrom") << endl;
    cout << "Kalimat 2: " << kalimat2 << "||" << (Palindrome(kalimat2) ? "Palindrom" : "Bukan Palindrom") << endl;

    return 0;
} 
