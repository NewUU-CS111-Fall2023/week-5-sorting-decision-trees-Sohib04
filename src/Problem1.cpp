/*
 * Author:Abdimannabov Sohibjon
 * Date:16/11/23
 */

#include <iostream>
#include <regex>
using namespace std;

void bubbleSort(string arr[], int n){
    bool swapped;
  do {
    swapped = false;
    for (int i = 0; i < n - 1; i++) {
      regex punctuation("[^a-zA-Z0-9 ]");
      string str1 = regex_replace(arr[i], punctuation, "");
      string str2 = regex_replace(arr[i + 1], punctuation, "");
      if (str1 > str2) {
        swap(arr[i], arr[i + 1]);
        swapped = true;
      }
    }
  } while (swapped);
}

int main() {
    string arr[] = {"Catcher in the Rye", "Pride and Prejudice", "To Kill a Mockingbird", "The Great Gatsby", "Moby Dick"};
    int size = sizeof(arr)/sizeof(arr[0]);
    bubbleSort(arr, size);
    for(auto i:arr){
        cout<<i<<endl;
    }
}
