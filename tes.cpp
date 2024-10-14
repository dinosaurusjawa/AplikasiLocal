#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

void soloMode() {
    srand(static_cast<unsigned int>(time(0)));
    int angkaRandom = rand() % 100 + 1;
    int percobaan = 0;
    int angkaTebakan;

    cout << "Saya telah memilih angka antara 1 dan 100.\n";
    cout << "Coba tebak dalam 5 kali percobaan!\n";

    while (percobaan < 5) {
        cout << "Masukkan angka tebakan: ";
        cin >> angkaTebakan;

        if (angkaTebakan > angkaRandom) {
            cout << "Terlalu besar! Coba lagi.\n";
        } else if (angkaTebakan < angkaRandom) {
            cout << "Terlalu kecil! Coba lagi.\n";
        } else {
            cout << "Selamat! Anda berhasil menebak angka dengan benar.\n";
            return;
        }
        percobaan++;
    }

    cout << "Kesempatan habis! Angka yang benar adalah: " << angkaRandom << endl;
}

void duoMode() {
    string pemain1, pemain2;
    cout << "Masukkan nama pemain 1: ";
    cin >> pemain1;
    cout << "Masukkan nama pemain 2: ";
    cin >> pemain2;

    srand(static_cast<unsigned int>(time(0)));
    int angkaRandom = rand() % 100 + 1;
    int percobaan1 = 0, percobaan2 = 0;
    int angkaTebakan;

    cout << "Saya telah memilih angka antara 1 dan 100.\n";

    while (percobaan1 < 5 && percobaan2 < 5) {
        // Giliran pemain 1
        cout << pemain1 << ", masukkan angka tebakan: ";
        cin >> angkaTebakan;

        if (angkaTebakan > angkaRandom) {
            cout << "Terlalu besar! Coba lagi.\n";
        } else if (angkaTebakan < angkaRandom) {
            cout << "Terlalu kecil! Coba lagi.\n";
        } else {
            cout << "Selamat " << pemain1 << "! Anda berhasil menebak angka dengan benar.\n";
            return;
        }
        percobaan1++;

        // Giliran pemain 2
        cout << pemain2 << ", masukkan angka tebakan: ";
        cin >> angkaTebakan;

        if (angkaTebakan > angkaRandom) {
            cout << "Terlalu besar! Coba lagi.\n";
        } else if (angkaTebakan < angkaRandom) {
            cout << "Terlalu kecil! Coba lagi.\n";
        } else {
            cout << "Selamat " << pemain2 << "! Anda berhasil menebak angka dengan benar.\n";
            return;
        }
        percobaan2++;
    }

    cout << "Kesempatan habis! Angka yang benar adalah: " << angkaRandom << endl;
}

void trioMode() {
    string pemain1, pemain2, pemain3;
    cout << "Masukkan nama pemain 1: ";
    cin >> pemain1;
    cout << "Masukkan nama pemain 2: ";
    cin >> pemain2;
    cout << "Masukkan nama pemain 3: ";
    cin >> pemain3;

    srand(static_cast<unsigned int>(time(0)));
    int angkaRandom = rand() % 100 + 1;
    int percobaan1 = 0, percobaan2 = 0, percobaan3 = 0;
    int angkaTebakan;

    cout << "Saya telah memilih angka antara 1 dan 100.\n";

    while (percobaan1 < 5 && percobaan2 < 5 && percobaan3 < 5) {
        // Giliran pemain 1
        cout << pemain1 << ", masukkan angka tebakan: ";
        cin >> angkaTebakan;

        if (angkaTebakan > angkaRandom) {
            cout << "Terlalu besar! Coba lagi.\n";
        } else if (angkaTebakan < angkaRandom) {
            cout << "Terlalu kecil! Coba lagi.\n";
        } else {
            cout << "Selamat " << pemain1 << "! Anda berhasil menebak angka dengan benar.\n";
            return;
        }
        percobaan1++;

        // Giliran pemain 2
        cout << pemain2 << ", masukkan angka tebakan: ";
        cin >> angkaTebakan;

        if (angkaTebakan > angkaRandom) {
            cout << "Terlalu besar! Coba lagi.\n";
        } else if (angkaTebakan < angkaRandom) {
            cout << "Terlalu kecil! Coba lagi.\n";
        } else {
            cout << "Selamat " << pemain2 << "! Anda berhasil menebak angka dengan benar.\n";
            return;
        }
        percobaan2++;

        // Giliran pemain 3
        cout << pemain3 << ", masukkan angka tebakan: ";
        cin >> angkaTebakan;

        if (angkaTebakan > angkaRandom) {
            cout << "Terlalu besar! Coba lagi.\n";
        } else if (angkaTebakan < angkaRandom) {
            cout << "Terlalu kecil! Coba lagi.\n";
        } else {
            cout << "Selamat " << pemain3 << "! Anda berhasil menebak angka dengan benar.\n";
            return;
        }
        percobaan3++;
    }

    cout << "Kesempatan habis! Angka yang benar adalah: " << angkaRandom << endl;
}

int main() {
    int pilihanMenu;

    do {
        cout << "SELAMAT DATANG DI PERMAINAN TEBAK ANGKA ;)\n";
        cout << "\n1. Mulai Game\n";
        cout << "2. Exit\n";
        cout << "3. Coming Soon\n";
        cout << "Pilih menu: ";
        cin >> pilihanMenu;

        switch (pilihanMenu) {
            case 1: {
                int modePermainan;
                cout << "Pilih mode permainan:\n";
                cout << "1. Solo\n";
                cout << "2. Duo\n";
                cout << "3. Trio\n";
                cout << "Pilih mode: ";
                cin >> modePermainan;

                switch (modePermainan) {
                    case 1:
                        soloMode();
                        break;
                    case 2:
                        duoMode();
                        break;
                    case 3:
                        trioMode();
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
            case 3:
                cout << "Fitur ini akan segera hadir. Terima kasih!\n";
                break;
            default:
                cout << "Pilihan tidak valid. Silakan pilih 1, 2, atau 3.\n";
                break;
        }
    } while (pilihanMenu != 2);

    return 0;
}
