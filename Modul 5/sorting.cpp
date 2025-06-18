#include <iostream>
#include <conio.h>
#include <functional>
#include <chrono>
#include <string>
#include <iomanip>

using namespace std;

string name, id;

void timeSort(const function<void()>& sortFunc, const string& sortName) {
    auto start = chrono::high_resolution_clock::now();
    sortFunc();
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;
    cout << fixed << setprecision(10);
    cout << sortName << "\ntook " << duration.count() << " seconds\n";
}

void insertionSort(){
    string arr = name;
    cout << "Unsorted : " << arr << endl;

    int n = arr.length();
    for (int i = 1; i < n; i++) {
        char key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }

    cout << "Result : " << arr << endl;
}

void mergeSort(){
    string arr = name;
    cout << "Unsorted : " << arr << endl;

    int n = arr.length();
    for (int size = 1; size < n; size = 2 * size) {
        for (int left = 0; left < n - 1; left += 2 * size) {
            int mid = min(left + size - 1, n - 1);
            int right = min(left + 2 * size - 1, n - 1);
            
            int n1 = mid - left + 1;
            int n2 = right - mid;
            
            string L = arr.substr(left, n1);
            string R = arr.substr(mid + 1, n2);
            
            int i = 0, j = 0, k = left;
            while (i < n1 && j < n2) {
                if (L[i] <= R[j]) arr[k++] = L[i++];
                else arr[k++] = R[j++];
            }
            while (i < n1) arr[k++] = L[i++];
            while (j < n2) arr[k++] = R[j++];
        }
    }

    cout << "Result : " << arr << endl;
}

void shellSort(){
    string arr = name;
    cout << "Unsorted : " << arr << endl;

    int n = arr.length();
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            char temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];
            arr[j] = temp;
        }
    }

    cout << "Result : " << arr << endl;
}

void bubbleSort(){
    string arr = id;
    cout << "Unsorted : " << arr << endl;

    int n = arr.length();
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                char temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    cout << "Result : " << arr << endl;
}

void quickSort(){
    string arr = id;
    cout << "Unsorted : " << arr << endl;

    int n = arr.length();
    int stack[100];
    int top = -1;
    
    stack[++top] = 0;
    stack[++top] = n - 1;
    
    while (top >= 0) {
        int high = stack[top--];
        int low = stack[top--];
        
        if (low < high) {
            char pivot = arr[high];
            int i = low - 1;
            
            for (int j = low; j < high; j++) {
                if (arr[j] < pivot) {
                    i++;
                    char temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
            char temp = arr[i + 1];
            arr[i + 1] = arr[high];
            arr[high] = temp;
            int pi = i + 1;
            
            if (pi - 1 > low) {
                stack[++top] = low;
                stack[++top] = pi - 1;
            }
            if (pi + 1 < high) {
                stack[++top] = pi + 1;
                stack[++top] = high;
            }
        }
    }

    cout << "Result : " << arr << endl;
}

void selectionSort(){
    string arr = id;
    cout << "Unsorted : " << arr << endl;

    int n = arr.length();
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++)
            if (arr[j] < arr[minIdx])
                minIdx = j;
        char temp = arr[minIdx];
        arr[minIdx] = arr[i];
        arr[i] = temp;
    }

    cout << "Result : " << arr << endl;
}

int main(){
    name = "Clarissa Dhea Allisya";
    id = "2410817220023";

    int choice;
    do {
        cout << "-----------------------\n";
        cout << "|       SORTING       |\n";
        cout << "-----------------------\n";
        cout << "1. Insertion Sort\n";
        cout << "2. Merge Sort\n";
        cout << "3. Shell Sort\n";
        cout << "4. Bubble Sort\n";
        cout << "5. Quick Sort\n";
        cout << "6. Selection Sort\n";
        cout << "7. Exit\n";
        cout << "-----------------------\n";
        cout << "Masukkan Pilihan : ";
        cin >> choice;

        switch (choice) {
            case 1: timeSort([&]() { insertionSort(); }, "Insertion Sort"); break;
            case 2: timeSort([&]() { mergeSort(); }, "Merge Sort"); break;
            case 3: timeSort([&]() { shellSort(); }, "Shell Sort"); break;
            case 4: timeSort([&]() { bubbleSort(); }, "Bubble Sort"); break;
            case 5: timeSort([&]() { quickSort(); }, "Quick Sort"); break;
            case 6: timeSort([&]() { selectionSort(); }, "Selection Sort"); break;
            default: cout <<"\nTERIMA KASIH" << endl;
            cout <<"Program was made by Clarissa Dhea Allisya (2410817220023)." << endl;
        }
        cout<<"\npress any key to continue"<<endl;
            getch();
            system("cls");
    } while (choice != 7);

    return 0;
}