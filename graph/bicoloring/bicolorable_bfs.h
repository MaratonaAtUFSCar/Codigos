#include <vector>
#include <queue>
#include <string.h>

using namespace std;

/*
 *  Note:               Change this "magic" number
 */
#define MAX 1000

vector<int> g[MAX];
int colors[MAX];

/*
 *  Calling:            is_bicolorable($ANY_VERTICE_ID);
 *
 *  Notes:              1. If the graph is not connected, you may want to run the following:
 *                          for (int i = 0; i < V; ++i) {
 *                              if (!colors[i] && !is_bicolorable(i, 1)) {
 *                                  ok = false;
 *                                  break;
 *                              }
 *                          }
 *
 *                      2. If is_bicolorable() returns true, we will have a bipartited graph
 *                      divided on the groups (colors[i] == 1) and (colors[i] == -1)
 */
 bool is_bicolorable(int beg) {
     memset(colors, 0, sizeof colors);
     queue<int> q;

     q.push(beg);
     colors[beg] = 1;

     while (!q.empty()) {
         int curr = q.front(); q.pop();

         for (int i = 0; i < MAX; ++i) {
             if (!g[curr][i]) continue;

             int next = i;

             if (!colors[next]) {
                 colors[next] = -colors[curr];
                 q.push(next);
             }
             else if (colors[next] == colors[curr]) {
                 return false;
             }
         }
     }

     return true;
 }
