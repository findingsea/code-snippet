#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void PrintVector(vector<int> &ve) {
  for (auto &v : ve) {
    cout << v << " ";
  }
  cout << endl;
}

void Swap(vector<int> &ve, int i, int j) {
  auto temp = ve[i];
  ve[i] = ve[j];
  ve[j] = temp;
}

int Partition(vector<int> &ve, int left, int right) {
  int pivot = right;
  --right;
  while (left < right) {
    while (ve[left] < ve[pivot] && left < right) ++left;
    while (ve[pivot] < ve[right] && left < right) --right;
    std::swap(ve[left], ve[right]);
  }
  if (ve[left] >= ve[pivot]) {
    std::swap(ve[left], ve[pivot]);
    pivot = left;
  }
  return pivot;
}

int PartitionLarge(vector<int> &ve, int left, int right) {
  cout << "--- PartitionLarge ---" << endl;
  int pivot = right;
  --right;
  while (left < right) {
    while (ve[left] >= ve[pivot] && left < right) ++left;
    while (ve[pivot] >= ve[right] && left < right) --right;
    std::swap(ve[left], ve[right]);
    PrintVector(ve);
    cout << "pivot " << pivot << endl;
  }
  if (ve[left] <= ve[pivot]) {
    std::swap(ve[left], ve[pivot]);
  }
  pivot = left;
  return pivot;
}

int FindKth(vector<int> &ve, int i, int j, int k) {
  int pivot = PartitionLarge(ve, i, j);
  if (k == pivot) {
    return ve[k];
  } else if (k < pivot) {
    return FindKth(ve, i, pivot - 1, k);
  } else {
    return FindKth(ve, pivot + 1, j, k);
  }
}

int main() {
  vector<int> ve = {3,3,3,3,3};
  // vector<int> ve = {5,2,4,1,3,6,0};
  cout << FindKth(ve, 0, ve.size() - 1, 1) << endl;
}