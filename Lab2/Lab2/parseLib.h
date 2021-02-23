#include <string>
#include <vector>

void parse(std::string name, std::vector<std::string>& country, std::vector<std::vector<int>>& voices);
void split(std::string s, std::vector<std::string>&country, std::vector<std::vector<int>>& voices);
void output(std::string name, std::vector<std::string>& country, std::vector<int>& points);