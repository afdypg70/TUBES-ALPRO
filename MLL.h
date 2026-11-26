#ifndef MLL_H_INCLUDED
#define MLL_H_INCLUDED

#include <iostream>

using namespace std;

typedef struct elmParent *adrParent;
typedef struct elmChild *adrChild;

struct Turnamen {
    string namaTurnamen;
    string game;
    int prizePool;
};

struct Pertandingan {
    string idMatch;
    string timA;
    string timB;
    int skorA;
    int skorB;
    string status;
};

struct elmChild {
    Pertandingan info;
    adrChild next;
};

struct elmParent {
    Turnamen info;
    adrParent next;
    adrChild firstChild;
};

struct ListParent {
    adrParent first;
};

void createList(ListParent &L);
adrParent createParent(string namaTurnamen, string game, int prizePool);
void insertParent(ListParent &L, adrParent p);
adrParent findParent(ListParent L, string namaTurnamen);
void printParent(ListParent L);
adrChild createChild(string idMatch, string timA, string timB, int skorA, int skorB, string status);
void insertChild(adrParent p, adrChild c);
void printChild(adrParent p);
adrChild findChild(adrParent p, string idMatch);
void deleteChild(adrParent p, string idMatch);
void deleteParent(ListParent &L, string namaTurnamen);
void printAll(ListParent L);

#endif // MLL_H_INCLUDED
