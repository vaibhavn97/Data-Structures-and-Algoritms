#include <iostream>

using namespace std;

class Node {
public:
  int data;
  Node* next;

  Node() {
    data = 0;
    next = nullptr;
  }

  Node(int data) {
    this->data = data;
    this->next = nullptr;
  }
};

class LL {
private:
  Node* head;
  Node* tail;

public:
  LL() {
    head = tail = nullptr;
  }

  // Returns a string representation of the linked list.
  string toString() {
    string ans = "";
    Node* ptr = head;
    while (ptr != nullptr) {
      ans += to_string(ptr->data) + " -> ";
      ptr = ptr->next;
    }
    ans += "NULL";
    return ans;
  }

  // Adds a new node with the given data to the front of the linked list.
  void addFirst(int data) {
    Node* node = new Node(data);
    if (head == nullptr) {
      head = tail = node;
      return;
    }
    node->next = head;
    head = node;
  }

  // Adds a new node with the given data to the end of the linked list.
  void addLast(int data) {
    Node* node = new Node(data);
    if (head == nullptr) {
      head = tail = node;
      return;
    }
    tail->next = node;
    tail = node;
  }

  // Adds a new node with the given data at the specified index.
  void addAt(int index, int data) {
    if (index == 0) {
      addFirst(data);
      return;
    }
    Node* node = new Node(data);
    Node* ptr = head;
    for (int i = 1; i <= index - 1 && ptr != nullptr; i++) {
      ptr = ptr->next;
    }
    if (ptr != nullptr) {
      node->next = ptr->next;
      ptr->next = node;
    }
  }

  // Removes the first node from the linked list.
  void removeFirst() {
    if (head == nullptr) {
      return;
    }
    head = head->next;
    if (head == nullptr) {
      tail = nullptr;
    }
  }

  // Removes the last node from the linked list.
  void removeLast() {
    if (head == nullptr) {
      return;
    }
    if (head->next == nullptr) {
      head = tail = nullptr;
      return;
    }
    Node* ptr = head;
    while (ptr->next->next != nullptr) {
      ptr = ptr->next;
    }
    ptr->next = nullptr;
    tail = ptr;
  }

  // Removes the node at the specified index.
  void removeAt(int index) {
    if (index == 0) {
      removeFirst();
      return;
    }
    Node* ptr = head;
    for (int i = 1; i <= index - 1 && ptr != nullptr; i++) {
      ptr = ptr->next;
    }
    if (ptr != nullptr && ptr->next != nullptr) {
      ptr->next = ptr->next->next;
    } else {
      throw std::out_of_range("Linked List Index out of Bounds");
    }
  }

  // Returns the value of the node at the specified index.
  int valueAt(int index) {
    Node* ptr = head;
    for (int i = 1; i <= index && ptr != nullptr; i++) {
      ptr = ptr->next;
    }
    if (ptr == nullptr) {
      throw std::out_of_range("Linked List Index Out of Bounds");
    }
    return ptr->data;
 
  }
};

int main() {
  LL lis;
  lis.addFirst(1);
  lis.addLast(2);
  lis.addFirst(0);
  lis.addLast(3);
  lis.addAt(3, 78348);
  lis.addLast(5);
  lis.addAt(4, 4);
  lis.addFirst(-1);
  lis.addLast(-49);
  cout << lis.toString() << endl;
  lis.removeFirst();
  lis.removeLast();
  lis.removeAt(3);
  cout << lis.toString() << endl;
  cout << lis.valueAt(100) << endl;
  return 0;
}
