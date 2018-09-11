// 终点 容量 费用 反向边
struct edge {int to ,cap , cost, rev;}

int V;
vector<edge> G[MAX_V];
int dist[MAX_V];
int prevv[MAX_V], preve[MAX_V];   // 最短路中的前驱节点和对应边

void add_edge(int from, int to, int cap, int cost){
	G[from].push_back((edge){to, cap, cost, G[to].size()});
	G[to].push_back((edge){from, 0, -cost, G[from].size()-1 });  // -cost....
}

// 求从s到t的流量f的最小费用流
// 相对于最大流，此处不仅仅是寻找一条路，而是寻找一条最小费用路（最短路）
// 由于反向边的cost一定为负数，所以不适用Dijkstra算法（除非是不使用used数组，允许节点重新入队，但是由于负权边太多故效率不高）
// 此处采用bellman-ford 算法
int min_cost_flow(int s, int t, int f){
	int  res = 0;
	
	while (f > 0 ){
		//  更新距离
		fill (dist, dist+V, INF);
		dist[s] = 0;
		bool update = true;
		while (update){
			update = false;
			for (int v=0; v<V; v++){
				if (dist[v] == INF) continue;
				for (int i=0; i<G[v].size(); i++){
					edge &e = G[v][i];
					if (e.cap > 0 && dist[e.to] > dist[v] + e.cost){
						dist[e.to] = dist[v] + e.cost;
						prevv[e.to] = v;
						preve[e.to] = i;
						update = true;
					}
				}
			}
		}

		if (dist[t] == INF){
			return -1;
		}
		// 求路径瓶颈流量
		int d = f;
		for (int i=t; i!=s; i=prevv[i]){
			d = MIN(G[prevv[i]][preve[i]].cap, d);
		}
		// 从后往前修改增广路的容量
		f -= d;
		res += d * dist[t];
		for (int i=t; i!=s; i=prevv[i]){
			G[prevv[i]][preve[i]].cap -= d;
			G[i][ G[prevv[i]][preve[i]].rev ].cap += d;
		}
	}
	return res;


}

int max_flow(int s, int t){
	int flow = 0;
	while (1){
		memset(used, 0, sizeof(used));
		int f = dfs(s, t, INF);
		if (f == 0) return flow;
		flow += f;
	}
	
}
