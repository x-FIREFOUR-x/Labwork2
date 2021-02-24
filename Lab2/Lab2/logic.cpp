#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <iomanip>
#include "logic.h"

using namespace std;
int** counting_goals(vector <vector<int>> voices)
{
	int size = voices.size();
	
	int** balls = new int* [size];
	for (int i = 0; i < size; i++)
		balls[i] = new int [size];

	vector <int> country;
	for (int i = 0; i < size; i++)
	{
		country.push_back(i);
	}
	
	for (int column = 0; column < size; column++)
	{
		vector <int> column_goals;
		for (int i = 0; i < size; i++)
		{
			column_goals.push_back(voices[i][column]);
		}
		scoring(balls, country, column, column_goals);
	}

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cout << setw(2) << balls[i][j] << " ";
		}
		cout << endl;
	}
	return balls;
}

void scoring (int** balls, vector <int> country, int column, vector <int> column_goals)
{
	int size = column_goals.size();
	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size; j++)
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

	for (int i = 0; i < size; i++)
	{
		if ( i ==  0) 
			balls[country[i]][column] = 12;
		else 
			if (i == 1)
				balls[country[i]][column] = 10;
			else
				if (i > 1 && i < 10)
					balls[country[i]][column] = 10 - i;
				else
					balls[country[i]][column] = 0;
		
	}

}

vector<int> sum_balls(int** balls, int amont_country)
{
	vector <int> list_balls;
	for (int i = 0; i < amont_country; i++)
	{
		int sum = 0;
		for (int j = 0; j < amont_country; j++)
		{
			sum += balls[i][j];
		}
		list_balls.push_back(sum);
	}

	cout << endl;
	for (int i = 0; i < amont_country; i++)
	{
		cout << list_balls[i] << endl;
	}
	return list_balls;
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
