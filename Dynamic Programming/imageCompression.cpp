//求对应灰度值所需要的位数长度
int length(int n) {
	int bit = 0;
	while (n) {
		n = n >> 1;
		bit++;
	} 
	return bit;
}
//l[i]:最优分段最后一段的段长
//b[i]:最优分段最后一段的像素位数
void Compress(int n,int p[],int s[],int l[],int b[])
{
	int Lmax = 256, header = 11;
	s[0] = 0;
	for (int i = 1; i <= n; i++) {
		b[i] = length(p[i]);
		int bmax = b[i];
		s[i] = s[i - 1] + b[i];
		l[i] = 1;
		for (int j = 2; j <= i && j <= Lmax; j++) {
			if (bmax < b[i - j + 1])
				bmax = b[i - j + 1];
			if (s[i] > s[i - j] + j * bmax) {
				s[i] = s[i - j] + j * bmax;
				l[i] = j;
			}
		}
		s[i] += header;
	}

}
void Traceback(int n, int& i, int s[], int l[]) 
{
	if (!n)
		return;
	Traceback(n - l[n], i, s, l);
	s[i++] = n - l[n];
}
void output(int s[], int l[], int b[], int n)
{
	cout << "The optimal value is" << s[n] << endl;
	int m = 0;
	Traceback(n, m, s, l);
	s[m] = n;
	cout << "Decompose into" << m << "segments" << endl;
	for (int j = 1; j <= m; j++) {
		l[j] = l[s[j]];
		b[j] = b[s[j]];
	}
	for (int j = 1; j <= m; j++) {
		cout << l[j] << ' ' << b[j] << endl;
	}
}
