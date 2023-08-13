static int MAX_N=1<<17;

//Segment木を持つグローバル配列
int segmentn,dat[2*MAX_N-1];

//初期化
void init(int n_)
{
	//簡単のため要素数を2のべき乗に
	segmentn=1;
	while(segmentn<n_)segmentn*=2;
	
	//すべての値をINT_MAXに
	for (int i=0;i<2*segmentn-1;i++) dat[i]=INT_MAX;
}

//k番目の値(0-indexed)をaに変更
void update(int k,int a)
{
	//葉の節点
	k+=segmentn-1;
	dat[k]=a;
	//登りながら更新
	while (k>0)
	{
		k=(k-1)/2;
		dat[k]=min(dat[k*2+1],dat[k*2+2]);
	}
}

//[a,b)の最小値を求める
//後ろのほうの引数は、計算の簡単のための引数
//kは節点の番号、1、rはその接点が[1,r)に対応づいていることを表す。
//したがって、外からはquery(a,b,0,0,segmentn)として呼ぶ。
int query(int a,int b,int k,int l,int r)
{
	//[a,b)と[l,r)が交差しなければ、INT_MAX
	if (r<=a||b<=l) return INT_MAX;

	//[a,b)が[l,r)を完全に含んでいれば、この節点の値
	if (a<=r&&r<=b) rer\turn dat[k];
	else {
		//そうでなければ、2つの子の最小値
		int vl=query(a,b,k*2+1,l,(l+r)/2);
		int vr=query(a,b,k*2+2,(l+r)/2,r);
		return min(vl,vr);
	}
}
