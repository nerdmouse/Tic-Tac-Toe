/*
    Make a two player tic tac toe game

    Modify the program so that it will announce when a player has won the game (and
    which player won, x or o

    Modify the program so that it is a one player game against the computer (with the
    computer making its moves randomly)

    Modify the program so that anytime the player is about to win (aka, they have 2 of
    3 x's in a row, the computer will block w/an O)
*/

#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <algorithm>

using namespace std;

bool gameOver = false;
int turnCounter{ 0 };

char playerTurn;
char player;

// creates a vector that holds the AI's possible moves
vector<char> aiMoveVec{ '1', '2', '3', '4', '5', '6', '7', '8', '9' };
vector<char> usedMovesVec{};

char aiMove;
char aiCharacter;

//int playerOrder{ 1 };

// coordinates that are used for where the player is allowed playable moves
char coordinates[3][3] =
{
    {'1', '2', '3' },
    {'4', '5', '6' },
    {'7', '8', '9' }
};

// declares playerMove() early to allow checkMove() to utilize it
int playerMove();
int aiPlayer();

char checkPlayerWin()
{
    
    if (coordinates[0][0] == player && coordinates[0][1] == player)
    {
        aiMove = '3';
        return aiMove;
    }
    else if (coordinates[0][1] == player && coordinates[0][2] == player)
    {
        aiMove = '1';
        return aiMove;
    }
    else if (coordinates[0][0] == player && coordinates[0][2] == player)
    {
        aiMove = '2';
        return aiMove;
    }

    else if (coordinates[0][0] == player && coordinates[1][0] == player)
    {
        aiMove = '7';
        return aiMove;
    }
    else if (coordinates[0][0] == player && coordinates[2][0] == player)
    {
        aiMove = '4';
        return aiMove;
    }
    else if (coordinates[1][0] == player && coordinates[2][0] == player)
    {
        aiMove = '1';
        return aiMove;
    }

    else if (coordinates[0][0] == player && coordinates[1][1] == player)
    {
        aiMove = '9';
        return aiMove;
    }
    else if (coordinates[0][0] == player && coordinates[2][2] == player)
    {
        aiMove = '5';
        return aiMove;
    }
    else if (coordinates[1][1] == player && coordinates[2][2] == player)
    {
        aiMove = '1';
        return aiMove;
    }

    else if (coordinates[0][1] == player && coordinates[1][1] == player)
    {
        aiMove = '8';
        return aiMove;
    }
    else if (coordinates[0][1] == player && coordinates[2][1] == player)
    {
        aiMove = '5';
        return aiMove;
    }
    else if (coordinates[1][1] == player && coordinates[2][1] == player)
    {
        aiMove = '2';
        return aiMove;
    }

    else if (coordinates[0][2] == player && coordinates[1][2] == player)
    {
        aiMove = '9';
        return aiMove;
    }
    else if (coordinates[1][2] == player && coordinates[2][2] == player)
    {
        aiMove = '3';
        return aiMove;
    }
    else if (coordinates[0][2] == player && coordinates[2][2] == player)
    {
        aiMove = '6';
        return aiMove;
    }

    else if (coordinates[0][2] == player && coordinates[1][1] == player)
    {
        aiMove = '7';
        return aiMove;
    }
    else if (coordinates[0][2] == player && coordinates[2][0] == player)
    {
        aiMove = '5';
        return aiMove;
    }
    else if (coordinates[1][1] == player && coordinates[2][0] == player)
    {
        aiMove = '3';
        return aiMove;
    }

    else if (coordinates[1][0] == player && coordinates[1][1] == player)
    {
        aiMove = '6';
        return aiMove;
    }
    else if (coordinates[1][0] == player && coordinates[1][2] == player)
    {
        aiMove = '5';
        return aiMove;
    }
    else if (coordinates[1][1] == player && coordinates[1][2] == player)
    {
        aiMove = '4';
        return aiMove;
    }

    else if (coordinates[2][0] == player && coordinates[2][1] == player)
    {
        aiMove = '9';
        return aiMove;
    }
    else if (coordinates[2][0] == player && coordinates[2][2] == player)
    {
        aiMove = '8';
        return aiMove;
    }
    else if (coordinates[2][1] == player && coordinates[2][2] == player)
    {
        aiMove = '7';
        return aiMove;
    }
    /*
    if (std::find(usedMovesVec.begin(), usedMovesVec.end(), '1') != usedMovesVec.end()
        && std::find(usedMovesVec.begin(), usedMovesVec.end(), '2') != usedMovesVec.end())
    {
        aiMove = '3';
        return aiMove;
    }
    else if (std::find(usedMovesVec.begin(), usedMovesVec.end(), '1') != usedMovesVec.end()
        && std::find(usedMovesVec.begin(), usedMovesVec.end(), '3') != usedMovesVec.end())
    {
        aiMove = '2';
        return aiMove;
    }
    else if (std::find(usedMovesVec.begin(), usedMovesVec.end(), '2') != usedMovesVec.end()
        && std::find(usedMovesVec.begin(), usedMovesVec.end(), '3') != usedMovesVec.end())
    {
        aiMove = '1';
        return aiMove;
    }

    else if (std::find(usedMovesVec.begin(), usedMovesVec.end(), '1') != usedMovesVec.end()
        && std::find(usedMovesVec.begin(), usedMovesVec.end(), '5') != usedMovesVec.end())
    {
        aiMove = '9';
        return aiMove;
    }
    else if (std::find(usedMovesVec.begin(), usedMovesVec.end(), '1') != usedMovesVec.end()
        && std::find(usedMovesVec.begin(), usedMovesVec.end(), '9') != usedMovesVec.end())
    {
        aiMove = '5';
        return aiMove;
    }
    else if (std::find(usedMovesVec.begin(), usedMovesVec.end(), '5') != usedMovesVec.end()
        && std::find(usedMovesVec.begin(), usedMovesVec.end(), '9') != usedMovesVec.end())
    {
        aiMove = '1';
        return aiMove;
    }

    else if (std::find(usedMovesVec.begin(), usedMovesVec.end(), '1') != usedMovesVec.end()
        && std::find(usedMovesVec.begin(), usedMovesVec.end(), '4') != usedMovesVec.end())
    {
        aiMove = '7';
        return aiMove;
    }
    else if (std::find(usedMovesVec.begin(), usedMovesVec.end(), '1') != usedMovesVec.end()
        && std::find(usedMovesVec.begin(), usedMovesVec.end(), '7') != usedMovesVec.end())
    {
        aiMove = '4';
        return aiMove;
    }
    else if (std::find(usedMovesVec.begin(), usedMovesVec.end(), '4') != usedMovesVec.end()
        && std::find(usedMovesVec.begin(), usedMovesVec.end(), '7') != usedMovesVec.end())
    {
        aiMove = '1';
        return aiMove;;
    }

    else if (std::find(usedMovesVec.begin(), usedMovesVec.end(), '2') != usedMovesVec.end()
        && std::find(usedMovesVec.begin(), usedMovesVec.end(), '5') != usedMovesVec.end())
    {
        aiMove = '8';
        return aiMove;
    }
    else if (std::find(usedMovesVec.begin(), usedMovesVec.end(), '2') != usedMovesVec.end()
        && std::find(usedMovesVec.begin(), usedMovesVec.end(), '8') != usedMovesVec.end())
    {
        aiMove = '5';
        return aiMove;
    }
    else if (std::find(usedMovesVec.begin(), usedMovesVec.end(), '5') != usedMovesVec.end()
        && std::find(usedMovesVec.begin(), usedMovesVec.end(), '8') != usedMovesVec.end())
    {
        aiMove = '2';
        return aiMove;;
    }

    else if (std::find(usedMovesVec.begin(), usedMovesVec.end(), '3') != usedMovesVec.end()
        && std::find(usedMovesVec.begin(), usedMovesVec.end(), '6') != usedMovesVec.end())
    {
        aiMove = '9';
        return aiMove;
    }
    else if (std::find(usedMovesVec.begin(), usedMovesVec.end(), '3') != usedMovesVec.end()
        && std::find(usedMovesVec.begin(), usedMovesVec.end(), '9') != usedMovesVec.end())
    {
        aiMove = '6';
        return aiMove;
    }
    else if (std::find(usedMovesVec.begin(), usedMovesVec.end(), '6') != usedMovesVec.end()
        && std::find(usedMovesVec.begin(), usedMovesVec.end(), '9') != usedMovesVec.end())
    {
        aiMove = '3';
        return aiMove;
    }

    else if (std::find(usedMovesVec.begin(), usedMovesVec.end(), '3') != usedMovesVec.end()
        && std::find(usedMovesVec.begin(), usedMovesVec.end(), '5') != usedMovesVec.end())
    {
        aiMove = '7';
        return aiMove;
    }
    else if (std::find(usedMovesVec.begin(), usedMovesVec.end(), '3') != usedMovesVec.end()
        && std::find(usedMovesVec.begin(), usedMovesVec.end(), '7') != usedMovesVec.end())
    {
        aiMove = '5';
        return aiMove;
    }
    else if (std::find(usedMovesVec.begin(), usedMovesVec.end(), '5') != usedMovesVec.end()
        && std::find(usedMovesVec.begin(), usedMovesVec.end(), '7') != usedMovesVec.end())
    {
        aiMove = '3';
        return aiMove;
    }

    else if (std::find(usedMovesVec.begin(), usedMovesVec.end(), '4') != usedMovesVec.end()
        && std::find(usedMovesVec.begin(), usedMovesVec.end(), '5') != usedMovesVec.end())
    {
        aiMove = '6';
        return aiMove;
    }
    else if (std::find(usedMovesVec.begin(), usedMovesVec.end(), '4') != usedMovesVec.end()
        && std::find(usedMovesVec.begin(), usedMovesVec.end(), '6') != usedMovesVec.end())
    {
        aiMove = '5';
        return aiMove;
    }
    else if (std::find(usedMovesVec.begin(), usedMovesVec.end(), '5') != usedMovesVec.end()
        && std::find(usedMovesVec.begin(), usedMovesVec.end(), '6') != usedMovesVec.end())
    {
        aiMove = '4';
        return aiMove;
    }

    else if (std::find(usedMovesVec.begin(), usedMovesVec.end(), '7') != usedMovesVec.end()
        && std::find(usedMovesVec.begin(), usedMovesVec.end(), '8') != usedMovesVec.end())
    {
        aiMove = '9';
        return aiMove;
    }
    else if (std::find(usedMovesVec.begin(), usedMovesVec.end(), '7') != usedMovesVec.end()
        && std::find(usedMovesVec.begin(), usedMovesVec.end(), '9') != usedMovesVec.end())
    {
        aiMove = '8';
        return aiMove;
    }
    else if (std::find(usedMovesVec.begin(), usedMovesVec.end(), '8') != usedMovesVec.end()
        && std::find(usedMovesVec.begin(), usedMovesVec.end(), '9') != usedMovesVec.end())
    {
        aiMove = '7';
        return aiMove;
    }
    */

    aiMoveVec.erase(std::remove(aiMoveVec.begin(), aiMoveVec.end(), aiMove), aiMoveVec.end());
    usedMovesVec.push_back(aiMove);

}
bool checkWin()
{
    std::string winMSG = "Congratulations on winning ";

    if (coordinates[0][0] == coordinates[0][1] && coordinates[0][1] == coordinates[0][2])
    {
        cout << endl << winMSG << coordinates[0][0] << endl;;
        gameOver = true;
        return gameOver;
    }
    else if (coordinates[0][0] == coordinates[1][0] && coordinates[1][0] == coordinates[2][0])
    {
        cout << endl << winMSG << coordinates[0][0] << endl;
        gameOver = true;
        return gameOver;
    }
    else if (coordinates[0][0] == coordinates[1][1] && coordinates[1][1] == coordinates[2][2])
    {
        cout << endl << winMSG << coordinates[0][0] << endl;
        gameOver = true;
        return gameOver;
    }
    else if (coordinates[0][1] == coordinates[1][1] && coordinates[1][1] == coordinates[2][1])
    {
        cout << endl << winMSG << coordinates[0][1] << endl;
        gameOver = true;
        return gameOver;
    }
    else if (coordinates[0][2] == coordinates[1][2] && coordinates[1][2] == coordinates[2][2])
    {
        cout << endl << winMSG << coordinates[0][2] << endl;
        gameOver = true;
        return gameOver;
    }
    else if (coordinates[0][2] == coordinates[1][1] && coordinates[1][1] == coordinates[2][0])
    {
        cout << endl << winMSG << coordinates[0][2] << endl;
        gameOver = true;
        return gameOver;
    }
    else if (coordinates[1][0] == coordinates[1][1] && coordinates[1][1] == coordinates[1][2])
    {
        cout << endl << winMSG << coordinates[1][1] << endl;
        gameOver = true;
        return gameOver;
    }
    else if (coordinates[2][0] == coordinates[2][1] && coordinates[2][1] == coordinates[2][2])
    {
        cout << endl << winMSG << coordinates[2][0] << endl;
        gameOver = true;
        return gameOver;
    }

}

// checks the coordinates, and will place the appropriate 'X' or 'O' into the location
// will check and see if the location is taken by an 'X' or an 'O'
int checkMove(char _playerChoice, char _player)
{
    char playerPiece = _player;
    char playerChoice = _playerChoice;

    // checks the user's move to see if it's already been filled by an 'X' or an 'O'
    // if the input isn't valid, then it'll produce an error letting the player make
    // another choice
    if (playerChoice == '1' && coordinates[0][0] != 'X' && coordinates[0][0] != 'O')
    {
        coordinates[0][0] = playerPiece;
        checkWin();
    }
    else if (playerChoice == '2' && coordinates[0][1] != 'X' && coordinates[0][1] != 'O')
    {
        coordinates[0][1] = playerPiece;
        checkWin();
    }
    else if (playerChoice == '3' && coordinates[0][2] != 'X' && coordinates[0][2] != 'O')
    {
        coordinates[0][2] = playerPiece;
        checkWin();
    }
    else if (playerChoice == '4' && coordinates[1][0] != 'X' && coordinates[1][0] != 'O')
    {
        coordinates[1][0] = playerPiece;
        checkWin();
    }
    else if (playerChoice == '5' && coordinates[1][1] != 'X' && coordinates[1][1] != 'O')
    {
        coordinates[1][1] = playerPiece;
        checkWin();
    }
    else if (playerChoice == '6' && coordinates[1][2] != 'X' && coordinates[1][2] != 'O')
    {
        coordinates[1][2] = playerPiece;
        checkWin();
    }
    else if (playerChoice == '7' && coordinates[2][0] != 'X' && coordinates[2][0] != 'O')
    {
        coordinates[2][0] = playerPiece;
        checkWin();
    }
    else if (playerChoice == '8' && coordinates[2][1] != 'X' && coordinates[2][1] != 'O')
    {
        coordinates[2][1] = playerPiece;
        checkWin();
    }
    else if (playerChoice == '9' && coordinates[2][2] != 'X' && coordinates[2][2] != 'O')
    {
        coordinates[2][2] = playerPiece;
        checkWin();
    }
    else
    {
        cout << "Invalid move." << endl;
        cout << playerChoice;
        cout << endl;
        playerMove();
    }

    return 0;
}

// draws a tic tac toe board for the player to use
// shows coordinates 1 - 9 that will be modified by checkMove()
int drawBoard()
{


    // creates a tic tac toe board 
    cout << "     " << "|" << "     " << "|" << "     " << endl

        << "  " << coordinates[0][0] << "  " << "|" << "  " << coordinates[0][1] << "  "
        << "|" << "  " << coordinates[0][2] << "  " << endl

        << "_____" << "|" << "_____" << "|" << "_____" << endl

        << "     " << "|" << "     " << "|" << "     " << endl
        << "  " << coordinates[1][0] << "  " << "|" << "  " << coordinates[1][1] << "  "
        << "|" << "  " << coordinates[1][2] << "  " << endl

        << "_____" << "|" << "_____" << "|" << "_____" << endl

        << "     " << "|" << "     " << "|" << "     " << endl
        << "  " << coordinates[2][0] << "  " << "|" << "  " << coordinates[2][1] << "  "
        << "|" << "  " << coordinates[2][2] << "  " << endl

        << "     " << "|" << "     " << "|" << "     " << endl;

    return 0;
}

// assigns the player turn, and calls checkMove() to see if the move is valid
int playerMove()
{

    cin >> playerTurn;

    checkMove(playerTurn, player);

    /*
    if (turnCounter % 2 == 0)
    {
        player = 'X';
        checkMove(playerMove, player);
    }
    else
    {
        player = 'O';
        checkMove(playerMove, player);
    }
    */

    // removes player move from AI's possible move pool
    aiMoveVec.erase(std::remove(aiMoveVec.begin(), aiMoveVec.end(), playerTurn), aiMoveVec.end());
    usedMovesVec.push_back(playerTurn);

    return 0;
}

// creates an AI that plays against the player
int aiPlayer()
{
    int odds = rand() & 10;
    if (gameOver == false)
    {
        
        cout << "AI's Turn" << endl;
        int chooseAIMove = rand() % aiMoveVec.size();
        aiMove = aiMoveVec[chooseAIMove];

        if (odds != 1)
        {
            checkPlayerWin();
        }
        //checkPlayerWin();
        checkMove(aiMove, aiCharacter);

        /*
        if (turnCounter % 2 == 0)
        {
            //if (odds != 1)
            //{
                checkPlayerWin();
            //}
            aiCharacter = 'X';
            checkMove(aiMove, aiCharacter);
        }
        else
        {
            //if (odds != 1)
            //{
                checkPlayerWin();
            //}
            aiCharacter = 'O';
            checkMove(aiMove, aiCharacter);
        }
        */

        // removes the AI's previously used moves
        aiMoveVec.erase(std::remove(aiMoveVec.begin(), aiMoveVec.end(), aiMove), aiMoveVec.end());
        usedMovesVec.push_back(aiMove);
    }


    return 0;

}

int main()
{
    srand(time(NULL));
    cout << "Welcome to Tic Tac Toe!" << endl;
    cout << "X will go first, followed by O" << endl;
    //cout << "Do you wish to go first or second?" << endl << "Select 1 or 2: ";
    //cin >> playerOrder;

    // just a spacer
    cout << endl;

    int turnOrder{ 1 };
    
    cout << "Would you like to go first or second?" << endl
        << "Select '1' or '2': " << endl;
    cin >> turnOrder;

    if (turnOrder == 1)
    {
        player = 'X';
        aiCharacter = 'O';
    }
    else if (turnOrder == 2)
    {
        player = 'O';
        aiCharacter = 'X';
    }
    else
    {
        player = 'X';
        aiCharacter = 'O';
    }

    // makes a big boi spacer
    for (int i = 0; i < 50; i++)
    {
        cout << endl;
    }
    

    do
    {
        drawBoard();
        cout << endl;

        cout << "Choose where you'd like to go: ";
        playerMove();
        turnCounter++;

        cout << endl;

        //drawBoard();
        cout << endl;
        //cout << "AI's turn: ";
        aiPlayer();
        cout << endl;


        turnCounter++;


        if (turnCounter == 9)
        {
            gameOver = true;
        }
    } while (gameOver == false);

    drawBoard();

}

