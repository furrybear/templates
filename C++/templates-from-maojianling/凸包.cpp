// 结合向量运算部分使用

bool cmp_x(const P p1, const P p2){
	if(p1.x == p2.x) return p1.y < p2.y;
	return p1.x < p2.x;
}

int N, L;

vector<P> convex_hull(P* ps, int n){
	vector<P> qs(n*2);
	sort(ps, ps+n, cmp_x);
	int k = 0;
	// qs[0] = ps[0];  //结构体可以直接等吗 ? 可以
	// qs[1] = ps[1];
	for (int i = 0; i < n; ++i){
		while (k > 1 && (ps[i]-qs[k-1]).det(qs[k-1]-qs[k-2]) >= 0){
			k--;
		}
		qs[k++] = ps[i];
	}
	for (int i = n-2, end = k; i >= 0; --i){
		while ( k > end && (ps[i]-qs[k-1]).det(qs[k-1]-qs[k-2]) >= 0){
			k--;
		}
		qs[k++] = ps[i];
	}
	qs.resize(k-1);
	return qs;
}