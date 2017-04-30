#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include "Rectangle.h"
#include "Format.h"

#define MENUSIZE 72
class Menu
{
public:
	Menu();
	//Ui Drawing
	static void printMain();
	//Selections
	static void exit();
	//Debug
	static void debug();
	~Menu();
};
