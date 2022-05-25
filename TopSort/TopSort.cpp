#include <iostream>
#include<vector>
#include <stack>
#include "Node.h"

void topsort(vector<Node> tasks);
void removeNodeDependency(vector<Node>& tasks, int removeNodeId);

using namespace std;

int main()
{
	Node node1(1, "Printing task sheet", vector<Node>());
	Node node2(2, "Math", vector<Node> { node1 });
	Node node3(3, "Go to city", vector<Node>());
	Node node4(4, "Buy detergent", vector<Node> { node3 });
	Node node5(5, "Doing the dishes", vector<Node> { node4 });
	Node node6(6, "Buying Cola", vector<Node> { node3 });
	Node node7(7, "Rent a book from the library", vector<Node> { node3 });
	Node node8(8, "Buying song", vector<Node>());
	Node node9(9, "Creating musik disc", vector<Node> { node8 });
	Node node10(10, "Searching the internet", vector<Node>());
	Node node11(11, "Writing Text", vector<Node> { node10 });

	topsort(vector<Node>
	{
		node11,
		node10,
		node9,
		node8,
		node7,
		node6,
		node5,
		node4,
		node3,
		node2,
		node1,
	});
}

void topsort(vector<Node> tasks) 
{
	while (tasks.size() > 0)
	{
		bool circle = true;

		for(int i = 0; i < tasks.size(); i++)
		{
			if (!tasks[i].dependenNodes.size() > 0) 
			{
				cout << "Task: " + tasks[i].taskName << endl;

				removeNodeDependency(tasks, tasks[i].id);
				tasks.erase(tasks.begin() + i);

				circle = false;
			}
		}

		if(circle)
		{
			cout << "Cyclic dependency can not be resolved!!!" << endl;
			break;
		}
	}
}

void removeNodeDependency(vector<Node>& tasks, int removeNodeId) 
{
	for (int i = 0; i < tasks.size(); i++)
	{
		for (int j = 0; j < tasks[i].dependenNodes.size(); j++)
		{
			if (tasks[i].dependenNodes[j].id == removeNodeId)
			{
				tasks[i].dependenNodes.erase(tasks[i].dependenNodes.begin() + j);
			}
		}
	}
}

