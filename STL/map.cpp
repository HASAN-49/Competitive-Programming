#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;

int main() {
  // ================= MAP DEMONSTRATION =================
  map<int, string> mp; // Declaration of a map (stores key-value pairs, keys are unique and sorted)

  int n; cin >> n; // number of inputs
  for (int i = 0; i < n; i++) { // Taking n inputs
    int key; string value;
    cin >> key >> value;
    mp[key] = value; // Insert elements (key is unique, sorted automatically)
  }

  cout << "Initial Map (keys sorted): \n";
  for (auto cur : mp) {
    cout << cur.first << " -> " << cur.second << '\n';
  }

  // Insertion using make_pair
  mp.insert(make_pair(50, "Mango"));

  // Insertion using [] operator
  mp[100] = "Banana";

  cout << "\nAfter insertions: \n";
  for (auto cur : mp) {
    cout << cur.first << " -> " << cur.second << '\n';
  }

  // Searching for a key
  cout << "\nEnter key to search in map: \n";
  int key; cin >> key;
  if (mp.find(key) != mp.end()) {
    cout << "Key " << key << " is present with value: " << mp[key] << '\n';
  } 
  else {
    cout << "Key " << key << " is NOT present in map\n";
  }

  // Size and empty
  cout << "\nMap size: " << mp.size() << '\n';
  cout << "Is map empty? " << (mp.empty() ? "Yes" : "No") << '\n';

  // Clear the map
  mp.clear();
  cout << "\nAfter clear(), map size: " << mp.size() << '\n';


  // ================= UNORDERED MAP DEMONSTRATION =================
  unordered_map<int, string> ump; // Declaration of an unordered_map (keys unique, no specific order)

  cin >> n; // number of inputs in unordered map
  for (int i = 0; i < n; i++) { // Taking n inputs
    int key; string value;
    cin >> key >> value;
    ump[key] = value; // Insert elements (average O(1))
  }

  // Insertion using insert()
  ump.insert({200, "Orange"});

  cout << "\nUnordered Map (order not guaranteed): \n";
  for (auto cur : ump) {
    cout << cur.first << " -> " << cur.second << '\n';
  }

  // Searching for a key
  cout << "\nEnter key to search in unordered_map: \n";
  cin >> key;
  if (ump.find(key) != ump.end()) {
    cout << "Key " << key << " is present with value: " << ump[key] << '\n';
  } 
  else {
    cout << "Key " << key << " is NOT present in unordered_map\n";
  }

  // Deleting a key
  cout << "\nEnter key to erase from unordered_map: \n";
  cin >> key;
  ump.erase(key);

  cout << "After erase, unordered_map contents: \n";
  for (auto cur : ump) {
    cout << cur.first << " -> " << cur.second << '\n';
  }

  // Size and empty
  cout << "\nUnordered_map size: " << ump.size() << '\n';
  cout << "Is unordered_map empty? " << (ump.empty() ? "Yes" : "No") << '\n';

  // Clear the unordered_map
  ump.clear();
  cout << "\nAfter clear(), unordered_map size: " << ump.size() << '\n';

  return 0;
}
