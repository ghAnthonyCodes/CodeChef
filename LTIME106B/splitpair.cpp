#include <cstdio>

// https://www.codechef.com/LTIME106B/problems/SPLITPAIR
int main() {
  int T, N;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &N);

    // Get first dig
    bool odd = (N & 1) == 1;
    N /= 10;

    // Find pos of next odd
    bool possible = false;
    if (odd) {
      while (N > 0) {
        if ((N & 1) == 1)
          possible = true;
        N /= 10;
      }
    } else {
      while (N > 0) {
        if ((N & 1) == 0)
          possible = true;
        N /= 10;
      }
    }
    if (possible)
      printf("YES\n");
    else
      printf("NO\n");
  }
  return 0;
}
