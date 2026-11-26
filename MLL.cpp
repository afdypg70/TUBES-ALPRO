#include <iostream>
#include "MLL.h"

using namespace std;

void createList(ListParent &L) {
    L.first = nullptr;
}

adrParent createParent(string namaTurnamen, string game, int prizePool) {
    adrParent p = new elmParent;
    p->info.namaTurnamen = namaTurnamen;
    p->info.game = game;
    p->info.prizePool = prizePool;
    p->next = nullptr;
    p->firstChild = nullptr;
    return p;
}

adrParent findParent(ListParent L, string namaTurnamen) {
    adrParent p = L.first;
    while (p != nullptr) {
        if (p->info.namaTurnamen == namaTurnamen) {
            return p;
        }
        p = p->next;
    }
    return nullptr;
}

void insertParent(ListParent &L, adrParent p) {
    if (findParent(L, p->info.namaTurnamen) != nullptr) {
        cout << "[Gagal] Nama turnamen sudah ada.\n";
        return;
    }

    if (L.first == nullptr) {
        L.first = p;
    } else {
        adrParent q = L.first;
        while (q->next != nullptr) {
            q = q->next;
        }
        q->next = p;
    }
    cout << "[Sukses] Turnamen berhasil ditambahkan.\n";
}

void printParent(ListParent L) {
    if (L.first == nullptr) {
        cout << "Daftar turnamen masih kosong.\n";
        return;
    }

    cout << "\n=== DAFTAR TURNAMEN ===\n";
    adrParent p = L.first;
    int nomor = 1;
    while (p != nullptr) {
        cout << nomor << ". " << p->info.namaTurnamen
             << " | Game: " << p->info.game
             << " | Prize Pool: $" << p->info.prizePool << "\n";
        nomor++;
        p = p->next;
    }
}

adrChild createChild(string idMatch, string timA, string timB, int skorA, int skorB, string status) {
    adrChild c = new elmChild;
    c->info.idMatch = idMatch;
    c->info.timA = timA;
    c->info.timB = timB;
    c->info.skorA = skorA;
    c->info.skorB = skorB;
    c->info.status = status;
    c->next = nullptr;
    return c;
}

void insertChild(adrParent p, adrChild c) {
    if (p == nullptr) {
        cout << "[Gagal] Turnamen tidak ditemukan.\n";
        return;
    }

    if (p->firstChild == nullptr) {
        p->firstChild = c;
    } else {
        adrChild q = p->firstChild;
        while (q->next != nullptr) {
            q = q->next;
        }
        q->next = c;
    }
    cout << "[Sukses] Pertandingan berhasil ditambahkan ke " << p->info.namaTurnamen << ".\n";
}

void printChild(adrParent p) {
    if (p == nullptr) {
        cout << "Turnamen tidak ditemukan.\n";
        return;
    }

    cout << "\n--- Pertandingan di " << p->info.namaTurnamen << " ---\n";
    if (p->firstChild == nullptr) {
        cout << "Belum ada pertandingan di turnamen ini.\n";
        return;
    }

    adrChild c = p->firstChild;
    while (c != nullptr) {
        cout << "[" << c->info.idMatch << "] " << c->info.timA << " (" << c->info.skorA << ") vs (" << c->info.skorB << ") " << c->info.timB << " | Status: " << c->info.status << "\n";
        c = c->next;
    }
}

adrChild findChild(adrParent p, string idMatch) {
    cout << "Masih dikerjakan.\n";
    return nullptr;
}

void deleteChild(adrParent p, string idMatch) {
    cout << "Masih dikerjakan.\n";
}

void deleteParent(ListParent &L, string namaTurnamen) {
    cout << "Masih dikerjakan.\n";
}

void printAll(ListParent L) {
    if (L.first == nullptr) {
        cout << "\nTidak ada turnamen.\n";
        return;
    }

    cout << "\n======================================================\n";
    cout << "       DATA LENGKAP TURNAMEN & PERTANDINGAN             \n";
    cout << "======================================================\n";

    adrParent p = L.first;
    int nomor = 1;
    while (p != nullptr) {
        cout << nomor << ". TURNAMEN : " << p->info.namaTurnamen << " (" << p->info.game << " - $" << p->info.prizePool << ")\n";

        if (p->firstChild == nullptr) {
            cout << "   -> Belum ada pertandingan terdaftar.\n";
        } else {
            adrChild c = p->firstChild;
            while (c != nullptr) {
                cout << "   -> [" << c->info.idMatch << "] " << c->info.timA << " " << c->info.skorA << " - " << c->info.skorB << " " << c->info.timB << " (" << c->info.status << ")\n";
                c = c->next;
            }
        }
        cout << "------------------------------------------------------\n";
        nomor++;
        p = p->next;
    }
}
