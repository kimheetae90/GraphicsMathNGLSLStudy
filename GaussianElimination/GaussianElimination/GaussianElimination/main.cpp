#include <iostream>

using namespace std;

float* matrix;

int rowCount;
int colCount;

void Set(int inrow, int incol, float val)
{
	matrix[inrow * colCount + incol] = val;
}

float Get(int inrow, int incol)
{
	return matrix[inrow * colCount + incol];
}

void Input()
{
	cin >> rowCount;
	cin >> colCount;

	matrix = new float[rowCount * colCount];

	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < colCount; j++)
		{
			float temp;
			cin >> temp;
			Set(i, j, temp);
		}
	}
}

void Print()
{
	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < colCount; j++)
		{
			cout << Get(i, j) << ",";
		}
		cout << endl;
	}
}

int main()
{
	Input();
	Print();

	for (int col = 0; col < colCount - 1; col++)
	{
		float root = Get(col, col);

		for (int fixCol = col; fixCol < colCount; fixCol++)
		{
			Set(col, fixCol, Get(col, fixCol) / root);
		}

		for (int row = 0; row < rowCount; row++)
		{
			if (col == row)
				continue;

			float multiplier = -1 * Get(row, col);
			for (int adjustCol = col; adjustCol < colCount; adjustCol++)
			{
				float finalValue = Get(row, adjustCol) + multiplier * Get(col, adjustCol);
				Set(row, adjustCol, finalValue);
			}
		}
	}

	Print();

	delete matrix;

	return 0;
}