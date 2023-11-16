#include <iostream>
#include <vector>
using namespace std;

void sort(vector<string>& arr, int n){

    if(n%2==0){
        for(int i = 0; i<=n-1; i+=2){
            string temp = arr[i+1];
            arr[i+1] = arr[i];
            arr[i] = temp;
        }
    }
    else{
        string soldier = arr[n-1];
        arr.pop_back();
        for(int i = 0; i<n-1; i+=2){
            string temp = arr[i+1];
            arr[i+1] = arr[i];
            arr[i] = temp;
        }
        arr.push_back(soldier);
    }

}

int main(){

    vector<string> arr;
    cout<<"Input size: "<<endl;
    int size;
    cin>>size;
    cout<<"Enter the list: "<<endl;
    string soldier;
    for(int i = 0; i<size; i++){
        cin>>soldier;
        arr.push_back(soldier);
    }
    sort(arr, size);
    for(auto i:arr){
        cout<<i<<endl;
    }
    return 0;
}
