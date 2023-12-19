/*
 * Board.cpp
 * Dog Class declaration
 * 
 *  Created on: Feb 24, 2023
 *      Author: Malika Iyer
 */

#include "dog.hpp"
#include <iostream>
#include <string.h>
using namespace std;

    Dog::Dog(string n){
 /* constructor, sets the name to be whatever name gets passed in, the 
  * strength to be 50 (I just picked 50 - you want another number, go for it!) and I made 
  * the original coordinates be 0 and 0 because the compiler yells at me a tiny little yell 
  * if I don't initialize all my fields in the constructor 
  */ 
        name = n;
        strength = 50;
        x=0;
        y=0;
    }
 
    Dog::Dog(){
    /* constructor, I made the default be fluffy, but you can make it anything you like!! 
    * I set the strength to be 50 (again, I just picked 50), and I made the original 
    * coordinates be 0 and 0 because... 
    */ 
        name = "fluffy";
        strength = 50;
        x =0;
        y=0;
    }
    bool Dog::changeStrength(int amt){
    /*changeStrength modifies the strength property by whatever amt is (basically adding here) 
    * It then calls printDog method to print out current information about the dog. 
    * It also checks to make sure that the dog object's strength is >0. 
    * If the dog object's strength is 0 or less, it calls the die method. 
    * It returns true if the strength is still >0 and false otherwise. 
    */ 
        strength+= amt;
        bool x;
        // printDog(); //printDog is already called in BoardConfig so it is being printed twice
        if (strength>0){
            x= true;
        }
        else if(strength<=0){
            die();
        }
        else{
            x= false;
        }
        return x;
    }
    void Dog::die(){
    /* This method just prints out a sad pathetic death of a dog message, letting everyone 
    * know of the demise of the dog object.  My message has ACK!!! and judgmental statements 
    * about how the user is a cruel, heartless person for letting a puppy dog die, but 
    * yours can be whatever you like. 
    */ 
        cout<< "OMG your dog died a sad pathetic death, shame on you for being a horrible person!! Do better next time :/" << endl;
    }
    void Dog::printDog(){
    /* this method just prints out the basic information about the dog - its 
    *name and its current strength. 
    */ 
        cout << name << " has strength " << strength << endl;
    }

    void Dog::won(){
    /* again, just a message about the user's incredible prowess in successfully navigating the 
    * sweet little puppy dog through the evil forest to the other side.  You can make it whatever 
    * you like. 
    */ 
        cout << "You won! Congratulations in being an angel human being and helping this cute little puppy survive :)" << endl;
    }
    void Dog::reset(){
    /* this method just resets the strength (for me it was 50) and the x and y to 0 and 0. 
    * 
    */ 
        strength = 50;
        x=0;
        y=0;
    }




