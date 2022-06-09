#include <iostream>
#include <string>
#include <type_traits>

using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::remove_reference;
using std::string;

int getRequiredSwaps(string from, string to);

int main() {
  string from;
  cerr << "From: ";
  cin >> from;
  string to;
  cerr << "To: ";
  cin >> to;
  int swaps = getRequiredSwaps(from, to);
    cout << "Required swaps: " << swaps << endl;
  return 0;
}

template <typename T> void swap(T &a, T &b) {
  typename remove_reference<T>::type temp = a;
  a = b;
  b = temp;
}

int getRequiredSwaps(string from, string to) {
  if (from.length() != to.length()) {
    return -1;
  } else {
    int swaps = 0;
    cout << from << endl;
    for (int i = 0; i < from.length(); i++) {
      if (from[i] != to[i]) {
        for (int j = i + 1; j < from.length(); j++) {
          if (from[j] == to[i]) {
            swap(from[i], from[j]);
            swaps++;
            break;
          }
        }
        cout << from << endl;
      }
    }
    if (from != to) {
      return -1;
    } else {
      return swaps;
    }
  }
}
