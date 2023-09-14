#include <bits/stdc++.h>
using namespace std;

int node[40][40]; //representasi graf
int visited[40][40];
int n; //luas matriks nxn
int flag;
int move_x[4] = {0, 0, 1, -1};
int move_y[4] = {1, -1, 0, 0};

void dfs(int x, int y)
{
	visited[x][y] = 1;
//	printf("node: %d %d - node:%d\n ", x, y, node[x][y]);
	// jika node ini adalah kotak tujuan
	if(node[x][y] == 3)
	{
		flag = 1;
		return;
	}
	
	for (int i=0; i<4; i++)
	{
//		i = 0 -> x, y+1
//		i = 1 -> x, y-1
//		i = 2 -> x+1, y
//		i = 3 -> x-1, y
		int next_x = x + move_x[i];
		int next_y = y + move_y[i];
		
		if(!visited[next_x][next_y] && node[next_x][next_y] != 1
			&& next_x <= n && next_y <= n && next_x > 0 && next_y > 0)
		{
			dfs(next_x, next_y);
		}
	}
	
	
}
int main()
{
	int start_i, start_j;
	
	scanf("%d", &n);
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=n; j++)
		{
			scanf("%d", &node[i][j]);
			
			// jika node ini merupakan kotak start
			if(node[i][j] == 2)
			{
				start_i = i;
				start_j = j;
			}
		}
	}
	
	flag = 0;
	dfs(start_i, start_j);
	
	if(flag == 1)
	{
		printf("yey");
	}
	else
	{
		printf("yah");
	}
}
