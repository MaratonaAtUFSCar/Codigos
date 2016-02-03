#include <vector>
#include <string.h>

using namespace std;

/*
 *  Note:               Change this "magic" number
 */
#define MAX 1000

vector<int> g[MAX];
int colors[MAX];

/*
 *  Before calling:     memset(colors, 0, sizeof colors);
 *
 *  Calling:            is_bicolorable($ANY_VERTICE_ID, 1);
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
 bool is_bicolorable(int curr, int color) {
     colors[curr] = color;

     for (int i = 0; i < g[curr].size(); ++i) {
         int next = g[curr][i];

         if (!colors[next]) {
             if (!is_bicolorable(next, -color)) return false;
         }
         else if (colors[next] == color) {
             return false;
         }
     }

     return true;
 }
