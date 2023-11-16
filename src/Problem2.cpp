#include <iostream>
using namespace std;

void selectionSort(int arr[], int n){
    int min_indx;
    for(int i = 0; i<n-1; i++){
        min_indx = i;
        for(int j = i+1; j<n; j++){
            if(arr[j]<arr[min_indx]){
                min_indx = j;
            }
        }
        int temp = arr[min_indx];
        arr[min_indx] = arr[i];
        arr[i] = temp;
    }
}

int main(){

    int arr[]{8, 3, 12, 6, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    selectionSort(arr, n);
    for(auto i: arr){
        cout<<i<<endl;
    }

    return 0;
}
