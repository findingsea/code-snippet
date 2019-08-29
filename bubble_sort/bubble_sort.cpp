#include <iostream>
using namespace std;

void BubbleSort(int arr[], int length) {
  for (int len = length; len > 1; --len) {
    for (int j = 0; j < len - 1; ++j) {
      if (arr[j] > arr[j + 1]) {
        swap(arr[j], arr[j + 1]);
      }
    }
  }
}

int main() {
  int test_arr[] = {8, 5, 3, 2, 7, 6, 1, 4, 9};
  BubbleSort(test_arr, 10);
  for (auto &test : test_arr) {
    cout << test << " ";
  }
  cout << endl;
}