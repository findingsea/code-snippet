#include<iostream>
using namespace std;

// Definition for a binary tree node.
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

void ReverseList(ListNode *head) {
  if (head == nullptr || head->next == nullptr) return;
  auto *node = head->next;
  ListNode *pre = nullptr;
  while (node != nullptr) {
    auto *next = node->next;
    node->next = pre;
    pre = node;
    node = next;
  }
  head->next = pre;
}

void PrintList(ListNode *head) {
  auto *node = head;
  while (node != nullptr) {
    cout << node->val << " ";
    node = node->next;
  }
  cout << endl;
}

int main() {
  ListNode head(-1), n1(1), n2(2), n3(3), n4(4);
  head.next = &n1;
  n1.next = &n2;
  n2.next = &n3;
  n3.next = &n4;
  PrintList(&head);
  ReverseList(&head);
  PrintList(&head);
}