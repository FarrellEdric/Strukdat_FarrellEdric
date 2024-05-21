#include <iostream>
#include <cstring>

using namespace std;

const int MAX = 100;

void pembalikKata(char* sentence) {
    char stack[MAX];
    int top = -1;
    int length = strlen(sentence);

    
    for (int i = 0; i < length; ++i) {
        if (top >= (MAX - 1)) {
            cout << "Stack Overflow\n";
            return;
        } else {
            stack[++top] = sentence[i];
        }
    }


    for (int i = 0; i < length; ++i) {
        if (top < 0) {
            cout << "Stack Underflow\n";
            return;
        } else {
            sentence[i] = stack[top--];
        }
    }
}

int main() {
    while (true){
    char kalimat[MAX];
    
    cout << "Masukkan kalimat: ";
    cin.getline(kalimat, sizeof(kalimat));

    int word_count = 1;
    char temp[MAX];
    strcpy(temp, kalimat);
    char* token = strtok(temp, " ");
    while (token != nullptr) {
        ++word_count;
        token = strtok(nullptr, " ");
    }

    if (word_count <= 3 && word_count <= 2) {
        cerr << "Kalimat harus mengandung minimal 3 kata." << endl;
        return 1;
    }

    cout << "Kalimat asli: " << kalimat << endl;
    pembalikKata(kalimat);
    cout << "Kalimat setelah dibalik: " << kalimat << endl;
    }
    return 0;
}
