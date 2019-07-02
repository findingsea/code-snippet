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
  virtual ~Car() {
    cout << "Set price to zero..." << endl;
    price = 0;
  }
private:
  int price = 1000;
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
  ~Benz() {
    cout << "Set benz discount to zero..." << endl;
    discount = 0;
  }
private:
  int discount = 1;
};

class Tree {
public:
  virtual void Grownup() {
    cout << "Growning up..." << endl;
  }
  ~Tree() {
    cout << "Discontruct Tree..." << endl;
  }
};

class Sequoia : public Tree {
public:
  void Grownup() {
    cout << "Sequoia is growning up..." << endl;
  }
  ~Sequoia() {
    cout << "Discount Sequoia..." << endl;
  }
};

// 当使用类的指针调用成员函数时，普通函数由指针类型决定，而虚函数由指针指向的实际类型决定
i
  // Benz *benz = new Car();  // 编译失败，car是抽象类，无法实例化
  Car *benz = new Benz();
  benz->Start();
  benz->Run();
  Tree *sequois = new Sequoia();
  sequois->Grownup();
  delete(benz);  // 会调用子类Benz的析构，再调用基类Car的析构
  delete(sequois);  // 只会调用基类Tree的析构，潜在风险造成子类Sequoia的泄露
}