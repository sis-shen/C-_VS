#include "ParkMap.h"
using namespace std;





int main()
{
	vector<string> spots({ "����","����A","����B","����C","����D","����E" });
	vector<vector<int>> _Edges({ {0,1,2},{0,2,6},{0,3,9},{1,3,12},{2,4,1},{2,5,5},{3,4,10},{3,5,8},{4,5,3} });
	ParkMap<string> park_map(spots, spots.size(), _Edges);

	park_map.short_path_v2v("����", "����E");
	park_map.BestPath();
	return 0;
}