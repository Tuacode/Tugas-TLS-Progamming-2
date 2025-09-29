#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool isDigit(char c) {
    return (c >= '0' && c <= '9');
}

bool isAllDigits(const string &s) {
    for (char c : s) {
        if (!isDigit(c)) return false;
    }
    return !s.empty();
}

string myReverse(const string &s) {
    string t = s;
    int i = 0, j = t.size() - 1;
    while (i < j) {
        char tmp = t[i];
        t[i] = t[j];
        t[j] = tmp;
        i++;
        j--;
    }
    return t;
}

int main() {
    string pwd;
    cout << "Masukkan sandi: ";
    cin >> pwd;

    int L = pwd.size();
    bool found = false;

    // Coba semua substring digit
    for (int i = 0; i < L; i++) {
        for (int j = i + 1; j <= L; j++) {
            string sub = pwd.substr(i, j - i);
            if (!isAllDigits(sub)) continue;

            int digitLen = j - i;
            int n = L - digitLen;
            int pos = (n + 1) / 2; 

            if (pos != i) continue; // digit harus di posisi yang benar

            int asciiVal = stoi(sub);
            if (asciiVal < 32 || asciiVal > 126) continue; // hanya printable

            char firstChar = (char)asciiVal;

            string revConsonants = pwd.substr(0, i) + pwd.substr(j);
            string consonants = myReverse(revConsonants);

            cout << "\n=== Hasil Rekonstruksi ===" << endl;
            cout << "Kode ASCII: " << asciiVal << " => huruf pertama: '" << firstChar << "'" << endl;
            cout << "Kerangka konsonan: " << consonants << endl;
            cout << "Pola kata asli: diawali '" << firstChar << "', lalu konsonan " << consonants 
                 << " dengan vokal bebas di antara/ujung." << endl;

            found = true;
        }
    }

    if (!found) {
        cout << "Tidak ada pola valid ditemukan." << endl;
    }

    return 0;
}
