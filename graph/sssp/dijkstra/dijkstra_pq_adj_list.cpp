/*
    Autor: Antonio Carlos - BCC-014
 */

 #include <bits/stdc++.h>
 using namespace std;

 #define MAX -1

 typedef pair<int, int> ii;

 vector<ii> g[MAX];
 int dist[MAX];
 bool vis[MAX];

/*
    Complexidade: O(|E| * log |V|)

    s é o vértice source
    t é o vértice target

    OBS:
    A priority_queue ordena, por default, em ordem não-crescente.
    Como queremos escolher sempre a menor distância disponível,
    precisamos inverter esse comportamento.
    Pessoalmente, eu prefiro definir a queue utilizando o comparador greater:
    -   priority_queue<ii, vector<ii>, greater<ii> > pq;

    Uma alternativa comum é a Opção 2, que adiciona a pq o valor -dist[next],
    o que permite utilizar o comportamento default da pq:
    -   dist[i] <= dist[j] <-> -dist[i] >= -dist[j]
 */
int dijkstra(int s, int t) {
    priority_queue<ii, vector<ii>, greater<ii> > pq;
    // Opção 2: priority_queue<ii> pq;
    pq.push(ii(0, s));

    memset(dist, 0x3f, sizeof dist);
    memset(vis, false, sizeof vis);
    dist[s] = 0;

    while (!pq.empty()) {
        int curr = pq.top().second; pq.pop();

        if (vis[curr]) continue;
        vis[curr] = true;

        if (curr == t) return dist[curr];

        for (int i = 0; i < g[curr].size(); ++i) {
            int d    = g[curr][i].first;
            int next = g[curr][i].second;

            // relax
            if (dist[next] > dist[curr] + d) {
                dist[next] = dist[curr] + d;
                pq.push(ii(dist[next], next));
                // Opção 2: pq.push(ii(-dist[next], next));
            }
        }
    }

    // Não existe caminho entre s e t
    return -1;
}
