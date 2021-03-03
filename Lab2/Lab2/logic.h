#include <vector>
#include <string>
using namespace std;
int** counting_goals(vector <vector<int>> voices, vector<int> points);
void scoring(int** list_voiñes, vector <int> country, int column, vector <int> column_goals, vector<int> points);
vector<int> sum_balls(int** balls, int amont_country);
vector<string> sort_country(vector<int>& list_balls, vector<string> country);
void readWinnerPoints(int n, vector<int>&);