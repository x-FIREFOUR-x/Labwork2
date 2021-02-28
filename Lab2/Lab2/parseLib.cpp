#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include<direct.h>
#include<io.h>
#include "parseLib.h"


using namespace std;

void parse(string name, vector<string>& country, vector<vector<int>>& voices)
{
	string s;
	int n;
	string nameCopy = name + "\\*.csv";
	const char* path = (nameCopy).c_str();
	_finddata_t data;
	intptr_t handle = _findfirst(path, &data);
	do
	{
		string dateName = data.name;
		if (dateName != "result.csv")
		{
			ifstream fin(name + "\\" + data.name);
			getline(fin, s);
			n = stoi(s);
			for (int i = 0; i < n; i++)
			{
				getline(fin, s);
				split(s, country, voices);
			}
			fin.close();
		}
	} while (_findnext(handle, &data) == 0);
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

void output(string name, vector<string>& country, vector<int>& points)
{
	name = name + "\\result.csv";
	ofstream fout(name);
	for (int i = 0; i < 10; i++)
	{
		fout << country[i] << ";" << points[i] << "\n";
	}
	fout.close();
}
