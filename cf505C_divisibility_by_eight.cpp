// eavelasquez
// https://codeforces.com/problemset/problem/550/C
// math, brute force
#include <iostream>

using namespace std;

bool is_divisible_by_eight(long n)
{
  return n % 8 == 0;
}

int main() {
  string n;
  cin >> n; // n is a string of digits

  int ans = -1;
  for (int i = 0; i < n.size(); ++i) {
    if (ans != -1) {
      break;
    }

    int x = n[i] - '0';
    if (is_divisible_by_eight(x)) {
      ans = x;
      break;
    }

    for (int j = i + 1; j < n.size(); ++j) {
      if (ans != -1) {
        break;
      }

      x = (n[i] - '0') * 10 + (n[j] - '0');
      if (is_divisible_by_eight(x)) {
        ans = x;
        break;
      }

      for (int k = j + 1; k < n.size(); ++k) {
        if (ans != -1) {
          break;
        }

        x = (n[i] - '0') * 100 + (n[j] - '0') * 10 + (n[k] - '0');
        if (is_divisible_by_eight(x)) {
          ans = x;
          break;
        }
      }
    }
  }

  if (ans != -1) {
    cout << "YES\n" << ans << endl;
  } else {
    cout << "NO" << endl;
  }

  return 0;
}