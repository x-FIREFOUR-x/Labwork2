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
	vector<int> list_voices = counting_goals(voices);
	output("output.txt", country, list_voices);

	return 0;
}