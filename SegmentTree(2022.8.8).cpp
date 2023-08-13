template< typename T=int > struct SegmentTree {

	/*
	使用例
	https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A&lang=jp
	int n, q;
	cin >> n >> q;
	SegmentTree<int> segtree(n, [](int a, int b) {return min(a, b); }, inf);
	while (q--) {
		int t, x, y;
		cin >> t >> x >> y;
		if (t == 0) segtree.update(x, y);
		else cout << segtree.query(x, y + 1) << endl;
	}
	*/

	//T型の引数2つを取り、T型の値を返す関数のラムダ式の型
	using func = function< T(T, T) >;

	int sz;//要素数より大きい 最小の2の累乗数
	vector< T > seg;

	const func f;
	const T default_value;

	//コンストラクタ セグメント木に格納するデータ数、比較関数、デフォルトの値を指定する。
	SegmentTree(int kosuu, const func f, const T& default_value = 0) : f(f), default_value(default_value) {
		sz = 1;
		while (sz < kosuu) sz <<= 1;//sz*=2;
		//配列を初期化
		seg.assign(2 * sz, default_value);
	}

	//k(>=0)番目の要素をxに置き換えるのみ。後でbuild()を呼び出す必要がある。
	void set(int k, const T& x) {
		seg[k + sz] = x;
	}

	//セグメント木の状態を最新にする。O(n)
	void build() {
		for (int k = sz - 1; k > 0; k--) {
			seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]);
		}
	}

	//k(>=0)番目の要素をxに置き換え、セグメント木の状態を最新にする。
	void update(int k, const T& x) {
		k += sz;
		seg[k] = x;
		while (k >>= 1) {
			seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]);
		}
	}

	//半開区間[a,b)での値を取得する
	T query(int a, int b) {
		T L = default_value, R = default_value;
		for (a += sz, b += sz; a < b; a >>= 1, b >>= 1) {
			if (a & 1) L = f(L, seg[a++]);
			if (b & 1) R = f(seg[--b], R);
		}
		return f(L, R);
	}

	//k(>=0)番目の要素を取得する
	T operator[](const int& k) const {
		return seg[k + sz];
	}

	void showAll_newline() {
		for (auto it = seg.begin(); it != seg.end(); it++) {
			if (*it == default_value) cout << it - seg.begin() << ':' << "default" << endl;
			else cout << it - seg.begin() << ':' << *it << endl;
		}
	}
	void showAll_inline() {
		for (auto it = seg.begin(); it != seg.end(); it++) {
			if (*it == default_value) cout << it - seg.begin() << ':' << "default" << ' ';
			else cout << it - seg.begin() << ':' << *it << ' ';
		}
		cout << endl;
	}

	template< typename C > int find_subtree(int a, const C& check, T& M, bool type) {
		while (a < sz) {
			T nxt = type ? f(seg[2 * a + type], M) : f(M, seg[2 * a + type]);
			if (check(nxt)) a = 2 * a + type;
			else M = nxt, a = 2 * a + 1 - type;
		}
		return a - sz;
	}

	//[a,x)がcheck()を満たす最初の要素位置xを返す。
	template< typename C > int find_first(int a, const C& check) {
		T L = default_value;
		if (a <= 0) {
			if (check(f(L, seg[1]))) return find_subtree(1, check, L, false);
			return -1;
		}
		int b = sz;
		for (a += sz, b += sz; a < b; a >>= 1, b >>= 1) {
			if (a & 1) {
				T nxt = f(L, seg[a]);
				if (check(nxt)) return find_subtree(a, check, L, false);
				L = nxt;
				++a;
			}
		}
		return -1;
	}

	//[x,b)がcheck()を満たす最初の要素位置xを返す。
	template< typename C > int find_last(int b, const C& check) {
		T R = default_value;
		if (b >= sz) {
			if (check(f(seg[1], R))) return find_subtree(1, check, R, true);
			return -1;
		}
		int a = sz;
		for (b += sz; a < b; a >>= 1, b >>= 1) {
			if (b & 1) {
				T nxt = f(seg[--b], R);
				if (check(nxt)) return find_subtree(b, check, R, true);
				R = nxt;
			}
		}
		return -1;
	}
};