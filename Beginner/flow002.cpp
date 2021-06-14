/**********************************************************/
/*                                                        */
/* Anthony Meyer                                          */
/* https://www.codechef.com/problems/FLOW002              */
/* 6/14/2021                                              */
/*                                                        */
/**********************************************************/

#include <cstdio>
int main() {
  int T, A, B;
  scanf("%d", &T); 
  while (T--) {
    scanf("%d %d", &A, &B);
    printf("%d\n", A % B);
  }
  return 0;
}
