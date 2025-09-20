#include <iostream>
#include <queue>
using namespace std;

int main() {
  // ================= QUEUE DEMONSTRATION =================
  queue<int> q; // Declaration of a queue (FIFO - First In, First Out)

  int n; cin >> n; // number of elements
  for (int i = 0; i < n; i++) { // Taking n inputs
    int x; cin >> x;
    q.push(x); // Push element at the back
  }

  cout << "Queue size after pushes: " << q.size() << '\n';

  // Front element
  if (!q.empty()) {
    cout << "Front element: " << q.front() << '\n';
  }

  // Pop an element
  if (!q.empty()) {
    cout << "\nPopping front element: " << q.front() << '\n';
    q.pop(); // Removes front element
  }

  cout << "Queue size after pop: " << q.size() << '\n';

  if (!q.empty()) {
    cout << "New front element: " << q.front() << '\n';
  } 
  else {
    cout << "Queue is empty now.\n";
  }

  // Check if empty
  cout << "\nIs queue empty? " << (q.empty() ? "Yes" : "No") << '\n';

  // Pop all elements to show emptying the queue
  while (!q.empty()) {
    cout << "Removing: " << q.front() << '\n';
    q.pop();
  }

  cout << "Final queue size: " << q.size() << '\n';
  cout << "Is queue empty? " << (q.empty() ? "Yes" : "No") << '\n';

  return 0;
}
