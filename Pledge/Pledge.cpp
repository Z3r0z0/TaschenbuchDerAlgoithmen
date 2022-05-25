#include <iostream>

const int mazeHeight = 9;
const int mazeWidth = 9;

char maze[mazeHeight][mazeWidth + 1] 
{
    "# #######",
    "#   #   #",
    "# ### # #",
    "# #   # #",
    "# # # ###",
    "#   # # #",
    "# ### # #",
    "#   #   #",
    "####### #",
};

const char Wall = '#';
const char Free = ' ';
const char SomeDude = '*';

int main()
{
    std::cout << "Hello World!\n";
}

bool solve(int x, int y)
{

}
