#include <iostream>
#include <conio.h>
#include <stdlib.h>
#define MAX 20

using namespace std;
 
struct Queue {
    char data[MAX];
    int rear, front;
};

Queue Q;
int PIL;
char PILIHAN[2];

bool isEmpty() {
    return (Q.front == -1);
}

bool isFull() {
    return (Q.rear == MAX - 1);
}

void Inisialisasi() {
    Q.front = -1;
    Q.rear = -1;
}
void INSERT()  {
    char HURUF;

    if (isFull()) {
        cout << "Queue is full" << endl;
        return;
    }
    cout << "Masukkan karakter: ";
    cin >> HURUF;

    if (isEmpty()) {
        Q.front = 0;
    }
    Q.rear++;
    Q.data[Q.rear] = HURUF;
    cout << "Data insert succes" << endl;
}
void DELETE() {
    if (isEmpty()) {
        cout << "Queue is empty" << endl;
        return;
    }
    char deleted = Q.data[Q.front];
    cout << "Data deleted : " << deleted << endl;
    
    if (Q.front == Q. rear) {
        Inisialisasi();
    }else {
        Q.front++;
    }
}
void CETAKLAYAR() {
    if (isEmpty()) {
        cout << "Queue is empty" << endl;
        return;
    }
    cout << "Data in queue : ";
    for (int i = Q.front; i <= Q.rear; i++) {
        cout << Q.data[i] << " ";
    }
    cout << endl;
}
int main(){
    Inisialisasi();
    do
    {
        cout<<"QUEUE"<<endl;
        cout<<"=============="<<endl;
        cout<<"1. INSERT"<<endl;
        cout<<"2. DELETE"<<endl;
        cout<<"3. CETAK QUEUE"<<endl;
        cout<<"4. QUIT"<<endl;
        cout<<"PILIHAN : "; cin>>PILIHAN;
        PIL=atoi(PILIHAN);

        switch (PIL)
        {
        case 1:
            INSERT ();
            break;
        case 2:
            DELETE();
            break;
        case 3:
            CETAKLAYAR ();
            break;
        default:
            cout<<"TERIMA KASIH"<<endl;
            break;
        }
        cout<<"press any key to continue"<<endl;
        getch();
        system("cls");
    } while (PIL<4);
    
    return 0;
}