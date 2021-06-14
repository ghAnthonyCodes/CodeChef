/**********************************************************/
/*                                                        */
/* Anthony Meyer                                          */     
/* https://www.codechef.com/problems/BITTUP               */
/*                                                        */
/**********************************************************/

#include <iostream>
#include <cstdio>

#define ull unsigned long long
#define MOD 1000000007

// Exponentiation/Power using Bitmasking
ull pow(ull a, ull n) {
  ull ans = 1;
  while (n > 0) {
    if (n & 1)
      ans = ans*a % MOD;
    a = a*a % MOD; // Square up
    n = n >> 1;    // Discard the last bit of N
  }
  return ans;
}

int main() {
  int T;
  int N, M;
  scanf("%d", &T);
  while (T--) {
    scanf("%d %d", &N, &M);
    // Solve
    ull root = pow(2, N)-1;
    ull answer = pow(root, M);
    printf("%lld\n", answer);
  }
  return 0;
}
