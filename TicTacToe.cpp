
	#include<iostream>
	#include "TicTacToe.h"
	#include <cstdlib>
	#include <fstream>
	#include <cctype>


		void TicTacToe:: DisplayBoard()
		{
			for(int i=0; i<3; i++)
			{
				cout<<endl;
				for(int j=0; j<3; j++)
				{
					cout<<" "<<board[i][j]<<" |";
				}
				cout<<endl;
			}
		}

		void TicTacToe::ChoosePosition()
		{
			int position=0;
			bool isInvalid=true;
			do
			{
				if(turn==0)
				{
					do
					{
						cout<<"\n"<<player_1.name<<" enter your position: ";
						cin>>position;
						if (position<1|| position>9)
							cout<<"\nIn valid choice Must be a number 1-9!!";
					}while (position<1|| position>9);

				//if statement for assigning board postion and input validation
					if(position == 1 && isdigit(board[0][0])==true) {board[0][0]=player_1.symbol; availableMoves--; isInvalid=false;}
					else if(position == 2 && isdigit(board[0][1])==true) {board[0][1]=player_1.symbol; 	availableMoves--; isInvalid=false;}
					else if(position == 3 && isdigit(board[0][2])==true) {board[0][2]=player_1.symbol; availableMoves--; isInvalid=false;}
					else if(position == 4 && isdigit(board[1][0])==true) {board[1][0]=player_1.symbol; availableMoves--; isInvalid=false;}
					else if(position == 5 && isdigit(board[1][1])==true) {board[1][1]=player_1.symbol; availableMoves--; isInvalid=false;}
					else if(position == 6 && isdigit(board[1][2])==true) {board[1][2]=player_1.symbol; availableMoves--; isInvalid=false;}
					else if(position == 7 && isdigit(board[2][0])==true) {board[2][0]=player_1.symbol; availableMoves--; isInvalid=false;}
					else if(position == 8 && isdigit(board[2][1])==true) {board[2][1]=player_1.symbol; availableMoves--; isInvalid=false;}
					else if(position == 9 && isdigit(board[2][2])==true) {board[2][2]=player_1.symbol; availableMoves--; isInvalid=false;}

					else
					{
						cout<<"\n\nINVALID MOVE\nPOSITION TAKEN\n\n";
						isInvalid=true;
					}
				}
				else
				{
					//Player 2
					//input validation
					do
					{
						cout<<"\n"<<player_2.name<<" enter your position: ";
						cin>>position;
						if (position<1|| position>9)
							cout<<"In valid choice Must be a number 1-9!!";
					}while (position<1|| position>9);

					if(position == 1 && isdigit(board[0][0])==true) {board[0][0]=player_2.symbol; availableMoves--; isInvalid=false;}
					else if(position == 2 && isdigit(board[0][1])==true) {board[0][1]=player_2.symbol; availableMoves--; isInvalid=false;}
					else if(position == 3 && isdigit(board[0][2])==true) {board[0][2]=player_2.symbol; availableMoves--; isInvalid=false;}
					else if(position == 4 && isdigit(board[1][0])==true) {board[1][0]=player_2.symbol; availableMoves--; isInvalid=false;}
					else if(position == 5 && isdigit(board[1][1])==true) {board[1][1]=player_2.symbol; availableMoves--; isInvalid=false;}
					else if(position == 6 && isdigit(board[1][2])==true) {board[1][2]=player_2.symbol; availableMoves--; isInvalid=false;}
					else if(position == 7 && isdigit(board[2][0])==true) {board[2][0]=player_2.symbol; availableMoves--; isInvalid=false;}
					else if(position == 8 && isdigit(board[2][1])==true) {board[2][1]=player_2.symbol; availableMoves--; isInvalid=false;}
					else if(position == 9 && isdigit(board[2][2])==true) {board[2][2]=player_2.symbol; availableMoves--; isInvalid=false;}

					else
					{
							cout<<"\n\nINVALID MOVE\nPOSITION TAKEN\n\n";
							isInvalid=true;
					}
				}
			}while(isInvalid==true);
			//std::system("clear");
			turn = !turn;
		}



		void TicTacToe:: DisplayWinner()
		{
			if(currentWinner == 1)
			{
				cout<<player_1.name<<" WON!!\n\n";
			}
			else if(currentWinner == 2)
			{
				cout<<player_2.name<<" WON!\n\n";
			}

			else if(currentWinner==3)
			{
				cout<<"\n\nTIE!!\n\n";
			}
		}

		void TicTacToe::ResetMatch()
		{
			turn = 0;
			currentWinner = 3;
			availableMoves=9;

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

		//After a position has been chosen the CheckForWinner() function will be called each time
		int TicTacToe:: CheckForWinner()
		{
			currentWinner = 3; //If currentWinner is 3 then the game is still ongoing (0 = tie; 1=player1; 2=player2)

			if(board[0][0] == 'X' && board[0][1] == 'X' && board[0][2] == 'X')		//top row
			{
				currentWinner = 1;
				player_1.currentScore++;
			}
			else if(board[0][0] == 'X' && board[1][0] == 'X' && board[2][0] == 'X')		//first column
			{
				currentWinner = 1;
				player_1.currentScore++;
			}
			else if(board[0][1] == 'X' && board[1][1] == 'X' && board[2][1] == 'X')		//second column
			{
				currentWinner = 1;
				player_1.currentScore++;
			}
			else if(board[0][2] == 'X' && board[1][2] == 'X' && board[2][2] == 'X')		//third column
			{
				currentWinner = 1;
				player_1.currentScore++;
			}
			else if(board[1][0] == 'X' && board[1][1] == 'X' && board[1][2] == 'X')		//second row
			{
				currentWinner = 1;
				player_1.currentScore++;
			}
			else if(board[2][0] == 'X' && board[2][1] == 'X' && board[2][2] == 'X')		//third row
			{
				currentWinner = 1;
				player_1.currentScore++;
			}

			else if(board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X')
			{
				currentWinner = 1;
				player_1.currentScore++;
			}
			else if(board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == 'X')
			{
				currentWinner = 1;
				player_1.currentScore++;
			}



			///////////
			else if(board[0][0] == 'O' && board[0][1] == 'O' && board[0][2] == 'O')		//top row
			{
				currentWinner = 2;
				player_2.currentScore++;
			}
			else if(board[0][0] == 'O' && board[1][0] == 'O' && board[2][0] == 'O')		//first column
			{
				currentWinner = 2;
				player_2.currentScore++;
			}
			else if(board[0][1] == 'O' && board[1][1] == 'O' && board[2][1] == 'O')		//second column
			{
				currentWinner = 2;
				player_2.currentScore++;
			}
			else if(board[0][2] == 'O' && board[1][2] == 'O' && board[2][2] == 'O')		//third column
			{
				currentWinner = 2;
				player_2.currentScore++;
			}
			else if(board[1][0] == 'O' && board[1][1] == 'O' && board[1][2] == 'O')		//second row
			{
				currentWinner = 2;
				player_2.currentScore++;
			}
			else if(board[2][0] == 'O' && board[2][1] == 'O' && board[2][2] == 'O')		//third row
			{
				currentWinner = 2;
				player_2.currentScore++;
			}
			else if(board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O')
			{
				currentWinner = 2;
				player_2.currentScore++;
			}
			else if(board[0][2] == 'O' && board[1][1] == 'O' && board[2][0] == 'O')
			{
				currentWinner = 2;
				player_2.currentScore++;
			}

			return currentWinner;

		}

		void TicTacToe:: ResetGame()
		{
			cout<<"Enter name for player 1: ";
			cin>>player_1.name;
			cout<<"Enter name for player 2: ";
			cin>>player_2.name;

			player_1.symbol='X';
			player_1.currentScore=0;


			player_2.symbol='O';
			player_2.currentScore=0;

			char c=49;
			for(int i=0; i<3; i++)
			{
				for(int j=0; j<3; j++)
				{
					board[i][j]=c;
					c++;
				}
			}
			availableMoves=9;

			turn==1;
		}

		void TicTacToe:: DisplayStats()
		{
			cout<<"\n\n\n";
			cout<<"Player\t\tWins\n-------------------------\n";
			cout<<player_1.name<<"\t\t"<<player_1.currentScore<<endl;
			cout<<player_2.name<<"\t\t"<<player_2.currentScore<<endl;
			cout<<"\n\n\n";
		}

		void TicTacToe:: DisplayMenu()
		{
			cout<<"\t(1)\tNEW GAME "<<endl<<endl;
			cout<<"\t(2)\tNEW MATCH"<<endl<<endl;
			cout<<"\t(3)\tQUIT"<<endl<<endl;
		}

		bool TicTacToe:: IsTie()
		{
			if(availableMoves == 0)	{return true;}

			else					{return false;}
		};




