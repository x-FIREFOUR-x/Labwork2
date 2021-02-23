#include <iostream>
#include <string>
#include <cstdlib>
#include "logic.h"

using namespace std;
string** counting_goals(string* name_countries, int** voices, int number_countries)
{
	string** list_countries_voises = new string* [number_countries];
	for (int i = 0; i < number_countries; i++)
	{
		list_countries_voises[i] = new string[number_countries];
	}

	for (int i = 0; i < number_countries; i++)
	{
		int sum_voices = 0;
		for (int j = 0; j < number_countries; j++)
		{
			sum_voices += voices[i][j];
		}

		list_countries_voises[i][0] = name_countries[i];
		list_countries_voises[i][1] = to_string(sum_voices);
	}

	return list_countries_voises;
}
