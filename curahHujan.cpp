// Gandung Bisma Alvareza (245150300111034)
// Stefanus Evan Anggawardhana (245150307111039)
// Akbar Bintang Kusuma (245150307111050)

#include <iostream>
using namespace std;

class Hari {
public:
    int nilai;
    Hari* next;
    Hari(int n): nilai(n), next(nullptr){}
};

class Curah{
public:
    Hari* headHari;
    Curah* next;
    Curah(Hari* baru) : headHari(baru), next(nullptr){}
};
    
void tambahHari(Hari*& head,int y){
    Hari* baru = new Hari(y);
    if(!head){
        head = baru;
    } else {
        Hari* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = baru;
    }

}

void tambahCurah(Curah*& head, Hari* baruHari){
    Curah* baru = new Curah(baruHari);
    if(!head){
        head = baru;
    } else {
        Curah* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = baru;
    }

}

void tampilkan(Curah* head){
    int i = 1;
    while (head){
        cout << "Curah hari ke-" << i++ << ": ";
        Hari* temp = head-> headHari;
        while(temp){
            cout << temp-> nilai <<" ";
            temp = temp->next;
        }
        cout << endl;
        head = head->next;
    }
}

int main() {
    Curah* listCurah = nullptr;
    int pilihan;
    do {
        cout << "Program Logging Curah Hujan\n";
        cout << "List program:\n";
        cout << "1. Tambah curah hujan harian\n";
        cout << "2. Tampilkan semua curah hujan\n";
        cout << "3. Keluar\n";
        cout << "Pilih masukkan (1-3): ";
        cin >> pilihan;

        switch (pilihan) {
        case 1: {
            Hari* mingguBaru = nullptr;
            int jumlahCurah, nilai;

            cout << "Berapa jumlah yang ingin dimasukkan? ";
            cin >> jumlahCurah;

            for (int i=0; i<jumlahCurah; i++){
                cout << "Masukkan curah hujan ke-" << (i+1) << ": ";
                cin >> nilai;
                tambahHari(mingguBaru, nilai);
            }
            tambahCurah(listCurah, mingguBaru);
            break;
        }
        case 2:
            tampilkan(listCurah);
            break;
        case 3:
            cout << "Program selesai\n";
            break;
        default:
            cout << "Pilihan tidak valid\n";
            break;
        }
    } while (pilihan != 3);

    return 0;
}
