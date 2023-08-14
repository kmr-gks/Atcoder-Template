//ここはコンパイルエラー回避のためのもの
#include "bits/stdc++.h"
typedef long long ll;
const int mod=1e9+7;
#define rep(i,n) for (int i=1;i<=(n);++i)
#define fore(i,a) for(auto&i:a)
using namespace std;


//nCr modを求める関数群
#define KAIJOU_MAX 1000000
//nの階乗とその逆元
ll kaijo[KAIJOU_MAX], gyakuKaijo[KAIJOU_MAX];

//xの逆元(mod)を計算
ll calcGyakugen(ll x) {
	ll res = 1;
	ll k = mod - 2;
	ll y = x;
	while (k) {
		//繰り返し二乗法とフェルマーの小定理
		if (k & 1) res = (res * y) % mod;
		y = (y * y) % mod;
		k /= 2;
	}
	return res;
}

//最初に呼び出す必要がある。
void initialize_mylibrary() {
	kaijo[0] = 1;
	for (ll i = 1; i < KAIJOU_MAX; i++) kaijo[i] = (kaijo[i - 1] * i) % mod;
	for (ll i = 0; i < KAIJOU_MAX; i++) gyakuKaijo[i] = calcGyakugen(kaijo[i]);
}

//nCkをmodで計算する
ll nCk(ll n, ll k) {
	//ll a = kaijo[n]; // = n!
	//ll b = gyakuKaijo[n-k]; // = (n-k)!
	//ll c = gyakuKaijo[k]; // = k!
	return ((kaijo[n] * gyakuKaijo[n - k] % mod) * gyakuKaijo[k]) % mod;
}

vector<int> prime;
void calcSosuu() {
	rep(i, 2, 100000) {
		int yakusu = 2;
		bool flag = true;
		while (yakusu*yakusu <= i) {
			if (i%yakusu == 0) {
				flag = false;
				break;
			}
			yakusu++;
		}
		if (flag) prime.push_back(i);
	}
}

struct chokusen {
	//ax+by+c=0
	double a, b, c;
	chokusen(double a,double b,double c):a(a),b(b),c(c){}
};

int getRandomNumFromTo(int from=-1e9, int to=1e9)
{
	static random_device rd;
	static mt19937 gen(rd());
	std::uniform_int_distribution<> dist(from, to);
	return dist(gen);
}

chokusen twoTenToChokusen(int px, int py, int qx, int qy){
	//y=ax+b
	double a, b;
	if (qx - px != 0) {
		a = ((double)qy - py) / ((double)qx - px);
		b = py - a * px;
		//ax - y + b =0
		return chokusen(a,-1,b);
	}
	else {
		//x=px
		return chokusen(1,0,-px);
	}
}

