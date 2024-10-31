#include <iostream>
#include <cstdlib> // untuk fungsi rand() dan srand()
#include <ctime>   // untuk fungsi time()

using namespace std;

int main() {
    int pilihanMenu; // Untuk memilih menu
    do {
        // Menu awal
        cout << "=== Selamat Datang di Permainan Tebak Angka ===" << endl;
        cout << "1. Mulai Game" << endl;
        cout << "2. Exit" << endl;
        cout << "3. Coming Soon (update code dan juga multiplayer)" << endl;
        cout << "Pilih opsi (1/2/3): ";
        cin >> pilihanMenu;

        switch (pilihanMenu) {
            case 1: {
                // Memulai Game
                int angkaTebakan, angkaRandom, maxPercobaan = 5, percobaan = 0;

                // Inisialisasi angka random
                srand(static_cast<unsigned int>(time(0)));
                angkaRandom = rand() % 100 + 1; // Angka random antara 1 sampai 100

                cout << "Saya telah memilih angka antara 1 dan 100." << endl;
                cout << "Coba tebak dalam " << maxPercobaan << " kali percobaan!" << endl;

                // Loop untuk memberi kesempatan tebak
                while (percobaan < maxPercobaan) {
                    cout << "Masukkan tebakan Anda: ";
                    cin >> angkaTebakan;

                    if (angkaTebakan > angkaRandom) {
                        cout << "Terlalu besar! Coba lagi." << endl;
                    } else if (angkaTebakan < angkaRandom) {
                        cout << "Terlalu kecil! Coba lagi." << endl;
                    } else {
                        cout << "Selamat! Anda berhasil menebak angka dengan benar." << endl;
                        break;
                    }

                    percobaan++;
                }

                if (percobaan == maxPercobaan) {
                    cout << "Maaf, kesempatan Anda habis. Angka yang benar adalah: " << angkaRandom << endl;
                }
                break; // Mengakhiri case 1
            }
            case 2:
                cout << "Terima kasih telah bermain! Sampai jumpa!" << endl;
                break; // Mengakhiri case 2
            case 3:
                cout << "Fitur ini akan segera hadir. Terima kasih!" << endl;
                break; // Mengakhiri case 3
            default:
                cout << "Pilihan tidak valid. Silakan pilih 1, 2, atau 3." << endl;
        }
        cout << endl; // Memberi jarak antar menu
    } while (pilihanMenu != 2); // Loop sampai pilihan adalah 2 (Exit)

    return 0;
}
