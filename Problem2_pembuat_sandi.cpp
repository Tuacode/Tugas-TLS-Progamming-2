#include <iostream>
#include <string>
using namespace std;

bool isVowel(char c) {
    c = tolower(c);
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
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

string makePassword(const string &word) {
    
    string consonants = "";
    for (char c : word) {
        if (!isVowel(c)) consonants += c;
    }

    
    string revConsonants = myReverse(consonants);

    
    if (word.empty()) return revConsonants;
    int asciiVal = (int)word[0];
    string asciiStr = to_string(asciiVal);

    
    int n = consonants.size();
    int pos = (n + 1) / 2; 

    
    string result = revConsonants.substr(0, pos) + asciiStr + revConsonants.substr(pos);
    return result;
}

int main() {
    string input;
    cout << "Masukkan kata: ";
    cin >> input;

    string password = makePassword(input);
    cout << "Hasil sandi: " << password << endl;

    return 0;
}
