#include <iostream>
#include<time.h>
#include<stdlib.h>
using namespace std;



char board[9] = {
    ' ',
    ' ',
    ' ',
    ' ',
    ' ',
    ' ',
    ' ',
    ' ',
    ' ',
};

void show_board()
{

    cout << "     "
         << "     |     "
         << "    |    " << endl;
    cout << "     " << board[0] << "    |    " << board[1] << "    |    " << board[2] << endl;
    cout << "     "
         << "     |     "
         << "    |    " << endl;
    cout << "---------------------------------" << endl;
    cout << "     "
         << "     |     "
         << "    |    " << endl;
    cout << "     " << board[3] << "    |    " << board[4] << "    |    " << board[5] << endl;
    cout << "     "
         << "     |     "
         << "    |    " << endl;
    cout << "---------------------------------" << endl;
    cout << "     "
         << "     |     "
         << "    |    " << endl;
    cout << "     " << board[6] << "    |    " << board[7] << "    |    " << board[8] << endl;
    cout << "     "
         << "     |     "
         << "    |    " << endl;
}

void get_computer_choise()
{
    srand(time(0));
    int choice;
    do
    {
        choice = rand() % 10;
    } while (board[choice] != ' ');
    board[choice] = 'O';
}

void get_X_player()
{
    while (true)
    {
        /* code */
        cout << "select your position =  ";
        int choice;
        cin >> choice;
        choice--;
        if (choice < 0 || choice > 8)
        {
            cout << "please select your choice frome (1 - 9). " << endl;
        }
        else if (board[choice] != ' ')
        {
            /* code */
            cout << "please select an Empty position" << endl;
        }
        else
        {
            board[choice] = 'X';
            break;
        }
    }
}
void get_O_player()
{
    while (true)
    {
        /* code */
        cout << "select your position: ";
        int choice;
        cin >> choice;
        choice--;
        if (choice < 0 || choice > 8)
        {
            cout << "please select your choice frome (1 - 9). " << endl;
        }
        else if (board[choice] != ' ')
        {
            /* code */
            cout << "please select an Empty position" << endl;
        }
        else
        {
            board[choice] = 'O';
            break;
        }
    }
}

int cout_board(char symbol)
{
    int total = 0;
    for (int i = 0; i < 9; i++)
    {
        if (board[i] == symbol)
        {
            total += 1;
        }
    }
    return total;
}

char check_winner()
{
    // checking winner in row
    if (board[0] == board[1] && board[1] == board[2] && board[0] != ' ')
    {
        
        return board[0];
    }
    if (board[3] == board[4] && board[4] == board[5] && board[3] != ' ')
    {
        
        return board[3];
    }
    if (board[6] == board[7] && board[7] == board[8] && board[6] != ' ')
    {
        
        return board[6];
    }

    // checking winner in col
    if (board[0] == board[3] && board[3] == board[6] && board[0] != ' ')
    {
        
        return board[0];
    }
    if (board[1] == board[4] && board[4] == board[7] && board[1] != ' ')
    {
        
        return board[1];
    }
    if (board[2] == board[5] && board[5] == board[8] && board[2] != ' ')
    {
        
        return board[2];
    }

    // diagonal
    if (board[0] == board[4] && board[4] == board[8] && board[0] != ' ')
    {
        
        return board[0];
    }
    if (board[2] == board[4] && board[4] == board[6] && board[2] != ' ')
    {
        
        return board[2];
    }

    if (cout_board('X') + cout_board('O') < 9)
    {
        return 'c';
    }
    else
    {
        return 'd';
    }
}
void computer_vs_player()
{
    string player_name;
    cout << "enter your name :"<<endl;
    cin >> player_name;
    while (true)
    {
        /* code */
        system("cls");
        show_board();
        if(cout_board('X') == cout_board('O')){
            cout<< player_name << "'s turn"<<endl;
            get_X_player();
        }
        else{
            get_computer_choise();
        }
        char winner = check_winner();
        if(winner == 'X'){
            system("cls");
            cout<<player_name<<" won the game"<<endl;
            
            break;
        }
        else if(winner == 'O'){
            system("cls");
            cout<<"computer win"<<endl;
            break;
        }
        else if(winner == 'd'){
            cout<<"game is draw."<<endl;
            break;
        }
    }
    
}
void player_vs_player()
{
    string X_player_name , O_player_name;
    cout << "enter X player name :"<<endl;
    cin >> X_player_name;
    cout << "enter O player name :"<<endl;
    cin>> O_player_name;
    while (true)
    {
        /* code */
        system("cls");
        show_board();
        if(cout_board('X') == cout_board('O')){
            cout<< X_player_name << "'s turn"<<endl;
            get_X_player();
        }
        else{
            cout<< O_player_name << "'s turn"<<endl;
            get_O_player();
        }
        char winner = check_winner();
        if(winner == 'X'){
            system("cls");
            show_board();
            cout<<X_player_name<<" won the game"<<endl;
            break;
        }
        else if(winner == 'O'){
            system("cls");
            show_board();
            cout<<O_player_name<<" won the game"<<endl;
            break;
        }
        else if(winner == 'd'){
            cout<<"game is draw."<<endl;
            break;
        }
    }
    
}


int main()
{
    int mode;
    cout<<"1. computer vs player"<<endl;
    cout<<"2. player vs player"<<endl;
    cout<<"select Game Mode"<<endl;
    cin>>mode;
    switch (mode){
        case 1:
        computer_vs_player();
        break;
        case 2:
        player_vs_player();
        break;
        default:
        cout<<"please select valid game mode"<<endl;
        break;
    }
    

    return 0;
}