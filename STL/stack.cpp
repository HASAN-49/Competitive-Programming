#include <iostream>
#include <stack>
using namespace std;

int main() {
  // ================= STACK DEMONSTRATION =================
  stack<int> stk; // Declaration of a stack (LIFO - Last In, First Out)

  int n; cin >> n; // number of inputs
  for (int i = 0; i < n; i++) { // Taking n inputs
    int x; cin >> x;
    stk.push(x); // Push element on top of stack
  }

  cout << "Stack size after pushes: " << stk.size() << '\n';

  // Top element
  if (!stk.empty()) {
    cout << "Top element: " << stk.top() << '\n';
  }

  // Pop an element
  if (!stk.empty()) {
    cout << "\nPopping top element: " << stk.top() << '\n';
    stk.pop(); // Removes top element
  }

  cout << "Stack size after pop: " << stk.size() << '\n';

  if (!stk.empty()) {
    cout << "New top element: " << stk.top() << '\n';
  } 
  else {
    cout << "Stack is empty now.\n";
  }

  // Check if empty
  cout << "\nIs stack empty? " << (stk.empty() ? "Yes" : "No") << '\n';

  // Pop all elements to show emptying the stack
  while (!stk.empty()) {
    cout << "Removing: " << stk.top() << '\n';
    stk.pop();
  }

  cout << "Final stack size: " << stk.size() << '\n';
  cout << "Is stack empty? " << (stk.empty() ? "Yes" : "No") << '\n';

  return 0;
}
