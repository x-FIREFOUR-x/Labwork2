#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include "logic.h"

using namespace std;
int** counting_goals(vector <vector<int>> voices)
{
	int** list_voiñes = new int* [voices.size()];
	for (int i = 0; i < voices.size(); i++)
		list_voiñes[i] = new int[voices.size()];

	vector <int> country;
	for (int i = 0; i < voices.size(); i++)
	{
		country.push_back(i);
	}

	for (int column = 0; column < voices.size(); column++)
	{
		vector <int> column_goals;
		for (int i = 0; i < country.size(); i++)
		{
			column_goals[i] = voices[i][column];
		}
		scoring(list_voiñes, country, column, column_goals);
	}

	return list_voiñes;
}

void scoring (int** list_voiñes, vector <int> country, int column, vector <int> column_goals)
{
	for (int i = 0; i < country.size(); i++)
	{
		for (int j = i + 1; j < country.size(); j++)
		{
			if (column_goals[i] < column_goals[j])
			{
				int buf_column_goals = column_goals[i];
				column_goals[i] = column_goals[j];
				column_goals[j] = buf_column_goals;

				int buf_country = country[i];
				country[i] = country[j];
				country[j] = buf_country;

			}
		}
	}

	for (int i = 0; i < country.size(); i++)
	{
		if ( i ==  0) 
			list_voiñes[country[i]][column] = 12;
		else 
			if (i == 1)
				 list_voiñes[country[i]][column] = 10;
			else
				if (i > 1 && i < 10)
					list_voiñes[country[i]][column] = 10 - i;
				else
					list_voiñes[country[i]][column] = 0;
		
	}

}

/*vector<string> sort_country(vector<int>& list_voices, vector<string> country)
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
}*/
