#include <iostream>
using namespace std;

int main() {
    // Variables to represent conditions (K1, K2, K3)
    bool K1, K2, K3;

    // Step X1
    cout << "Mulai program." << endl;

    // Input for K1
    cout << "Apakah K1 benar? (1 untuk benar, 0 untuk salah): ";
    cin >> K1;

    if (K1) {  // K1 benar
        cout << "Langkah A dijalankan." << endl;

        // Input for K2
        cout << "Apakah K2 benar? (1 untuk benar, 0 untuk salah): ";
        cin >> K2;

        if (K2) {  // K2 benar
            cout << "Langkah C dijalankan." << endl;
        } else {   // K2 salah
            cout << "Langkah A salah, kembali ke X2." << endl;
        }

    } else {  // K1 salah
        cout << "Langkah B dijalankan." << endl;

        // Input for K3
        cout << "Apakah K3 benar? (1 untuk benar, 0 untuk salah): ";
        cin >> K3;

        if (K3) {  // K3 benar
            cout << "Langkah D dijalankan." << endl;
        } else {   // K3 salah
            cout << "Langkah B salah, kembali ke X2." << endl;
        }
    }

    // Step X2
    cout << "Langkah X2 selesai." << endl;

    return 0;
}
