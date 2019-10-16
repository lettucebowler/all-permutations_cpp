#include <iostream>
#include <math.h>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

void permute(string a, int l, int r, int &counter, vector<std::string> &perm) {
  // Base case
  if (l == r) {
      cout<<counter << " : " << a << endl;
      perm.push_back(a);
      counter++;
    }
  else {
      // Permutations made
      for (int i = l; i <= r; i++) {
        // Swapping done
        swap(a[l], a[i]);
        // Recursion called
        permute(a, l+1, r, counter, perm);
        //backtrack
        swap(a[l], a[i]);
      }
  }
}

int main () {
  string input;
  int i = 0;
  cout << "enter a string : ";
  cin >> input;
  int n = input.length();
  int permcount = 1;

  for(int k = 1; k <= n; k++) {
    permcount *= (k);
  }

  vector<std::string> perm;
  permute(input, 0, n-1, i, perm);
  sort(perm.begin(), perm.end());

  for(i = 0; i < permcount; i++) {
    cout << i + 1 << " : " << perm[i] << endl;
  }
}
