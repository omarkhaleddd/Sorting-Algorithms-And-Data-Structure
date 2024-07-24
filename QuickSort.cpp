#include <iostream>

//QuickSort Algorithm

using namespace std;
int Partition(int arr[], int s, int e) {
    int pivot = arr[e];
    int pIndex = s;
    for(int j = s;j<e;j++){
        if(arr[j]<pivot){
            int temp = arr[j];
            arr[j]= arr[pIndex];
            arr[pIndex] = temp;
            pIndex++;
//            cout<< arr[j]<< " ";
        }
//        cout <<endl<<arr[j]<<endl;
    }
    int temp = arr[e];
    arr[e] = arr[pIndex];
    arr[pIndex] = temp;
    return  pIndex;
}

void QuickSort(int arr[],int s, int e){
    if(s<e){
        int p = Partition(arr, s, e);
        QuickSort(arr, s, p - 1);
        QuickSort(arr, p + 1, e);
    }
}



int main() {
    int n ;
    cin>>n;
    int arr[n];
    for(int i = 0 ; i < n ; i++){
        cin>>arr[i];
    }
    QuickSort(arr,0,n-1);
    for(int i = 0 ; i < n ; i++ )
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}