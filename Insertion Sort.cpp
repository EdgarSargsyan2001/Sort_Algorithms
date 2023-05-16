#include <iostream>
using namespace std;

int main() {
  const int size = 5;
  int arr[size] = {};

  for(int i = 0;i < size;i++){
    std::cin >> arr[i];
  }
  
  int key = 0;
  int j = 0;
  
  for (int i = 1; i < size; i++) {
    
    key = arr[i];
    j = i - 1;
    
    while (j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      j--;
    }
    
    arr[j + 1] = key;
  }

  
  
  for (int i = 0; i < size; i++) {
    cout << arr[i] << " ";
  }
}