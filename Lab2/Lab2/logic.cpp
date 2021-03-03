#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <iomanip>
#include "logic.h"

using namespace std;
int** counting_goals(vector <vector<int>> voices, vector<int> points)
{
	//int size = voices.size();
	
	int** balls = new int* [voices.size()];
	for (int i = 0; i < voices.size(); i++)
		balls[i] = new int [voices.size()];

	vector <int> country;
	for (int i = 0; i < voices.size(); i++)
	{
		country.push_back(i);
	}
	
	for (int column = 0; column < voices.size(); column++)
	{
		vector <int> column_goals;
		for (int i = 0; i < voices.size(); i++)
		{
			column_goals.push_back(voices[i][column]);
		}
		scoring(balls, country, column, column_goals, points);
	}

	return balls;
}

void scoring (int** balls, vector <int> country, int column, vector <int> column_goals, vector<int> points)
{
	//int size = column_goals.size();
	for (int i = 0; i < column_goals.size(); i++)
	{
		for (int j = i + 1; j < column_goals.size(); j++)
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

	for (int i = 0; i < column_goals.size(); i++)
	{
		if (i < points.size())
			balls[country[i]][column] = points[i];
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

	return list_balls;
}

vector<string> sort_country(vector<int>& list_balls, vector<string> country)
{
	for (int i = 0; i < list_balls.size(); i++)
	{
		for (int j = i + 1; j < list_balls.size(); j++)
		{
			if (list_balls[i] < list_balls[j])
			{
				int buf_voices = list_balls[i];
				list_balls[i] = list_balls[j];
				list_balls[j] = buf_voices;

				string buf_country = country[i];
				country[i] = country[j];
				country[j] = buf_country;

			}
		}
	}

	return country;
}

void readWinnerPoints(int n, vector<int>&points)
{
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		points.push_back(num);
	}
}