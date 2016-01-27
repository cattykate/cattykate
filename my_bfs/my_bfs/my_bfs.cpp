#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
	int n = 0;

	cout << "Enter the number of vertices " << std::endl;
	cin >> n;

	cout << "Enter graph's matrix" << std::endl;

	int v[n][n];
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			std::cin >> v[i][j];
		}
	}

	int s = 0;

	cout << "Enter the start vertex" << std::endl;
	cin >> s;

	int t = 0;

	cout << "Enter the needed vertex" << std::endl;
	cin >> t;

	bool f[n];
	for (int i = 0; i < n; ++i)
	{
		f[i] = true;
	}
	f[s] = false; // the start vertex is passed

	queue<int> q;
	q.push(s);


	vector<int> parent(n, -1); // parants of vertex

	while (!q.empty())
	{
		for (int i = 0; i < n; ++i)
		{
			if (v[q.front()][i] > 0 && f[i])
			{
				q.push(i);
				parent[i] = q.front(); // fill parents
				f[i] = false;
			}
		}
		q.pop();
	}

	if (parent[t] == -1)
	{
		cout << "Path does not exists";
		return 0;
	}


	vector<int> path;
	path.push_back(t); // add needed vertex to the path
	while (parent[t] != -1) // view his parents and write their to the path (while they are exist)
	{
		path.push_back(parent[t]);
		t = parent[t];// go back
	}

	cout << "\n";
	for (int i = 0; i < path.size(); i++)
	{
		cout << path[i] << " ";
	}

	return 0;
}