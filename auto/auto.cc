#include <iostream>
#include <string>
#include <stack>
using namespace std;

auto sum(auto a, auto b) {
  int c = a + b;
  return c;
}

int main() {
  cout << sum(1, 1) << endl;
  cout << sum(1.0, 2.0) << endl;
}