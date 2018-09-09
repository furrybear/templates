int V;   				// 顶点数
vector<int> G[MAX_V];  	// 图的邻接表表示
int match[MAX_V];    	//所匹配的顶点
bool used[MAX_V];    	// DFS中用到的访问机制

void add_edge(int u, int v){
	G[u].push_back(v);
	G[v].push_back(u);
}

// 通过DFS寻找增广路

// if 有未match邻居：ok
// else 在match点递归

bool dfs(int v){
	used[v] = true;
	for (int i = 0; i < G[v].size(); ++i){
		int u = G[v][i], w = match[u];
		if (w < 0 || !used[w] && dfs(w)) {
			match[v] = u;
			match[u] = v;
			return true;
		}
		return false;
	}
}

int bipartite_matching() {
	int res = 0;
	memset (match, -1, sizeof (match));
	for (int v = 0; v < V; v++){
		memset ( used, 0, sizeof(used));
		if (dfs(v)){
			res ++;
		}
	}
	return res;
}