#include <iostream>
#include <climits>
#include <vector>

using namespace std;

int main()
{
	int n = 0;
	int s = 0;

	cout << "How much vertices? " << endl;
	cin >> n;

	cout << "Enter start vertex" << endl;
	cin >> s;

	cout << "Enter graph's matrix" << endl;

	int v[n][n];
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> v[i][j];
		}
	}

	int dist[n];
	for (int i = 0; i < n; i++)
	{
		dist[i] = INT_MAX;
	}

	bool f[n];
	for (int i = 0; i < n; ++i)
	{
		f[i] = true;
	}

	dist[s] = 0;

	while (f[s]) // start. go to the neighbors
	{
		int shortest = INT_MAX;
		for (int i = 0; i < n; i++)
		{
			if (f[i] && dist[i] < shortest) // assigned to the neighbors their values (distance to them)
			{
				s = i;
				shortest = dist[i];
			}
		}

		for (int i = 0; i < n; ++i) // the shortest distance
		{
			if (v[s][i] > 0 && v[s][i] + dist[s] < dist[i])
				dist[i] = v[s][i] + dist[s];
		}

		f[s] = false; // the vertex is passed

		for (int i = 0; i < n; ++i)
		{
			if (v[s][i] > 0 && f[i])
			{
				s = i;
				break;
			}
		}
	}

	for (int i = 0; i < n; ++i)
	{
		cout << dist[i] << " ";
	}

	return 0;
}
