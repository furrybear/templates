long long factorial(long long number) {   
	if(number<=1)  
        return 1;  
    else   
        return number*factorial(number-1);  
}  

int combinator(int n,int m) {  // C_n^m
   int temp;  
    if(n<m)  
    {   temp=n;  
        n=m;  
        m=temp;}  
    return factorial(n)/(factorial(m)*factorial(n-m));  
}  


ll combinator(int n,int m) {
    ll s = 1;
    ll k = 1;
    if (m > n / 2)
        m = n - m;
    for (ll i = n - m + 1; i <= n; i++) {
        s *= i;
        while (k <= m && s % k == 0) {
            s /= k;
            k++;
        }
    }
    return s%MAX_N;
}

ll combinator(int n, int m){
    if (m > n / 2)
        m = n - m;
    ll res = 1;
    for (int i = 1; i <= m; ++i){
        res = (res * ((n - i + 1)/i))%MAX_N;
    }
    return res;
}