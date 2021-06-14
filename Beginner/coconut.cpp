/**********************************************************/
/*                                                        */
/* Anthony Meyer                                          */     
/* https://www.codechef.com/problems/COCONUT              */
/*                                                        */
/**********************************************************/

#include <iostream>
#include <cstdio>
#include <cmath>

int main() {
  int T;
  int xa, xb, Xa, Xb;
  scanf("%d", &T);
  while (T--) {
    scanf("%d %d %d %d", &xa, &xb, &Xa, &Xb); 
    int A = static_cast<int>(ceil(1.0*Xa/xa));
    int B = static_cast<int>(ceil(1.0*Xb/xb));

    // Solve
    printf("%d\n", A+B);
  }
  return 0;
}
