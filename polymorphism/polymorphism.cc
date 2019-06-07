#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Car {
public:
  virtual int Start() = 0;
  void Run() {
    cout << "Car is running..." << endl;
  }
};

class Benz : public Car {
public:
  int Start() {
    cout << "Benz starts sucessfully." << endl;
    return 0;
  }
  void Run() {
    cout << "Benz is running..." << endl;
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

// 当使用类的指针调用成员函数时，普通函数由指针类型决定，而虚函数由指针指向的实际类型决定
int main() {
  // Benz *benz = new Car();  // 编译失败，car是抽象类，无法实例化
  Car *benz = new Benz();
  benz->Start();
  benz->Run();
  Tree *sequois = new Sequoia();
  sequois->Grownup();
}