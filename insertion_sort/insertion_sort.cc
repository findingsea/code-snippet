#include <iostream>
#include <vector>
using namespace std;

void PrintVector(vector<int> &ve) {
  for (auto &v : ve) {
    cout << v << " ";
  }
  cout << endl;
}

void InsertionSort(vector<int> &ve) {
  for (int i = 0; i < ve.size(); ++i) {
    auto key = ve[i];
    auto j = i - 1;
    while (j >= 0 && key < ve[j]) {
      ve[j + 1] = ve[j];
      --j;
    }
    ve[j + 1] = key;
  }
}

int main() {
  vector<int> ve = {4, 5, 5, 3, 2, 6, 9, 1, 8, 7};
  InsertionSort(ve);
  PrintVector(ve);
}