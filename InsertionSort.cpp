#include <iostream>

//Insertion Sort Algorithm

using namespace std;

void InsertionSort(int array[], int size){
    for (int i = 1; i < size; ++i) {
        int key = array[i];
        int j = i - 1;
        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = key;

    }
    return ;
}

int main() {
    int n ;
    cin>>n;
    int arr[n];
    for(int i = 0 ; i < n ; i++){
        cin>>arr[i];
    }
    InsertionSort(arr,n);
    for(int i = 0 ; i < n ; i++ )
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}