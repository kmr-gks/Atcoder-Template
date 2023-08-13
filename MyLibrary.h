typedef long long ll;

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define modwaru 1'000'000'007
#define maxint 2'147'483'647

//プロトタイプ
//a^nをpで割った余りを返す
ll modpow(ll a,ll n,ll p);
//SegmentTree:初期化n_:要素数
static int segmentn,segdat[2*(1<<17)-1];
void seginit(int n_);
//SegmentTree:k番目の値(0-indexed)をaに変更
void segupdate(int k,int a);
//SegmentTree:[a,b)の最小値を求めるquery(a,b,0,0,segmentn)として呼ぶ。
int segquery(int a,int b,int k,int l,int r);
//文字列sからbeforeを検索してafterに置換し、をs返す
char* myreplace(char* s, const char* before, const char* after);


//https://math.nakaken88.com/textbook/cp-binary-exponentiation-and-recursive-function/
ll modpow(ll a, ll n, ll p) {
	if (n == 0) return 1; // 0乗にも対応する場合
	if (n == 1) return a % p;
	if (n % 2 == 1) return (a * modpow(a, n - 1, p)) % p;
	ll t = modpow(a, n / 2, p);
	return (t * t) % p;
}

// 座標圧縮1次元
// 0-indexed
// O(nlogn)
// T型配列Xを座標圧縮する
// 引数を圧縮後の値に書き換え、元の値をソートしたデータを返す。
// 同じ値はまとめるので、戻り値の要素数は引数より小さくなる可能性があります。
// https://algo-logic.info/coordinate-compress
template <typename T>
vector<T> compress(vector<T>& X)
{
	vector<T> vals = X;
	sort(vals.begin(), vals.end());
	vals.erase(unique(vals.begin(), vals.end()), vals.end());
	for (int i = 0; i < (int)X.size(); i++)
	{
		X[i] = lower_bound(vals.begin(), vals.end(), X[i]) - vals.begin();
	}
	return vals;
}

void seginit(int n_)
{
	//簡単のため要素数を2のべき乗に
	segmentn=1;
	while(segmentn<n_)segmentn*=2;
	
	//すべての値をINT_MAXに
	for (int i=0;i<2*segmentn-1;i++) segdat[i]=INT_MAX;
}

void segupdate(int k,int a)
{
	//葉の節点
	k+=segmentn-1;
	segdat[k]=a;
	//登りながら更新
	while (k>0)
	{
		k=(k-1)/2;
		segdat[k]=min(segdat[k*2+1],segdat[k*2+2]);
	}
}

int segquery(int a,int b,int k,int l,int r)
{
	//[a,b)と[l,r)が交差しなければ、INT_MAX
	if (r<=a||b<=l) return INT_MAX;

	//[a,b)が[l,r)を完全に含んでいれば、この節点の値
	if (a<=r&&r<=b) return segdat[k];
	else {
		//そうでなければ、2つの子の最小値
		int vl=segquery(a,b,k*2+1,l,(l+r)/2);
		int vr=segquery(a,b,k*2+2,(l+r)/2,r);
		return min(vl,vr);
	}
}

/*
	文字列を置換する

	引数
		s: 置換対象の文字列。NULL不可
		before: 置き換える文字列。NULL不可。"" の場合は何もしない
		after: 置き換え後の文字列。NULL不可

	戻り値
		s を返す
*/
char* myreplace(char* s, const char* before, const char* after)
{

	const size_t before_len = strlen(before);
	if (before_len == 0) {
		return s;
	}
	const size_t after_len = strlen(after);
	char* p = s;
	for (;;) {
		// 置換する文字列を探す
		p = strstr(p, before);
		if (p == NULL) {
			// 見つからなければ、これ以上置換するものはないので終了する
			break;
		}
		// 置換対象にならない位置を計算
		const char* p2 = p + before_len;
		// 置換対象にならない位置(p2) 以降の文字列を、
		// 置換の影響を受けない位置に移動
		memmove(p + after_len, p2, strlen(p2) + 1);
		// 置換する
		memcpy(p, after, after_len);
		// 探索開始位置をずらす
		p += after_len;
	}
	return s;
}
