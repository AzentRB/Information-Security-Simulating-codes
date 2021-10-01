#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h> 
#include <complex>
#include <queue>
#include <set>
#include <unordered_set>
#include <list>
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
vector<int> X; 
int W[80],A,B,C,D,E,A1,B1,C1,D1,E1,lol;
void printX() { 
    for(int i=0;i<X.size();i++) {
        printf("%02x",X[i]);
        if((i+1)%4==0) printf(" ");
        if((i+1)%16==0) printf("\n");
    }
}
int S(unsigned int x, int n) { return x>>(32-n)|(x << n);}
void append(string m) {  
    lol=(m.size()+8)/64+1;X.resize(lol*64);
    int i=0;for(;i<m.size();i++) X[i]=m[i];
    X[i++]=0x80;while(i<X.size()-8) X[i]=0,i++;
    long long int a=m.size() * 8;
    for (i=X.size() - 1;i >= X.size() - 8;i--) X[i] =a%256,a/=256;
}
void setW(vector<int> m, int n) { 
    n *= 64;
    for(int i=0;i<16;i++) W[i]=(m[n+4*i]<<24)+(m[n+4*i+1]<<16)+(m[n+4*i+2]<<8)+m[n+4*i+3];
    for(int i=16;i<80;i++) W[i]=S(W[i-16]^W[i-14]^W[i-8]^W[i-3],1);
}
int ft(int t) {
    if(t<20) return (B&C)|((~B)&D);
    else if(t<40) return B^C^D;
    else if(t<60) return (B&C)|(B&D)|(C&D);
    else return B^C^D;
}
int Kt(int t) { 
    if(t<20) return 0x5a827999;
    else if(t<40) return 0x6ed9eba1;
    else if(t<60) return 0x8f1bbcdc;
    else return 0xca62c1d6;
}
void sha1(string text) {
    A1=A=0x67452301,B1=B=0xefcdab89,C1=C=0x98badcfe,D1=D=0x10325476,E1=E=0xc3d2e1f0;
    append(text);printX();
    int temp;
    for(int i=0;i<lol;i++) {
        setW(X,i);
        for(int t=0;t<80;t++) temp=E+ft(t)+S(A,5)+W[t]+Kt(t),E=D,D=C,C=S(B,30),B=A,A=temp;
        A1=A=A+A1,B1=B=B+B1,C1=C=C+C1,D1=D=D+D1,E1=E=E+E1;
    }
    printf("%08x%08x%08x%08x%08x\n\n", A1, B1, C1, D1, E1);
}
void solve(){
    string text="malhr";
    sha1(text);
}
int main(){
    fast_cin();
    ll t=1;
    //cin >> t;
    for(int it=1;it<=t;it++) {
        //cout << "Case #" << it+1 << ": ";
        solve();
    }
    return 0;
}