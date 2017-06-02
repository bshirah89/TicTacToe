//ttt.h
#include <string>

using namespace std;

struct Player
{
	string name;
	char symbol;
	int currentScore;

	Player()
	{
		name="Chris";
		symbol='X';
		int currentScore=0;
	}
};

class TicTacToe
{
	private:
		Player player_1, player_2;
		int currentWinner, availableMoves;
		bool turn;
		char board[3][3];

	public:
		TicTacToe()
		{
			currentWinner=3;
			availableMoves=9;
			player_1.name="Chr is";
			player_1.symbol='X';
			player_1.currentScore=0;

			player_2.name="John";
			player_2.symbol='O';
			player_2.currentScore=0;

			turn=1;

			char c=49;
			for(int i=0; i<3; i++)
			{
				for(int j=0; j<3; j++)
				{
					board[i][j]=c;
					c++;
				}
			}
		}


		// additional functions
		void DisplayBoard();
		void ChoosePosition();
		void DisplayWinner();
		void ResetMatch();
		int CheckForWinner();
		void ResetGame();
		void DisplayStats();
		void DisplayMenu();
		bool IsTie();
		void Intro();
};

