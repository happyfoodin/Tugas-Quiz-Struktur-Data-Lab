#include <iostream>
using namespace std;
 
#define MAX 20
 
// Node BST untuk ID buku
struct Node {
    int data;
    Node* kiri;
    Node* kanan;
};
 
// Node queue untuk antrean mahasiswa
struct NodeAntrean {
    string nama;
    NodeAntrean* next;
};
 
//PRE-ORDER
void preOrder(Node* root) {
    if (root != NULL) {
        cout << root->data << " ";
        preOrder(root->kiri);
        preOrder(root->kanan);
    }
}
 
//IN-ORDER
void inOrder(Node* root) {
    if (root != NULL) {
        inOrder(root->kiri);
        cout << root->data << " ";
        inOrder(root->kanan);
    }
}
 
//POST-ORDER
void postOrder(Node* root) {
    if (root != NULL) {
        postOrder(root->kiri);
        postOrder(root->kanan);
        cout << root->data << " ";
    }
}
 
void tambah(Node*& root, int angka) {
    if (root == NULL) {
        root = new Node();
        root->data = angka;
        root->kiri = NULL;
        root->kanan = NULL;
 
        return;
    }
 
    // inputan lebih kecil dari data root
    else if (angka < root->data) {
        tambah(root->kiri, angka);
 
    // inputan lebih besar dari data root
    } else {
        tambah(root->kanan, angka);
    }
 
    return;
}
 
// Mencari ID buku pada BST
int cari(Node* root, int angka) {
    if (root == NULL) {
        return -1;
    }
 
    if (root->data == angka) {
        return root->data;
    } else if (angka < root->data) {
        return cari(root->kiri, angka);
    } else {
        return cari(root->kanan, angka);
    }
}
 
int main() {
    system("cls");
 
    // ===== BST : ID BUKU =====
    Node* root = NULL;
    int angka;
 
    cout << "Masukkan ID buku (0 untuk berhenti): ";
    cin >> angka;
 
    while (angka != 0) {
        tambah(root, angka);
        cin >> angka;
    }
 
    cout << endl;
 
    cout << "Pre Order : ";
    preOrder(root);
 
    cout << endl;
 
    cout << "In Order : ";
    inOrder(root);
 
    cout << endl;
 
    cout << "Post Order : ";
    postOrder(root);
 
    cout << endl;
 
    // Pencarian ID buku
    int cariId;
    cout << "\nMasukkan ID buku yang dicari : ";
    cin >> cariId;
 
    int hasilCari = cari(root, cariId);
 
    if (hasilCari != -1) {
        cout << "Buku ditemukan !" << endl;
    } else {
        cout << "Buku tidak ditemukan !" << endl;
    }
 
    // ===== QUEUE : ANTREAN PEMINJAMAN =====
    NodeAntrean* front = nullptr;
    NodeAntrean* rear = nullptr;
    int jumlahAntrean;
 
    cout << "\nBerapa mahasiswa yang antre : ";
    cin >> jumlahAntrean;
    cin.ignore();
 
    // Enqueue
    for (int i = 1; i <= jumlahAntrean; i++) {
        cout << "Nama mahasiswa ke-" << i << " : ";
 
        NodeAntrean* nodeBaru = new NodeAntrean();
        getline(cin, nodeBaru->nama);
        nodeBaru->next = nullptr;
 
        if (front == nullptr) {
            front = nodeBaru;
            rear = nodeBaru;
        } else {
            rear->next = nodeBaru;
            rear = nodeBaru;
        }
    }
 
    // Tampilkan antrean
    NodeAntrean* temp = front;
    cout << "\nIsi antrean : ";
 
    while (temp != nullptr) {
        cout << temp->nama << " | ";
        temp = temp->next;
    }
 
    cout << endl;
 
    // Dequeue (FIFO)
    cout << "\nProses peminjaman buku : " << endl;
 
    while (front != nullptr) {
        NodeAntrean* hapus = front;
        cout << "Dilayani : " << front->nama << endl;
        front = front->next;
        delete hapus;
 
        temp = front;
        cout << "Sisa antrean : ";
 
        while (temp != nullptr) {
            cout << temp->nama << " | ";
            temp = temp->next;
        }
 
        cout << endl;
    }
 
    // ===== STACK : RIWAYAT PENGEMBALIAN =====
    int stack[MAX];
    int top = -1;
    int jumlahKembali, idKembali;
 
    cout << "\nBerapa buku yang dikembalikan : ";
    cin >> jumlahKembali;
 
    if (jumlahKembali > MAX) {
        cout << "Riwayat maksimal " << MAX << " buku." << endl;
        jumlahKembali = MAX;
    }
 
    // Push
    for (int i = 1; i <= jumlahKembali; i++) {
        cout << "ID buku yang dikembalikan ke-" << i << " : ";
        cin >> idKembali;
 
        top++;
        stack[top] = idKembali;
    }
 
    // Tampilkan riwayat (yang terakhir dikembalikan paling depan)
    cout << "\nRiwayat pengembalian : ";
    for (int i = top; i >= 0; i--) {
        cout << stack[i] << " ";
    }
    cout << endl;
 
    // Pop
    if (top == -1) {
        cout << "Riwayat Kosong" << endl;
    } else {
        cout << "Pop : " << stack[top] << endl;
        top--;
 
        cout << "Riwayat setelah pop : ";
        for (int i = top; i >= 0; i--) {
            cout << stack[i] << " ";
        }
        cout << endl;
    }
 
    return 0;
}