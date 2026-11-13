#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int TABLE_SIZE = 20;

class HashTable {
private:
    vector<pair<int, string>> table;
    vector<int> status;

    int hash1(int key) {
        return key % TABLE_SIZE;
    }

    int hash2(int key) {
        return 19 - (key % 19);
    }

public:
    HashTable() {
        table.resize(TABLE_SIZE);
        status.resize(TABLE_SIZE, 0);
    }

    void insert(int key, string value) {
        int index = hash1(key);
        int step = hash2(key);
        int initialIndex = index;

        int deletedIndex = -1;

        while (true) {
            if (status[index] == 1 && table[index].first == key) {
                table[index].second = value;
                cout << "Data berhasil diperbarui!" << endl;
                return;
            }

            if (status[index] == 2 && deletedIndex == -1) {
                deletedIndex = index;
            }

            if (status[index] == 0) {
                if (deletedIndex != -1) {
                    index = deletedIndex;
                }

                table[index] = make_pair(key, value);
                status[index] = 1;

                cout << "Data berhasil ditambahkan!" << endl;
                return;
            }

            index = (index + step) % TABLE_SIZE;

            if (index == initialIndex) {
                break;
            }
        }

        if (deletedIndex != -1) {
            table[deletedIndex] = make_pair(key, value);
            status[deletedIndex] = 1;
            cout << "Data berhasil ditambahkan!" << endl;
        } else {
            cout << "Hash Table penuh!" << endl;
        }
    }

    void search(int key) {
        int index = hash1(key);
        int step = hash2(key);
        int initialIndex = index;

        while (status[index] != 0) {
            if (status[index] == 1 && table[index].first == key) {
                cout << "Data ditemukan!" << endl;
                cout << "NIM  : " << table[index].first << endl;
                cout << "Nama : " << table[index].second << endl;
                return;
            }

            index = (index + step) % TABLE_SIZE;

            if (index == initialIndex) {
                break;
            }
        }

        cout << "Data tidak ditemukan!" << endl;
    }

    void remove(int key) {
        int index = hash1(key);
        int step = hash2(key);
        int initialIndex = index;

        while (status[index] != 0) {
            if (status[index] == 1 && table[index].first == key) {
                status[index] = 2;
                cout << "Data berhasil dihapus!" << endl;
                return;
            }

            index = (index + step) % TABLE_SIZE;

            if (index == initialIndex) {
                break;
            }
        }

        cout << "Data tidak ditemukan!" << endl;
    }

    void display() {
        cout << "\n========== ISI HASH TABLE ==========\n";

        for (int i = 0; i < TABLE_SIZE; i++) {
            cout << i << " : ";

            if (status[i] == 1) {
                cout << table[i].first << " - " << table[i].second;
            } 
            else if (status[i] == 2) {
                cout << "DELETED";
            } 
            else {
                cout << "EMPTY";
            }

            cout << endl;
        }

        cout << "====================================\n";
    }
};

int main() {
    system("cls");

    HashTable ht;

    int pilihan;
    int nim;
    string nama;

    do {
        cout << "\n===== MENU HASH TABLE =====" << endl;
        cout << "1. Insert Data Mahasiswa" << endl;
        cout << "2. Search Data Mahasiswa" << endl;
        cout << "3. Remove Data Mahasiswa" << endl;
        cout << "4. Display Hash Table" << endl;
        cout << "5. Exit" << endl;
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "\nMasukkan NIM  : ";
                cin >> nim;

                cin.ignore();

                cout << "Masukkan Nama : ";
                getline(cin, nama);

                ht.insert(nim, nama);
                break;

            case 2:
                cout << "\nMasukkan NIM yang dicari: ";
                cin >> nim;

                ht.search(nim);
                break;

            case 3:
                cout << "\nMasukkan NIM yang ingin dihapus: ";
                cin >> nim;

                ht.remove(nim);
                break;

            case 4:
                ht.display();
                break;

            case 5:
                cout << "\nProgram selesai." << endl;
                break;

            default:
                cout << "\nPilihan tidak valid!" << endl;
        }

    } while (pilihan != 5);

    return 0;
    }
