#define MAX_N 100000

int par[MAX_N];
int tree_rank[MAX_N]; //  树的高度，合并的时候用于避免退化

void init(int n){
	for (int i = 0; i < n; ++i)	{
		par[i] = i;
		tree_rank[i] = 0;
	}
}

// 查询根
int find(int x){
	if (par[x] == x){
		return x;
	}else {
		return par[x] = find(par[x]);
	}
}

// 合并
void unite(int x, int y){
	x = find(x);
	y = find(y);
	if (x == y){
		return;
	}
	if (tree_rank[x] < tree_rank[y]){
		par[x] = y;
	}else {
		par[y] = x;
		if (tree_rank[x] == tree_rank[y])
		{
			tree_rank [x] ++;
		}
	}
}

bool same(int x, int y){
	return find(x) == find(y);
}