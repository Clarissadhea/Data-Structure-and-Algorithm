#include <iostream>
#include <conio.h>
#include <random>
#include <vector>
#include <algorithm>

using namespace std;

void sequentialSearch(const vector<int> &nums, int target){
    bool found = false;
    vector<int> positions;
    
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == target) {
            found = true;
            positions.push_back(i);
        }
    }
    
    if (found) {
        cout << "Found " << positions.size() << " in the nums at index(es): ";
        for (int i = 0; i < positions.size(); i++) {
            cout << positions[i];
            if (i < positions.size() - 1) cout << " ";
        }
        cout << endl;
    } else {
        cout << target << " not found in the array" << endl;
    }
}

void binarySearch(const vector<int> &nums, int target){
        int left = 0;
    int right = nums.size() - 1;
    bool found = false;
    vector<int> positions; 
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (nums[mid] == target) {
            found = true;
            
            int leftPos = mid;
            while (leftPos >= 0 && nums[leftPos] == target) {
                positions.insert(positions.begin(), leftPos);
                leftPos--;
            }
            
            int rightPos = mid + 1;
            while (rightPos < nums.size() && nums[rightPos] == target) {
                positions.push_back(rightPos);
                rightPos++;
            }
            
            break;
        }
        else if (nums[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    
    if (found) {
        cout << "Found " << target << " in the nums at index(es): ";
        for (int i = 0; i < positions.size(); i++) {
            cout << positions[i];
            if (i < positions.size() - 1) cout << " ";
        }
        cout << endl;
    } else {
        cout << target << " not found in the array" << endl;
    }
}

void clearScreen(){
    system("cls");
}

void explain(){
    cout << "\n1. SEQUENTIAL SEARCHING" << endl;
    cout << "Pengertian : Sequential searching adalah algoritma pencarian " << endl;
    cout << "yang memeriksa setiap elemen dalam data secara berurutan dari " << endl;
    cout << "awal hingga menemukan elemen yang dicari atau mencapai akhir data." << endl;
    cout << "KELEBIHAN :" << endl;
    cout << "- Sederhana dan mudah dipahami." << endl;
    cout << "- Dapat digunakan pada array yang tidak terurut." << endl;
    cout << "- Dapat digunakan pada struktur data apa saja (array, linked list, dll)." << endl;
    cout << "- Cocok untuk dataset kecil." << endl;
    cout << "KEKURANGAN :" << endl;
    cout << "- Kompleksitas waktu O(n) - lambat untuk data besar." << endl;
    cout << "- Tidak efisien untuk pencarian berulang." << endl;
    cout << "- Harus memeriksa semua elemen dalam kasus terburuk." << endl;
    
    cout << "\n======================================================" << endl;
    cout << "2. BINARY SEARCHING" << endl;
    cout << "Pengertian: Binary searching adalah algoritma pencarian yang bekerja dengan " << endl;
    cout << "membagi data menjadi dua bagian dan mengeliminasi setengah data pada setiap iterasi." << endl;
    cout << "KELEBIHAN :" << endl;
    cout << "- Sangat efisien dengan kompleksitas waktu O(log n)." << endl;
    cout << "- Sangat cepat untuk dataset besar." << endl;
    cout << "- Jumlah perbandingan lebih sedikit" << endl;
    cout << "- Lebih efisien dibanding sequential search." << endl;
    cout << "KEKURANGAN :" << endl;
    cout << "- Hanya dapat digunakan pada array yang terurut." << endl;
    cout << "- Memerlukan preprocessing (sorting) jika data belum terurut." << endl;
    cout << "- Lebih kompleks untuk diimplementasikan." << endl;
    cout << "- Kurang efisien untuk dataset kecil." << endl;
    
    cout << "\n======================================================" << endl;
    cout << "KESIMPULAN:" << endl;
    cout << "Sequential Search cocok untuk data kecil atau tidak terurut " << endl;
    cout << "dan binary Search cocok untuk data besar yang terurut atau " << endl;
    cout << "pencarian berulang pada dataset yang sama" << endl;
    cout << "======================================================" << endl;
}

int main() {
    int opt, target;
    do {
        cout << "Pilih menu" << endl;
        cout << "1. Sequential Searching" << endl;
        cout << "2. Binary Searching" << endl;
        cout << "3. Jelaskan Perbedaan Sequential Searching dan Binary Searching!" << endl;
        cout << "4. Exit" << endl;
        cout << "Pilih: ";
        cin >> opt;

        switch (opt) {
            case 1: {
                vector<int> nums (100);
                mt19937_64 rng(random_device{}());
                uniform_int_distribution<int> dist(1, 50);

                for (auto &val: nums) {
                    val = (dist(rng));
                }

                cout << "100 angka acak telah digenerate." << endl;
                cout << "Nums:" << endl;
                
                for (int i = 0; i < nums.size(); i++) {
                    cout << "[" << i << "]:" << nums[i] << " ";
                    if ((i + 1) % 10 == 0) {
                        cout << endl;
                    }
                }
                if (nums.size() % 10 != 0) {
                    cout << endl;
                }

                cout << "Masukkan angka yang ingin dicari: "; cin >> target;

                sequentialSearch(nums, target);
                break;
            }

            case 2: {
                int size;
                cout << "Masukkan ukuran vector: ";
                cin >> size;

                vector<int> nums(size);
                mt19937_64 rng(random_device{}());
                uniform_int_distribution<int> dist(1, 100);

                for (auto &val: nums) {
                    val = (dist(rng));
                }
                sort(nums.begin(), nums.end());

                cout << size << " angka acak telah digenerate dan diurutkan." << endl;
                cout << "Nums:" << endl;
                
                for (int i = 0; i < nums.size(); i++) {
                    cout << "[" << i << "]:" << nums[i] << " ";
                    if ((i + 1) % 10 == 0) {
                        cout << endl;
                    }
                }
                if (nums.size() % 10 != 0) {
                    cout << endl;
                }

                cout << "Masukkan angka yang ingin dicari: "; cin >> target;

                binarySearch(nums, target);
                break;
            }

            case 3:
                explain();
                break;

            case 4:
                cout << "\nTERIMA KASIH\n";
                cout << "Programme was made by Clarissa Dhea Allisya (2410817220023)" << endl;
                break;

            default:
                cout << "Opsi tidak terdefinisi, mohon masukkan ulang opsi" << endl;
                break;
        }

        if (opt != 4) {
            cout << "\nTekan sembarang tombol untuk melanjutkan...";
            getch();
            clearScreen();
        }

    } while (opt != 4);

    return 0;
}