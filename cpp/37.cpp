/*
37. Sudoku Solver

Write a program to solve a Sudoku puzzle by filling the empty cells.

Empty cells are indicated by the character '.'.

You may assume that there will be only one unique solution.

-------------------      -------------------
|5 3 .|. 7 .|. . .|      |5 3 4|6 7 8|9 1 2|
|6 . .|1 9 5|. . .|      |6 7 2|1 9 5|3 4 8|
|. 9 8|. . .|. 6 .|      |1 9 8|3 4 2|5 6 7|
-----------------        -------------------
|8 . .|. 6 .|. . 3|      |8 5 9|7 6 1|4 2 3|
|4 . .|8 . 3|. . 1|  --> |4 2 6|8 5 3|7 9 1|
|7 . .|. 2 .|. . 6|      |7 1 3|9 2 4|8 5 6|
-----------------        -------------------
|. 6 .|. . .|2 8 .|      |9 6 1|5 3 7|2 8 4|
|. . .|4 1 9|. . 5|      |2 8 7|4 1 9|6 3 5|
|. . .|. 8 .|. 7 9|      |3 4 5|2 8 6|1 7 9|
-----------------        -------------------
*/

#include<iostream>
#include<vector>
#include<set>

using namespace std;

void solveSudoku(vector<vector<char>>&);
bool solve(vector<vector<char>>&);
bool isValid(vector<vector<char>>&, int, int, char);

int main()
{
	vector<vector<char>> board = {
		{ '5','3','.','.','7','.','.', '.', '.' },
		{ '6','.','.','1','9','5','.', '.', '.' },
		{ '.','9','8','.','.','.','.', '6', '.' },
		{ '8','.','.','.','6','.','.', '.', '3' },
		{ '4','.','.','8','.','3','.', '.', '1' },
		{ '7','.','.','.','2','.','.', '.', '6' },
		{ '.','6','.','.','.','.','2', '8', '.' },
		{ '.','.','.','4','1','9','.', '.', '5' },
		{ '.','.','.','.','8','.','.', '7', '9' } };
	solveSudoku(board);
	for (int i = 0; i < board.size(); ++i)
	{
		for (int j = 0; j < board[i].size(); ++j)
		{
			cout << board[i][j] << " ";
		}
		cout << endl;
	}

	system("pause");
	return 0;
}

void solveSudoku(vector<vector<char>>& board)
{
	if (board.size() == 0)
	{
		return;
	}
	solve(board);
}

bool solve(vector<vector<char>>& board)
{
	for (int i = 0; i < board.size(); ++i)
	{
		for (int j = 0; j < board[i].size(); ++j)
		{
			if (board[i][j] == '.')
			{
				for (char c = '1'; c <= '9'; ++c)
				{
					if (isValid(board, i, j, c))
					{
						board[i][j] = c;
						if (solve(board))
						{
							return true;
						}
						else
						{
							board[i][j] = '.';
						}
					}
				}
				return false;
			}
		}
	}
	return true;
}

bool isValid(vector<vector<char>>& board, int row, int col, char num)
{
	for (int i = 0; i < board[0].size(); ++i)
	{
		if (board[row][i] == num || board[i][col] == num)
		{
			return false;
		}
		if (board[(row / 3) * 3 + i / 3][(col / 3) * 3 + i % 3] == num)
		{
			return false;
		}
	}
	return true;
}