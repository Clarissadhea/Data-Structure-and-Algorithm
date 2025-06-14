#include<iostream>
#include<string>

using namespace std;

struct Kendaraan {
    string plat;
    string jenis;
    string nama_pemilik;
    string alamat;
    string kota;
};

int main(){
    Kendaraan kendaraan;
    kendaraan.plat = "DA1234MK";
    kendaraan.jenis = "RUSH";
    kendaraan.nama_pemilik = "Andika Hartanto";
    kendaraan.alamat = "Jl. Kayu Tangi 1";
    kendaraan.kota = "Banjarmasin";

    cout << "a. Plat Nomor Kendaraan : " << kendaraan.plat << endl;
    cout << "b. Jenis Kendaraan : " << kendaraan.jenis << endl;
    cout << "c. Nama Pemilik : " << kendaraan.nama_pemilik << endl;
    cout << "d. Alamat : " << kendaraan.alamat << endl;
    cout << "e. Kota : " << kendaraan.kota << endl;

    return 0;
}