/*
 * Dog.cpp
 *
 *  Created on: Feb 13, 2023
 *      Author: victo
 */

#include "Board.hpp"
#include <iostream>
using namespace std;

Dog::Dog(string n){
	name = n;
	strength = 50;
	int x = 0;
	int y = 0;

}

Dog::Dog(){
	name ="Fluffy";
	strength = 50;
	int x = 0;
	int y = 0;
}

bool Dog::changeStrength(int amount){
	bool strengthGood = true;
	strength += amount;
	printDog();
	if(strength>0){
		strengthGood = true;
	}
	else{
		strengthGood = false;
		die();
	}
	return strengthGood;

}

void Dog::die(){
	cout<<"Really, bro? You had one job.... and you lost"<<endl;
}

void Dog::printDog(){
	cout<<"Dog name: ";
	cout<<name;
	cout<<endl;

	cout<<"Dog Strength: ";
	cout<<strength;
	cout<<endl;
}

void Dog::won(){
	cout<<"Good job, you walked the dog across the forest successfully"<<endl;
}

void Dog::reset(){
	strength = 50;
	x = 0;
	y = 0;
}






