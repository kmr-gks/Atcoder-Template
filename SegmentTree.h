static int MAX_N=1<<17;

//Segment�؂����O���[�o���z��
int segmentn,dat[2*MAX_N-1];

//������
void init(int n_)
{
	//�ȒP�̂��ߗv�f����2�ׂ̂����
	segmentn=1;
	while(segmentn<n_)segmentn*=2;
	
	//���ׂĂ̒l��INT_MAX��
	for (int i=0;i<2*segmentn-1;i++) dat[i]=INT_MAX;
}

//k�Ԗڂ̒l(0-indexed)��a�ɕύX
void update(int k,int a)
{
	//�t�̐ߓ_
	k+=segmentn-1;
	dat[k]=a;
	//�o��Ȃ���X�V
	while (k>0)
	{
		k=(k-1)/2;
		dat[k]=min(dat[k*2+1],dat[k*2+2]);
	}
}

//[a,b)�̍ŏ��l�����߂�
//���̂ق��̈����́A�v�Z�̊ȒP�̂��߂̈���
//k�͐ߓ_�̔ԍ��A1�Ar�͂��̐ړ_��[1,r)�ɑΉ��Â��Ă��邱�Ƃ�\���B
//���������āA�O�����query(a,b,0,0,segmentn)�Ƃ��ČĂԁB
int query(int a,int b,int k,int l,int r)
{
	//[a,b)��[l,r)���������Ȃ���΁AINT_MAX
	if (r<=a||b<=l) return INT_MAX;

	//[a,b)��[l,r)�����S�Ɋ܂�ł���΁A���̐ߓ_�̒l
	if (a<=r&&r<=b) rer\turn dat[k];
	else {
		//�����łȂ���΁A2�̎q�̍ŏ��l
		int vl=query(a,b,k*2+1,l,(l+r)/2);
		int vr=query(a,b,k*2+2,(l+r)/2,r);
		return min(vl,vr);
	}
}
