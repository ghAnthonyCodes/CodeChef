/**********************************************************/
/*                                                        */
/* Anthony Meyer                                          */
/* https://www.codechef.com/problems/TSORT                */
/* 6/14/2021                                              */
/*                                                        */
/**********************************************************/

#include <cstdio>
#include <cstring>

#define MAXN 1000000
int main() {
  int T;
  int A[MAXN + 1];
  int a;
  memset(A, 0, sizeof(A));
  scanf("%d", &T);
  for (int t=0; t<T; t++) {
    scanf("%d", &a);
    A[a]++;
  }
  for (int i=0; i<=MAXN; i++) {
    for (int j=0; j<A[i]; j++)
      printf("%d\n", i);
  }
  return 0;
}
