#include <iostream>
#include <vector>
using namespace std;

const int N = 6;
int graph[N][N] = {
  { 0, 1, 0, 0, 0, 0 }, 
  { 1, 0, 1, 1, 1, 0 },
  { 0, 1, 0, 0, 0, 0 },
  { 0, 1, 0, 0, 1, 0 },
  { 0, 1, 0, 1, 0, 1 },
  { 0, 0, 0, 0, 1, 0 } };

int nodes[N], dfs_timer = 0;
bool checked[N];
int tin[N], fup[N];
vector<int> time_in, time_out;

void dfs(int n)
{
	time_in[n] = dfs_timer++;
	nodes[n] = 1;
	for (int i = 0; i < N; i++)
	{
		if (graph[n][i] == 1 && nodes[i] == 0)
		{
			dfs(i);
		}
	}
	nodes[n] = 2;
	time_out[n] = dfs_timer++;
}

void findCutVertex(int n, int p = -1)
{
	checked[n] = true;
	tin[n] = fup[n] = time_in[n];
	int children = 0;
	for (int i = 0; i < N; i++)
	{
		if (graph[n][i] == 1) {
			int to = i;
			if (to == p) continue;
			if (checked[to]) {
				fup[n] = min(tin[to], fup[n]);
			}
			else {
				findCutVertex(to, n);
				fup[n] = min(fup[n], fup[to]);
				if (tin[n] <= fup[to] && p != -1) {
					cout << n + 1 << endl;
				}
				++children;
			}
		}
	}
	if (p == -1 && children > 1)
	{
		cout << n + 1 << endl;
	}
}


int main()
{
	for (int i = 0; i < N; i++) {
		nodes[i] = 0;
		time_in.push_back(0);
		time_out.push_back(0);
	}

	dfs(0);

	for (int i = 0; i < N; ++i)
		checked[i] = false;

	findCutVertex(0);
}

