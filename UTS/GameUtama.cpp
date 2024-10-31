#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>

using namespace std;

void soloMode();
void multiplayerMode(int playerCount);

int main() {
    srand(static_cast<unsigned int>(time(0))); // Seed random number generator once
    int pilihanMenu;

    do {
        // Tampilan halaman utama dengan tabel
        cout << "==============================\n";
        cout << "|   SELAMAT DATANG DI GAME   |\n";
        cout << "|       TEBAK ANGKA ;)       |\n";
        cout << "==============================\n";
        cout << "|         Menu Utama         |\n";
        cout << "==============================\n";
        cout << "|  1. Mulai Game             |\n";
        cout << "|  2. Exit                   |\n";
        cout << "==============================\n";
        cout << "Pilih menu: ";
        cin >> pilihanMenu;

        switch (pilihanMenu) {
            case 1: {
                int modePermainan;
                cout << "==============================\n";
                cout << "|      Pilih Mode Game       |\n";
                cout << "==============================\n";
                cout << "|  1. Solo                    |\n";
                cout << "|  2. Duo                     |\n";
                cout << "|  3. Trio                    |\n";
                cout << "==============================\n";
                cout << "Pilih mode: ";
                cin >> modePermainan;

                switch (modePermainan) {
                    case 1:
                        soloMode();
                        break;
                    case 2:
                        multiplayerMode(2);
                        break;
                    case 3:
                        multiplayerMode(3);
                        break;
                    default:
                        cout << "Pilihan tidak valid. Silakan pilih 1, 2, atau 3.\n";
                        break;
                }
                break;
            }
            case 2:
                cout << "Terima kasih telah bermain! Sampai jumpa!\n";
                break;
            default:
                cout << "Pilihan tidak valid. Silakan pilih 1 atau 2.\n";
                break;
        }
    } while (pilihanMenu != 2);

    return 0;
}

void playAgain(bool &playAgainOption, int playerCount = 1) {
    char pilihan;
    cout << "Apakah Anda ingin bermain lagi? (Y/N): ";
    cin >> pilihan;
    playAgainOption = (pilihan == 'Y' || pilihan == 'y');
    
    if (!playAgainOption) {
        cout << "Kembali ke menu utama.\n";
    } else {
        cout << "Permainan akan dimulai ulang...\n";
    }
}

void soloMode() {
    bool playAgainOption;
    do {
        int angkaRandom = rand() % 100 + 1;
        int percobaan = 5;
        int angkaTebakan;

        cout << "Saya telah memilih angka antara 1 dan 100.\n";
        cout << "Coba tebak dalam 5 kali percobaan!\n";

        bool menang = false;
        for (int i = 0; i < percobaan; ++i) {
            cout << "Percobaan ke-" << i + 1 << ". Sisa percobaan: " << percobaan - i << endl;
            cout << "Masukkan angka tebakan: ";
            cin >> angkaTebakan;

            if (angkaTebakan > angkaRandom) {
                cout << "Terlalu besar! Coba lagi.\n";
            } else if (angkaTebakan < angkaRandom) {
                cout << "Terlalu kecil! Coba lagi.\n";
            } else {
                cout << "Selamat! Anda berhasil menebak angka dengan benar 🎉🏆\n";
                cout << "Anda mendapatkan piala untuk keberhasilan ini!\n";
                menang = true;
                break;
            }
        }

        if (!menang) {
            cout << "Kesempatan habis! Angka yang benar adalah: " << angkaRandom << endl;
            cout << "Segini doang nih? Hahaha 😆\n";
        }

        playAgain(playAgainOption);
    } while (playAgainOption);
}

void multiplayerMode(int playerCount) {
    vector<string> players(playerCount);
    bool playAgainOption;
    
    // Input nama pemain hanya sekali
    for (int i = 0; i < playerCount; ++i) {
        cout << "Masukkan nama pemain " << i + 1 << ": ";
        cin >> players[i];
    }
    
    do {
        vector<int> attempts(playerCount, 0);
        int angkaRandom = rand() % 100 + 1;
        int maxAttempts = 5;
        int angkaTebakan;
        bool gameWon = false;

        cout << "Saya telah memilih angka antara 1 dan 100.\n";

        while (!gameWon) {
            for (int i = 0; i < playerCount; ++i) {
                if (attempts[i] >= maxAttempts) continue;

                cout << players[i] << ", giliran Anda (Percobaan ke-" << attempts[i] + 1 << "). Sisa percobaan: " << maxAttempts - attempts[i] << endl;
                cout << "Masukkan angka tebakan: ";
                cin >> angkaTebakan;

                if (angkaTebakan > angkaRandom) {
                    cout << "Terlalu besar! Coba lagi.\n";
                } else if (angkaTebakan < angkaRandom) {
                    cout << "Terlalu kecil! Coba lagi.\n";
                } else {
                    cout << "Selamat " << players[i] << "! Anda berhasil menebak angka dengan benar.\n";
                    gameWon = true;
                    cout << "🏆 " << players[i] << " mendapat peringkat 1!\n";
                    break;
                }

                attempts[i]++;
                if (attempts[i] >= maxAttempts) {
                    cout << players[i] << " telah kehabisan kesempatan.\n";
                }
            }

            bool allOutOfAttempts = true;
            for (int i = 0; i < playerCount; ++i) {
                if (attempts[i] < maxAttempts) {
                    allOutOfAttempts = false;
                    break;
                }
            }
            if (allOutOfAttempts && !gameWon) {
                cout << "Kesempatan habis untuk semua pemain! Angka yang benar adalah: " << angkaRandom << endl;
                cout << "Segini doang nih? Hahaha 😆\n";
                break;
            }
        }
        
        playAgain(playAgainOption, playerCount);
    } while (playAgainOption);
}
