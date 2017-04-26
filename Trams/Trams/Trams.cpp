#include <iostream>

using namespace std;

int adj[100][100] = { 0 };

void input();						//input and build adjacency matrix

int main()
{
	input();
	return 0;
}

void input()
{
	int n;							//count of vertices
	int u, v;						//start and end vertices for each edge
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
		//function to count need edges
	}
}