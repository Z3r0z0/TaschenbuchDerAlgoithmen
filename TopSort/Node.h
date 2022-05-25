#include<vector>
#include<string>

using namespace std;

#pragma once
class Node
{
public:
	Node(int id, string name, vector<Node> dependencies)
	{
		this->id = id;
		
		dependenNodes = dependencies;
		taskName = name;
	}

	int id;
	vector<Node> dependenNodes;
	string taskName;
};

