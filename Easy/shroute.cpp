/**********************************************************/
/*                                                        */
/* Anthony Meyer                                          */
/* https://www.codechef.com/problems/SHROUTE              */
/*                                                        */
/**********************************************************/

#include <cstdio>
#include <iostream>
#include <cstring>

#define MAXN 100001

int CR[MAXN];  // Trains left to right
int CL[MAXN];  // Trains right to left

int A[MAXN];   // Train list
int B[MAXN];   // Passenger list
int T, N, M;   // Test case parameters
int MAX;
bool firstL;
bool firstR;

void fillCl(void);
void fillCr(void);

int main() { 

  // Number of test cases
  scanf("%d", &T);

  // For each test case
  while (T--) {

    // ****** INPUT *******
    scanf("%d %d", &N, &M);
    MAX = N+5;
    for (int n=1; n<=N; n++) {
      scanf("%d", &A[n]); 
      CR[n]  = MAX;
      CL[n]  = MAX;
    }
    for (int m=1; m<=M; m++) 
      scanf("%d", &B[m]);

    // ****** SOLVE *******
    fillCl();
    fillCr();

    // Find answer per query
    for (int m=1; m<=M; m++) {
      int ans = std::min(CL[B[m]], CR[B[m]]);
      printf("%d ", ans == MAX ? -1 : ans);
    }
    printf("\n");

  }
  return 0;
}

void fillCl() {

  firstL = false;

  // Leftbound trains
  for (int s = N; s > 0; s--) {

    if (A[s] != 2 && firstL == false) 
      continue;

    // Handle R->L trains
    if (A[s] == 2) {
      CL[s] = 0;
      firstL = true;
    } 
    else {
      CL[s] = CL[s+1] + 1;
    }
  }
}

void fillCr() {

  firstR = false;

  // Rightbound trains
  for (int s = 1; s <= N; s++) {

    if (A[s] != 1 && firstR == false) 
      continue;

    // Handle L->R trains
    if (A[s] == 1) {
      CR[s] = 0;
      firstR = true;
    } 
    else {
      CR[s] = CR[s-1] + 1;
    }
  }
}
