#include <iostream>
#include <string>
using namespace std;


string getLampColor(int detik) {
    
    int hijau = 20;
    int kuning = 3;
    int merah = 80;
    int totalSiklus = hijau + kuning + merah; 

    int posisi = (detik - 45) % totalSiklus;
    if (posisi < 0) posisi += totalSiklus; 

    
    if (posisi < kuning) {
        return "Kuning";
    } else if (posisi < kuning + merah) {
        return "Merah";
    } else {
        return "Hijau";
    }
}

int main() {
    
    int waktu[] = {80, 135, 150, 212};
    int n = 4;

    for (int i = 0; i < n; i++) {
        int t = waktu[i];
        cout << "Detik " << t << " -> " << getLampColor(t) << endl;
    }

    return 0;
}
