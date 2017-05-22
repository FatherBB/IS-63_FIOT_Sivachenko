#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <fstream>
#include <iostream>

using namespace std;

const int inf = 1E9;
int n, m, t[1000], i, j, v;
struct { int from, to, l; } edges[10000];

int main()
{
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	fin >> n >> m;
	for (i = 0; i < m; ++i)
	{
		fin >> edges[i].from >> edges[i].to >> edges[i].l;
		--edges[i].from; --edges[i].to;
	}

	v = 0;

	for (i = 0; i<n; ++i) 
		t[i] = inf;

	t[v] = 0;

	for (i = 1; i <= n; ++i)
	for (j = 0; j < m; ++j)
	if (t[edges[j].from]<inf && t[edges[j].from] + edges[j].l<t[edges[j].to])
	if (i == n) 
	{ 
		printf("INCORRECT INPUT"); 
		return 0; 
	}
	else
		t[edges[j].to] = t[edges[j].from] + edges[j].l;
	
	fout << t[n-1];
	fin.close();
	fout.close();
}