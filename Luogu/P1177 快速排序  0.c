int AdjustArray(int s[], int l, int r) //���ص������׼����λ��
{
	int i = l, j = r;
	int x = s[l]; //s[l]��s[i]���ǵ�һ����
	while (i < j)
	{
		// ����������С��x��������s[i]
		while(i < j && s[j] >= x) 
			j--;  
		if(i < j) 
		{
			s[i] = s[j]; //��s[j]�s[i]�У�s[j]���γ���һ���µĿ�
			i++;
		}
 
		// ���������Ҵ��ڻ����x��������s[j]
		while(i < j && s[i] < x)
			i++;  
		if(i < j) 
		{
			s[j] = s[i]; //��s[i]�s[j]�У�s[i]���γ���һ���µĿ�
			j--;
		}
	}
	//�˳�ʱ��i����j����x�������С�
	s[i] = x;
 
	return i;
}
void quick_sort1(int s[], int l, int r)
{
	if (l < r)
    {
		int i = AdjustArray(s, l, r);//�ȳ��ڿ�����������s[]
		quick_sort1(s, l, i - 1); // �ݹ���� 
		quick_sort1(s, i + 1, r);
	}
}

//��������
void quick_sort(int s[], int l, int r)
{
    if (l < r)
    {
		//Swap(s[l], s[(l + r) / 2]); //���м��������͵�һ��������
        int i = l, j = r, x = s[l];
        while (i < j)
        {
            while(i < j && s[j] >= x) // ���������ҵ�һ��С��x����
				j--;  
            if(i < j) 
				s[i++] = s[j];			
            while(i < j && s[i] < x) // ���������ҵ�һ�����ڵ���x����
				i++;  
            if(i < j) 
				s[j--] = s[i];
        }
        s[i] = x;
        quick_sort(s, l, i - 1); // �ݹ���� 
        quick_sort(s, i + 1, r);
    }
}
