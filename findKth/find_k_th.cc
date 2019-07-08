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

int FindKth(vector<int> &ve, int i, int j, int k) {
  int pivot = (i + j) / 2;
  Swap(ve, i, pivot);
  pivot = i;
  for (int idx = i + 1; idx <= j; ++idx) {
    if (ve[idx] < ve[pivot]) {
      Swap(ve, pivot + 1, idx);
      Swap(ve, pivot, pivot + 1);
      ++pivot;
    }
  }
  if (k == pivot) {
    return ve[k];
  } else if (k < pivot) {
    return FindKth(ve, i, pivot - 1, k);
  } else {
    return FindKth(ve, pivot + 1, j, k);
  }
}

int main() {
  vector<int> ve = {4, 5, 3, 2, 6, 9, 1, 8, 7};
  cout << FindKth(ve, 0, ve.size() - 1, 5) << endl;
}