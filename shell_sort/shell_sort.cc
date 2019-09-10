#include <iostream>
#include <vector>
using namespace std;

void PrintVector(vector<int> &ve) {
  for (auto &v : ve) {
    cout << v << " ";
  }
  cout << endl;
}

void SehllSort(vector<int> &ve) {
  int d = ve.size();
  while (d > 1) {
    d /= 2;
    for (int x = 0; x < ve.size(); x += d) {
      for (int i = x; i < ve.size(); i += d) {
        auto key = ve[i];
        auto j = i - d;
        while (j >= 0 && ve[i] < ve[j]) {
          ve[j + d] = ve[j];
          j -= d;
        }
        ve[j + d] = x;
      }
    }
  }
}

int main() {
  vector<int> ve = {4, 5, 5, 3, 2, 6, 9, 1, 8, 7};
  SehllSort(ve);
  PrintVector(ve);
}