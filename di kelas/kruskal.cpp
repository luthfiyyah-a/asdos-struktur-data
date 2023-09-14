#include <bits/stdc++.h>
using namespace std;

struct t {
	int src;
	int dst;
	int w;
};

int par[4] = {-1};

int find(int x) 
{
    if(par[x] != x) {
        return par[x] = find(par[x]);
    }
	return x;
}    


void Kruskal() {
	
	struct t edge[14];
	
	edge[0].src = 0; 
	edge[0].dst = 1;
	edge[0].w = 1;
	
	edge[1].src = 1;
	edge[1].dst = 2;
	edge[1].w = 2;
	
	edge[2].src = 2;
	edge[2].dst = 3;
	edge[2].w = 2;

	edge[3].src = 3;
	edge[3].dst = 4;
	edge[3].w = 5;
	
	edge[4].src = 4;
	edge[4].dst = 0;
	edge[4].w = 4;
	
	edge[5].src = 0;
	edge[5].dst = 2;
	edge[5].w = 3;
	
    int res = 0;
    for(int i = 0; i < edge.size(); i++) {
        int src = edge[i].src;
        int dst = edge[i].dst;
        int w = edge[i].w;
        int parSrc = find(src);
        int parDst = find(dst);

        // Disjoint Set
        if(parSrc != parDst) {
            res += w;
            par[parSrc] = par[parDst];
        }
    }
    cout << res << endl;
    return;
}
