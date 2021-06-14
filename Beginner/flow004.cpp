/**********************************************************/
/*                                                        */
/* Anthony Meyer                                          */
/* https://www.codechef.com/problems/FLOW004              */
/* 6/14/2021                                              */
/*                                                        */
/**********************************************************/

#include <cstdio>

int main() {
  int T, N;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &N);
    int f = N % 10;
    while (N > 10)
      N /= 10;
    
    // Answer
    printf("%d\n", f + N);
  }
  return 0;
}
