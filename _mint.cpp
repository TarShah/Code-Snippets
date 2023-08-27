template<int MOD>
struct MI {
  unsigned x;
  MI() : x(0) { }
  MI(signed sig) : x(sig) {  }
  MI(signed long long sig) : x(sig%MOD) { }
  int get() const { return (int)x; }
  MI pow(ll p) { MI res = 1, a = *this; while (p) { if (p & 1) res *= a; a *= a; p >>= 1; } return res; }
 
  MI &operator+=(MI that) { if ((x += that.x) >= MOD) x -= MOD; return *this; }
  MI &operator-=(MI that) { if ((x += MOD - that.x) >= MOD) x -= MOD; return *this; }
  MI &operator*=(MI that) { x = (unsigned long long)x * that.x % MOD; return *this; }
  MI &operator/=(MI that) { return (*this) *= that.pow(MOD - 2); }
 
  MI operator+(MI that) const { return MI(*this) += that; }
  MI operator-(MI that) const { return MI(*this) -= that; }
  MI operator*(MI that) const { return MI(*this) *= that; }
  MI operator/(MI that) const { return MI(*this) /= that; }
  bool operator<(MI that) const { return x < that.x; }
  bool operator>(MI that) const { return x > that.x; }
  bool operator==(MI that) const { return x == that.x; }
  bool operator>=(MI that) const { return x >= that.x; }
  bool operator<=(MI that) const { return x <= that.x; }
  friend ostream& operator<<(ostream &os, MI a) { os << a.x; return os; }
};
typedef MI<1000000007> mint;
// To use pow, use a.pow(p);

const int nax = 1e5+5;
const int mod =1e9+7;
mint fact[nax];
mint inv[nax];
void calc()
{
	fact[0]=1;
	inv[0]=1;
	for(int i=1;i<nax;i++)
	{
		fact[i]=fact[i-1]*(mint)i;
		inv[i]=fact[i].pow(mod-2);
	}
}
