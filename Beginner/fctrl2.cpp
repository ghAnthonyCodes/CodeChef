/**********************************************************/
/*                                                        */
/* Anthony Meyer                                          */
/* https://www.codechef.com/problems/FCTRL2               */
/* 6/14/2021                                              */
/*                                                        */
/**********************************************************/

#include <cstdio>
#include <vector>

#define vi std::vector<int> 
#define vvi std::vector<vi> 

/**********************************************************/
/*                                                        */
/* Takes an int 123 and stores as                         */
/* [ 3, 2, 1 ]                                            */
/*                                                        */
/**********************************************************/
void parseInt(int a, vi &V) {
  V = vi();
  while (a) {
    V.push_back(a % 10);
    a /= 10;
  }
}

/**********************************************************/
/*                                                        */
/* Takes two ints 123*45 and multiplies.                  */
/* [3, 2, 1] : A                                          */
/* [5, 4]    : B                                          */
/* ~~~~~~~~~~                                             */
/* [        ] C                                           */
/* [        ]                                             */
/*                                                        */
/**********************************************************/
vi bigMult(vi A, vi B) {
  int offset = 0;
  int row = 0;
  vvi C = vvi();
  vi res = vi();
  int maxVectorSize = 0;
  for (auto b : B) {
    C.push_back(vi()); 
    for (int i=0; i<offset; i++)
      C[row].push_back(0);
    int carry = 0;
    for (int i=0; i<A.size(); i++) {
      int M = b*A[i] + carry;
      C[row].push_back(M % 10);
      carry = M/10;
    }
    while (carry) {
      C[row].push_back(carry % 10);
      carry /= 10;
    }
    maxVectorSize = std::max(maxVectorSize, (int)C[row].size());
    row++;
    offset++;
  }

  // Produce final answer
  int carry = 0;
  for (int d=0; d<maxVectorSize; d++) {
    int sum = carry;
    for (auto r : C) {
      if (d < r.size())
        sum += r[d];
    }
    res.push_back(sum % 10);
    carry = sum / 10;
  }
  while (carry) {
    res.push_back(carry % 10);
    carry /= 10;
  }
  return res;
}

void printBigInt(vi &A) {
  for (int i=A.size()-1; i>=0; i--)
    printf("%d", A[i]);
  printf("\n");
}
int main() {

  vi a, b;
  int T, N;

  scanf("%d", &T);
  while (T--) {
    scanf("%d", &N);
    parseInt(N, a); 
    vi ans;
    for (int n=N-1; n>0; n--) {
      parseInt(n, b);
      ans = bigMult(a, b); 
      a = ans;
    }
    printBigInt(a);
  }
  return 0;
}
