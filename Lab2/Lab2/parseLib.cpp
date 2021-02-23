#include<string>
#include "parseLib.h"

using namespace std;

void split(string s, string* country, int** voices, int ind)
{
	int next, pos, i;
	pos = 0;
	next = 0;
	next = s.find(',', pos);
	country[ind] = s.substr(pos, next - pos);
	pos = next + 1;
	i = 0;
	while (next != s.npos)
	{
		next = s.find(',', pos);
		voices[ind][i] = stoi(s.substr(pos, next - pos));
		pos = next + 1;
		i++;
	}
}