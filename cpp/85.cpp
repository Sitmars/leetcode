/*
85. Maximal Rectangle

Given a 2D binary matrix filled with 0's and 1's,
find the largest rectangle containing only 1's and return its area.

For example, given the following matrix:

	1 0 1 0 0
	1 0 1 1 1
	1 1 1 1 1
	1 0 0 1 0

Return 6.
*/


#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int maximalRectangle(vector<vector<char>>&);

struct rect {
	int row;
	int col;
};

int main()
{
	vector<vector<char>> matrix = {
		{ '1','1' },
		{ '1','1'}
	};
	int result = maximalRectangle(matrix);
	cout << result << endl;

	system("pause");
	return 0;
}

int maximalRectangle(vector<vector<char>>& matrix)
{
	if (matrix.size() == 0)
	{
		return 0;
	}
	vector<int> left(matrix[0].size(), 0);
	vector<int> right(matrix[0].size(), matrix[0].size());
	vector<int> height(matrix[0].size(), 0);
	int area = 0;
	for (int i = 0; i < matrix.size(); ++i)
	{
		int cleft = 0;
		int cright = matrix[0].size();
		for (int j = 0; j < matrix[0].size(); ++j)
		{
			if (matrix[i][j] == '1')
			{
				++height[j];
			}
			else
			{
				height[j] = 0;
			}
		}
		for (int j = 0; j < matrix[0].size(); ++j)
		{
			if (matrix[i][j] == '1')
			{
				left[j] = max(left[j], cleft);
			}
			else
			{
				left[j] = 0;
				cleft = j + 1;
			}
		}
		for (int j = matrix[0].size() - 1; j >= 0; --j)
		{
			if (matrix[i][j] == '1')
			{
				right[j] = min(right[j], cright);
			}
			else
			{
				right[j] = matrix[0].size();
				cright = j;
			}
		}
		for (int j = 0; j < matrix[0].size(); ++j)
		{
			area = max(area, (right[j] - left[j])*height[j]);
		}
	}
	return area;
}

int maximalRectangle2(vector<vector<char>>& matrix)
{
	if (matrix.size() == 0 || matrix[0].size() == 0)
	{
		return 0;
	}
	int num = 0;
	vector<vector<rect>> hor(matrix.size(), vector<rect>(matrix[0].size()));  //从左边拓展
	vector<vector<rect>> ver(matrix.size(), vector<rect>(matrix[0].size()));  //从上边拓展
	vector<vector<rect>> diag(matrix.size(), vector<rect>(matrix[0].size())); //从对角拓展
	if (matrix[0][0] == '1')
	{
		hor[0][0].row = 1;
		hor[0][0].col = 1;
		ver[0][0].row = 1;
		ver[0][0].col = 1;
		diag[0][0].row = 1;
		diag[0][0].col = 1;
		num = 1;
	}
	for (int i = 1; i < matrix[0].size(); ++i)
	{
		if (matrix[0][i] == '1')
		{
			hor[0][i].row = 1;
			hor[0][i].col = hor[0][i - 1].col + 1;
			ver[0][i].row = 1;
			ver[0][i].col = 1;
			diag[0][i].row = 1;
			diag[0][i].col = 1;
			num = max(num, hor[0][i].col);
		}
	}
	for (int i = 1; i < matrix.size(); ++i)
	{
		if (matrix[i][0] == '1')
		{
			ver[i][0].col = 1;
			ver[i][0].row = ver[i - 1][0].row + 1;
			hor[i][0].row = 1;
			hor[i][0].col = 1;
			diag[i][0].row = 1;
			diag[i][0].col = 1;
			num = max(num, ver[i][0].row);
		}
	}
	for (int i = 1; i < matrix.size(); ++i)
	{
		for (int j = 1; j < matrix[i].size(); ++j)
		{
			if (matrix[i][j] == '1')
			{
				hor[i][j].col = hor[i][j - 1].col + 1;
				hor[i][j].row = min(hor[i][j - 1].row, ver[i - 1][j].row + 1);
				hor[i][j].row = max(hor[i][j].row, 1);
				ver[i][j].row = ver[i - 1][j].row + 1;
				ver[i][j].col = min(ver[i - 1][j].col, hor[i][j - 1].col + 1);
				ver[i][j].col = max(ver[i][j].col, 1);
				diag[i][j].row = min(diag[i - 1][j - 1].row, ver[i - 1][j].row) + 1;
				diag[i][j].col = min(diag[i - 1][j - 1].col, hor[i][j - 1].col) + 1;
				if (diag[i][j].row == 1 || diag[i][j].col == 1)
				{
					diag[i][j].row = diag[i][j].col = 1;
				}
				num = max(num, hor[i][j].row * hor[i][j].col);
				num = max(num, ver[i][j].row * ver[i][j].col);
				num = max(num, diag[i][j].row * diag[i][j].col);
			}
		}
	}
	return num;
}