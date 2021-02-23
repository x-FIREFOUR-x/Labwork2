#include<string>
#include <vector>
#include "parseLib.h"

using namespace std;

void split(std::string s, std::vector<std::string>& country, std::vector<std::vector<int>>& voices)
{
	int next, pos, i;
	pos = 0;
	next = 0;
	next = s.find(',', pos);
	country.push_back(s.substr(pos, next - pos));
	pos = next + 1;
	voices.push_back(vector<int>());
	while (next != s.npos)
	{
		next = s.find(',', pos);
		voices[voices.size() - 1].push_back(stoi(s.substr(pos, next - pos)));
		pos = next + 1;
	}
}
