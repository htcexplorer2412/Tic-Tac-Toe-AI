#include"iostream"

struct Move {
	int row, col;
};

void printBoard(char (& board)[3][3])
{
	for (auto i = 1; i < 4; i++)
	{
		for (auto j = 1; j < 4; j++)
		{

			std::cout << board[i - 1][j - 1] << " ";
			if (j % 3 == 0)
			{
				std::cout << std::endl;
			}

		}
	}
}

bool drawChecker(char(&board)[3][3])
{
	int num = 0;
	for (auto i = 0; i < 3; i++)
	{
		for (auto j = 0; j < 3; j++)
		{
			if (board[i][j] == 'X' || board[i][j] == 'O')
			{
				num++;
			}
		}
	}
	if (num == 9)
	{
		return true;
	}
	return false;
}

void updateBoard(char (& board)[3][3], int index, char player)
{
	int i = (index - 1) / 3;
	int j = (index - 1) % 3;
	board[i][j] = player;
	printBoard(board);

}

int colRowChecker(char(&board)[3][3])
{
	for (auto i = 0; i < 3; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
		{
			if (board[i][0] == 'X')
			{
				return 10;
			}

			else if (board[i][0] == 'O')
			{
				return -10;
			}

		}

		else if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
		{
			if (board[0][i] == 'X')
			{
				return 10;
			}

			else if (board[0][i] == 'O')
			{
				return -10;
			}

		}
	}

	return 0;
}

int gameStateChecker(char(&board)[3][3])
{
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
	{
		if (board[0][0] == 'X')
		{
			return 10;
		}

		else if (board[0][0] == 'O')
		{
			return -10;
		}
	}

	else if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
	{
		if (board[0][2] == 'X')
		{
			return 10;
		}

		else if (board[0][2] == 'O')
		{
			return -10;
		}
	}

	else 
	{
		return colRowChecker(board);
	}

	

}

int minimax(char (&board)[3][3], bool turn)
{
	int score = gameStateChecker(board);
	std::cout << score << std::endl;

	if (score == 10)
	{
		return score;
	}
		

	if (score == -10)
	{
		return score;
	}
		

	if (drawChecker)
	{
		return 0;
	}

	if (turn)
	{
		int best = -1000;

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				// Check if cell is empty 
				if (board[i][j] == '_')
				{
					// Make the move 
					board[i][j] = 'X';

					// Call minimax recursively and choose 
					// the maximum value 
					best = std::max(best, minimax(board, !turn));

					// Undo the move 
					board[i][j] = '_';
				}
			}
		}

		return best;


	}

	else
	{
		int best = 1000;

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				// Check if cell is empty 
				if (board[i][j] == '_')
				{
					// Make the move 
					board[i][j] = 'O';

					// Call minimax recursively and choose 
					// the maximum value 
					best = std::min(best, minimax(board, !turn));

					// Undo the move 
					board[i][j] = '_';
				}
			}
		}
		return best;

	}
		

}

Move findBestMove(char  (&board)[3][3])
{
	int bestVal = -1000;
	Move bestMove;
	bestMove.row = -1;
	bestMove.col = -1;

	for (auto i = 0; i < 3; i++)
	{
		for (auto j = 0; j < 3; j++)
		{
			if (board[i][j] == '_')
			{
				board[i][j] = 'X';

				int moveVal = minimax(board, false);

				board[i][j] = '_';

				if (moveVal > bestVal)
				{

					bestMove.row = i;
					bestMove.col = j;
					bestVal = moveVal;
				}
			}
		}
	}
	return bestMove;
}

int main()
{
	char board[3][3] = { {'X','O','O'} , {'O','X','X'} , {'_','_','_'} };
	bool turn = true;
	bool gameOver = false;
	int  index = 0;
	printBoard(board);

	Move bestMove = findBestMove(board);
	index = (3*bestMove.row) + bestMove.col;

	std::cout << "Best Index is " << index << " " << bestMove.row <<" " << bestMove.col << std::endl;
	
    return 0;
}