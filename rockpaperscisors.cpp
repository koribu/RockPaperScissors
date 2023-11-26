// rockpaperscisors.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

enum class Action
{
    ROCK,
    PAPER,
    SCISSORS
};

enum class GameResult
{
    DRAW,
    PLAYERWIN,
    COMPUTERWIN
};

GameResult CheckGameCondition(Action player, Action computer)
{
    if (player == computer)
    {
        return GameResult::DRAW;
    }

    if (player == Action::ROCK && computer == Action::SCISSORS ||
        player == Action::PAPER && computer == Action::ROCK ||
        player == Action::SCISSORS && computer == Action::PAPER)
    {
        return GameResult::PLAYERWIN;
    }
    else
        return GameResult::COMPUTERWIN;
}

std::string GetActionName(Action action)
{
    if (action == Action::ROCK)
        return "Rock";
    else if (action == Action::PAPER)
        return "Paper";
    else
        return "Scissors";
}


int main()
{
    srand(time(NULL));

    Action playerAction, computerAction;
    
    bool isGameEnded = false;
    int round = 1;
    int playerScore, computerScore;
    playerScore = computerScore = 0;

    std::string playerInput;


    
    std::cout << "Hello!!!\n\nWelcome to my Rock Paper Scissors Game!\n\n";
    std::cout << "\nInstructions: You will write 'rock' 'paper' or 'scissors' as your action.\n\nComputer will choose an action randomly.\n\nThen result will show.\n\nThere are 3 rounds. \n\n\nCan you save humanity?\n\n";
    

    while (!isGameEnded)
    {
      

        bool isValidInput = true;
        do 
        {
            std::cout << "\n\n\nPlease enter your move: ";
            std::cin >> playerInput;

            if (playerInput == "rock")
                playerAction = Action::ROCK;
            else if (playerInput == "paper")
                playerAction = Action::PAPER;
            else if (playerInput == "scissors")
                playerAction = Action::SCISSORS;
            else
            {
                isValidInput = false;
                std::cout << "The action undefined. Please try again.";
            }

        } while (!isValidInput);
        

        computerAction = static_cast<Action>(rand() % 3);
        GameResult result = CheckGameCondition(playerAction, computerAction);

        std::cout << "\n\nROUND " << round << " RESULT\n\nPlayer Action: " << GetActionName(playerAction)<<"\nComputer Action: "<<GetActionName(computerAction);


        if (result == GameResult::DRAW)
        {
            
            std::cout << "\n\nIt is Draw";
        }
        else if (result == GameResult::PLAYERWIN)
        {
            std::cout << "\n\nPlayer Won!";
            playerScore++;
        }
        else         
        {
            std::cout << "\n\nComputer Won!";
            computerScore++;
        }
        

        std::cout << "\n\nPLAYER - " << playerScore << "  /  COMPUTER - " << computerScore << "\n\n";
       

        if (playerScore >= 3)
        {
            isGameEnded = true;

            std::cout << "PLAYER WON!!!\n\n\n";
        }
        else if (computerScore >= 3)
        {
            isGameEnded = true;
            std::cout << "COMPUTER WON!!\n\n\n";
        }

        round++;
    }

}



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
