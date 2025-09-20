#include <iostream>
#include <vector>
#include <algorithm> // For sort, lower_bound, upper_bound

using namespace std;

void print(vector<int> v) {
  int n = v.size();
  cout << n << '\n';
  for (int i = 0; i < n; i++) {
    cout << v[i] << ' ';
  }
  cout << '\n';
}

int main() {
  // Input vector size
  int n; cin >> n;

  vector<int> v;

  // Taking inputs
  for (int i = 0; i < n; i++) {
      int x; cin >> x;
      v.push_back(x); // Using push_back() to add elements
  }

  cout << "Initial values: \n";
  print(v);
  cout << '\n';

  // 1. at(): Access elements with bounds checking
  int idx; cin >> idx;
  cout << "Value at " << idx << "is: " << v.at(idx) << '\n';

  // 2. front() and back()
  cout << "First element (front): " << v.front() << '\n';
  cout << "Last element (back): " << v.back() << '\n';

  // 3. push_back(): Add element
  int value; cin >> value;
  v.push_back(value);
  cout << "\nAfter push_back: \n";
  print(v);

  // 4. pop_back(): Remove last element
  v.pop_back();
  cout << "\nAfter pop_back: \n";
  print(v);

  // 5. insert(): Insert at index 1
  cin >> value;
  v.insert(v.begin() + 1, value);
  cout << "\nAfter insert at index 1: \n";
  print(v);

  // 6. erase(): Remove element at index 0
  v.erase(v.begin());
  cout << "\nAfter erase at index 0: \n";
  print(v);


  // 7. size() and empty()
  cout << "\nVector size: " << v.size() << '\n';
  cout << "Is vector empty? " << (v.empty() ? "Yes" : "No") << '\n';

  // 8. Iterators: begin(), end(), rbegin(), rend()
  cout << "\nIterating forward using begin/end: ";
  for (auto it = v.begin(); it != v.end(); ++it) {
      cout << *it << " ";
  }
  cout << '\n';

  cout << "Iterating backward using rbegin/rend: ";
  for (auto rit = v.rbegin(); rit != v.rend(); ++rit) {
      cout << *rit << " ";
  }
  cout << '\n';

  // 9. swap(): Exchange contents of two elements
  swap(v[2], v[4]);
  cout << "\nAfter swap, v: \n";
  print(v);

  // 10. sort(), lower_bound(), upper_bound()
  sort(v.begin(), v.end());
  cout << "\nSorted nums: \n";
  print(v);

  cout << "\nEnter a value to find lower_bound and upper_bound: \n";
  cin >> value;
  auto lb = lower_bound(v.begin(), v.end(), value);
  auto ub = upper_bound(v.begin(), v.end(), value);

  cout << "Lower bound index of " << value << ": " << (lb - v.begin()) << '\n';
  cout << "Upper bound index of " << value << ": " << (ub - v.begin()) << '\n';

  // 11. assign(): Replace elements with 5 copies of 9
  v.assign(5, 9);
  cout << "\nAfter assign(3, 9): \n";
  print(v);

  // 12. clear(): Removes all elements
  v.clear();
  cout << "\nAfter clear(), v size: " << v.size() << '\n';

  return 0;
}
