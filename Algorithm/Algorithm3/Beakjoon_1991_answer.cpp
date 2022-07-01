#include <iostream>
#include <vector>

using namespace std;

vector<pair<char , pair<char, char>>> graph;

char alpha[26] = { 0 };


void preCicle(char root)
{
	if (root == '.')
	{
		return;
	}
	else
	{
		cout << root;
		
		int index = 0;
		for (int i = 0; i < 26; i++)
		{
			if (alpha[i] == root)
			{
				index = i;
				break;
			}
		}

		preCicle(graph[index].second.first);
		preCicle(graph[index].second.second);
	}
}

void middleCicle(char root)
{
	if (root == '.')
	{
		return;
	}
	else
	{
		
		int index = 0;
		for (int i = 0; i < 26; i++)
		{
			if (alpha[i] == root)
			{
				index = i;
				break;
			}
		}

		middleCicle(graph[index].second.first);
		cout << root;
		middleCicle(graph[index].second.second);
	}
}

void endCicle(char root)
{
	if (root == '.')
	{
		return;
	}
	else
	{
		
		int index = 0;
		for (int i = 0; i < 26; i++)
		{
			if (alpha[i] == root)
			{
				index = i;
				break;
			}
		}

		endCicle(graph[index].second.first);
		endCicle(graph[index].second.second);
		cout << root;
	}
}

int main()
{

	int num = 0;
	cin >> num;

	for (int i = 0; i < num; i++)
	{
		char parent;
		char left;
		char right;
		cin >> parent >> left >> right;

		pair<char, char> pair1 = { left , right };
		alpha[i] = parent;

		graph.push_back({ parent, pair1 });
	}

	preCicle('A');
	cout << "\n";
	middleCicle('A');
	cout << "\n";
	endCicle('A');
	cout << "\n";

	return 0;
}