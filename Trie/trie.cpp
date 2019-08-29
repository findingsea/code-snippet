#include <iostream>
#include <queue>
#include <memory>
using namespace std;

#define ALPHABET_SIZE 26

struct TrieNode {
  bool is_key = false;
  uint32_t count = 0;
  shared_ptr<TrieNode> children[ALPHABET_SIZE];
};

class TrieTree {
public:
  TrieTree() {
    root = make_shared<TrieNode>();
  }
  void Insert(string key) {
    auto node = root;
    for (int i = 0; i < key.length(); ++i) {
      if (!node->children[key[i] - 'a']) {
        node->children[key[i] - 'a'] = make_shared<TrieNode>();
      }
      node = node->children[key[i] - 'a'];
      ++node->count;
    }
    node->is_key = true;
  }
  bool Search(string key) {
    auto node = root;
    int idx = 0;
    for (; idx < key.length(); ++idx) {
      if (!node->children[key[idx] - 'a']) {
        return false;
      }
      node = node->children[key[idx] - 'a'];
    }
    return idx == key.length() && node->is_key;
  }
  void Print() {
    queue<shared_ptr<TrieNode> > qu;
    qu.push(root);
    while (!qu.empty()) {
      int count = qu.size();
      while (count > 0) {
        auto node = qu.front();
        qu.pop();
        --count;
        for (int i = 0; i < ALPHABET_SIZE; ++i) {
          if (node->children[i] != nullptr) {
            cout << (char) (i + 'a') << " ";
            qu.push(node->children[i]);
          }
        }
        cout << ";  ";
      }
      cout << endl;
    }
  }
private:
  shared_ptr<TrieNode> root;
};

int main() {
  TrieTree trie_tree;
  trie_tree.Insert("find");
  trie_tree.Insert("found");
  trie_tree.Print();
  cout << "Search 'find': " << trie_tree.Search("find") << endl;
  cout << "Search 'finding': " << trie_tree.Search("finding") << endl;
}