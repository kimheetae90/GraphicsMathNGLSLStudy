#include <iostream>
#include <vector>

using namespace std;

float Det(vector<vector<float>>& inMatrix, int line)
{
	if (line == 2)
	{
		return inMatrix[0][0] * inMatrix[1][1] - inMatrix[0][1] * inMatrix[1][0];
	}

	float result = 0.0f;
	for (int i = 0; i < line; i++)
	{
		vector<vector<float>> smallMatrix;
		for (int row = 1; row < line ; row++)
		{
			vector<float> column;
			for (int col = 0; col < line; col++)
			{
				if (col == i)
					continue;

				column.push_back(inMatrix[row][col]);
			}
			smallMatrix.push_back(column);
		}

		result += (i % 2 == 0 ? 1.0f : -1.0f) * inMatrix[0][i] * Det(smallMatrix, line - 1);
	}

	return result;
}

int main()
{
	vector<vector<float>> matrix;

	vector<float> row1;
	row1.push_back(2); row1.push_back(-2); row1.push_back(0);
	matrix.push_back(row1);
	vector<float> row2;
	row2.push_back(-3); row2.push_back(1); row2.push_back(2);
	matrix.push_back(row2);
	vector<float> row3;
	row3.push_back(1); row3.push_back(-3); row3.push_back(-1);
	matrix.push_back(row3);

	cout << Det(matrix, 3) << endl;

	return 0;
}