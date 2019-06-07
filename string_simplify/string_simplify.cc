#include <iostream>
#include <string>
#include <stack>
using namespace std;

string simplify(string& s) {
  stack<bool> minus;
  minus.push(false);
  bool last_minus = false;
  string newstr;
  for (int i = 0; i < s.length(); ++i) {
    auto ch = s[i];
    if (ch == ' ') continue;
    if (ch == '(') {
      minus.push(minus.top() ^ last_minus);
      continue;
    } else if (ch == ')') {
      minus.pop();
      continue;
    }
    if (ch == '-') {
      last_minus = true;
      if (minus.top()) {
        ch = '+';
      }
    } else if (ch == '+') {
      last_minus = false;
      if (minus.top()) {
        ch = '-';
      }
    }
    newstr += ch;
  }
  return newstr;
}

int main() {
  string sample = "(1-(4+5-2)-3)-(6+8)";
  cout << simplify(sample) << endl;
}