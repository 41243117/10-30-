#include <iostream>

using namespace std;

void print_arr(int* arr, int size) {
    for (int i = 0; i < size; i++) cout << arr[i] << " ";
    cout << '\n';
}

void change_size(int*& arr, int size, int new_size) {
    int* new_arr = new int[new_size];
    int* recycler = arr;
    copy(arr, arr + size, new_arr);

    for (int i = 0; i < new_size; i++) {
        if (i >= size)new_arr[i] = 0;
        else new_arr[i] = arr[i];
    }

    delete[] recycler;
    arr = new_arr;
}

int main() {
    int size ;
    int new_size ;
    cout << "size:";
    cin >> size;
    cout << endl << "new size:";
    cin >> new_size;
    cout << endl;
    int* arr = new int[size];
    
    for (int i = 0; i < size; i++) {
        arr[i] = i + 1;
    };

    print_arr(arr, size);  
    int memory = 1;
    for (int i = 1;; i++) {    //新的陣列空間已2的指數增長
        memory *= 2;
        if (memory >= new_size)break;
    }
    change_size(arr, size, memory);
    print_arr(arr, memory);  
}