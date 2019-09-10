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

}

int main() {
  vector<int> ve = {4, 5, 5, 3, 2, 6, 9, 1, 8, 7};
  SehllSort(ve);
  PrintVector(ve);
}