// eavelasquez
// https://codeforces.com/problemset/problem/545/C
// math, greedy
#include <iostream>
#include <vector>

using namespace std;

struct tree
{
  long x; // x coordinate
  long h; // height
};

long distance(long x, long y)
{
  return (x - y) > 0 ? (x - y) : (y - x);
}

int main()
{
  long n;
  cin >> n; // n trees

  vector<tree> trees(n);

  for (int i = 0; i < n; ++i)
  {
    cin >> trees[i].x >> trees[i].h; // x and h of each tree
  }

  for (int i = 0; i < n; ++i)
  {
    cout << "x: " << trees[i].x << ", h: " << trees[i].h << endl;
  }

  long last = trees[0].x; // last tree's x coordinate
  long ans = n > 1 ? 2L : 1L; // if there is only one tree, it is the only one that can be cut

  for (int i = 1; i < n - 1; ++i) {
    if (distance(trees[i].x, last) > trees[i].h) { 
      // if the distance between the last tree and the current tree is greater than the current tree's height, then the current tree can be cut
      ans += 1;
      last = trees[i].x;
      cout << "cutting tree " << i << " at coordinate " << trees[i].x << " to the left" << endl;
    } else if (distance(trees[i].x, trees[i + 1].x) > trees[i].h) {
      // if the distance between the current tree and the next tree is greater than the current tree's height, then the current tree can be cut
      ans += 1;
      last = trees[i].x + trees[i].h;
      cout << "cutting tree " << i << " at coordinate " << trees[i].x << " to the right" << endl;
    } else {
      // if the current tree cannot be cut, then the last tree can be cut
      last = trees[i].x;
    }

    cout << "last tree's x coordinate: " << last << endl;
  }

  cout << "ans: " << ans << endl;

  return 0;
}