#include <iostream>
#include <vector>
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
        } else {
            cout << "Tabel penuh" << endl;
        }
    }
 
    void search(int key) {
        int index = hash1(key);
        int step = hash2(key);
        int initialIndex = index;
 
        while (status[index] != 0) {
            if (status[index] == 1 && table[index].first == key) {
                cout << "Data ditemukan : " << table[index].second << endl;
                return;
            }
 
            index = (index + step) % TABLE_SIZE;
 
            if (index == initialIndex) {
                break;
            }
        }
 
        cout << "Data tidak ditemukan" << endl;
    }
 
    void remove(int key) {
        int index = hash1(key);
        int step = hash2(key);
        int initialIndex = index;
 
        while (status[index] != 0) {
            if (status[index] == 1 && table[index].first == key) {
                status[index] = 2;
                cout << "Data berhasil dihapus" << endl;
                return;
            }
 
            index = (index + step) % TABLE_SIZE;
 
            if (index == initialIndex) {
                break;
            }
        }
 
        cout << "Data tidak ditemukan" << endl;
    }
 
    void display() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            cout << i << " : ";
 
            if (status[i] == 1) {
                cout << table[i].first << " - " << table[i].second;
            } else if (status[i] == 2) {
                cout << "DELETED";
            } else {
                cout << "EMPTY";
            }
 
            cout << endl;
        }
    }
};
 
int main() {
    system("cls");
    HashTable ht;
 
    // Insert 16 data mahasiswa (key = NIM, value = nama)
    // Key dengan hash1 yang sama akan collision, lalu dipindah memakai hash2
    ht.insert(251401001, "Andi");     // hash1 = 1
    ht.insert(251401021, "Budi");     // hash1 = 1
    ht.insert(251401041, "Citra");    // hash1 = 1
    ht.insert(251401002, "Dewi");     // hash1 = 2
    ht.insert(251401022, "Eka");      // hash1 = 2
    ht.insert(251401003, "Fajar");    // hash1 = 3
    ht.insert(251401005, "Gita");     // hash1 = 5
    ht.insert(251401007, "Hana");     // hash1 = 7
    ht.insert(251401027, "Indra");    // hash1 = 7
    ht.insert(251401010, "Joko");     // hash1 = 10
    ht.insert(251401030, "Kiki");     // hash1 = 10
    ht.insert(251401050, "Lina");     // hash1 = 10
    ht.insert(251401015, "Maya");     // hash1 = 15
    ht.insert(251401035, "Nanda");    // hash1 = 15
    ht.insert(251401019, "Oka");      // hash1 = 19
    ht.insert(251401039, "Putri");    // hash1 = 19
 
    cout << "Isi hash table : " << endl;
    ht.display();
 
    // Search
    cout << "\nMencari key 251401041 : " << endl;
    ht.search(251401041);
 
    cout << "\nMencari key 251401099 : " << endl;
    ht.search(251401099);
 
    // Remove
    cout << "\nMenghapus key 251401021 : " << endl;
    ht.remove(251401021);
 
    cout << "\nMenghapus key 251401099 : " << endl;
    ht.remove(251401099);
 
    cout << "\nIsi hash table setelah penghapusan : " << endl;
    ht.display();
 
    // Search data yang sudah dihapus
    cout << "\nMencari key 251401021 : " << endl;
    ht.search(251401021);
 
    // Search data yang berada setelah data yang dihapus
    cout << "\nMencari key 251401041 : " << endl;
    ht.search(251401041);
 
    return 0;
}