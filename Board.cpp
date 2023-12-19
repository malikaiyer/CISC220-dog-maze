/*
* class Definition
  author: Malika Iyer
*/
#include "Board.hpp"
#include <iostream>
#include <string.h>

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
	mydog.name = name;
	//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
	//COMMENT the above line BACK IN AFTER YOU WRITE YOUR DOG CLASS
	wallStrength = 6;
	InitAll();
}
void Board::InitAll() {
	bool keepPlaying = true;
// 	/*********************************************************************/
// 	//FOR TESTING!!!
// 	// Here's where there's code for getting your initial methods working
// 	// Once you've got this part working, you can comment it out and then
// 	// just play the game.
// 	//
// 	// First:  Write and test printBoard following the instructions inside of
// 	// the printBoard Method below.  Then test it to make sure it's working
// 	// properly.
// 	printBoard();
// 	// Your output should be this:
// 	//		 _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
// 	//		| 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 |
// 	//		| 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 |
// 	//		| 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 |
// 	//		| 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 |
// 	//		| 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 |
// 	//		| 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 |
// 	//		| 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 |
// 	//		| 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 |
// 	//		| 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 |
// 	//		| 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 |
// 	//		| 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 |
// 	//		| 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 |
// 	//		| 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 |
// 	//		| 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 |
// 	//		| 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 |
// 	//		| 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 |
// 	//		| 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 |
// 	//		| 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 |
// 	//		| 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 |
// 	//		| 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 |
// 	//		 _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
// 	//
// 	//
// 	// Next:
// 	// Write the boardConfig Method using the instructions inside the BoardConfig
// 	// method below, and then test it.
// 	startx = 1;
// 	starty = 0;
// 	endx = 1;
// 	endy = size-1;
// 	boardConfig();
// 	printBoard();
// 	// Your results should look something like the following (walls are random, so
// 	// yours will be unique:
// //		 _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
// //		|   |                           |   |     |
// //		->D     |               |       |       E ->
// //		|                       |       |   |     |
// //		|               |               |   |     |
// //		|   |   |       |       |                 |
// //		|   |   |         _ _ _   _ _ _ _     _ _ |
// //		|       |       |                         |
// //		|   |           |               |         |
// //		|   |                   |           |     |
// //		|   _ _ |     _ _ _ _ _ _           | _   |
// //		|       |               |       |         |
// //		|   |   |                       |   |     |
// //		|               |       |                 |
// //		|   _     _ _   | _ _ _ |   _   _   _     |
// //		|   |           |               |         |
// //		|                                   |     |
// //		|   |           |       |           |     |
// //		|   |   |                                 |
// //		|                       |                 |
// //		|       |       |               |   |     |
// //		 _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
// //
// 	//
// 	// Next, let's write the addFood method to add food and print the board:
// 	boardConfig();
// 	level = 'e';
// 	cout << "easy with addFood" << endl;
// 	addFood();
// 	printBoard();
// 	cout << "***************************************" << endl;
// 	boardConfig();
// 	level = 'm';
// 	cout << "medium with addFood" << endl;
// 	addFood();
// 	printBoard();
// 	cout << "***************************************" << endl;
// 	boardConfig();
// 	level = 'h';
// 	cout << "hard with addFood" << endl;
// 	addFood();
// 	printBoard();
// 	cout << "***************************************" << endl;
// 	// OUTPUT Should be something like this (note the different number of Food
// 	// items depending on the differing level of difficulty):
// //		 _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
// //		|       | F               F         |     |
// //		->D     _ _ _ _ _ _ _ _   _   _     _   E ->
// //		|       |   |                 F     |     |
// //		|       |   |           F           |     |
// //		|       |   |                 F     |     |
// //		|       |   |                       | F   |
// //		|     F |   |                 F           |
// //		| _ _ _ | _ | _ F   _   _ _ _   _ _ _ _   |
// //		|       |                           |     |
// //		| _ _   _ _ | _ _ _ _ _   _ _     _ _   F |
// //		|                                   |     |
// //		| _ _ _   _ | _     _ _   _ F _ _ _ _   _ |
// //		|           |                     F |     |
// //		| _ _ _ |   |   _ _ _ _ _ _     _ _ _   _ |
// //		|                 F                 |     |
// //		| _ _   | _ | _     _   _ _ _ _ _ _ _ _   |
// //		|       |   |         F F         F |     |
// //		|       |       F                   |     |
// //		|         F                         |     |
// //		|     F |   |   F                   |     |
// //		 _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
// //	***************************************
// //
// //
// //		 _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
// //		|                               |   |   F |
// //		->D _ _       _ _   | _     | _ _       E ->
// //		|       |           |                     |
// //		|                   |           |   |   F |
// //		|       |                                 |
// //		| _ F     _ _ _       F _ _ F _ | _     _ |
// //		|       |           |       |       |     |
// //		| _ _   _   F _ _     _   _ _   | _ |     |
// //		|       |               F   |   |   |     |
// //		|       |   F                       |     |
// //		|                   |   F   |           F |
// //		| _     _   _   _         _ | _ _ _ _ F   |
// //		|       |   F       |       |   |   |     |
// //		|       |           |       |   |       F |
// //		|                           |       |   F |
// //		|       |           |                     |
// //		|     F             |     F   F |   |     |
// //		|                               |         |
// //		|       |                   |             |
// //		| F                                       |
// //		 _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
// //	***************************************
// //
// //
// //		 _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
// //		|       F       F           |             |
// //		->D _ _ _       _     _ _ _ | _ _ _ _ _ E ->
// //		|       |                   |             |
// //		|                                 F       |
// //		|       |                   |   F         |
// //		| _   _ | _ _ _ _   _ _ _ _ _ _       _   |
// //		|       |                   |             |
// //		|     _ | _ _   _ _ _ _ _ _ | _     _ _ _ |
// //		|       |                   |       F     |
// //		| _   _ _ _   _     _   _ _ | _ _ _   _ _ |
// //		|       |               F   |             |
// //		| _ _   | _ _     _ F _   _ _ _ _ _ _   _ |
// //		|     F |                                 |
// //		|       |                   | F           |
// //		|                     F     |             |
// //		| _ _   | _   _   _ _ _ _ _ _ _   _ _     |
// //		|       |               F   | F           |
// //		| _ _   |   _ _ _ _   _ _ _ _ _ _   _     |
// //		|     F       F                           |
// //		|                   F     F |             |
// //		 _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
// //	***************************************

// 	//Once you have this working, you must add the traps. Write the addTraps
// 	// method, as described below.  Your output should be as follows:


// 	level = 'e';
// 	addFood();
// 	addTraps();
// 	printBoard();
// 	cout << "***************************************" << endl;
// 	boardConfig();
// 	level = 'm';
// 	addFood();
// 	addTraps();
// 	printBoard();
// 	cout << "***************************************" << endl;
// 	boardConfig();
// 	level = 'h';
// 	addFood();
// 	addTraps();
// 	printBoard();
// 	cout << "***************************************" << endl;
// 	// Your output should look something like this:
// //		 _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
// //		|           F F   F | F | F   F     |     |
// //		->D   _ _ _ _       _ _ _     _ _ _ _ _ E ->
// //		|   F     F         |   |           |     |
// //		|     F       T     |           F   |     |
// //		|   F   |           |     T               |
// //		|   _   | _     _ _ _ _ _ _ _ _     _ _ _ |
// //		|             F     |   |           |     |
// //		| _ _ _ | F _     _ | _ _ _ _   _   _ _ _ |
// //		|       |       T       |         T | F   |
// //		|             F     F   |           |     |
// //		|   F   |           | F |     F     |     |
// //		|       |   F   F   |   |   T F     | T   |
// //		|     F | F     F       |           |     |
// //		| _ _ _ | _   _ _ _ F _ | _   _   _ _ _   |
// //		|       | F         | F |                 |
// //		| _ _ _ | _ _ _ _ _ |   _ _     _     _ _ |
// //		|       |               |           |     |
// //		| T F   | F         |   |       F F |     |
// //		| T     |           |         F     |     |
// //		|   F     F T       |   |   F T     |     |
// //		 _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
// //	***************************************
// //
// //
// //		 _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
// //		|       |       F       |                 |
// //		->D _ _ _   | _   _ | _     T   _   _   E ->
// //		| T         |       |         T |   | T   |
// //		|   F   |   |     F   F         |         |
// //		|           |           |     T           |
// //		|       | F         |           |   |     |
// //		|                   |   |       |   | F   |
// //		| _ F _       _ F   | _ F   _   _ _ | _ _ |
// //		|       |                   F             |
// //		|                   |   | T     |   |     |
// //		|       |           |           |   F     |
// //		|       |   |       T                     |
// //		|             F         |               T |
// //		| _     | _ |     _ _ _   _   _ _ _ |     |
// //		|           |           |       F       F |
// //		|           |           |       | T       |
// //		|       | T |       |               |   F |
// //		|       |     T     |   |     F     F     |
// //		|                       F       |   |     |
// //		|                       |       | T |     |
// //		 _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
// //	***************************************
// //
// //
// //		 _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
// //		|   |       F   |   F   T       |   |     |
// //		->D |           |   T       |           E ->
// //		|                         T     |   |     |
// //		| _ |   _ _     _ _ _ _     _   _ _ _ _ _ |
// //		|   |           |           |   |   |     |
// //		| _ | _ _   _ _ _ _ _ _ _   _   _   | F _ |
// //		|   | F         | T         F   |         |
// //		|   |     F     |           |   |   | T   |
// //		|   |           |   T       |   |   |     |
// //		|   |   _ _   _ _ _ _ _ _ _ _   _ _ _     |
// //		|     T   F T   |     F     |   |         |
// //		| _ | _ _ T _ _ |   _ _ _ _ |   _ _   _ _ |
// //		| F | T         |           |   |   |     |
// //		|             F     T               |     |
// //		|                     T     |   |   |     |
// //		|   |     T     |           | F |   |     |
// //		|   |           |         F | F |   |   F |
// //		|         T           F     |   |     F   |
// //		|               |           |       |     |
// //		|               |           |   |   |     |
// //		 _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
// //	***************************************
// //
// // ****************************************************************************
// //  Part 2:
// //  Dog.hpp and Dog.cpp
// // *****************************************************************************
// //	Now you'll have to write the Dog class and header file before you can write'
// //	and test the moveDog method.
// //  The instructions for this are below the Board.hpp and Board.cpp files in the
// //  lab instructions.
// //	Once you are done writing the Dog class and header, you'll need to do the '
// //	uncomment out (comment in?) the following
// //	 * 1) in the .hpp class, you'll have to comment in the Dog myDog line Board.hpp
// //	 * (it's around line 47)
// //	 * 2) In the 3rd Board Constructor, you'll need to comment in the mydog.name line
// //	 *  (it's around line 37 in this file)
// //	 * 3) And you'll have add to your printBoard method a line for printing out
// //	 *    the dog object's name and the dog object's strength.
// //
// // And now write moveDog() as described inside the  moveDog method, below.
// // Once done, uncomment out the following 4 lines and test with the following code:
// //	moveDog('d');
// //	moveDog('u');
// //	moveDog('r');
// //	moveDog('l');
// 	// your dog should move down, up, right, and then left.  If you hit a food
// 	// or a trap, you should get a message as described in the moveDog method, below.


	/*********************************************************************/
	//End of Testing.  Now comment out the above testing stuff, and
	// comment in the rest of the init method, below
	/*********************************************************************/


	/**********************************************************************/
	/* PART THREE
	 * COMMENT OUT THE ABOVE TESTING CODE AND COMMENT IN THE BELOW CODE TO RUN
	 * THE GAME.
	 */
	
	while (keepPlaying) {
		cout << "To play this game, you will need to get your dog from one end of the board to the other. F = Food, P = Power Ups. You can break down walls and watch out for traps! What level of difficulty do you want (e, m, h, or x (extra hard))?" << endl; //adding extra hard
		char c;
		cin >> c;
		level = c;
		startx = rand() % size;
		starty = 0;
		// if(level=='e' || level=='m' || level=='h'){
		endx = rand() % size;  //}
		endy = size-1;

		mydog.x = startx;
		mydog.y = starty;
		boardConfig();
		addFood();
		addTraps();
		addPowerUps();
		printBoard();
		playGame();
		clearBoard();

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

mydog.printDog();  // COMMENT THIS IN WHEN YOU Write your Dog class!!
cout << " _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _" << endl;   
	for (int i = 0; i<20; i++){
		if (i == startx){
			cout << "->";
		}

		else if (i != startx){
			cout << " |";    
		}

		for (int j = 0; j<20; j++){
			if (board[i][j] != 'F' && board[i][j] != 'T' && board[i][j] != 'I' && board[i][j] != '_' && board[i][j] != 'D'
			 && board[i][j] != '|' && board[i][j] != 'P')
			{
				board[i][j] = ' ';
			}
			cout << board[i][j] << ' ';
        }

		if (i != endx){
			cout << "|" << endl;    
			}
		else if (i == endx){
			cout << "  ->" << endl;
			}
    } 
	cout << "  _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _" << endl;
	// cout<< "Dog name:" << mydog.name << endl;
	// cout<< "Dog Strength" << mydog.strength << endl;
	// mydog.printDog(); 
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

	bool repeat = true;
	int i=0;


	while(i<10){
		int wall = (1 + 2*rand())%20; //odd numbers
		int vertOrHoriz = rand()%2;
		// cout << "wall: " << wall << endl;
		// cout << "vert or horiz: " << vertOrHoriz << endl;
		i++;

		for(int j=0; j<20; j++){
			if (vertOrHoriz==0 && board[j][wall] == '|'){
				repeat = false;
				break;
			}
			else if (vertOrHoriz==1 && board[wall][j] == '_'){
				repeat = false;
				break;
			}
			else{
				repeat = true;
			}
		}
		// cout <<  "repeat: " << repeat << endl;

		if(repeat == true){
			if (level=='e'){
				for(int i=0; i<9; i++){
					int row = rand()%20;
						if(vertOrHoriz==0){  //0=vert 1=horiz
							board[row][wall] = '|';
							}
						else if(vertOrHoriz==1){  
							board[wall][row] = '_';
							}
				}
			}

			else if (level=='m'){
				for(int i=0; i<13; i++){
					int row = rand()%20;
					if(vertOrHoriz==0){  //0=vert 1=horiz
						board[row][wall] = '|';
						}
					else if(vertOrHoriz==1){  
						board[wall][row] = '_';
						}
				}
			}

			else if (level=='h' || level=='x'){
				for(int i=0; i<16; i++){
					int row = rand()%20;
					if(vertOrHoriz==0){  //0=vert 1=horiz
						board[row][wall] = '|';
						}
					else if(vertOrHoriz==1){  
						board[wall][row] = '_';
						}
				}
			}
		}

		else if (repeat==false){
			i--;
		}
	}
	board[startx][starty] = 'D';
}	


void Board::addFood() {
	// (5 pts)
	/* Instructions for writing addFood:
	/* this method randomly adds food around the board.  For easy, I added the field size
	 * number of foods randomly around the board.  For medium, I added size-2 foods, and for
	 * hard I added size-4 foods.  The amount of strength the dog gets when they eat (aka
	 * move onto) the food is determined in the moveDog method.
	 */
	if (level== 'e'){
		for (int x=0; x < size-1; x++){
			int i = rand()%20;
			int j = rand()%20;
			if(board[i][j] == '-' || board[i][j]== '|' || board[i][j] =='F' || (i==startx && j==starty)){
				x--;
			}
			else{
				board[i][j] = 'F';
			}
		}
	}
	else if (level== 'm'){
		for (int x=0; x < size-2; x++){
			int i = rand()%20;
			int j = rand()%20;
			if(board[i][j] == '-' || board[i][j]== '|' || board[i][j] =='F' || (i==startx && j==starty)){
				x--;
			}
			else{
				board[i][j] = 'F';
			}
			}
		}
	else if (level== 'h' || level=='x'){
		for (int x=0; x < size-4; x++){
			int i = rand()%20;
			int j = rand()%20;
			if(board[i][j] == '-' || board[i][j]== '|' || board[i][j] =='F' || (i==startx && j==starty)){
				x--;
			}
			else{
				board[i][j] = 'F';
			}
			}
		}
}

void Board::addTraps() {
	// (5 pts)
	//Instructions for addTraps
	/* this method randomly adds traps around the board.  For easy I added size - 6 traps,
	 * for medium, I added size - 8 traps, and for hard I added size - 10 traps.  Note: Traps are
	 * only printed on the board when the game is in debug mode.  The amount of strength each trap
	 * saps from the dog is determined in the moveDog method when the dog moves on a Trap.
	 */
	if (level=='e'){
		for (int x=0; x < 6; x++){
			int i = rand()%20;
			int j = rand()%20;
			if(board[i][j]=='F' || board[i][j] == '-' || board[i][j]== '|' || board[i][j] =='T' || (i==startx && j==starty)){
				x--;
			}
			else{
				board[i][j] = 'T';
			}
		}
		}
	else if (level== 'm'){
		for (int x=0; x < 8; x++){
			int i = rand()%20;
			int j = rand()%20;
			if(board[i][j]=='F' || board[i][j] == '-' || board[i][j]== '|' || board[i][j] =='T' || (i==startx && j==starty)){
				x--;
			}
			else{
				board[i][j] = 'T';
			}
		}
		}
	else if (level== 'h' || level=='x'){
		for (int x=0; x < 10; x++){
			int i = rand()%20;
			int j = rand()%20;
			if(board[i][j]=='F' || board[i][j] == '-' || board[i][j]== '|' || board[i][j] =='T' || (i==startx && j==starty)){
				x--;
			}
			else{
				board[i][j] = 'T';
			}
		}
		}

}

void Board::addPowerUps(){
	/*for Bonus points
	This method adds power ups to the board and gives the dog extra powers that it can reach to get to the end point.
	However, these powerups may also cause harm so choose carefully
	Power up 0: dog moves 2 steps at a time now
	Power up 1: dog's strength stays constant throughout
	Power up 2: dog's keys have flipped to be random
	Power up 3: End position constantly changes
	Power Up 4: Removes all the walls from the game
	*/
	if (level=='e'){
		for (int x=0; x < 5; x++){
			int i = (rand()%11)+4;
			int j = (rand()%11)+4;
			if(board[i][j]=='F' || board[i][j] == '-' || board[i][j]== '|' || board[i][j] =='T' || board[i][j] == 'P'){
				x--;
			}
			else{
				board[i][j] = 'P';
			}
		}
		}
	else if (level== 'm'){
		for (int x=0; x < 6; x++){
			int i = rand()%11+4;
			int j = rand()%11+4;
			if(board[i][j]=='F' || board[i][j] == '-' || board[i][j]== '|' || board[i][j] =='T' || board[i][j] == 'P'){
				x--;
			}
			else{
				board[i][j] = 'P';
			}
		}
		}
	else if (level== 'h' || level=='x'){
		for (int x=0; x < 7; x++){
			int i = rand()%11+4;
			int j = rand()%11+4;
			if(board[i][j]=='F' || board[i][j] == '-' || board[i][j]== '|' || board[i][j] =='T' || board[i][j] == 'P'){
				x--;
			}
			else{
				board[i][j] = 'P';
			}
		}
		}

}


bool Board::moveDog(char c) {
	// (12 pts)
	//Instructions for moveDog
	/* This is a somewhat long method.
		 * First, it determines the new coorindates of the dog, based on the direction in which the
		 * dog wants to move (based on what c holds - u is up, d is down, l is left, r is right).
		 *
		 * If the dog is at the edge of the board, the dog should not move
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

		// int mydog.x = startx; //row
		// int mydog.y = starty; //col
		board[mydog.x][mydog.y] = ' ';
		bool ret;

		if(level=='x'){  //ending changes every run for the x level
			endx = rand()%20;
		}

		if (c=='u'){
			mydog.x-=1;
		}
		else if (c=='d'){
			mydog.x+=1;
		}
		else if(c=='l'){
			mydog.y-=1;
		}
		else if(c=='r'){
			mydog.y+=1;
		}

		if(mydog.x==endx && mydog.y== (endy+1)){
			mydog.won(); 
			return false;
		}

		else if(mydog.x<0 || mydog.x>=20 || mydog.y<0 || mydog.y>=20){ //to make it not move when it is at the edge
			if (c=='u'){
				mydog.x+=1;
			}
			else if (c=='d'){
				mydog.x-=1;
			}
			else if(c=='l'){
				mydog.y+=1;
			}
			else if(c=='r'){
				mydog.y-=1;
			}
			ret = mydog.changeStrength(-2);
			board[mydog.x][mydog.y] = 'D';
		}

		else if (board[mydog.x][mydog.y]=='F'){ //changes strength by a random positive amt when stepped over food
			int amt = rand()%17+2;
			ret = mydog.changeStrength(amt);
			board[mydog.x][mydog.y] = 'D';
		}

		else if(board[mydog.x][mydog.y]=='T'){ //changes strength by a random negative amt when stepped over Trap
			int amt = rand()%17+2;
			ret = mydog.changeStrength(-1*amt);
			board[mydog.x][mydog.y] = 'D';
		}

		else if(board[mydog.x][mydog.y]=='|' || board[mydog.x][mydog.y]=='_' ){
			if(mydog.strength>wallStrength){
				cout << "Do you want to break down this wall? (y/n)" << endl;
				char ch;
				cin >> ch;
				if (ch=='y'){
					ret = mydog.changeStrength(-1*wallStrength);
					board[mydog.x][mydog.y] = 'D';
					
				}	
				else if (ch=='n'){
					ret = mydog.changeStrength(-1);
					if (c=='u'){
						mydog.x+=1;
					}
					else if (c=='d'){
						mydog.x-=1;
					}
					else if(c=='l'){
						mydog.y+=1;
					}
					else if(c=='r'){
						mydog.y-=1;
					}
					ret = mydog.changeStrength(0);
					board[mydog.x][mydog.y] = 'D';
				}			
			}
			else if(mydog.strength<wallStrength){
				cout << "the dog does not have enough strength to break down this wall" << endl;
				if (c=='u'){
				mydog.x+=1;
				}
				else if (c=='d'){
					mydog.x-=1;
				}
				else if(c=='l'){
					mydog.y+=1;
				}
				else if(c=='r'){
					mydog.y-=1;
				}
				ret = mydog.changeStrength(0);
				board[mydog.x][mydog.y] = 'D';
			}
		}

		else if(board[mydog.x][mydog.y] == 'P'){
			/*Power up 0: dog moves 5 steps in any direction. Changestrength is still -2
			Power up 1: dog teleported to a random place
			Power Up 2: Removes all the walls from the game*/
			int randomNo = rand()%2; //decides which power up happens

			if (randomNo==0){ //moves the dog 5 steps in the direction the owner previously put on the board
				cout << "Your dog moved 5 steps in the direction you chose" << endl;
				board[mydog.x][mydog.y] = ' ';
				 if (c=='u'){
					if (mydog.x >4){
						mydog.x-=5;}
					else{
						mydog.x-= mydog.x%19;}
				}
				else if (c=='d'){
						if(mydog.x<14){
							mydog.x+=5;}
						else{
							mydog.x+= mydog.x%19;}
				}
				else if(c=='l'){
						if(mydog.y>4){
							mydog.y-=5;}
						else{
							mydog.y-= mydog.y%19;}
				}
				else if(c=='r'){
						if(mydog.y<14){
							mydog.y+=5;}
						else{
							mydog.y+= mydog.y%19;}
				}
				ret = mydog.changeStrength(-2);
				board[mydog.x][mydog.y] = 'D';
			}
			else if (randomNo==1){ //this power up transports to dog to a random place on the board
				cout << "Your dog just transported to a random place in the board" << endl;
				board[mydog.x][mydog.y] = ' ';
				mydog.x = rand()%20;
				mydog.y = rand()%20;
				ret = mydog.changeStrength(-2);
				board[mydog.x][mydog.y] = 'D';
			}

			else if(randomNo==2){ //removes all the walls from the game
				cout << "This power up removed all the walls from the game!" << endl;
				board[mydog.x][mydog.y] = 'D';
				removeWalls();
				ret = mydog.changeStrength(-2);
			}
		}

		else if (board[mydog.x][mydog.y] == ' '){
			ret = mydog.changeStrength(-2);
			board[mydog.x][mydog.y] = 'D';
		}

		else{
			if (c=='u'){
				mydog.x+=1;
			}
			else if (c=='d'){
				mydog.x-=1;
			}
			else if(c=='l'){
				mydog.y+=1;
			}
			else if(c=='r'){
				mydog.y-=1;
			}
			ret = mydog.changeStrength(0);
			board[mydog.x][mydog.y] = 'D';
		}

		return ret;
}


void Board::playGame() {
	bool play = true;
	while (play) {
		cout << "Move (u, d, l, r) "<<endl;
		char c;
		cin >> c;
		play = moveDog(c);
		printBoard();
	}
}

void Board::removeWalls(){
	for(int i=0; i<20; i++){
		for (int j = 0; j<20; j++){
			if (board[i][j] != 'F' && board[i][j] != 'T' && board[i][j] != 'D'){
					board[i][j] = ' ';
				}
			}
	}
}

void Board::clearBoard(){
	for(int i=0; i<20; i++){
		for (int j = 0; j<20; j++){
			board[i][j] = ' ';
	}
}
}


