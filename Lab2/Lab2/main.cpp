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
	string name;
	cin >> name;
	parse(name, country, voices);
	int** balls = counting_goals(voices);
	vector<int> list_balls = sum_balls(balls, voices.size());
	country = sort_country(list_balls, country);
	output(name, country, list_balls);

	return 0;
}