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
