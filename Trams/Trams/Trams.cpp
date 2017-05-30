#include <iostream>
#include <stack>

using namespace std;

int adj[100][100] = { 0 };

void input();						//input and build adjacency matrix
void DFS(int, int, int, int&);

int main()
{
	input();
	return 0;
}

void input()
{
	int n;							//count of vertices
	int u, v;						//start and end vertices for each edge
	int k = n - 1;
	cin >> n;
	for (int i = 0; i < n - 1; i++)
	{
		cin >> u >> v;
		adj[u - 1][v - 1] = 1;
		adj[v - 1][u - 1] = 1;
	}
	int m;							//count of transport lines
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> u >> v;				//start and end for transport line
		DFS(u, v, n, k);			//function to count need edges
	}
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
		for (int i = 0; i < n; i++)
		{
			if (adj[DFSStack.top()][i] && !visited[i])
			{
				DFSStack.push(i);
				visited[i] = true;
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
				if (adj[u][v] == 1)
				{
					adj[u][v] = 2;
					adj[v][u] = 2;
					k--;
				}

			}
			break;
		}
	}
	delete visited;
}