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
string enc(string key,string plaintext,int round){
	string Li,Ri,Ln,Rn,K,f;
	K=keyer(key,round);Li.append(plaintext,0,6);
	Ri.append(plaintext,6,6);Ln=Ri;
	f.append(hehe(Ri,K));
	Rn.append(f);Rn=XOR(Li,f);
	return (Ln+Rn);
}
string dec(string key,string ciphertext,int round){
	string Li,Ri,Ln,Rn,K,f;
	K=keyer(key,round);Li.append(ciphertext,0,6);
	Ri.append(ciphertext,6,6);Rn=Li;
	f.append(hehe(Rn,K));Ln.append(f);
	Ln=XOR(Ri,f);
	return (Ln+Rn);
}
string keyer(string key,int round){
	string K;
	if(round==1) K.append(key,0,8);
	else if(round==2) K.append(key,1,8);
	else if(round==3) K.append(key,2,7),K.append(key,0,1);
	else if(round==4) K.append(key,3,6),K.append(key,0,2);
	return K;
}
string hehe(string R,string K){
	char tmp;
	string s1,s2;
	R.append(R,4,2);
	tmp=R[3];R[5]=R[2];R[4]=tmp;
	R[3]=R[2];R[2]=tmp;R=XOR(R,K);
	s1.append(R,0,4);s2.append(R,4,4);
	return bx1(s1)+bx2(s2);
}
string XOR(string x,string y){
	for(int i=0;i<x.length();i++)
		if(x[i]==y[i]) x[i]='0';
		else if(x[i]!=y[i]) x[i]='1';
	return x;
}
string bx1(string s1){
	string row1[8]={"101","010","001","110","011","100","111","000"};
	string row2[8]={"001","100","110","010","000","111","101","011"};
	int column=0;
	if(s1[0]=='0') {
		if(s1[1]=='1') column += 4;
		if(s1[2]=='1') column += 2;
		if(s1[3]=='1') column += 1;
		return row1[column];
	}
	else if(s1[0]=='1'){
        if(s1[1]=='1') column += 4;
		if(s1[2]=='1') column += 2;
		if(s1[3]=='1') column += 1;
		return row2[column];
	}
	else return "ERROR";
}
string bx2(string s2){
	string row1[8]={"100","000","110","101","111","001","011","010"};
	string row2[8]={"101","011","000","111","110","010","001","100"};
	int column=0;
	if(s2[0]=='0'){
		if(s2[1]=='1') column += 4;
		if(s2[2]=='1') column += 2;
		if(s2[3]=='1') column += 1;
		return row1[column];
	}
	else if(s2[0]=='1') {
		if(s2[1]=='1') column+=4;
		if(s2[2]=='1') column += 2;
		if(s2[3]=='1') column += 1;
		return row2[column];
	}
	else return "ERROR";
}
string randomString(int length){
	srand(time(0));
	int randomNumber;
	string randomBit,randomString;
	for(int k=0; k < length; k++){
		randomNumber=rand() % 2;
		if(randomNumber==0) randomBit="0";
		else if(randomNumber==1) randomBit="1";
		randomString.append(randomBit);
	}
	return randomString;
}
void solve(){
    string plaintext=randomString(12);
	string key=randomString(9),ciphertext,decryption;
	int numrounds=4,rounds;
	cout << "Original Plaintext: " << plaintext << endl << "Key: " << key << endl << "Encryption: " << endl;
	for(int i=0; i < numrounds; i++){
		plaintext=enc(key,plaintext,i+1);
		cout << "C (after round " << i+1 << "): " << plaintext << endl;
		rounds=i+1;
	}
	ciphertext.append(plaintext,6,6),ciphertext.append(plaintext,0,6);
	cout << endl << "Ciphertext after " << rounds  << " rounds: " << ciphertext << endl << endl;
	cout << "Proof by decryption:\n" << "Ciphertext: " << ciphertext << endl << endl;
	decryption.append(ciphertext,6,6),decryption.append(ciphertext,0,6);
	for(int j=numrounds; j > 0; j--) {
		decryption=dec(key,decryption,j);
		if(j != 1) cout << "C(after round " << j << "): " << decryption << endl;
		else if(j==1) cout << "Plaintext after:  " << decryption << endl << endl;
	}
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