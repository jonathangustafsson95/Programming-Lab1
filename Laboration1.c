/*
* File: LaborationGrupp7.c
* -------------------------
* This program is a collection of 4 games.
*/

#include <stdio.h>
#include "genlib.h"
#include "simpio.h"
#include "random.h"
#include "strlib.h"

/* Function prototypes */

void displayMainMenu(void);
void craps(void);
void pigs(void);
void twoDicePigs(void);
void roulette(void);
void anyKey();

/* 
* Function: displayMainMenu
* Usage: displayMenu();
* ---------------------------
* This function displays all the alternatives of games for the user.
*/

void displayMainMenu(void) 
{
	system("cls");
	printf("Which game would you like to play?\n");
	printf("		Enter 1 for Craps\n");
	printf("		Enter 2 for Pig\n");
	printf("		Enter 3 for Two-dice pig\n");
	printf("		Enter 4 for Roulette\n");
	printf("		Enter 0 to Quit\n");
}

/* Main program */
 
main() 
{
	bool run = TRUE;
	while (run) {
		displayMainMenu();
		printf("Your choice? ");
		int answer = GetInteger();
		switch (answer)

		{
		case 0:
			run = FALSE;
			anyKey();
			break;
		case 1:
			craps();
			break;
		case 2:
			pigs();
			break;
		case 3:
			twoDicePigs();
			break;
		case 4:
			roulette();
			break;
		default:
			printf("Invalid input, please enter a number between 0-4\n");
			break;
		}
	}

}

/*
 * Craps Game
 * -------------
 * This program plays the dice game called craps.  For a discussion
 * of the rules of craps, please see the GiveInstructions function.
 */

 /* Function prototypes */

void GiveInstructions(void);
void PlayCrapsGame(void);
int RollTwoDice(void);
bool GetYesOrNo(string prompt);

/* Main program */

void craps(void)
{
	Randomize();
	if (GetYesOrNo("Would you like instructions? ")) {
		GiveInstructions();
	}
	while (TRUE) {
		PlayCrapsGame();
		if (!GetYesOrNo("Would you like to play again? ")) break;
	}
}

/*
 * Function: GiveInstructions
 * Usage: GiveInstructions();
 * -----------------------
 * This function welcomes the player to the game and gives
 * instructions on the rules to craps.
 */

void GiveInstructions(void)
{
	printf("Welcome to the craps table!\n\n");
	printf("To play craps, you start by rolling a pair of dice\n");
	printf("and looking at the total.  If the total is 2, 3, or\n");
	printf("12, that's called 'crapping out' and you lose.  If\n");
	printf("you roll a 7 or an 11, that's called a 'natural' and\n");
	printf("you win.  If you roll any other number, that number\n");
	printf("becomes your 'point' and you keep on rolling until\n");
	printf("you roll your point again (in which case you win)\n");
	printf("or a 7 (in which case you lose).\n");
}

/*
 * Function: PlayCrapsGame
 * Usage: PlayCrapsGame();
 * -----------------------
 * This function plays one game of craps.
 */

void PlayCrapsGame(void)
{
	int total, point;

	printf("\nHere we go!\n");
	total = RollTwoDice();
	if (total == 7 || total == 11) {
		printf("That's a natural.  You win.\n");
	}
	else if (total == 2 || total == 3 || total == 12) {
		printf("That's craps.  You lose.\n");
	}
	else {
		point = total;
		printf("Your point is %d.\n", point);
		while (TRUE) {
			total = RollTwoDice();
			if (total == point) {
				printf("You made your point.  You win.\n");
				break;
			}
			else if (total == 7) {
				printf("That's a seven.  You lose.\n");
				break;
			}
		}
	}
}

/*
 * Function: RollTwoDice
 * Usage: total = RollTwoDice();
 * -----------------------------
 * This function rolls two dice and returns their sum.  As part
 * of the implementation, the result is displayed on the screen.
 */

int RollTwoDice(void)
{
	int d1, d2, total;

	printf("Rolling the dice . . .\n");
	d1 = RandomInteger(1, 6);
	d2 = RandomInteger(1, 6);
	total = d1 + d2;
	printf("You rolled %d and %d -- that's %d.\n", d1, d2, total);
	return (total);
}

/*
 * Function: GetYesOrNo
 * Usage: if (GetYesOrNo(prompt)) . . .
 * ------------------------------------
 * This function asks the user the question indicated by prompt
 * and waits for a yes/no response.  If the user answers "yes"
 * or "no", the program returns TRUE or FALSE accordingly.
 * If the user gives any other response, the program asks
 * the question again.
 */

bool GetYesOrNo(string prompt)
{
	string answer;

	while (TRUE) {
		printf("%s", prompt);
		answer = GetLine();
		if (StringEqual(answer, "yes")) return (TRUE);
		if (StringEqual(answer, "no")) return (FALSE);
		printf("Please answer yes or no.\n");
	}
}

/* 
* Pigs game
* -------------------
* A dice game called Pigs. For further instructions
* look up the pigsInstructions function.
*/

/* Function prototypes */

void pigs(void);
void pigsInstructions(void);
void playPigsGame(void);
int humanTurn(int playerTotal);
int computerTurn(int totalScore);
int computerExtraRoll(int currentComputerScore);
void anyKey();


 /* 
 * Function: pigs
 * Usage: pigs();
 * -----------------------
 * The function asks the user if it wants instructions or not before the game is about to begin.
 * Its the start function for the Pigs Game.
 * The function also asks the user if he/she wants to play again after a finished game.
 */

void pigs(void) 
{
	system("cls");
	Randomize();
	if (GetYesOrNo("Would you like instructions? ")) {
		pigsInstructions();
	}
	while (TRUE) {
		playPigsGame();
		if (!GetYesOrNo("Would you like to play again? ")) break;
	}
}

/* 
* Function: pigsInstructions
* Usage: pigsInstructions();
* -----------------------
* The function welcomes the player to the game and gives instructions on the rules to Pigs.
*/

void pigsInstructions(void) 
{
	system("cls");
	printf("Welcome to the pigs game!\n\n");
	printf("To play pigs, you start by rolling a dice.\n");
	printf("If you roll a 1, you lose your turn and your points this round.\n");
	printf("If you roll a number between 2-6 you will collect points and\n");
	printf("you can either continue to play or to hold. If you choose to hold\n");
	printf("you will save your collected points from the round and then pass\n");
	printf("the next round to the computer.\n");
	printf("The first player who first gets 100 or over will win the game.\n\n");
	anyKey();
}

/* 
* Function: playPigsGame
* Usage: playPigsGame();
*  -----------------------
* This function plays one game of Pigs.
* The functions calls upon two different functions, the humanTurn and computerTurn functions.
*/

void playPigsGame(void)
{
	int humanTotal, computerTotal, humanResult, computerResult;
	humanTotal = 0;
	computerTotal = 0;
	while (TRUE) {
		humanResult = humanTurn(humanTotal);
		humanTotal += humanResult;
		if (humanTotal >= 100) {
			printf("Congrats you win!\n");
			anyKey();
			break;
		}
		system("cls");
		inGameTotalPointsPigs(humanTotal, computerTotal);
		anyKey();

		computerResult = computerTurn(computerTotal);
		computerTotal += computerResult;
		if (computerTotal >= 100) {
			printf("You loose, computer wins with the score of: %d\n", computerTotal);
			anyKey();
			break;
		}
		system("cls");
		inGameTotalPointsPigs(humanTotal, computerTotal);
	}
}

/* 
* Function: humanTurn
* Usage: humanTurn(int humanTotal);
* -----------------------
* This function plays one round for the user. The input is the users total score from the function playPigsGame.
* The output is the score for one round.
*/

int humanTurn(int humanTotal) 
{
	int currentHumanScore, dice;
	bool booleanchoice;
	currentHumanScore = 0;

	printf("Here we go, its your turn!\n");
	while (TRUE) {
		booleanchoice = GetYesOrNo("Do you want to roll? (yes = roll, no = hold).\n");
		if (booleanchoice == TRUE){
			printf("Rolling the dice . . .\n");
			dice = rollOneDice();
			printf("You rolled %d! \n", dice);
			if (dice != 1){
				currentHumanScore += dice;
				printf("Your current turn score is: %d\n", currentHumanScore);
			} else {
				printf("You lose your current score.\n\n");
				anyKey();
				return(0);
			}
		} else if (booleanchoice == FALSE) {
			printf("\nYou finished this round with this amount of points: %d \n\n", currentHumanScore);
			anyKey();
			return(currentHumanScore);
		}
	}
}

/*
* Function: computerTurn
* Usage: computerTurn(int computerTotal);
* -----------------------
* This function plays one round for the computer. The input is the computers total score from the function playPigsGame.
* The output is the score for one round.
* If the computer had two succesful rolls, it calls for the function computerExtraRoll.
*/

int computerTurn(int computerTotal) 
{
	int currentComputerScore, rolls, chance, dice;
	rolls = 0;
	currentComputerScore = 0;
	printf("The computers turn!\n\n");

	while (TRUE) {
		if (rolls < 2) {
			printf("Rolling the dice. . .\n");
			dice = rollOneDice();
			printf("The computer rolled %d!\n", dice);
			if (dice != 1) {
				currentComputerScore += dice;
				printf("The computers current score is %d!\n", currentComputerScore);
				anyKey();
				rolls++;
			} else {
				printf("The computer just lost its current score!\n");
				anyKey();
				currentComputerScore = 0;
				return(currentComputerScore);
			}
		} else if (rolls >= 2) {
			chance = RandomInteger(1, 2);
			if (chance == 2) {
				return(computerExtraRoll(currentComputerScore));
			} else {
				return(currentComputerScore);
			}
		} else {
			return(currentComputerScore);
		}

	}
}

/*
* Function: computerExtraRoll
* Usage: computerExtraRoll(int currentComputerScore);
* -----------------------
* This function plays one extra round for the computer. The input is the computers current score from the function computerTurn.
* The output is the score for one extra roll.
*/

int computerExtraRoll(int currentComputerScore)
{
	int dice;
	printf("Rolling the dice...\n");
	dice = rollOneDice();
	printf("The computer rolled %d!\n", dice);
	if (dice != 1) {
		currentComputerScore += dice;
		printf("The computers current score is %d!\n", currentComputerScore);
		anyKey();
		return(currentComputerScore);
	} else {
		currentComputerScore = 0;
		printf("The computer lost its current score\n");
		anyKey();
		return(currentComputerScore);
	}
}

/*
* Function: rollOneDice
* Usage: rollOneDice();
* -----------------------
* This function rolls one dice (a random integer between 1-6)
*/

int rollOneDice(void)
{
	int dice;
	dice = RandomInteger(1, 6);
}

/*
* Function: anyKey
* Usage: anyKey();
* -----------------------
* This function requests a key press from the user to continue.
*/

void anyKey() 
{
	printf("Press any key to continue: ");
	getchar();
}

/*
* Function: inGameTotalPointsPigs
* Usage: inGameTotalPointsPigs(int humanTotal, int computerTotal);
* -----------------------
* This function displays the total amount of points for both the computer and user.
*/

int inGameTotalPointsPigs(int humanTotal, int computerTotal)
{
	printf("			################################################################\n");
	printf("			#                                                              #\n");
	printf("				   Your total: %d		Computer Total: %d         \n", humanTotal, computerTotal);
	printf("			#                                                              #\n");
	printf("			################################################################\n\n");
}

/*
* Two Dice Pigs game
* -------------------
* A dice game called Two Dice Pigs. For further instructions
* look up the twoDicePigsInstructions function.
*/


/* Function prototypes */

void playTwoDicePigs(void);
void twoDicePigsInstructions(void);
int twoDicePigsHumanTurn(int humanTotal);
int twoDicePigsComputerTurn(int computerTotal);
int twoDicePigsComputerExtraRoll(int currentComputerScore);
int inGameTotalPointsPigs(int humanTotal, int computerTotal);

/*
 * Function: twoDicePigs
 * Usage: twoDicePigs();
 * -----------------------
 * The function asks the user if it wants instructions or not before the game is about to begin.
 * Its the start function for the Two Dice Pigs Game.
 * The function also asks the user if he/she wants to play again after a finished game.
 */

void twoDicePigs(void)
{
	system("cls");
	Randomize();
	if (GetYesOrNo("Would you like instructions? ")) {
		twoDicePigsInstructions();
	}
	while (TRUE) {
		playTwoDicePigs();
		if (!GetYesOrNo("Would you like to play again? ")) break;
	}
}

/*
* Function: twoDicePigsInstructions
* Usage: twoDicePigsInstructions();
* -----------------------
* The function welcomes the player to the game and gives instructions on the rules to Two Dice Pigs.
*/

void twoDicePigsInstructions(void) 
{
	system("cls");
	printf("Welcome to the two dice pigs game!\n\n");
	printf("To play pigs, you start by rolling two dices.\n");
	printf("If one of your dices is the number 1, then you'll loose your turn and current points this round.\n");
	printf("Else if both your dices is the number 1, then you'll loose both your total and current score.");
	printf("If you roll two numbers between 2-6 you will collect points and\n");
	printf("you can either continue to play or to hold. If you choose to hold\n");
	printf("you will save your collected points from the round and then pass\n");
	printf("the next round to the computer.\n");
	printf("The first player who first gets 100 or above will win the game.\n\n");
	anyKey();
}

/*
* Function: playTwoDicePigs
* Usage: playTwoDicePigs();
*  -----------------------
* This function plays one game of Two Dice Pigs.
* The functions calls upon two different functions, the twoDicePigsHumanTurn and twoDicePigsComputerTurn functions.
*/

void playTwoDicePigs(void)
{
	int humanTotal, computerTotal, humanResult, computerResult;
	humanTotal = 0;
	computerTotal = 0;

	while (TRUE) {
		humanResult = twoDicePigsHumanTurn(humanTotal);
		humanTotal += humanResult;
		if (humanTotal >= 100) {
			printf("Congrats you win!\n");
			anyKey();
			break;
		} else if (humanResult == -1) {
			humanTotal = 0;
		}
		system("cls");
		inGameTotalPointsPigs(humanTotal, computerTotal);
		anyKey();

		computerResult = twoDicePigsComputerTurn(computerTotal);
		computerTotal += computerResult;

		if (computerTotal >= 100) {
			printf("You loose, computer wins with the score of: %d\n", computerTotal);
			anyKey();
			break;
		} else if (computerResult == -1) {
			computerTotal = 0;
		}
		system("cls");
		inGameTotalPointsPigs(humanTotal, computerTotal);
	}
}

/*
* Function: twoDicePigsHumanTurn
* Usage: twoDicePigsHumanTurn(int humanTotal);
* -----------------------
* This function plays one round for the user. The input is the users total score from the function playTwoDicePigs.
* The output is the score for one round.
*/

int twoDicePigsHumanTurn(int humanTotal) 
{
	int currentHumanScore, d1, d2;
	bool booleanchoice;
	currentHumanScore = 0;

	printf("Here we go, its your turn!\n");
	while (TRUE) {
		booleanchoice = GetYesOrNo("Do you want to roll? (yes = roll, no = hold).\n");
		if (booleanchoice == TRUE) {
			d1 = rollOneDice();
			d2 = rollOneDice();
			printf("Rolling the dices . . .\n");
			printf("You rolled %d and %d! \n", d1, d2);
			if (d1 == 1 && d2 == 1) {
				printf("You loose both your total and current score...\n");
				anyKey();
				return(-1);
			} else if (d1 == 1 || d2 == 1) {
				printf("You loose your current score...\n");
				anyKey();
				return(0);
			} else {
				currentHumanScore += (d1 + d2);
				printf("Your current turn score is %d!\n", currentHumanScore);
			}

		} else if (booleanchoice == FALSE) {
			printf("\nYou finished this round with: %d, amount of points. \n\n", currentHumanScore);
			anyKey();
			return(currentHumanScore);
		}
	}
}

/* Funktion: twoDicePigsComputerTurn
 *  -----------------------
 *  Funktionen representerar datorns tur att slå tärningen.
 *  Datorn kastar alltid minst två gånger, om den inte får en 1:a, två 1:or. Då returneras 0 respektive -1 till funktionen playPigsGame.
 *  Om datorn kastat två gånger utan att slå en 1:a så avgörs det med 50% chans om den returnerar den nuvarande vinsten
 *  eller att kasta igen. Väljer den att kasta igen, så anropas funktionen twoDicePigsComputerExtraRoll.
 */

int twoDicePigsComputerTurn(int computerTotal) 
{
	int currentComputerScore, rolls, chance, d1, d2;
	rolls = 0;
	currentComputerScore = 0;
	printf("The computers turn!\n\n");
	while (TRUE) {
		if (rolls < 2) {
			printf("Rolling the dice. . .\n");
			d1 = rollOneDice();
			d2 = rollOneDice();
			printf("The computer rolled %d! and %d\n", d1, d2);
			if (d1 == 1 && d2 == 1){
				printf("The computers lost its current and total score!\n");
				anyKey();
				return(-1);
			} else if (d1 == 1 || d2 == 1) {
				printf("The computer lost its current score...\n");
				anyKey();
				return(0);
			} else {
				currentComputerScore += (d1 + d2);
				printf("The computers current turn score is %d!\n", currentComputerScore);
				anyKey();
				rolls++;
			}
		} else if (rolls >= 2) {
			chance = RandomInteger(1, 2);
			if (chance == 2) {
				return(twoDicePigsComputerExtraRoll(currentComputerScore));
			} else {
				return(currentComputerScore);
			}
		}
	}
	anyKey();
}

/*
* Function: twoDicePigsComputerExtraRoll
* Usage: twoDicePigsComputerExtraRoll(int currentComputerScore);
* -----------------------
* This function plays one extra round for the computer. The input is the computers current score from the function twoDicePigsComputerTurn.
* The output is the score for one extra roll.
*/

int twoDicePigsComputerExtraRoll(int currentComputerScore)
{
	int d1, d2;
	printf("Rolling the dices...\n");
	d1 = rollOneDice();
	d2 = rollOneDice();
	printf("The computer rolled %d! and %d\n", d1, d2);
	if (d1 == 1 && d2 == 1) {
		printf("The computers lost its current and total score!\n");
		anyKey();
		return(-1);
	} else if (d1 == 1 || d2 == 1) {
		printf("The computer lost its current score...\n");
		anyKey();
		return(0);
	} else {
		currentComputerScore += (d1 + d2);
		printf("The computers current turn score is %d!\n", currentComputerScore);
		anyKey();
		return(currentComputerScore);
	}
}

/*
* Roulette Game
* -------------------
* A Roulette game with simplified rules, look up the function rouletteInstructions for further instructions.
*/

/* Function prototypes */

void rouletteInstructions(void);
void rouletteChoice(void);
void europeanRoulette(void);
int playEuropeanRoulette(int number1, int number2, int bet);
void americanRoulette(void);
int playAmericanRoulette(int number1, int number2, int bet);
int quitGame(void);

/*
* Function: roulette
* Usage: roulette();
* -----------------------
* The function asks the user if it wants instructions or not before the game is about to begin.
* Its the start function for the Roulette Games.
* The function also asks the user if he/she wants to play again after a finished game.
*/

void roulette(void)
{
	system("cls");
	Randomize();
	if (GetYesOrNo("Would you like instructions? ")) {
		rouletteInstructions();
	}
	while (TRUE) {
		rouletteChoice();
		if (!GetYesOrNo("Are you sure you don't want to keep playing? Type no to head back to the main menu, yes to continue.\n")) break;
	}
}

/*
* Function: rouletteInstructions
* Usage: rouletteInstructions();
* -----------------------
* The function welcomes the player to the game and gives instructions on the rules to the Roulette games.
*/

void rouletteInstructions(void) 
{
	system("cls");
	printf("Welcome to the roulette game!\n\n");
	printf("You'll have two options which consists of two types of roulettes, the European and American type.\n");
	printf("\nThe European Roulette\n");
	printf("You'll first choose a total amount in dollars to play with between 100$ and 10.000$.\n");
	printf("The next part is to choose one or two numbers between 0-36 to bet on.\n");
	printf("You'll always have to enter two numbers, so if you want to bet on one,\n");
	printf("please enter it twice. Else if you want to bet on two different numbers,\n");
	printf("just enter these two different numbers in numerical order.\n");
	printf("Then you'll have to place a bet before the wheel starts to spin, and the bet\n");
	printf("can't be higher then your total amount.\n");
	printf("If took a bet on two different numbers and one matched the number that the wheel stopped at,\n");
	printf("then your bet will be rised by 17, and it'll be added to your total amount.\n");
	printf("If you took a bet on one number and it matched with the number that the wheel stopped at,\n");
	printf("then your bet will be rised by 17, and it'll be added to your total amount.\n");
	printf("Else you will loose your bet if you didn't get a match, and it will be dragged away from your total amount.\n");
	printf("\nThe American Roulette\n");
	printf("It's basicaly the same. The different part is that the wheel consists of 38 fields instead of 37\n");
	printf("and have two 0 fields.");
	printf("So the difference is if you took a bet on the number 0, and the wheel also stopped at 0,\n");
	printf("then your bet will be rised by 17, and it'll be added to your total amount.\n");
	printf("But it's the same rules apart from that.\n");
	printf("\nGood luck!\n\n");
	anyKey();
}

/*
* Function: rouletteChoice
* Usage: rouletteChoice();
* -----------------------
* Gives the user three options, to play European Roulette, American Roulette or to quit to the function roulette.
*/

void rouletteChoice(void)
{
	bool choice;
	int answer, x;
	while (TRUE) {
		system("cls");
		printf("Which type of roulette would you like to play?\n\n");
		printf("		Enter 1 for European Roulette\n");
		printf("		Enter 2 for American Roulette\n");
		printf("		Enter 0 to quit the game...\n");
		printf("Your choice?\n");

		int answer = GetInteger();
		switch (answer)
		{
		case 1:
			europeanRoulette();
			break;
		case 2:
			americanRoulette();
			break;
		case 0:
			return(FALSE);
		default:
			system("cls");
			printf("Invalid input, please enter a number between 1-2\n");
			break;
		}
	}
}

/*
* Function: europeanRoulette
* Usage: europeanRoulette();
* -----------------------
* The function asks the user for a total amount of money to play with, and number/numbers to bet on, and also
* how much money he/she wanna bet on the number/numbers.
* The function asks the user if he/she wanna quit the game and return to the function roulettChoice
* after each turn.
* Calls for the function playEuropeanRoulette.
*/

void europeanRoulette(void)
{
	int totalAmount, number1, number2, bet, returnBet, quitOrContinue;

	system("cls");
	printf("Welcome to european roulette! Enter a total amount of money you want to play with. \nChoose an amount between 100$ and 10.000$\n");
	totalAmount = GetInteger();
		if (totalAmount < 100 || totalAmount > 10000) {
			printf("Invalid input, please enter a correct amount of money.\n");
			anyKey();
			return(europeanRoulette());
		}

	while (TRUE) {
		if (totalAmount == 0) {
			system("cls");
			printf("You dont have any money left!\n");
			anyKey();
			break;
		}

		system("cls");
		inGameTotalAmount(totalAmount);
		printf("Which numbers between 0-36 do you want to bet on?\n");
		printf("If you want to bet on one number, please enter the same number twice below, else choose two different numbers!\n");
		printf("First number: ");
		number1 = GetInteger();
		printf("Second number: ");
		number2 = GetInteger();
		printf("How much do you want to bet?\n");
		bet = GetInteger();

		if (totalAmount < bet) {
			inGameTotalAmount(totalAmount);
			printf("You can't bet higher then your total amount... Try again!\n");
			anyKey();
			continue;
		}
		
		returnBet = playEuropeanRoulette(number1, number2, bet);

		if (returnBet == bet) {
			system("cls");
			totalAmount -= bet;
			inGameTotalAmount(totalAmount);
			printf("You loose this round...\n\n", totalAmount);
			quitOrContinue = quitGame();
			if (quitOrContinue == 0) {
				break;
			} else {
				continue;
			}
			anyKey();
		} else if (returnBet == bet * 35) {
			system("cls");
			totalAmount += returnBet;
			inGameTotalAmount(totalAmount);
			printf("Congratz you won! \n", totalAmount);
			quitOrContinue = quitGame();
			if (quitOrContinue == 0) {
				break;
			}
			else {
				continue;
			}
			anyKey();
		} else if (returnBet == bet * 17) {
			system("cls");
			totalAmount += returnBet;
			inGameTotalAmount(totalAmount);
			printf("Congratz you won!\n", totalAmount);
			quitOrContinue = quitGame();
			if (quitOrContinue == 0) {
				break;
			}
			else {
				continue;
			}
			anyKey();
		}
	}
}

/*
* Function: playEuropeanRoulette
* Usage: playEuropeanRoulette(int number1, int number2, int bet);
* -----------------------
* Plays one turn of European Roulette. Returns the value to the function europeanRoulette, either if the user
* wins or not.
*/

int playEuropeanRoulette(int number1, int number2, int bet) 
{
	int randomNumber;
	randomNumber = RandomInteger(0, 36);
	printf("\nIts rolling...\n");
	printf("It stopped at %d!\n\n", randomNumber);
	anyKey();

	if (number1 == randomNumber && number2 == randomNumber) 
	{
		bet *= 35;
		return(bet);
	} else if (number1 == randomNumber || number2 == randomNumber) {
		bet *= 17;
		return(bet);
	} else {
		return(bet);
	}
}

/*
* Function: americanRoulette
* Usage: americanRoulette();
* -----------------------
* The function asks the user for a total amount of money to play with, and number/numbers to bet on, and also
* how much money he/she wanna bet on the number/numbers.
* The function asks the user if he/she wanna quit the game and return to the function roulettChoice
* after each turn.
* Calls for the function playAmericanRoulette.
*/

void americanRoulette(void) 
{
	int totalAmount, number1, number2, bet, returnBet, quitOrContinue;

	system("cls");
	printf("Which total amount of money do you want to play with? Choose an amount between 100$ and 10.000$\n");
	totalAmount = GetInteger();
	if (totalAmount < 100 || totalAmount > 10000) {
		printf("Invalid amount, please enter an amount between 100$-10000$.\n");
		anyKey();
		return(americanRoulette());
	}

	while (TRUE) {
		if (totalAmount == 0) {
			system("cls");
			printf("You dont have any money left!\n");
			anyKey();
			break;
		}

		system("cls");
		inGameTotalAmount(totalAmount);
		printf("Which numbers between 0-36 do you want to bet on?\n");
		printf("If you want to bet on one number, please enter the same number twice below, else choose two different numbers!\n");
		printf("First number: ");
		number1 = GetInteger();
		printf("Second number: ");
		number2 = GetInteger();
		printf("How much do you want to bet?\n");
		bet = GetInteger();

		if (totalAmount < bet) {
			inGameTotalAmount(totalAmount);
			printf("You can't bet higher then your total amount...\n");
			printf("Try again!\n");
			anyKey();
			continue;
		}

		returnBet = playAmericanRoulette(number1, number2, bet);

		if (returnBet == bet) {
			system("cls");
			totalAmount -= bet;
			inGameTotalAmount(totalAmount);
			printf("You loose this round...\n\n", totalAmount);
			quitOrContinue = quitGame();
			if (quitOrContinue == 0) {
				break;
			}
			else {
				continue;
			}
			anyKey();
		} else if (returnBet == bet * 35) {
			system("cls");
			totalAmount += returnBet;
			inGameTotalAmount(totalAmount);
			printf("Congratz you won! \n", totalAmount);
			quitOrContinue = quitGame();
			if (quitOrContinue == 0) {
				break;
			}
			else {
				continue;
			}
			anyKey();
		} else if (returnBet == bet * 17) {
			system("cls");
			totalAmount += returnBet;
			inGameTotalAmount(totalAmount);
			printf("Congratz you won!\n", totalAmount);
			quitOrContinue = quitGame();
			if (quitOrContinue == 0) {
				break;
			}
			else {
				continue;
			}
			anyKey();
		}
	}
}

/*
* Function: playAmericanRoulette
* Usage: playAmericanRoulette(int number1, int number2, int bet);
* -----------------------
* Plays one turn of American Roulette. Returns the value to the function americanRoulette, either if the user
* wins or not.
*/

int playAmericanRoulette(int number1, int number2, int bet) 
{
	int randomNumber;
	randomNumber = RandomInteger(0, 37);
	printf("\nIts rolling...\n");

	if (randomNumber == 37) {
		randomNumber = 0;
		printf("It stopped at %d!\n\n", randomNumber);
		anyKey();
	} else {
		printf("It stopped at %d!\n\n", randomNumber);
		anyKey();
	}

	if (randomNumber > 0) {

		if (number1 == randomNumber && number2 == randomNumber) {
			bet *= 35;
			return(bet);
		} else if (number1 == randomNumber || number2 == randomNumber) {
			bet *= 17;
			return(bet);
		} else {
			return(bet);
		}
	} else if (randomNumber == 0) {
		if (number1 == 0 || number2 == 0) {
			bet *= 17;
			return(bet);
		} else if (number1 == 0 && number2 == 0) {
			bet *= 17;
			return(bet);
		} else {
			return(bet);
		}
	}
}

/*
* Function: quitGame
* Usage: quitGame();
* -----------------------
* The function gives the user an option to exit out or stay in a functions.
*/

int quitGame(void)
{
	while (TRUE) {
		bool answer;
		answer = GetYesOrNo("\nIf you don't want to continue this game type no, otherwise type yes!\n");
		if (answer == FALSE) {
			return(0);
		} else {
			return(1);
		}
	}
}

/*
* Function: inGameTotalAmount
* Usage: inGamTotalAmount(int totalAmount);
* -----------------------
* The function displays the total amount of money for the user.
*/

int inGameTotalAmount(int to talAmount) 
{
	printf("			################################################################\n");
	printf("			#                                                              #\n");
	printf("				   Your total amount at the moment is %d$!         \n", totalAmount);
	printf("			#                                                              #\n");
	printf("			################################################################\n\n");
}