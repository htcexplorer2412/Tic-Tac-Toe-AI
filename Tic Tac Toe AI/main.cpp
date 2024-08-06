#include"iostream"

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

void updateBoard(char (& board)[3][3], int index, char player)
{
	int i = (index - 1) / 3;
	int j = (index - 1) % 3;
	board[i][j] = player;
	printBoard(board);

}

bool colRowChecker(char(&board)[3][3])
{
	for (auto i = 0; i < 3; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
		{
			return true;
		}

		else if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
		{
			return true;
		}
		
		else
		{
			return false;
		}
	}
}

void gameStateChecker(char(&board)[3][3], bool &turn, bool& gameOver)
{
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
	{
		gameOver = true;
	}
	else if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
	{
		gameOver = true;
	}
	else if (colRowChecker(board))
	{
		
		gameOver = true;
	}

}

int main()
{
	char board[3][3] = { {'1','2','3'} , {'4','5','6'} , {'7','8','9'} };
	bool turn = true;
	bool gameOver = false;
	int  index = 0;
	printBoard(board);


	while (!gameOver)
	{
		if (turn)
		{
			std::cout << "Player 1 Turn" << std::endl;
			std::cout << "Please Select 1 to 9 to Display X"<< std::endl;
			std::cin >> index;
			updateBoard(board, index, 'X');
			gameStateChecker(board, turn, gameOver);
            turn = false;
		}

		else
		{
			std::cout << "Player 2 Turn" << std::endl;
			std::cout << "Please select 1 to 9 to display O" << std::endl;
			std::cin >> index;
			updateBoard(board, index, 'O');
			gameStateChecker(board, turn, gameOver);
			turn = true;
		}
	}
	if (!turn)
	{
		std::cout << "Game Over Player X won"<< std::endl;
	}

	else if (turn)
	{
		std::cout << "Game Over Player O won" << std::endl;
	}
	
    return 0;
}