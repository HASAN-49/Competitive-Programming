#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
  // ================= PRIORITY QUEUE (MAX-HEAP) DEMONSTRATION =================
  priority_queue<int> pq; // Max-heap (default behavior, largest element at top)

  int n; cin >> n; // number of inputs
  for (int i = 0; i < n; i++) { // Taking n inputs
    int x; cin >> x;
    pq.push(x); // Push element (O(log n))
  }

  // Top element
  cout << "Max-Heap Priority Queue size after pushes: " << pq.size() << '\n';
  if (!pq.empty()) {
    cout << "Top element (maximum): " << pq.top() << '\n';
  }

  // Pop an element
  if (!pq.empty()) {
    cout << "\nPopping top element: " << pq.top() << '\n';
    pq.pop(); // Removes top element (O(log n))
  }

  cout << "Size after pop: " << pq.size() << '\n';
  if (!pq.empty()) {
    cout << "New top element: " << pq.top() << '\n';
  } else {
    cout << "Priority queue is empty now.\n";
  }

  // Pop all elements to demonstrate ordering
  cout << "\nRemoving all elements from max-heap priority_queue: ";
  while (!pq.empty()) {
    cout << pq.top() << ' ';
    pq.pop();
  }
  cout << '\n';


  // ================= PRIORITY QUEUE (MIN-HEAP) DEMONSTRATION =================
  priority_queue<int, vector<int>, greater<int>> minpq; 
  // Min-heap (smallest element at top)

  cin >> n; // number of inputs
  for (int i = 0; i < n; i++) {
    int x; cin >> x;
    minpq.push(x); // Push element (O(log n))
  }

  // Top element
  cout << "\nMin-Heap Priority Queue size after pushes: " << minpq.size() << '\n';
  if (!minpq.empty()) {
    cout << "Top element (minimum): " << minpq.top() << '\n';
  }

  // Pop an element
  if (!minpq.empty()) {
    cout << "\nPopping top element: " << minpq.top() << '\n';
    minpq.pop(); // Removes top element
  }

  cout << "Size after pop: " << minpq.size() << '\n';
  if (!minpq.empty()) {
    cout << "New top element: " << minpq.top() << '\n';
  } else {
    cout << "Priority queue is empty now.\n";
  }

  // Pop all elements to demonstrate ordering
  cout << "\nRemoving all elements from min-heap priority_queue: ";
  while (!minpq.empty()) {
    cout << minpq.top() << ' ';
    minpq.pop();
  }
  cout << '\n';

  return 0;
}
