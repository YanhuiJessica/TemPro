// k表示从i开始和从j开始相同字符串的长度, n为字符串总长度 
int getmin()
{
	int i = 0, j = 1, k = 0, t;
	while (i < n && j < n && k < n)
	{
		t = s[(i + k) % n] - s[(j + k) % n];
		if (!t) k++; //equal 
		else
		{
			if (t > 0) i += k + 1; // s[i] > s[j], 最大表示法直接交换 i,j 
			else j += k + 1;
			if (i == j) j++;
			k = 0;
		}
	}
	return min(i, j); //返回起始下标 
}