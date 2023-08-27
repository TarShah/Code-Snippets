//segtree<int> seg(array, [&](int i, int j){ return min(i,j); });
template <typename T, class F = function<T(const T&, const T&)>>
class segtree{
	public:
	int n;
	vector<T> tree;
	F func;
	
	segtree(vector<T> a,const F& f) : func(f) {
		n = static_cast<int>(a.size());
		tree.resize(2*n);
		for(int i=0;i<n;i++){
			tree[n+i] = a[i];
		}
		for(int i=n-1;i>0;i--){
			tree[i] = func(tree[2*i],tree[2*i+1]);
		}
	}
	void update(int pos, T value){
		tree[pos+n] = value;
		pos += n;
		for(int i=pos;i>1;i/=2){
			tree[i/2] = func(tree[i],tree[i^1]);  
		}
	}
	// Function on interval [l,r)
	T get(int l, int r){
		// Initialze res acc to func requirements
		T res = 0;
    	for (l += n, r += n; l < r; l/=2 , r/=2){
        	if(l&1){ 
            	res = func(res,tree[l++]);
      		}
      		if(r&1){ 
            	res = func(res,tree[--r]);
    		}
   		}
    	return res;
	}
	
};
