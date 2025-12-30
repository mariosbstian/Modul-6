#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H

#include <iostream>
using namespace std;

struct Kendaraan {
    string nopol;
    string warna;
    int thnBuat;
};

typedef Kendaraan infotype;

struct Node {
    infotype info;
    Node *next;
    Node *prev;
};

typedef Node* address;

struct List {
    address First;
    address Last;
};

void initList(List &L);
address createNode(infotype data);
void freeNode(address &P);

void appendNode(List &L, address P);
void displayList(const List &L);

address searchNode(const List &L, const string &nopol);

void removeFirst(List &L, address &P);
void removeLast(List &L, address &P);
void removeAfter(address Prec, address &P);

#endif
