/**********************************************************/
/*                                                        */
/* Anthony Meyer                                          */
/* https://www.codechef.com/problems/FLOW006              */
/* 6/14/2021                                              */
/*                                                        */
/**********************************************************/

#include <cstdio>
int main() {
  int N, T, sum;
  scanf("%d", &T);
  while (T--) {
    sum = 0;
    scanf("%d", &N);
    while (N) {
      sum += N % 10;
      N /= 10;
    }
    printf("%d\n", sum);
  }
  return 0;
}
