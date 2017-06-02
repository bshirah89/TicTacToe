//TicTacToe.Main
//Brandon Shirah, Chris Garnica, Chris Sylvain


#include<iostream>
#include <string>
#include "TicTacToe.cpp"


int main()
{
	//Set Up Names and declare instance of TicTacToe
	char menuChoice=0;
	TicTacToe game;


	cout<<" _____  _         _____                _____               _  _ "<<endl;
	cout<<"|_   _|(_)       |_   _|              |_   _|             | || |"<<endl;
	cout<<"  | |   _   ___    | |    __ _   ___    | |    ___    ___ | || |"<<endl;
	cout<<"  | |  | | / __|   | |   / _` | / __|   | |   / _ \\ / _\\ | || |"<<endl;
	cout<<"  | |  | || (__    | |  | (_| || (__    | |  | (_) ||  __/|_||_|"<<endl;
	cout<<"  |_/  |_|\\__ |    \\_/  \\____|\\___|     \\_/   \\___/ \\___| (_)(_) \n"<<endl;

	cout<< "Welcome to the Tic Tac Toe Game!!"<<endl;
	do
	{
		game.DisplayMenu();
		cin>>menuChoice;
		//set up if statments for menuchoices
		if (menuChoice=='1')
		{
			game.ResetGame();
			do
			{
				game.DisplayBoard();
				game.ChoosePosition();
			}while(game.CheckForWinner()==3 && game.IsTie()==false);
			game.DisplayBoard();
			game.DisplayWinner();
			game.DisplayStats();

		}
		else if (menuChoice=='2')
		{
			game.ResetMatch();
			do
			{
				game.DisplayBoard();
				game.ChoosePosition();
			}while(game.CheckForWinner()==3 && game.IsTie()==false);
			game.DisplayBoard();
			game.DisplayWinner();
			game.DisplayStats();
		}

	}while(menuChoice!='3');

	return 0;
}



