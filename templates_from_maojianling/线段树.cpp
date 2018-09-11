// 基于线段树的RMQ  range minimal queue实现

typedef long long ll;

const int max_n = 1000000;

// 根节点为0
// 节点i的儿子为 2i+1 和 2i+2
ll dat[2*max_n];
ll n;

void init (ll n_){
	n = 1;
	while (n < n_) n*= 2;
	memset(dat, INF, 2*n);
}


// [a, b) 为要求的区间
// [l, r) 为当前节点所代表的区间
// k 为节点编号 用法 query(a, b, 0, 0, n)
ll query(int a, int b, int k, int l, int r){
	if (r <= a || b <= l) return INF;
	if (l >= a && r <= b) return dat[k];
	else{
		ll v1 = query(a, b, 2*k+1, l, (l+r)/2);
		ll v2 = query(a, b, 2*k+2, (l+r)/2, r);
		return MIN(v1, v2);
	}
}


void update(int k, int a){
	k += n-1;
	dat[k] = a;
	while(k>0){
		k = (k-1) / 2;
		dat[k] = min(dat[k*2+1], dat[k*2+2])
	}
}
