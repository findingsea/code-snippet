#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Car {
public:
  virtual int Start() = 0;
};

class Benz : public Car {
public:
  int Start() {
    cout << "Benz starts sucessfully." << endl;
    return 0;
  }
};

class Tree {
public:
  virtual void Grownup() {
    cout << "Growning up..." << endl;
  }
};

class Sequoia : public Tree {
public:
  void Grownup() {
    cout << "Sequoia is growning up..." << endl;
  }
};

int main() {
  // Benz *benz = new Car();  // 编译失败，car是抽象类，无法实例化
  Car *benz = new Benz();
  benz->Start();
  Tree *sequois = new Sequoia();
  sequois->Grownup();
}