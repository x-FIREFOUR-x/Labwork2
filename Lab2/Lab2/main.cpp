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
	parse("input.txt", country, voices);
	int** balls = counting_goals(voices);
	//vector<int> list_balls = sum_balls(balls, voices.size());
	/*country = sort_country(list_voices, country);
	output("output.txt", country, list_voices);*/

	return 0;
}