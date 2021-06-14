/**********************************************************/
/*                                                        */
/* Anthony Meyer                                          */
/* https://www.codechef.com/problems/SUBTRCOV             */
/*                                                        */
/**********************************************************/

#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <bits/stdc++.h>

#define vi  std::vector<int>
#define vb  std::vector<bool>
#define vii std::vector<vi>
#define qi  std::queue<int>
#define pq  std::priority_queue<int>

// Globally declare graph and visited vectors
vii G;  
vb  V;
vi  P;
qi  Q;

// Test case parameters
int T, n, k, u, v;

// For running breadth first search to find longest path nodes
int bfsStart(int root);
void bfsExplore(int node);

// For finding specific path from node to node
void dfsStart(int root, int target);
bool dfsExplore(int node, int target);

// For calculating leave distance from longest path
void dfsLeaves(int root, pq &leaves, int ignoreA, int ignoreB);
void dfsLeaves(int root, pq &leaves, int ignore);

// MAIN CODE
int main() {

  // Read in number of test cases
  scanf("%d", &T);

  // For each test case
  while (T--) {

    // Tree size and K
    scanf("%d %d", &n, &k);

    // Create tree nodes but no connections
    G = vii(n, vi());

    // Read in edges
    for (int i=0; i<n-1; i++) {
      scanf("%d %d", &u, &v);
      u--; v--;
      G[u].push_back(v);
      G[v].push_back(u);
    }

    // Corner case
    if (n == 1 || k == 1) {
      printf("1\n");
      continue;
    }

    // Solve the problem
    int A, B;

    // 1. Run BFS starting from 1 to find the furthest element from 1 (A)
    A = bfsStart(0);

    // 2. Run BFS again starting from the furthest element of A, (B)
    B = bfsStart(A);

    // 3. Find the actual longest path from A to B
    dfsStart(A, B);

    // Now we do DFS from each node on p
    pq leaves;

    // For each node in the path
    for (int p=1; p<P.size()-1; p++)
      dfsLeaves(P[p], leaves, P[p-1], P[p+1]);

    // Initial S and K
    int setSize = 2;
    int K = P.size();
    while (K < k) {
      setSize++;
      int t = leaves.top();
      leaves.pop();
      K += t;
    }

    // Print the answer
    printf("%d\n", setSize);
  }
  return 0;
}

int bfsStart(int root) {
  
  // Furthest element
  int farthestNode = root;

  // Created visited list 
  V = vb(n, false);

  // Queue up root node
  Q.push(root);

  // Visit nodes until Queue is empty
  while (!Q.empty()) {
    int next = Q.front();
    Q.pop();
    if (!V[next]) {
      farthestNode = next;
      bfsExplore(next);
    }
  }

  // Return the farthest node from root
  return farthestNode;
}

void bfsExplore(int node) {
  V[node] = true;

  // Queue up children
  for (auto c : G[node]) {
    if (!V[c]) Q.push(c);
  }
}

// Ignore left and right node on path
void dfsStart(int root, int target) {

  // Create visited list
  V = vb(n, false);

  // Create stack for storing path
  P = vi();

  // Begin the DFS search
  dfsExplore(root, target);
}

bool dfsExplore(int node, int target) {

  // Mark as explored
  V[node] = true;

  // Add node to path
  P.push_back(node);

  // We are done
  if (node == target)
    return true;

  // Iterate through children
  for (auto c : G[node]) {

    // If not already visited, visit
    if (!V[c]) {
      if (dfsExplore(c, target))
        return true;
    }
  }

  // This is obviously not a part of the path
  P.pop_back();
  return false;
}

void dfsLeaves(int root, pq &leaves, int ignoreA, int ignoreB) {

  // Leaf node
  if (G[root].size() == 1) {
    leaves.push(1);
    return;
  }

  for (auto c : G[root]) {
    if (c == ignoreA || c == ignoreB)
      continue;
    dfsLeaves(c, leaves, root);
  }
}

void dfsLeaves(int root, pq &leaves, int ignore) {
  
  // Base case
  if (G[root].size() == 1) {
    leaves.push(1);
    return;
  }

  // Local PQ
  pq local;
  for (auto child : G[root]) {

    // Skip parent
    if (child == ignore)
      continue;

    // Add items to priority queue
    dfsLeaves(child, local, root);
  }

  // Take the highest element of priority queue and increase by 1
  int t = local.top() + 1;
  local.pop();
  leaves.push(t);
  while (!local.empty()) {
    t = local.top();
    local.pop();
    leaves.push(t);
  }
}
