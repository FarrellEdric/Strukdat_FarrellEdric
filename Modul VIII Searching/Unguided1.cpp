#include <iostream>
#include <string>
using namespace std;

void selectionSort(string& str) {
    int n = str.length();
    for (int i = 0; i < n - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if (str[j] < str[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            char temp = str[i];
            str[i] = str[minIndex];
            str[minIndex] = temp;
        }
    }
}

int binarySearch(const string& str, char target) {
    int left = 0;
    int right = str.length() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (str[mid] == target) {
            return mid; 
        } else if (str[mid] < target) {
            left = mid + 1; 
        } else {
            right = mid - 1;
        }
    }

    return -1; 
}

bool isChar(char ch) {
    ch = tolower(ch);
    return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
}

int countChar(const string& str) {
    int count = 0;
    for (char ch : str) {
        if (isChar(ch)) {
            count++;
        }
    }
    return count;
}

int main() {
    string kalimat;
    char target;

    cout << "Masukkan sebuah kalimat: ";
    getline(cin, kalimat);

    cout << "Masukkan huruf yang ingin dicari: ";
    cin >> target;

    selectionSort(kalimat);

    int result = binarySearch(kalimat, target);

    if (result != -1) {
        cout << "Huruf '" << target << "' ditemukan pada indeks: " << result << endl;
    } else {
        cout << "Huruf '" << target << "' tidak ditemukan dalam kalimat." << endl;
    }

    int charCount = countChar(kalimat);
    cout << "Jumlah huruf vokal dalam kalimat tersebut adalah: " << charCount << endl;

    return 0;
}
