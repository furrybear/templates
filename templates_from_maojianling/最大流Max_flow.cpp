struct edge {int to ,cap, rev;}

vector<edge> G[MAX_V];
bool used[MAX_V];

void add_edge(int from, int to, int cap){
	G[from].push_back((edge){to, cap, G[to].size()});
	G[to].push_back((edge){from, 0, G[from].size()-1 });
}

// 可以理解为 尝试寻找一条从s到t的容量为f的路径，返回值为实际找到
// 的流量（不一定是最大，仅仅代表一条增广路）
int  dfs(int s, int t, int f){
	if (s == t) return f;
	used[s] = true;
	// int max_f = f;
	// int v = s;
	for (int i=0; i<G[s].size(); i++){
		edge &e = G[s][i];
		if (!used[e.to] && e.cap > 0){
			int res = dfs(e.to, t, MIN(f, e.cap));
			e.cap -= res;
			G[e.to][e.rev].cap += res;

			return res;
		}
	}
	return 0;

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
