class UnionFind {
	//Union-Find木
	static constexpr int UNIONFIND_MAX = 100000;
	int par[UNIONFIND_MAX];
	int rank_uf[UNIONFIND_MAX];
	int ne_group_num[UNIONFIND_MAX];
	bool is_group_new;

public:
	//UnionFind:n要素で初期化
	UnionFind(int n)
	{
		for (int i = 0; i < UNIONFIND_MAX; i++)
		{
			par[i] = i;
			rank_uf[i] = 0;
		}
		is_group_new = false;
	}
	//木の根を求める:
	int find(int x)
	{
		if (par[x] == x)
		{
			//最上階
			return x;
		}
		else {
			//ひとつ上の階層に移動
			return par[x] = find(par[x]);
		}
	}
	//xとyの属する集合を併合
	void unite(int x, int y)
	{
		x = find(x);
		y = find(y);
		if (x == y) return;

		if (rank_uf[x] < rank_uf[y])
		{
			par[x] = y;
		}
		else {
			par[y] = x;
			if (rank_uf[x] == rank_uf[y]) rank_uf[x]++;
		}
		is_group_new = false;
	}
	//xとyが同じ集合に属するか否か
	bool same(int x, int y)
	{
		return find(x) == find(y);
	}
	void ne_group_count() {
		if (!is_group_new) {
			rep(i, 0, UNIONFIND_MAX) {
				ne_group_num[i] = 0;
			}
			rep(i, 0, UNIONFIND_MAX) {
				ne_group_num[find(i)]++;
			}
		}
		is_group_new = true;
	}
	//根が所属するグループに含まれる要素数を求める
	int getGroupNum(int ne) {
		ne_group_count();
		return ne_group_num[find(ne)];
	}
};