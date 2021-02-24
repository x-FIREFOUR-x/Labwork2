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

vector<string> sort_country(vector<int>& list_voices, vector<string> country)
{
	for (int i = 0; i < list_voices.size(); i++)
	{
		for (int j = i + 1; j < list_voices.size(); j++)
		{
			if (list_voices[i] < list_voices[j])
			{
				int buf_voices = list_voices[i];
				list_voices[i] = list_voices[j];
				list_voices[j] = buf_voices;

				string buf_country = country[i];
				country[i] = country[j];
				country[j] = buf_country;

			}
		}
	}

	return country;
}
