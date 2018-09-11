// 用二维vector来表示矩阵
typedef vector<int> vec;
typedef vector<vec> mat;
typedef long long ll;

const int M = 10000; // 防止结果太大，所以应该进行模运算

// 计算A*B
mat mul(mat &A, mat &B){
	mat C(A.size(), vec(B[0].size()));
	for (int i=0; i<A.size(); i++){
		for (int j = 0; j < B[0].size(); ++j){
			
			for (int k = 0; k < B.size(); ++k){
				C[i][j] = (C[i][j] + A[i][k]*B[k][j]) % M;				
			}

		}
	}
	return C;
}

// 计算A^n  A为m*m矩阵
mat pow(mat A, ll n){
	mat B(A.size(), vec(A[0].size()));
	for (int i=0; i< A.size(); i++){
		B[i][i] = 1;
	}
	while (n>0) {
		if ( n > 0) B = mul(B, A);
		A = mul(A, A);
		n >> = 1;
	}
	return B;
}
