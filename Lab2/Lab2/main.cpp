#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>
#include "parseLib.h"
#include "logic.h"

using namespace std;

int main()
{
	vector<string> country;
	vector<vector<int>> voices;
	vector<int> points;
	string name;
	int n;
	cin >> n;
	readWinnerPoints(n, points);
	cout << "Input path: ";
	cin >> name;
	parse(name, country, voices);
	int** balls = counting_goals(voices, points);
	vector<int> list_balls = sum_balls(balls, voices.size());
	vector<string> top_country;
	top_country = sort_country(list_balls, country);
	output(name, top_country, list_balls);

	return 0;
}