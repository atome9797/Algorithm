#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	set<int> set1;
	unordered_map < int, int > map;
	vector <int> vec;

	int N = 0;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int num = 0;
		cin >> num;

		set1.insert(num);
		vec.push_back(num);
	}

	int count = 0;
	for (set<int>::iterator iter =  set1.begin(); iter != set1.end(); iter++)
	{
		map.insert({ *iter , count });
		count++;
	}
	

	for (int element : vec)
	{
		cout << map[element] << " ";
	}
	

	


	return 0;
}