#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
  int N;
  cin >> N;
  int K;
  cin >> K;
  vector<int> A(K);
  for (int i = 0; i < N; i++) {
   int tmp;
    cin >> tmp;
    A[tmp % K]++;
  }
  int count = 0;
  for (int i = 0; i <= K / 2; i++) {
    if (i == 0 or (2*i == K)) {
      if (A[i]) count += 1;
    } else {
      count += max(A[i], A[K - i]);
    }
  }
  
  cout << count << '\n';
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}