#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
	int start = -3;
	int end = -11;
	int len;
	int *mas;
	int j;
	if (start < 0 && end < 0)
		len =  (-end) - (-start);
	else if (start > end)
		len = start - end;
	else
		len = end - start;
	mas = (int*)malloc(sizeof(int)*(len + 1));
	j = 0;
	if (start <= end)
	{
		while(end >= start)
		{
			mas[j] = start;
			start++;
			j++;
		}
	}
	else if (end <= start)
	{
		while(end <= start)
		{
			mas[j] = start;
	 		start--;
			j++;
		}
	}
	while(j > 0)
	{
		printf("%d\n", mas[j -1]);
		j--;
	}
}
		
