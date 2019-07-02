#include <iostream>
#include <string>
#include <stack>
#include <random>
#include <thread>
#include <sstream>
using namespace std;
void GetCount() {
  // count贯穿thread的生命周期
  thread_local int count = 0;
  ostringstream ostr;
  ostr << "Thread id: " << this_thread::get_id() << " " << count++ << endl;
  cout << ostr.str();
}
void GenCount() {
  for (int i = 0; i < 5; ++i) {
    GetCount();
  }
}
int main() {
  thread threads[5];
  for (int i = 0; i < 5; ++i) {
    threads[i] = thread(GenCount);
  }
  for (auto &t : threads) {
    t.join();
  }
}