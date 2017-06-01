#include <iostream>
#include <stack>
#include <vector>

using namespace std;

struct edge
{
	int end;
	bool need = false;
};

vector<vector<edge>> adj(100000);

int input();
void DFS(int, int, int, int&);

int main()
{
	cout << input();
	return 0;
}

int input()
{
	int n;
	int u, v;
	cin >> n;
	int k = n - 1;
	for (int i = 0; i < n - 1; i++)
	{
		cin >> u >> v;
		edge ue, ve;
		ue.end = v - 1;
		ve.end = u - 1;
		adj[u - 1].insert(adj[u - 1].end(), ue);
		adj[v - 1].insert(adj[v - 1].end(), ve);
	}
	int m;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> u >> v;
		DFS(u, v, n, k);
	}
	return k;
}

void DFS(int start, int end, int n, int &k)
{
	start--; end--;
	stack<int> DFSStack;
	int u, v;
	bool *visited = new bool[n];
	for (int i = 0; i < n; i++)
	{
		visited[i] = false;
	}
	DFSStack.push(start);
	visited[start] = true;
	while (!DFSStack.empty())
	{
		bool flag = false;
		for (int i = 0; i < adj[DFSStack.top()].size(); i++)
		{
			if (!visited[adj[DFSStack.top()][i].end])
			{
				visited[adj[DFSStack.top()][i].end] = true;
				DFSStack.push(adj[DFSStack.top()][i].end);
				flag = true;
				break;
			}
		}
		if (!flag)
		{
			DFSStack.pop();
		}
		if (DFSStack.top() == end)
		{
			while (!DFSStack.empty())
			{
				u = DFSStack.top();
				DFSStack.pop();
				if (DFSStack.empty()) break;
				v = DFSStack.top();
				bool twice = false;
				for (int i = 0; i < adj[u].size(); i++)
				{
					if (adj[u][i].end == v)
					{
						if (!adj[u][i].need)
						{
							k--;
							twice = true;
							adj[u][i].need = true;
						}
						break;
					}
				}
				if (twice)
					for (int i = 0; i < adj[v].size(); i++)
					{
						if (adj[v][i].end == u)
						{
							adj[v][i].need = true;
							break;
						}
					}
			}
			break;
		}
	}
	delete visited;
}