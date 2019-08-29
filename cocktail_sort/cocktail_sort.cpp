#include <iostream>
using namespace std;

void CocktailSort(int arr[], int length) {
  int left = 0, right = length - 1;
  while (left < right) {
    int idx = left;
    for (; idx < right; ++idx) {
      if (arr[idx] > arr[idx + 1]) {
        swap(arr[idx], arr[idx + 1]);
      }
    }
    --right;
    for (; idx > left; --idx) {
      if (arr[idx - 1] > arr[idx]) {
        swap(arr[idx - 1], arr[idx]);
      }
    }
    ++left;
  }
}

int main() {
  int test_arr[] = {8, 5, 3, 2, 7, 6, 1, 4, 9};
  CocktailSort(test_arr, 10);
  for (auto &test : test_arr) {
    cout << test << " ";
  }
  cout << endl;
}