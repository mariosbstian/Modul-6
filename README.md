# <h1 align="center">Laporan Praktikum Modul (6)</h1>
<p align="center">Mario Sebastian Barus</p>

## Dasar Teori
Dalam kajian struktur data, Doubly Linked List merupakan mana setiap node memiliki pointer next dan prev, memudahkan penelusuran data ke depan maupun ke belakang serta operasi penyisipan dan penghapusan elemen di tengah list. Dengan alokasi dinamis (new) dan dealokasi (delete) di C++, jumlah node dapat disesuaikan tanpa memboroskan memori, sementara pointer dan reference memungkinkan manipulasi data secara langsung. Fungsi-fungsi modular seperti createNode, appendNode, dan displayList menerapkan prinsip pemrograman terstruktur, sedangkan percabangan dan perulangan menjaga konsistensi dan memungkinkan pemrosesan seluruh elemen secara sistematis. Implementasi ini menekankan efisiensi memori, fleksibilitas akses data, dan pengendalian alur program berbasis input pengguna.
## Guided 

### dll_delete.cpp

```C++
#include <iostream> 
using namespace std; 
#define Nil NULL 

typedef int infotype; // Definisikan tipe data infotype sebagai integer untuk menyimpan informasi elemen
typedef struct elmlist *address; // Definisikan tipe address sebagai pointer ke struct elmlist

struct elmlist { 
    infotype info; // Deklarasikan field info untuk menyimpan data elemen
    address next;   
    address prev; 
}; 

struct List { 
    address first; 
    address last;
}; 

address alokasi(infotype x) { // Definisikan fungsi alokasi untuk membuat elemen baru
    address P = new elmlist; // Alokasikan memori baru untuk elemen
    P->info = x; P->next = Nil; P->prev = Nil; return P; // Set nilai info, next, prev, dan kembalikan pointer
} 
void dealokasi(address &P) { delete P; P = Nil; } // Definisikan fungsi dealokasi untuk mengosongkan memori elemen
void insertFirst(List &L, address P) { 
    P->next = L.first; P->prev = Nil; // Set pointer next P ke first saat ini dan prev ke Nil
    if (L.first != Nil) L.first->prev = P; else L.last = P; // Jika list tidak kosong, update prev first; jika kosong, set last ke P
    L.first = P; // Update first list menjadi P
}

void printInfo(List L) { 
    address P = L.first; while (P != Nil) { cout << P->info << " "; P = P->next; } cout << endl; // Loop melalui list dan cetak info setiap elemen
} 
void deleteFirst(List &L, address &P) { 
    P = L.first; L.first = L.first->next; // Set P ke first dan update first ke next-nya
    if (L.first != Nil) L.first->prev = Nil; else L.last = Nil; // Jika list tidak kosong, set prev first baru ke Nil; jika kosong, set last ke Nil
    P->next = Nil; P->prev = Nil; // Kosongkan pointer next dan prev P
}

void deleteLast(List &L, address &P) { 
    P = L.last; L.last = L.last->prev; // Set P ke last dan update last ke prev-nya
    if (L.last != Nil) L.last->next = Nil; else L.first = Nil; // Jika list tidak kosong, set next last baru ke Nil; jika kosong, set first ke Nil
    P->prev = Nil; P->next = Nil; // Kosongkan pointer prev dan next P
} 
    
void deleteAfter(List &L, address &P, address R) { 
    P = R->next; R->next = P->next; // Set P ke next R dan update next R ke next P
    if (P->next != Nil) P->next->prev = R; else L.last = R; // Jika ada next P, update prev-nya ke R; jika tidak, set last ke R
    P->prev = Nil; P->next = Nil; // Kosongkan pointer prev dan next P
} 

int main() { 
    List L; L.first = Nil; L.last = Nil; 
    insertFirst(L, alokasi(1)); insertFirst(L, alokasi(2)); insertFirst(L, alokasi(3)); // Sisipkan elemen 1, 2, 3 di awal list
    printInfo(L);
    address P; deleteFirst(L, P); dealokasi(P); // Deklarasikan P, hapus first, dealokasi P
    deleteAfter(L, P, L.first); dealokasi(P); // Hapus setelah first, dealokasi P
    printInfo(L); 
    return 0; 
}
```

### dll_insert.cpp

```C++
#include <iostream>
#define Nil NULL
using namespace std;

typedef int infotype; // Definisikan tipe data infotype sebagai integer untuk menyimpan informasi elemen
typedef struct elmlist *address; // Definisikan tipe address sebagai pointer ke struct elmlist

struct elmlist {
    infotype info; // Deklarasikan field info untuk menyimpan data elemen
    address next;
    address prev;
};

struct List { 
    address first; 
    address last; 
}; 

void insertFirst(List &L, address P) { 
    P->next = L.first; // Set pointer next dari P ke elemen pertama saat ini
    P->prev = Nil; // Set pointer prev dari P ke Nil karena menjadi elemen pertama
    if (L.first != Nil) L.first->prev = P; // Jika list tidak kosong, set prev elemen pertama lama ke P
    else L.last = P; // Jika list kosong, set last juga ke P
    L.first = P; // Update first list menjadi P
} 

void insertLast(List &L, address P) { 
    P->prev = L.last; // Set pointer prev dari P ke elemen terakhir saat ini
    P->next = Nil; // Set pointer next dari P ke Nil karena menjadi elemen terakhir
    if (L.last != Nil) L.last->next = P; // Jika list tidak kosong, set next elemen terakhir lama ke P
    else L.first = P; // Jika list kosong, set first juga ke P
    L.last = P; // Update last list menjadi P
} 

void insertAfter(List &L, address P, address R) { // Definisikan fungsi insertAfter untuk menyisipkan elemen setelah R
    P->next = R->next; // Set pointer next dari P ke elemen setelah R
    P->prev = R; // Set pointer prev dari P ke R
    if (R->next != Nil) R->next->prev = P; // Jika ada elemen setelah R, set prev elemen tersebut ke P
    else L.last = P; // Jika R adalah terakhir, update last menjadi P
    R->next = P; // Set next dari R ke P
}

address alokasi(infotype x) { // Definisikan fungsi alokasi untuk membuat elemen baru
    address P = new elmlist; // Alokasikan memori baru untuk elemen
    P->info = x; // Set info elemen dengan nilai x
    P->next = Nil; // Set next elemen ke Nil
    P->prev = Nil; // Set prev elemen ke Nil
    return P; 
} 

void printInfo(List L) { // Definisikan fungsi printInfo untuk mencetak isi list
    address P = L.first; // Set P ke elemen pertama list
    while (P != Nil) { // Loop selama P tidak Nil
        cout << P->info << " "; // Cetak info dari P 
        P = P->next; // Pindah ke elemen berikutnya
    } 
    cout << endl; 
}

int main() { 
    List L; 
    L.first = Nil; 
    L.last = Nil;
    address P1 = alokasi(1); 
    insertFirst(L, P1); 
    address P2 = alokasi(2); 
    insertLast(L, P2); 
    address P3 = alokasi(3); 
    insertAfter(L, P3, P1); 
    printInfo(L); 
    return 0; 
}
```

## Unguided 

### 1. [main.cpp]

```C++
#include "Doublelylist.h"

int main() {
    List L;
    initList(L);

    infotype data;
    address P;

    for (int i = 0; i < 4; i++) {
        cout << "Masukkan nomor polisi: ";
        cin >> data.nopol;
        cout << "Masukkan warna kendaraan: ";
        cin >> data.warna;
        cout << "Masukkan tahun kendaraan: ";
        cin >> data.thnBuat;

        if (searchNode(L, data.nopol) != nullptr) {
            cout << "Nomor polisi sudah terdaftar" << endl;
        } else {
            P = createNode(data);
            appendNode(L, P);
        }
        cout << endl;
    }

    cout << "\nDATA LIST\n\n";
    displayList(L);

    string cari;
    cout << "\nMasukkan Nomor Polisi yang dicari: ";
    cin >> cari;

    P = searchNode(L, cari);
    if (P != nullptr) {
        cout << "\nNomor Polisi : " << P->info.nopol << endl;
        cout << "Warna        : " << P->info.warna << endl;
        cout << "Tahun        : " << P->info.thnBuat << endl;
    } else {
        cout << "Data tidak ditemukan" << endl;
    }

    cout << "\nMasukkan Nomor Polisi yang akan dihapus: ";
    cin >> cari;

    P = searchNode(L, cari);
    if (P == nullptr) {
        cout << "Data tidak ditemukan." << endl;
    } else {
        address Q;
        if (P == L.First) {
            removeFirst(L, Q);
        } else if (P == L.Last) {
            removeLast(L, Q);
        } else {
            removeAfter(P->prev, Q);
        }
        cout << "Data dengan nomor polisi " << cari << " berhasil dihapus." << endl;
        freeNode(Q);
    }

    cout << "\nDATA LIST\n\n";
    displayList(L);

    return 0;
}

```
Kode ini merupakan file implementasi utama yang memanfaatkan Doubly Linked List untuk pengelolaan data kendaraan. File ini berperan sebagai program driver yang menampilkan cara penggunaan berbagai fungsi pada Doubly Linked List, sehingga memungkinkan program untuk menambahkan, menampilkan, mencari, serta menghapus data kendaraan secara dinamis dan efisien.
#### Full code Screenshot:
<img width="371" height="608" alt="image" src="https://github.com/user-attachments/assets/cf83c114-9d13-4e66-b440-6a499b544292" />

### [Doublelylist.cpp]

```C++
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

```

Kode ini merupakan file implementasi yang menyediakan fungsi-fungsi untuk mengelola Doubly Linked List, termasuk pembuatan node, penambahan node, penampilan list, pencarian berdasarkan nomor polisi, dan penghapusan node. File ini bekerja bersama header dan program utama agar pengelolaan data kendaraan dapat dilakukan secara dinamis dan terstruktur.
#### Full code Screenshot:
<img width="297" height="597" alt="image" src="https://github.com/user-attachments/assets/72c87bff-18ae-47e2-a37a-af7030386e51" />
<img width="396" height="268" alt="image" src="https://github.com/user-attachments/assets/7fd6dd95-d569-4031-9541-94612f551d7b" />




### [Doublelylist.h]

```C++
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

```

#### Output:
<img width="435" height="455" alt="image" src="https://github.com/user-attachments/assets/c9582208-7d5d-4771-9e80-00119b3a4d0c" />

Kode ini merupakan file header yang berisi deklarasi struktur data dan prototipe fungsi untuk mengimplementasikan Singly Linked List. File ini mendefinisikan tipe data, node, serta operasi dasar pada list yang digunakan sebagai acuan dalam file implementasi dan program utama agar pengelolaan data dapat berjalan secara terstruktur.

#### Full code Screenshot:
<img width="450" height="545" alt="image" src="https://github.com/user-attachments/assets/3d600d7d-e08d-4d01-8826-c1199e4892eb" />




## Kesimpulan
Secara keseluruhan, implementasi Singly dan Doubly Linked List memperlihatkan kemampuan untuk mengelola data secara dinamis dengan cara yang efisien, baik untuk tipe data sederhana maupun yang lebih kompleks, melalui berbagai operasi seperti penyisipan, penghapusan, dan pencarian elemen. Pemanfaatan pointer dan reference memungkinkan manipulasi data secara langsung di memori, sementara penggunaan fungsi modular, percabangan, dan perulangan membantu menjaga konsistensi data serta mempermudah proses traversing dan tampilan informasi. Dengan demikian, kode-kode ini menekankan prinsip efisiensi memori, fleksibilitas dalam mengakses dan mengubah elemen, serta pengendalian alur program yang responsif terhadap input pengguna, menjadi landasan penting dalam pemahaman struktur data.
## Referensi
[1] Lafore, R. (2002). Data Structures and Algorithms in C++ (2nd ed.). Sams Publishing.
[2] Cormen, T. H., Leiserson, C. E., Rivest, R. L., & Stein, C. (2009). Introduction to Algorithms (3rd ed.). MIT Press.
[3] Weiss, M. A. (2014). Data Structures and Algorithm Analysis in C++ (4th ed.). Pearson.
[4] Stroustrup, B. (2013). The C++ Programming Language (4th ed.). Addison-Wesley.
