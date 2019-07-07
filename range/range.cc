#include <set>
#include <iostream>
using namespace std;

class Range {
public:
  int min;
  int max;

  // 错误示例：a.min=b.min，那么a<(b)的判断为false，b<(a)的判断为false，就会判断a=b，无法插入
  // bool operator<(Range const& b) const {
  //   if (min == b.min && max == b.max) {
  //     return false;
  //   } else {
  //     return min < b.min;
  //   }
  // }
  bool operator<(Range const& b) const {
    if (min == b.min && max == b.max) {
      return false;
    } else if (min < b.min) {
      return true;
    } else if (min == b.min) {
      return max < b.max;
    } else {
      return false;
    }
  }
  Range(int min, int max) {
    this->min = min;
    this->max = max;
  }
};

int main() {
  set<Range> range_set;
  Range r1(1, 2);
  Range r2(1, 2);
  Range r3(1, 1);
  range_set.insert(r1);
  range_set.insert(r2);
  range_set.insert(r3);  
  for (auto &r : range_set) {
    cout << "[" << r.min << ", " << r.max << "]" << endl;
  }

  cout << "r1 < r3: " << (r1 < r3) << endl;
  cout << "r3 < r1: " << (r3 < r1) << endl;
}