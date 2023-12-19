/*
 * mainGame.cpp
 *
 *  Created on: Feb 24, 2023
 *      Author: Malika Iyer
 */

#include "Board.cpp" //I am using VSCode and it gives me errors when I include Board.hpp. So I have included Board.cpp here because it works
//i also had to manually make it run dog.cpp in the launch.json file because it was not recognizing any of the dog functions. Another way to get 
//rid of this error might be to #include "dog.cpp" in this file.
#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;

int main()
{
	srand(time(NULL));
	Board board('m', "fido", false);
	return 0;
}
