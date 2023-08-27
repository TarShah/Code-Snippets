//Binary exponentiation
auto binpow = [&](ll a, int p){
	if(p*log10(a)>18.1){
		return LLONG_MAX;
	}
	ll ret = 1;
	for(int i=0;i<7;i++){
		if(1LL<<i & p){
			ret*=a;
		}
		a=a*a;
	}
	return ret;
};
//kth power
auto kth = [&](ll n, int k){
	ll str = 1;
	ll end = n;
	while(str<=end){
		ll mid = (str+end)/2;
		if(binpow(mid,k)>n){
			end = mid-1;
		}
		else{
			str = mid+1; 
		}
	}
	return end;
};
