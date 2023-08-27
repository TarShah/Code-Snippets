// dsu d(n)
class dsu {
  	public:
  	vector<int> p;
  	vector<int> sz;
  	int n;

  	dsu(int _n) : n(_n) {
    	p.resize(n);
    	sz.resize(n,1);
    	iota(p.begin(), p.end(), 0);
  	}

  	inline int get(int x) {
    	return (x == p[x] ? x : (p[x] = get(p[x])));
  	}

  	inline bool unite(int x, int y) {
    	x = get(x);
    	y = get(y);
    	if (x != y) {
      		p[x] = y;
      		sz[y]+=sz[x]
      		return true;
    	}
    	return false;
  	}
};
