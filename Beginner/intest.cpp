/**********************************************************/
/*                                                        */
/* Anthony Meyer                                          */
/* https://www.codechef.com/problems/INTEST               */
/* 6/14/2021                                              */
/*                                                        */
/**********************************************************/

#include <cstdio>
int main() {
  int n, k, t;
  int div = 0;
  scanf("%d %d", &n, &k);
  for (int i=0; i<n; i++) {
    scanf("%d", &t); 
    div += t % k == 0 ? 1 : 0;
  }
  printf("%d\n", div);
  return 0;
}
