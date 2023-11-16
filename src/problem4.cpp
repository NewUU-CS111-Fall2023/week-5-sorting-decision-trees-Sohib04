#include <iostream>

using namespace std;

int counter(int arr[], int n){
    int count = 0;
    for(int i = 0; i<n; i++){
        if(arr[i+1]<arr[i]){
            count++;
        }
    }
    return count;
}

int main(){

    int arr[]{5, 2, 8, 1, 4, 6, 9};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<counter(arr, n);

    return 0;
}
