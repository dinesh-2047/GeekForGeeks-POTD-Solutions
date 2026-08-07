// Min Edge Movements to Connect a Graph


class Solution {
	public:
	vector<int > parent, rank ;
	int find(int x) {
		if (parent[x] == x)
			return x;
		return parent[x] = find(parent[x]);
	}
	void Union(int x, int y) {
		int px = find(x);
		int py = find(y);
		
		if (px == py)
			return;
		
		if (rank[px] < rank[py])
			parent[px] = py;
		else if (rank[px] > rank[py])
			parent[py] = px;
		else {
			parent[py] = px;
			rank[px]++;
		}
		
	}
	int minEdgesReq(int n, vector<vector<int>> & edges) {
		int m = edges.size();
		
		if (m < n - 1)
			return -1 ;
		parent.resize(n);
		rank.resize(n, 0);
		
		for (int i = 0 ; i < n; i++) {
			parent[i] = i ;
		}
		
		int comp = 0 ;
		for (auto &edge : edges) {
			int u = edge[0];
			int v = edge[1];
			
			Union(u, v);
		}
		
		for (int i = 0 ; i < n; i++) {
			if (find(i) == i) {
				comp++;
			}
		}
		return comp - 1 ;
	}
};
