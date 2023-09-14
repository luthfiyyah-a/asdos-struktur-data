#include <bits/stdc++.h>

int matriks[50][50];
void traversal(int k, int n)
{
	int flag = 0;
	int j = n-1;
	while(j >= 0)
	{
		if(matriks[j][k] == 'o')
		{
			flag = 0;
		}
		else if(matriks[j][k] == '.' && flag==0)
		{
			flag = j;
		}
		else if(matriks[j][k] == '*')
		{
			if(flag)
			{
				matriks[j][k] = '.';
				matriks[flag][k] = '*';
				flag--;
				while(j <= flag)
				{
					if(matriks[flag][k] != '.')
					{
						flag--;
					}
					else
					{
						break;
					}
				}
			}
		}
		j--;
	}
}

int main()
{
	int t;
	scanf("%d", &t);
	
	int n, m;
	char temp;
	for(int i=0; i<t; i++)
	{
		scanf("%d %d", &n, &m);
		getchar();
		for(int j=0; j<n; j++)
		{
			for(int k=0; k<m; k++)
			{
				scanf("%c", &matriks[j][k]);
			}
			getchar();
		}
		
		for(int k=0; k<m; k++)
		{
			traversal(k, n);
		}
		
		for(int j=0; j<n; j++)
		{
			for(int k=0; k<m; k++)
			{
				printf("%c", matriks[j][k]);
			}
			printf("\n");
		}
	}
}
