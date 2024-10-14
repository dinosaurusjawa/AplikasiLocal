#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

const int BOM = -1;
const int KOSONG = 0;

void tampilkanPapan(const vector<vector<int>>& papan, const vector<vector<bool>>& terbuka, int ukuran) {
    cout << "   ";
    for (int i = 0; i < ukuran; ++i) {
        cout << i << " ";
    }
    cout << endl;
    
    for (int i = 0; i < ukuran; ++i) {
        cout << i << " | ";
        for (int j = 0; j < ukuran; ++j) {
            if (terbuka[i][j]) {
                if (papan[i][j] == BOM) {
                    cout << "* "; // Tampilkan bom
                } else {
                    cout << papan[i][j] << " "; // Tampilkan angka bom di sekeliling
                }
            } else {
                cout << "# "; // Kotak tertutup
            }
        }
        cout << endl;
    }
}

// Fungsi untuk menyebarkan bom
void sebarkanBom(vector<vector<int>>& papan, int ukuran, int jumlahBom, int klikX, int klikY) {
    srand(time(0));
    int bomTerpasang = 0;

    while (bomTerpasang < jumlahBom) {
        int x = rand() % ukuran;
        int y = rand() % ukuran;
        if (papan[x][y] != BOM && (x != klikX || y != klikY)) {
            papan[x][y] = BOM;
            bomTerpasang++;
        }
    }
}

// Fungsi untuk menghitung bom di sekeliling
void hitungSekeliling(vector<vector<int>>& papan, int ukuran) {
    int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

    for (int i = 0; i < ukuran; ++i) {
        for (int j = 0; j < ukuran; ++j) {
            if (papan[i][j] == BOM) continue;

            int jumlahBom = 0;
            for (int k = 0; k < 8; ++k) {
                int nx = i + dx[k];
                int ny = j + dy[k];
                if (nx >= 0 && ny >= 0 && nx < ukuran && ny < ukuran && papan[nx][ny] == BOM) {
                    jumlahBom++;
                }
            }
            papan[i][j] = jumlahBom;
        }
    }
}

void mainkanMinesweeper() {
    int ukuran = 5;  // Ukuran sederhana 5x5
    int jumlahBom = 5;  // Jumlah bom sederhana 5
    vector<vector<int>> papan(ukuran, vector<int>(ukuran, KOSONG));
    vector<vector<bool>> terbuka(ukuran, vector<bool>(ukuran, false));

    int klikX, klikY;
    cout << "=== Minesweeper Sederhana ===" << endl;
    tampilkanPapan(papan, terbuka, ukuran);

    // Klik pertama
    cout << "Klik pertama (masukkan koordinat x y): ";
    cin >> klikX >> klikY;

    // Sebar bom setelah klik pertama
    sebarkanBom(papan, ukuran, jumlahBom, klikX, klikY);

    // Hitung bom di sekeliling
    hitungSekeliling(papan, ukuran);

    // Buka kotak pertama
    terbuka[klikX][klikY] = true;

    // Permainan berlangsung
    bool kalah = false;
    while (!kalah) {
        tampilkanPapan(papan, terbuka, ukuran);
        cout << "Masukkan koordinat (x y) untuk membuka kotak: ";
        cin >> klikX >> klikY;

        if (papan[klikX][klikY] == BOM) {
            cout << "Game Over! Anda mengklik bom!" << endl;
            kalah = true;
        } else {
            terbuka[klikX][klikY] = true;
        }

        // Cek apakah pemain telah membuka semua kotak aman
        bool menang = true;
        for (int i = 0; i < ukuran; ++i) {
            for (int j = 0; j < ukuran; ++j) {
                if (papan[i][j] != BOM && !terbuka[i][j]) {
                    menang = false;
                }
            }
        }

        if (menang) {
            cout << "Selamat! Anda berhasil menyelesaikan permainan!" << endl;
            break;
        }
    }

    // Tampilkan semua bom saat permainan berakhir
    if (kalah) {
        for (int i = 0; i < ukuran; ++i) {
            for (int j = 0; j < ukuran; ++j) {
                terbuka[i][j] = true;  // Buka semua kotak
            }
        }
        tampilkanPapan(papan, terbuka, ukuran);
    }
}

int main() {
    mainkanMinesweeper();
    return 0;
}
