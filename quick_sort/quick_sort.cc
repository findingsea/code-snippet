#include <iostream>
#include <vector>
using namespace std;

void PrintVector(vector<int> &ve) {
  for (auto &v : ve) {
    cout << v << " ";
  }
  cout << endl;
}

int Partition(vector<int> &arr, int left, int right) {
  int pivot = right;
  --right;
  while (left < right) {
    while (arr[left] <= arr[pivot] && left < right) ++left;
    while (arr[pivot] <= arr[right] && left < right) --right;
    std::swap(arr[left], arr[right]);
  }
  if (arr[left] >= arr[pivot]) {
    std::swap(arr[left], arr[pivot]);
    pivot = left;
  }
  PrintVector(arr);
  return pivot;
}

void QuickSort(vector<int> &arr, int begin, int end) {
  if (begin >= end) return;
  int pivot = Partition(arr, begin, end);
  QuickSort(arr, begin, pivot - 1);
  QuickSort(arr, pivot + 1, end);
}

int main() {
  // vector<int> ve = {4, 5, 5, 3, 2, 6, 9, 1, 8, 7};
  vector<int> ve ={5,1,1,2,0,0};
  QuickSort(ve, 0, ve.size() - 1);
}