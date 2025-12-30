#include "Doublelylist.h"

void initList(List &L) {
    L.First = nullptr;
    L.Last = nullptr;
}

address createNode(infotype data) {
    address newNode = new Node;
    newNode->info = data;
    newNode->next = nullptr;
    newNode->prev = nullptr;
    return newNode;
}


void freeNode(address &P) {
    delete P;
    P = nullptr;
}

void appendNode(List &L, address P) {
    if (L.First == nullptr) {
        L.First = P;
        L.Last = P;
    } else {
        L.Last->next = P;
        P->prev = L.Last;
        L.Last = P;
    }
}

void displayList(const List &L) {
    address curr = L.First;
    while (curr != nullptr) {
        cout << "No Polisi : " << curr->info.nopol << endl;
        cout << "Warna     : " << curr->info.warna << endl;
        cout << "Tahun     : " << curr->info.thnBuat << endl << endl;
        curr = curr->next;
    }
}

address searchNode(const List &L, const string &nopol) {
    address curr = L.First;
    while (curr != nullptr) {
        if (curr->info.nopol == nopol) return curr;
        curr = curr->next;
    }
    return nullptr;
}

void removeFirst(List &L, address &P) {
    if (L.First == nullptr) {
        P = nullptr;
    } else if (L.First == L.Last) {
        P = L.First;
        L.First = nullptr;
        L.Last = nullptr;
    } else {
        P = L.First;
        L.First = P->next;
        L.First->prev = nullptr;
        P->next = nullptr;
    }
}

void removeLast(List &L, address &P) {
    if (L.Last == nullptr) {
        P = nullptr;
    } else if (L.First == L.Last) {
        P = L.Last;
        L.First = nullptr;
        L.Last = nullptr;
    } else {
        P = L.Last;
        L.Last = P->prev;
        L.Last->next = nullptr;
        P->prev = nullptr;
    }
}

void removeAfter(address Prec, address &P) {
    if (Prec != nullptr && Prec->next != nullptr) {
        P = Prec->next;
        Prec->next = P->next;
        if (P->next != nullptr) {
            P->next->prev = Prec;
        }
        P->next = nullptr;
        P->prev = nullptr;
    } else {
        P = nullptr;
    }
}