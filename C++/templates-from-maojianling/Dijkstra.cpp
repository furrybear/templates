// 2018/01/02
// 此处没有使用used数组，因此节点可能会重复入队。
// 因此我觉得此处算法可以解决负权边（无负圈）情况，
// 但是这样会导致复杂度超出要求。



int N, M, X;

struct edge {int to, cost;};
typedef pair<int, int > P;  // first:最短距离  second:顶点编号

int V;
vector<edge> G[MAX_N];

int d[MAX_N];

void dijkstra(int s){
	priority_queue<P, vector<P>, greater<P> > que;
	fill(d, d+MAX_N, INF);
	d[s] = 0;
	que.push(P(0, s));
	while(!que.empty()){
		P p = que.top(); que.pop();
		int v = p.second;
		if (d[v] < p.first){ // 同一个节点被发现多次的时候会被push多次，此处相当于删除多余的
			continue;
		}
		for (int i = 0; i < G[v].size(); ++i){
			edge e = G[v][i];
			if (d[e.to] > d[v] + e.cost){
				d[e.to] = d[v] + e.cost;
				que.push(P(d[e.to], e.to));
			}
		}
	}
}