#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include "logic.h"

using namespace std;
vector<int> counting_goals(vector <vector<int>> voices)
{
	vector<int> list_voiñes;

	for (int i = 0; i < voices.size(); i++)
	{
		int sum_voices = 0;
		for (int j = 0; j < voices.size(); j++)
		{
			sum_voices += voices[i][j];
		}

		list_voiñes.push_back(sum_voices);
	}

	return list_voiñes;
}
