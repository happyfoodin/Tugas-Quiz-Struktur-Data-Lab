#include <iostream>
using namespace std;
 
struct Node {
    string nim;
    string nama;
    int nilai;
    Node* next;
};
 
// Linear Search berdasarkan NIM pada linked list
Node* linearSearch(Node* head, string nim) {
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->nim == nim) {
            return temp;
        }
        temp = temp->next;
    }
    return nullptr;
}
 
// Binary Search pada array nilai yang sudah terurut
int binarySearch(int data[], int n, int target) {
    int low = 0;
    int high = n - 1;
 
    while (low <= high) {
        int mid = low + (high - low) / 2;
 
        if (data[mid] == target) {
            return mid;
        } else if (target < data[mid]) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
 
    return -1;
}
 
int main() {
    system("cls");
    int n;
 
    cout << "Masukkan jumlah mahasiswa : ";
    cin >> n;
    cin.ignore();
 
    cout << endl;
 
    // Dynamic array untuk kumpulan nilai
    int *nilai = new int[n];
 
    // Single linked list untuk data mahasiswa
    Node* head = nullptr;
    Node* tail = nullptr;
 
    for (int i = 0; i < n; i++) {
        Node* nodeBaru = new Node();
 
        cout << "Data mahasiswa ke-" << i + 1 << endl;
        cout << "NIM   : ";
        getline(cin, nodeBaru->nim);
        cout << "Nama  : ";
        getline(cin, nodeBaru->nama);
        cout << "Nilai : ";
        cin >> nodeBaru->nilai;
        cin.ignore();
        cout << endl;
 
        nodeBaru->next = nullptr;
        nilai[i] = nodeBaru->nilai;
 
        if (head == nullptr) {
            head = nodeBaru;
            tail = nodeBaru;
        } else {
            tail->next = nodeBaru;
            tail = nodeBaru;
        }
    }
 
    // Tampilkan data mahasiswa
    cout << "Data mahasiswa : " << endl;
    Node* temp = head;
    int no = 1;
    while (temp != nullptr) {
        cout << no << ". " << temp->nim << " - " << temp->nama << " - " << temp->nilai << endl;
        temp = temp->next;
        no++;
    }
 
    cout << endl;
 
    // Insertion Sort pada nilai (terkecil ke terbesar)
    cout << "Nilai sebelum diurutkan : ";
    for (int i = 0; i < n; i++) {
        cout << nilai[i] << " ";
    }
    cout << endl;
 
    for (int i = 1; i < n; i++) {
        int key = nilai[i];
        int j = i - 1;
 
        while (j >= 0 && nilai[j] > key) {
            nilai[j + 1] = nilai[j];
            j--;
        }
        nilai[j + 1] = key;
    }
 
    cout << "Nilai setelah diurutkan : ";
    for (int i = 0; i < n; i++) {
        cout << nilai[i] << " ";
    }
    cout << endl;
 
    // Linear Search berdasarkan NIM
    string cariNim;
    cout << "\nMasukkan NIM yang dicari : ";
    getline(cin, cariNim);
 
    Node* hasilNim = linearSearch(head, cariNim);
 
    if (hasilNim != nullptr) {
        cout << "Data ditemukan !" << endl;
        cout << hasilNim->nim << " - " << hasilNim->nama << " - " << hasilNim->nilai << endl;
    } else {
        cout << "Data tidak ditemukan !" << endl;
    }
 
    // Binary Search pada nilai yang sudah diurutkan
    int target;
    cout << "\nMasukkan nilai yang dicari : ";
    cin >> target;
 
    int hasil = binarySearch(nilai, n, target);
 
    if (hasil != -1) {
        cout << "Nilai ditemukan pada indeks : " << hasil << endl;
    } else {
        cout << "Nilai tidak ditemukan !" << endl;
    }
 
    delete[] nilai;
 
    return 0;
}