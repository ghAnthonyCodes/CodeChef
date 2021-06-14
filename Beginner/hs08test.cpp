/**********************************************************/
/*                                                        */
/* Anthony Meyer                                          */
/* https://www.codechef.com/problems/HS08TEST             */
/* 6/14/2021                                              */
/*                                                        */
/**********************************************************/

#include <cstdio>
int main() {
  int request;
  float balance;
  scanf("%d%f", &request, &balance);
  if ((request % 5 == 0) && (request + 0.5 <= balance))
    balance -= (request + 0.5);
  printf("%.2f\n", balance);
}
