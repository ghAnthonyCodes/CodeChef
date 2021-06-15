/**********************************************************/
/*                                                        */
/* Anthony Meyer                                          */
/* https://www.codechef.com/problems/LUCKFOUR             */
/* 6/15/2021                                              */
/*                                                        */
/**********************************************************/

#include <cstdio>
int main() {
  int T, N;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &N);
    int count = 0;
    while (N) {
      if (N % 10 == 4)
        count++;
      N /= 10;
    }
    printf("%d\n", count);
  }
  return 0;
}
