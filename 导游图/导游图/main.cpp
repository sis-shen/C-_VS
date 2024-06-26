#include "ParkMap.h"
using namespace std;




int main()
{
	vector<string> spots({ "����","����A","����B","����C","����D","����E" });
	vector<vector<int>> _Edges({ {0,1,2},{0,2,6},{0,3,9},{1,3,12},{2,4,1},{2,5,5},{3,4,10},{3,5,8},{4,5,3} });
	ParkMap<string> park_map(spots, spots.size(), _Edges);

	cout << "���о���: ";
	for (auto str : spots)
	{
		cout << str << " ";
	}
	cout << endl<<endl;
	park_map.BestPath();
	//park_map.short_path_v2v("����", "����E");
	string str1, str2;
	
	while (true)
	{
		cout << "���������ѯ���·������������" << endl;
		cin >> str1>> str2;
		park_map.short_path_v2v(str1, str2);
	}


	return 0;
}