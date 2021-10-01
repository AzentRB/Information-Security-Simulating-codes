#include <chrono>
#include <random>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <iomanip>
#include <fstream>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int,int> p32;
typedef pair<ll,ll> p64;
typedef pair<double,double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int> > vv32;
typedef vector<vector<ll> > vv64;
typedef vector<vector<p64> > vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
ll MOD = 998244353;
double eps = 1e-12;
#define forn(i,e) for(ll i = 0; i < e; i++)
#define forsn(i,s,e) for(ll i = s; i < e; i++)
#define rforn(i,s) for(ll i = s; i >= 0; i--)
#define rforsn(i,s,e) for(ll i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
ll gcd(ll a,ll b,ll &x,ll &y) {
	if(a==0) {
		x=0,y=1;
		return b;
	}
	ll x1,y1,d=gcd(b % a, a, x1, y1);
	x=y1-(b/a)*x1,y=x1;
	return d;
}
ll lol(ll a,ll n,ll m) {
	if(n==0) return 1;
	if(n%2==1) return (a*lol(a,n-1,m))%m;
	ll b=lol(a,n/2,m);
	return (b*b)%m;
}
bool isPrime(ll n) {
	for(ll i=2;i<n;i++) if(n%i==0) return false;
	return true;
}
void solve(){
    ll p,q,e;
	cout << "Enter p, q (must be primes): ";
	cin >> p >> q;
	cout << "Enter public exponent (must be prime): ";
	cin >> e;
	while (!isPrime(e)) {
		cout << "e is not prime. Try again: ";
		cin >> e;
	}
	ll n=p*q,phi=(p-1)*(q-1),d,y,R;
	gcd(e,phi,d,y); 
	if(d<0) d+=phi;
	cout << "Enter value to encrypt: ";
	cin >> R;
	ll enc=lol(R,e,n),dec=lol(enc,d,n);
	cout << endl;
	cout << "e = " << e << endl;
}
int main()
{
    fast_cin();
    ll t=1;
    //cin >> t;
    for(int it=1;it<=t;it++) {
        //cout << "Case #" << it+1 << ": ";
        solve();
    }
    return 0;
}
