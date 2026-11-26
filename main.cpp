#include <iostream>
#include "MLL.h"

using namespace std;

void loadDataDummy(ListParent &L) {
    adrParent t1 = createParent("VCT Masters Tokyo", "Valorant", 1000000);
    adrParent t2 = createParent("MPL ID Season 14", "Mobile Legends", 336500);

    insertParent(L, t1);
    insertParent(L, t2);

    insertChild(t1, createChild("M01", "Paper Rex", "Fnatic", 2, 1, "Finished"));
    insertChild(t1, createChild("M02", "Paper Rex", "DRX", 0, 0, "Scheduled"));
    insertChild(t2, createChild("M11", "ONIC Esports", "RRQ Hoshi", 2, 1, "Finished"));
}

int main() {
    ListParent L;
    createList(L);

    int pilihan;
    do {
        cout << "\n=== ESPORTS TOURNAMENT MANAGEMENT ===\n";
        cout << "1. Tambah Turnamen\n";
        cout << "2. Cari Turnamen\n";
        cout << "3. Tampilkan Daftar Turnamen\n";
        cout << "4. Tambah Pertandingan ke Turnamen\n";
        cout << "5. Tampilkan Pertandingan Turnamen\n";
        cout << "6. Hapus Pertandingan (Belum Selesai)\n";
        cout << "7. Hapus Turnamen (Belum Selesai)\n";
        cout << "8. Tampilkan Semua Data Turnamen\n";
        cout << "9. Load Data Dummy untuk Demo\n";
        cout << "0. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        string namaTurnamen, game, idMatch, timA, timB, status;
        int prizePool, skorA, skorB;

        switch (pilihan) {
            case 1: {
                cout << "Nama Turnamen : ";
                getline(cin >> ws, namaTurnamen);
                cout << "Nama Game     : ";
                getline(cin >> ws, game);
                cout << "Prize Pool ($): ";
                cin >> prizePool;

                adrParent p = createParent(namaTurnamen, game, prizePool);
                insertParent(L, p);
                break;
            }
            case 2: {
                cout << "Nama Turnamen yang dicari: ";
                getline(cin >> ws, namaTurnamen);

                adrParent p = findParent(L, namaTurnamen);
                if (p != nullptr) {
                    cout << "[Ditemukan] " << p->info.namaTurnamen
                         << " (" << p->info.game << " - $" << p->info.prizePool << ")\n";
                } else {
                    cout << "[Tidak Ditemukan] Turnamen tidak ada.\n";
                }
                break;
            }
            case 3:
                printParent(L);
                break;
            case 4: {
                cout << "Nama Turnamen tujuan : ";
                getline(cin >> ws, namaTurnamen);

                adrParent p = findParent(L, namaTurnamen);
                if (p == nullptr) {
                    cout << "[Gagal] Turnamen tidak ditemukan.\n";
                    break;
                }

                cout << "ID Match (contoh M01): ";
                getline(cin >> ws, idMatch);
                cout << "Nama Tim A           : ";
                getline(cin >> ws, timA);
                cout << "Nama Tim B           : ";
                getline(cin >> ws, timB);
                cout << "Skor Tim A           : ";
                cin >> skorA;
                cout << "Skor Tim B           : ";
                cin >> skorB;
                cout << "Status               : ";
                getline(cin >> ws, status);

                adrChild c = createChild(idMatch, timA, timB, skorA, skorB, status);
                insertChild(p, c);
                break;
            }
            case 5: {
                cout << "Nama Turnamen: ";
                getline(cin >> ws, namaTurnamen);

                adrParent p = findParent(L, namaTurnamen);
                printChild(p);
                break;
            }
            case 6:
                deleteChild(nullptr, "");
                break;
            case 7:
                deleteParent(L, "");
                break;
            case 8:
                printAll(L);
                break;
            case 9:
                loadDataDummy(L);
                break;
            case 0:
                cout << "Program selesai.\n";
                break;
            default:
                cout << "Pilihan tidak tersedia.\n";
        }
    } while (pilihan != 0);

    return 0;
}
