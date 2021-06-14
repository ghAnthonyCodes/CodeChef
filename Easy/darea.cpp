/**********************************************************/
/*                                                        */
/* Anthony Meyer                                          */
/* https://www.codechef.com/problems/DAREA                */
/*                                                        */
/**********************************************************/

#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>

#define vpi std::vector<std::pair<int, int>>
#define ll long long

const int MAX_TREE_SIZE = 2*131072;

int xSortedTree[MAX_TREE_SIZE][4];
int ySortedTree[MAX_TREE_SIZE][4];
int N;
int TN;
vpi points;

/*******************************************************

X Sorted Segment Tree for Xmin, Ymin, Xmax, Ymax


    |-----------------------------------------------|
    |               (2,2,9,6)                       |
    |-----------------------------------------------|
    |        (2,2,6,6)      | (9,3,9,3)             |
    |-----------------------------------------------|
    | (2,2,3,4) | (4,2,6,6) | (9,3,9,3) |           |
    |-----------------------------------------------|
    | 2,2 | 3,4 | 4,2 | 6,6 | 9,3 | N/A | N/A | N/A |
    |-----------------------------------------------|

********************************************************/
void buildTree(int tree[][4]) {

  // Leaf nodes 
  for (int i=0; i<N; i++) {
    tree[TN+i][0] = points[i].first;
    tree[TN+i][1] = points[i].second;
    tree[TN+i][2] = points[i].first;
    tree[TN+i][3] = points[i].second;
  }
  for (int i=TN+N; i<2*TN; i++) {
    tree[i][0] = 1000000001; 
    tree[i][1] = 1000000001;
    tree[i][2] = -1;
    tree[i][3] = -1;
  }

  // Build tree by calculating parents
  for (int i = TN-1; i > 0; --i) {
    // X Min
    tree[i][0] = std::min(tree[i<<1][0], tree[i<<1 | 1][0]);
    tree[i][1] = std::min(tree[i<<1][1], tree[i<<1 | 1][1]);
    tree[i][2] = std::max(tree[i<<1][2], tree[i<<1 | 1][2]);
    tree[i][3] = std::max(tree[i<<1][3], tree[i<<1 | 1][3]);
  }
}


// [l, r)
void queryTree(int tree[][4], int l, int r, int *xMin, int *yMin, int *xMax, int *yMax) {
  *xMin = 1000000001;
  *yMin = 1000000001;
  *xMax = -1;
  *yMax = -1;
  for (l += TN, r += TN; l < r; l >>= 1, r >>= 1) {
    if (l&1) {
      // printf("Checking %d\n", l);
      *xMin = std::min(tree[l][0], *xMin);
      *yMin = std::min(tree[l][1], *yMin);
      *xMax = std::max(tree[l][2], *xMax);
      *yMax = std::max(tree[l++][3], *yMax);
    }
    if (r&1) {
      *xMin = std::min(tree[--r][0], *xMin);
      *yMin = std::min(tree[r][1], *yMin);
      *xMax = std::max(tree[r][2], *xMax);
      *yMax = std::max(tree[r][3], *yMax);
    }
  }
}

int main() {

  int T;
  int x,y;

  scanf("%d", &T);
  while (T--) {
    scanf("%d", &N);
    points = vpi(N);
    for (int i=0; i<N; i++) {
      scanf("%d %d", &x, &y);
      points[i] = { x, y };
    }
    if (N == 1) {
      printf("0\n");
      continue;
    }

    // Segtree size is next power of 2 up
    TN = (int)pow(2, ceil(log2(N)));

    // Sort pairs by X
    sort(points.begin(), points.end());
    buildTree(xSortedTree);
    std::sort(points.begin(), points.end(), [](auto &left, auto &right) {
      if (left.second < right.second)
        return true;
      if (left.second > right.second)
        return false;
      return left.first < right.first;
    });
    buildTree(ySortedTree);

    // Loop through all possible areas
    ll minArea = (ll)1000000000*(ll)1000000000;
    int a, b, c, d;

    // Iterate left to right
    for (int i=0; i<N-1; i++) {

      // Form left square
      queryTree(xSortedTree, 0, i+1, &a, &b, &c, &d);
      ll leftArea = (ll)(d-b)*(ll)(c-a);

      // Form right square
      queryTree(xSortedTree, i+1, N, &a, &b, &c, &d);
      ll rightArea = (ll)(d-b)*(ll)(c-a);

      // Calculate minimum area
      minArea = std::min(minArea, leftArea+rightArea);
    }
  
    // Iterate top to bottom
    for (int i=0; i<N-1; i++) {

      // Form top square
      queryTree(ySortedTree, 0, i+1, &a, &b, &c, &d);
      ll topArea = (ll)(d-b)*(ll)(c-a);

      // Form bottom square
      queryTree(ySortedTree, i+1, N, &a, &b, &c, &d);
      ll botArea = (ll)(d-b)*(ll)(c-a);

      // Calculate minimum area
      minArea = std::min(minArea, topArea+botArea);
    }
    printf("%lld\n", minArea);
  }
  
  return 0;
}
