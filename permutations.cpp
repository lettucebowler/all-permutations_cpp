#include <iostream>
#include <math.h>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

void permute(string a, int l, int r, int &counter, vector<std::string> &perm) {
  // Base case
  if (l == r) {
    //cout<<counter << " : " << a << endl;
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

int main (int argc, char * argv[]) {
  int i = 0;
  int permcount = 1;
  int n;
  string input;
  vector<std::string> perm;

  //Check for proper cli arguments, and if not present, take input from stdin.
  if(argc < 2) {
    cout << "String to permute : ";
    cin >> input;
  }
  else {
    input = argv[1];
  }

  //Calculate number of possible permutations based on string length
  n = input.length();
  for(int k = 1; k <= n; k++) {
    permcount *= (k);
  }

  //Generate permutations and put them in perm
  permute(input, 0, n-1, i, perm);

  //Output sorted list of permutations
  sort(perm.begin(), perm.end());
  for(i = 0; i < permcount; i++) {
    cout << i + 1 << " : " << perm[i] << endl;
  }
}
