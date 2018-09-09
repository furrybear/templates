
int bit[MAX_N+1], n;

// get the sum of 1-i
int sum(int i){
	int s = 0;
	while (i>0){
		s+= bit[i];
		i = i & (i-1);  // 等价于 i -= i&-1
	}
	return s;
}

// add x to point i
void add(int i, int x){
	while (i<=n){
		bit [i] += x;
		i += i & -i; // i & -i 取出末尾1
	}
}