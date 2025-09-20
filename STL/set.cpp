#include <iostream>
#include <set>
using namespace std;

int main() {
  // ================= SET DEMONSTRATION =================
  set<int> se; // Declaration of a set (stores unique elements in sorted order)

  int n; cin >> n; // Number of elements
  for (int i = 0; i < n; i++) { // Taking n inputs
    int x; cin >> x;
    se.insert(x); // Insert elements (duplicates are ignored)
  }

  cout << "Initial Set (sorted, unique elements): ";
  for (auto x : se) cout << x << ' ';
  cout << '\n';

  // Deletion by value
  cout << "\nEnter value to erase from set: \n";
  int val; cin >> val;
  se.erase(val); // Removes the element with given value
  cout << "After erase(" << val << "): ";
  for (auto x : se) cout << x << ' ';
  cout << '\n';

  // Deletion by iterator (remove first element if not empty)
  if (!se.empty()) {
    auto it = se.begin(); // Iterator to first element
    se.erase(it); // Removes the first element
  }
  cout << "After erase(begin()): ";
  for (auto x : se) cout << x << ' ';
  cout << '\n';

  // Searching with count()
  cout << "\nEnter value to search using count: \n";
  cin >> val;
  if (se.count(val)) cout << val << " is present in set (via count)\n";
  else cout << val << " is NOT present in set\n";

  // Searching with find()
  cout << "\nEnter value to search using find: \n";
  cin >> val;
  if (se.find(val) != se.end()) cout << val << " is present in set (via find)\n";
  else cout << val << " is NOT present in set\n";

  // Size and empty
  cout << "\nSet size: " << se.size() << '\n';
  cout << "Is set empty? " << (se.empty() ? "Yes" : "No") << '\n';

  // Iteration using range-based loop
  cout << "\nSet elements (range-based for loop): ";
  for (auto x : se) cout << x << ' ';
  cout << '\n';

  // Iteration using iterators
  cout << "\nSet elements (iterator loop): ";
  for (auto it = se.begin(); it != se.end(); it++) cout << *it << ' ';
  cout << '\n';

  // Clear the set
  se.clear();
  cout << "\nAfter clear(), set size: " << se.size() << '\n';


  // ================= MULTISET DEMONSTRATION =================
  multiset<int> mse; // Declaration of a multiset (allows duplicate elements)

  cout << "\nEnter number of elements for multiset: \n";
  cin >> n;
  for (int i = 0; i < n; i++) { // Taking inputs for multiset
    int x; cin >> x;
    mse.insert(x); // Insert elements (duplicates allowed)
  }

  cout << "\nInitial Multiset: ";
  for (auto x : mse) cout << x << ' ';
  cout << '\n';

  // Erase all occurrences of a value
  cout << "\nEnter value to erase from multiset: ";
  cin >> val;
  mse.erase(val); // Removes ALL occurrences of val
  cout << "After erase(" << val << "): ";
  for (auto x : mse) cout << x << ' ';
  cout << '\n';

  // Erase first element
  if (!mse.empty()) {
    mse.erase(mse.begin());
  }
  cout << "\nAfter erase(begin()): ";
  for (auto x : mse) cout << x << ' ';
  cout << '\n';

  // Count occurrences of a value
  cout << "\nEnter value to count in multiset: ";
  cin >> val;
  cout << val << " appears " << mse.count(val) << " times in multiset\n";

  // Erase only one occurrence using find()
  cout << "\nEnter value to erase only one occurrence: ";
  cin >> val;
  auto it = mse.find(val);
  if (it != mse.end()) {
    mse.erase(it); // Erase just one instance
    cout << "One occurrence of " << val << " erased\n";
  } 
  else {
    cout << val << " not found in multiset\n";
  }

  cout << "Final Multiset: ";
  for (auto x : mse) cout << x << ' ';
  cout << '\n';

  // Clear the multiset
  mse.clear();
  cout << "\nAfter clear(), multiset size: " << mse.size() << '\n';

  return 0;
}
