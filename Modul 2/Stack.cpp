#include <iostream>
#include <conio.h>
#include <stdlib.h>

#define MAX 20

using namespace std;

struct Stack {
    int data[MAX];
    int atas;
};

Stack Tumpuk;
int PIL;
char PILIHAN[2];

void Inisialisasi();
int kosong();
int penuh();
void input(int data);
void hapus();
void tampil();
void bersih();

void Inisialisasi() {
    Tumpuk.atas = -1;
}

int kosong() {
    if (Tumpuk.atas == -1)
        return 1;
    else
        return 0;
}
int penuh ()
{
    if(Tumpuk.atas == MAX-1)
        return 1;
    else
        return 0;
}

void input (int data)
{
    if (kosong()==1)
    {
        Tumpuk.atas++;
        Tumpuk.data[Tumpuk.atas] = data;
        cout << "Data " << Tumpuk.data[Tumpuk.atas]
             << " Masuk Ke Stack ";
    }
    else if(penuh()==0)
    {
        Tumpuk.atas++;
        Tumpuk.data[Tumpuk.atas] = data;
        cout << "Data " << Tumpuk.data[Tumpuk.atas]
             << " Masuk Ke Stack ";
    }
    else
        cout << "Tumpukan Penuh";
}

void hapus()
{
    if(kosong()== 0)
    {
        cout << "Data Teratas Sudah Terambil";
        Tumpuk.atas--;
    }
    else
    cout <<" Data Kosong";
}

void tampil()
{
    if(kosong()== 0)
    {
        for(int i = Tumpuk.atas; i>=0;  i--)
        {
            cout <<"\nTumpukan Ke " << i << " = " << Tumpuk.data[i];
        }
    }
    else
    cout << "Tumpukan Kosong";
}

void bersih ()
{
    Tumpuk.atas = -1;
    cout << "Tumpukan Kosong !";
}

int main() {
    int data;
    Inisialisasi();
    do {
        cout<<"STACK"<<endl;
        cout<<"=============="<<endl;
        cout<<"1. Push"<<endl;
        cout<<"2. Pop"<<endl;
        cout<<"3. Cetak data"<<endl;
        cout<<"4. Clear data"<<endl;
        cout<<"5. Exit"<<endl;
        cout<<"Pilih Menu : ";
        cin>>PILIHAN;
        PIL = atoi(PILIHAN);

        
        switch (PIL) {
            case 1:
                cout <<"Masukkan Data : ";
                cin >> data;
                input(data);
                break;
            case 2:
                hapus();
                break;
            case 3:
                tampil();
                break;
            case 4:
                bersih();
                break;
            default:
                cout << "Terima Kasih" << endl;
                break;
        }
        cout << "\nPress any key to continue";
        getch ();
        system("cls");
    }while (PIL < 5);
    return 0;
}