/*
 * Board.cpp
 *
 *  Created on: Feb 13, 2023
 *      Author: victo
 */

#include "Board.hpp"
#include <iostream>
using namespace std;

Board::Board(char diff, bool d){
	level = diff;
	debug = d;
	wallStrength = 6;
	InitAll();
}
Board::Board(bool d){
	level = 'e';
	debug = d;
	wallStrength = 6;
	InitAll();
}
Board::Board(char diff, string name, bool d) {
	level = diff;
	debug = d;
	//mydog.name = name;
	//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
	//COMMENT the above line BACK IN AFTER YOU WRITE YOUR DOG CLASS
	wallStrength = 6;
	InitAll();
}
void Board::InitAll() {
	bool keepPlaying = true;
	/*********************************************************************/
	//FOR TESTING!!!
	// Here's where there's code for getting your initial methods working
	// Once you've got this part working, you can comment it out and then
	// just play the game.
	//
	// First:  Write and test printBoard following the instructions inside of
	// the printBoard Method below.  Then test it to make sure it's working
	// properly.
	printBoard();
	// Your output should be this:
	//		 _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
	//		| 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 |
	//		| 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 |
	//		| 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 |
	//		| 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 |
	//		| 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 |
	//		| 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 |
	//		| 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 |
	//		| 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 |
	//		| 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 |
	//		| 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 |
	//		| 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 |
	//		| 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 |
	//		| 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 |
	//		| 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 |
	//		| 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 |
	//		| 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 |
	//		| 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 |
	//		| 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 |
	//		| 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 |
	//		| 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 |
	//		 _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
	//
	//
	// Next:
	// Write the boardConfig Method using the instructions inside the BoardConfig
	// method below, and then test it.
	startx = 1;
	starty = 0;
	endx = 1;
	endy = size-1;
	boardConfig();
	//printBoard(); 99999999999999999999999
	// Your results should look something like the following (walls are random, so
	// yours will be unique:
//		 _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
//		|   |                           |   |     |
//		->D     |               |       |       E ->
//		|                       |       |   |     |
//		|               |               |   |     |
//		|   |   |       |       |                 |
//		|   |   |         _ _ _   _ _ _ _     _ _ |
//		|       |       |                         |
//		|   |           |               |         |
//		|   |                   |           |     |
//		|   _ _ |     _ _ _ _ _ _           | _   |
//		|       |               |       |         |
//		|   |   |                       |   |     |
//		|               |       |                 |
//		|   _     _ _   | _ _ _ |   _   _   _     |
//		|   |           |               |         |
//		|                                   |     |
//		|   |           |       |           |     |
//		|   |   |                                 |
//		|                       |                 |
//		|       |       |               |   |     |
//		 _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
//
	//
	// Next, let's write the addFood method to add food and print the board:
	level = 'e';
	addFood();
	//printBoard(); 9999999999999999999999999
	cout << "***************************************" << endl;
	boardConfig();
	level = 'm';
	addFood();
	//printBoard();  999999999999999999999999999
	cout << "***************************************" << endl;
	boardConfig();
	level = 'h';
	addFood();
	printBoard();//09999999999999999999999999999
	cout << "***************************************" << endl;
	// OUTPUT Should be something like this (note the different number of Food
	// items depending on the differing level of difficulty):
//		 _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
//		|       | F               F         |     |
//		->D     _ _ _ _ _ _ _ _   _   _     _   E ->
//		|       |   |                 F     |     |
//		|       |   |           F           |     |
//		|       |   |                 F     |     |
//		|       |   |                       | F   |
//		|     F |   |                 F           |
//		| _ _ _ | _ | _ F   _   _ _ _   _ _ _ _   |
//		|       |                           |     |
//		| _ _   _ _ | _ _ _ _ _   _ _     _ _   F |
//		|                                   |     |
//		| _ _ _   _ | _     _ _   _ F _ _ _ _   _ |
//		|           |                     F |     |
//		| _ _ _ |   |   _ _ _ _ _ _     _ _ _   _ |
//		|                 F                 |     |
//		| _ _   | _ | _     _   _ _ _ _ _ _ _ _   |
//		|       |   |         F F         F |     |
//		|       |       F                   |     |
//		|         F                         |     |
//		|     F |   |   F                   |     |
//		 _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
//	***************************************
//
//
//		 _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
//		|                               |   |   F |
//		->D _ _       _ _   | _     | _ _       E ->
//		|       |           |                     |
//		|                   |           |   |   F |
//		|       |                                 |
//		| _ F     _ _ _       F _ _ F _ | _     _ |
//		|       |           |       |       |     |
//		| _ _   _   F _ _     _   _ _   | _ |     |
//		|       |               F   |   |   |     |
//		|       |   F                       |     |
//		|                   |   F   |           F |
//		| _     _   _   _         _ | _ _ _ _ F   |
//		|       |   F       |       |   |   |     |
//		|       |           |       |   |       F |
//		|                           |       |   F |
//		|       |           |                     |
//		|     F             |     F   F |   |     |
//		|                               |         |
//		|       |                   |             |
//		| F                                       |
//		 _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
//	***************************************
//
//
//		 _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
//		|       F       F           |             |
//		->D _ _ _       _     _ _ _ | _ _ _ _ _ E ->
//		|       |                   |             |
//		|                                 F       |
//		|       |                   |   F         |
//		| _   _ | _ _ _ _   _ _ _ _ _ _       _   |
//		|       |                   |             |
//		|     _ | _ _   _ _ _ _ _ _ | _     _ _ _ |
//		|       |                   |       F     |
//		| _   _ _ _   _     _   _ _ | _ _ _   _ _ |
//		|       |               F   |             |
//		| _ _   | _ _     _ F _   _ _ _ _ _ _   _ |
//		|     F |                                 |
//		|       |                   | F           |
//		|                     F     |             |
//		| _ _   | _   _   _ _ _ _ _ _ _   _ _     |
//		|       |               F   | F           |
//		| _ _   |   _ _ _ _   _ _ _ _ _ _   _     |
//		|     F       F                           |
//		|                   F     F |             |
//		 _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
//	***************************************

	//Once you have this working, you must add the traps. Write the addTraps
	// method, as described below.  Your output should be as follows:


	level = 'e';
	addFood();
	addTraps();
	//printBoard();99999999999999999999999999999
	cout << "***************************************" << endl;
	boardConfig();
	level = 'm';
	addFood();
	addTraps();
	//printBoard();99999999999999999999999999999999
	cout << "***************************************" << endl;
	boardConfig();
	level = 'h';
	addFood();
	addTraps();
	//printBoard();999999999999999999999999999999999
	cout << "***************************************" << endl;
	// Your output should look something like this:
//		 _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
//		|           F F   F | F | F   F     |     |
//		->D   _ _ _ _       _ _ _     _ _ _ _ _ E ->
//		|   F     F         |   |           |     |
//		|     F       T     |           F   |     |
//		|   F   |           |     T               |
//		|   _   | _     _ _ _ _ _ _ _ _     _ _ _ |
//		|             F     |   |           |     |
//		| _ _ _ | F _     _ | _ _ _ _   _   _ _ _ |
//		|       |       T       |         T | F   |
//		|             F     F   |           |     |
//		|   F   |           | F |     F     |     |
//		|       |   F   F   |   |   T F     | T   |
//		|     F | F     F       |           |     |
//		| _ _ _ | _   _ _ _ F _ | _   _   _ _ _   |
//		|       | F         | F |                 |
//		| _ _ _ | _ _ _ _ _ |   _ _     _     _ _ |
//		|       |               |           |     |
//		| T F   | F         |   |       F F |     |
//		| T     |           |         F     |     |
//		|   F     F T       |   |   F T     |     |
//		 _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
//	***************************************
//
//
//		 _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
//		|       |       F       |                 |
//		->D _ _ _   | _   _ | _     T   _   _   E ->
//		| T         |       |         T |   | T   |
//		|   F   |   |     F   F         |         |
//		|           |           |     T           |
//		|       | F         |           |   |     |
//		|                   |   |       |   | F   |
//		| _ F _       _ F   | _ F   _   _ _ | _ _ |
//		|       |                   F             |
//		|                   |   | T     |   |     |
//		|       |           |           |   F     |
//		|       |   |       T                     |
//		|             F         |               T |
//		| _     | _ |     _ _ _   _   _ _ _ |     |
//		|           |           |       F       F |
//		|           |           |       | T       |
//		|       | T |       |               |   F |
//		|       |     T     |   |     F     F     |
//		|                       F       |   |     |
//		|                       |       | T |     |
//		 _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
//	***************************************
//
//
//		 _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
//		|   |       F   |   F   T       |   |     |
//		->D |           |   T       |           E ->
//		|                         T     |   |     |
//		| _ |   _ _     _ _ _ _     _   _ _ _ _ _ |
//		|   |           |           |   |   |     |
//		| _ | _ _   _ _ _ _ _ _ _   _   _   | F _ |
//		|   | F         | T         F   |         |
//		|   |     F     |           |   |   | T   |
//		|   |           |   T       |   |   |     |
//		|   |   _ _   _ _ _ _ _ _ _ _   _ _ _     |
//		|     T   F T   |     F     |   |         |
//		| _ | _ _ T _ _ |   _ _ _ _ |   _ _   _ _ |
//		| F | T         |           |   |   |     |
//		|             F     T               |     |
//		|                     T     |   |   |     |
//		|   |     T     |           | F |   |     |
//		|   |           |         F | F |   |   F |
//		|         T           F     |   |     F   |
//		|               |           |       |     |
//		|               |           |   |   |     |
//		 _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
//	***************************************
//
// ****************************************************************************
//  Part 2:
//  Dog.hpp and Dog.cpp
// *****************************************************************************
//	Now you'll have to write the Dog class and header file before you can write'
//	and test the moveDog method.
//  The instructions for this are below the Board.hpp and Board.cpp files in the
//  lab instructions.
//	Once you are done writing the Dog class and header, you'll need to do the '
//	uncomment out (comment in?) the following
//	 * 1) in the .hpp class, you'll have to comment in the Dog myDog line Board.hpp
//	 * (it's around line 47)
//	 * 2) In the 3rd Board Constructor, you'll need to comment in the mydog.name line
//	 *  (it's around line 37 in this file)
//	 * 3) And you'll have add to your printBoard method a line for printing out
//	 *    the dog object's name and the dog object's strength.
//
// And now write moveDog() as described inside the  moveDog method, below.
// Once done, uncomment out the following 4 lines and test with the following code:
//	moveDog('d');
//	moveDog('u');
//	moveDog('r');
//	moveDog('l');
	// your dog should move down, up, right, and then left.  If you hit a food
	// or a trap, you should get a message as described in the moveDog method, below.





	/*********************************************************************/
	//End of Testing.  Now comment out the above testing stuff, and
	// comment in the rest of the init method, below
	/*********************************************************************/


	/**********************************************************************/
	/* PART THREE
	 * COMMENT OUT THE ABOVE TESTING CODE AND COMMENT IN THE BELOW CODE TO RUN
	 * THE GAME.
	 */
	/*
	while (keepPlaying) {
		cout << "What level of difficulty do you want (e, m, or h)?" << endl;
		char c;
		cin >> c;
		level = c;
		startx = rand() % size;
		starty = 0;
		endx = rand() % size;
		endy = size-1;

		mydog.x = startx;
		mydog.y = starty;
		boardConfig();
		addFood();
		addTraps();
		printBoard();
		playGame();

		cout << "Play again? " << endl;
		string s = "no";
		cin>>s;
		if (s == "yes" || s == "Yes" || s == "Y" || s == "y") {
			keepPlaying = true;
			mydog.reset();
		}
		else {
			cout <<"Thanks for playing!" << endl;
			keepPlaying = false;
		}
	}
	*/
}


/***********************************************************************/
/* HERE'S WHERE THE CODE GOES!                                         */
/***********************************************************************/

void Board::printBoard() {
	//(8 pts)
	//Instructions for this method:
//	 this method first uses the dog's printDog method to print out info
//	 about the dog, and then it prints out the board as follows:
//	 *
//	 This method prints out the board such that it looks like a board.  It
//	 prints a blank space for any square (for squares that do not have
//	 food, traps, walls, the dog, and aren't the beginning or the ending.
//   (at first, there will be no food or traps, or even walls or dog, but we
//   will be adding food as 'F' character, traps as 'T' character, walls as
//   '|' or '_' characters, and the dog 'D' character to the board, so you want
//   to print a space for everything that isn't a 'T','F','|','_',or'D'.
//	 Otherwise it prints out the character in the square. Note that I printed a
//	 border around the entire board so it was easier to look at, and, equally,
//	 I placed an -> arro (thats a minus and a greater than sign) in the border
//	 for where the beginning of the game was and where the end of the game was.

	//dog stuff goes here first

	//print top dashed lines
	for(int i = 0; i<21; i++){
		cout<<" _";
	}
	cout<<endl;

	//print array board
	for(int i = 0; i<size;i++){
		cout<<"/";
		for(int j = 0; j<size;j++){
			cout<<" ";
			cout<< board[i][j];
		}cout<<" /";

		cout<<endl;
	}

	//print bottom dashed lines
	for(int i = 0; i<21; i++){
			cout<<" _";
		}
		cout<<endl;

//mydog.printDog();  // COMMENT THIS IN WHEN YOU Write your Dog class!!

}

void Board::boardConfig() {
	//(8 pts)
	//Instructions for writing boardConfig:
	/* this method and the moveDog method are probably the longest methods.
	 * This method first puts dummy values in every square (I used '+' - I just didn't want
	 * every square to have gibberish, so I chose a character I wasn't using for any other
	 * purpose and initialized every square to have that value).
	 * I then added my random horizontal and vertical walls.
	 *
	 * Here's how I did it the walls:
	 *
	 * I only placed walls in the odd numbered rows and columns (in other words, row one might
	 * have a row, but then row 2 would not, whereas row three could and row 4 could not.
	 * Same with columns (although you can have flexibility.
	 *
	 * I picked an odd row or column that did not already have a wall in it at all.
	 *
	 * I generated a total of 10 walls.

	 * For each wall, I picked randomly for vertical or horizontal (just rand() % 2 to get either
	 * 0 for vertical, 1 for horizontal.
	 *
	 * I set the easy version to have at most 9 squares in a row or column as a wall, the
	 * medium to have at most 13 squares as walls in a row or column, and the hard version to
	 * have at most 16 squares per row or column.(but you can play with this because sometimes
	 * the hard version was seriously hard!!!
	 *
	 * Let's say I randomly decided to place a wall in row 3.  I then randomly chose 9 squares in
	 * row 3 to be a wall (if it was the easy version, 13 if it was the medium, and 16 if it was
	 * the hard)
	 *
	 * So that's the walls.  Then I added the 'D' to the beginning square nad an 'E' to the end square.
	 *
	 *
	 */


}


void Board::addFood() {
	// (5 pts)
	/* Instructions for writing addFood:
	/* this method randomly adds food around the board.  For easy, I added the field size
	 * number of foods randomly around the board.  For medium, I added size-2 foods, and for
	 * hard I added size-4 foods.  The amount of strength the dog gets when they eat (aka
	 * move onto) the food is determined in the moveDog method.
	 */


}

void Board::addTraps() {
	// (5 pts)
	//Instructions for addTraps
	/* this method randomly adds traps around the board.  For easy I added size - 6 traps,
	 * for medium, I added size - 8 traps, and for hard I added size - 10 traps.  Note: Traps are
	 * only printed on the board when the game is in debug mode.  The amount of strength each trap
	 * saps from the dog is determined in the moveDog method when the dog moves on a Trap.
	 */


}


bool Board::moveDog(char c) {
	// (12 pts)
	//Instructions for moveDog
	/* This is a somewhat long method.
		 * First, it determines the new coordinats of the dog, based on teh direction in which the
		 * dog wants to move (based on what c holds - u is up, d is down, l is left, r is right).
		 *
		 * If the dog is at teh edge of the board, teh dog should not move
		 *
		 * If the dog moves over food, a random number between 2 and 17 is generated, and the
		 * dog's changeStrength method is used to increase the dog's strength by the random amount.
		 *
		 * If the dog moves over the end of the board, the dog's won method is called and false is
		 * returned from this method.
		 *
		 * If the dog moves over a Trap, a random number between 2 and 17 is generated and the dog's
		 * changeStrength method is called with that negative number.  (Note that the changeStrength
		 * method returns a boolean indicating whether the dog's strength has gone to 0 or less, and
		 * thus the dog has died and the game is over. That boolean value is returned from this method).
		 *
		 * If the dog moves over a wall, the method checks to see if the dog has enough strength to
		 * knock down the wall (I made it cost 6 strength points to knock down a wall).  If the dog
		 * has enough strength, the user is asked, "Do you want to knock down that wall?"  If the user
		 * responds "yes", then the wall is knocked down, the dog moves into that square, adn the dog's
		 * strength decreases by 6.  If the answer is "no", the dog loses 1 strength point, just because.
		 *
		 * If the dog moves into a blank square, the dog loses 2 strength points using the changeStrength
		 * method (which, again, will return false if the dog has lost all their strength and died.
		 *
		 * NOTE: I am not concerned with the precise rules here.  If you want to change the range of
		 * random numbers for food, if you are worried about whether you still lose 2 strength points for
		 * moving even though you gained points for moving over food - I'm leaving all that to your preference.
		 * I am concerned that you are using classes, objects, and object methods and accessing object
		 * fields correctly!
		 *
		 */



}


void Board::playGame() {
	bool play = true;
	while (play) {
		cout << "Move (u, d, l, r) "<<endl;
		char c;
		cin >> c;
		play = moveDog(c);
		//printBoard();9999999999999999999999999999999
	}


}






