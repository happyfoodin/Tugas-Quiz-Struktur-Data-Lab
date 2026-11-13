# Quiz Lab Struktur Data

## Identitas

- Nama: Hafifuddin
- NIM: 251401140
- Program Studi: Ilmu Komputer
- Lab: 4

## Deskripsi Program

### 1. Quiz No. 1 – Dynamic Array, Linked List, dan Searching

Program ini mengimplementasikan beberapa struktur data dan algoritma:
- Dynamic Array: Menyimpan data nilai dengan ukuran yang ditentukan pengguna.
- Linked List: Menyimpan data mahasiswa berupa NIM, nama, dan nilai.
- Insertion Sort: Mengurutkan data nilai secara ascending.
- Linear Search: Mencari mahasiswa berdasarkan NIM.
- Binary Search: Mencari nilai pada array yang telah diurutkan.

### 2. Quiz No. 2 – Binary Search Tree, Queue, dan Stack

Program ini mengimplementasikan tiga struktur data:
- Binary Search Tree (BST): Menyimpan data dan menampilkan traversal Preorder, Inorder, dan Postorder.
- Queue: Mengelola antrean mahasiswa menggunakan prinsip FIFO (First In, First Out).
- Stack: Mengelola data menggunakan prinsip LIFO (Last In, First Out).

### 3. Quiz No. 3 – Graph, BFS, DFS, dan Dijkstra

Program ini mengimplementasikan struktur data Graph menggunakan Adjacency Matrix. Fitur yang tersedia:
- BFS (Breadth-First Search): Melakukan penelusuran graph secara melebar.
- DFS (Depth-First Search): Melakukan penelusuran graph secara mendalam.
- Dijkstra: Menentukan jarak terpendek dan menampilkan rute dari vertex awal ke vertex tujuan.

### 4. Quiz No. 4 – Hash Table dengan Double Hashing

Program ini mengimplementasikan Hash Table menggunakan metode Double Hashing untuk menangani collision. Fitur yang tersedia:
- Insert: Menambahkan data mahasiswa ke dalam hash table.
- Search: Mencari data berdasarkan NIM.
- Remove: Menghapus data berdasarkan NIM.
- Display: Menampilkan isi hash table beserta status setiap slot.

## Struktur Folder

```text
Quiz-Lab-Struktur-Data/
│
├── Quiz_no_1.cpp
├── Quiz_no_2.cpp
├── Quiz_no_3.cpp
├── Quiz_no_4.cpp
│
└── README.md
```

## Cara Menjalankan Program

Pastikan komputer sudah memiliki compiler C++, seperti GCC/G++ (MinGW).

1. Buka folder repository menggunakan Visual Studio Code atau terminal.
2. Buka terminal pada folder tersebut.
3. Compile program yang ingin dijalankan.

Quiz No. 1:
```bash
g++ Quiz_no_1.cpp -o quiz1
```

Quiz No. 2:
```bash
g++ Quiz_no_2.cpp -o quiz2
```

Quiz No. 3:
```bash
g++ Quiz_no_3.cpp -o quiz3
```

Quiz No. 4:
```bash
g++ Quiz_no_4.cpp -o quiz4
```

4. Jalankan program yang sudah berhasil di-compile.

Untuk Windows:
```bash
quiz1
```

Ganti `quiz1` dengan `quiz2`, `quiz3`, atau `quiz4` sesuai program yang ingin dijalankan.

## Video Penjelasan

Video berisi penjelasan alur kerja keempat program serta demonstrasi contoh eksekusi masing-masing program.

Link YouTube: 
