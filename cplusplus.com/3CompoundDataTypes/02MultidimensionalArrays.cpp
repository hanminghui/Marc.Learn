// Multidimensional arrays
// --------------------------------------------------------------------------------
// Multidimensional arrays can be described as "arrays of arrays".
// Multidimensional arrays are not limited to two indices, i.e., two dimensions.

#include <iostream>
using namespace std;

// defined constants instead of using directly their numerical values
// this gives the code a better readability,
// and allows changes in the code to be made easily in one place
#define WIDTH 9
#define HEIGHT 9

int jimmy [HEIGHT][WIDTH];
int i, j;

int main ()
{
	for (i = 0; i < HEIGHT; i++)
	{
		for (j = 0; j < WIDTH; j++)
		{
			jimmy [i][j] = (i + 1) * (j + 1);
		}
	}
	for (i = 0; i < HEIGHT; i++)
	{
		for (j = 0; j < WIDTH; j++)
		{
			cout << jimmy [i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
