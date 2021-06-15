/**********************************************************/
/*                                                        */
/* Anthony Meyer                                          */
/* https://www.codechef.com/problems/FLOW007              */
/* 6/15/2021                                              */
/*                                                        */
/**********************************************************/

#include <cstdio>
int main() {
  int T, N;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &N);
    while (N % 10 == 0)
      N /= 10;
    while (N) {
      printf("%d", N % 10); 
      N /= 10;
    }
    printf("\n");
  }
  return 0;
}
