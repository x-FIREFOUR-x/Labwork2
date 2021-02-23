#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "parseLib.h"

using namespace std;

void parse(string name, vector<string>& country, vector<vector<int>>& voices)
{
	string s;
	int n;
	ifstream fin(name);
	getline(fin, s);
	n = stoi(s);
	for (int i = 0; i < n; i++)
	{
		getline(fin, s);
		split(s, country, voices);
	}
	fin.close();
}

void split(string s, vector<string>& country, vector<vector<int>>& voices)
{
	int next, pos, i;
	pos = 0;
	next = 0;
	next = s.find(',', pos);
	country.push_back(s.substr(pos, next - pos));
	pos = next + 1;
	voices.push_back(vector<int>());
	while (next != s.npos)
	{
		next = s.find(',', pos);
		voices[voices.size() - 1].push_back(stoi(s.substr(pos, next - pos)));
		pos = next + 1;
	}
}
