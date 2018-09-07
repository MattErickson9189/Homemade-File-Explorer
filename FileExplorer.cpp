// FileExplorer.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <filesystem>
#include <vector>
#include <sstream>
#include <cstring>
#include <stdlib.h>
#include <sys/stat.h>

//defines the namespace
namespace fs = std::experimental::filesystem;

int main()
{
	//vector to store the file names
	std::vector<std::string> files;
	
	//sets the path 
	std::string path = "C:\\Users";
	
	//saves homepath
	std::string home = path;
	
	//Starts console in fullscreen
	system("mode 650");

	//creates stat struct
	struct stat s;

	while (1) {
		//place holder for files inside the vector
		int place = 1;
		//clears the vector
		files.clear();

		std::cout << "Displaying: " << path << std::endl;
		std::cout << "-1: Start directory" << std::endl << "0: Parent directory" << std::endl;

		//for loop iterates through all the files in the directory 
		for (auto & p : fs::directory_iterator(path)) {
			//converts file path to a string 
			std::stringstream ss;
			ss << p;
			//stores each file in a index of the vector
			files.push_back(ss.str());
			std::cout << place << ": " << p  << std::endl;
			place++;
		}//end of for

		std::cout << files.size() + 1 << ": Exit" << std::endl;
		std::cout << "Enter the number of the file you wish to go to" << std::endl;

		//takes in user input for which file they want to go to 
		int input;
		std::cin >> input;
		//brings the user to parent directory
		if (input == 0) {
			path = path.substr(0, path.find_last_of("/\\"));
		}//end of if
		//brings the user back to starting directory
		else if (input == -1) {
			path = home;
		}//end of elif
		//Stops the program
		else if (input == files.size() + 1) {
			exit(0);
		}//end of elif
		//continues to the next directory level
		else {

			path = files.at(input - 1);
		}//end of else
		system("CLS");
		if (path.substr(path.find_last_of(".") + 1) == "txt") {
			std::cout << "This is a text file do you wish to open? y/n" << std::endl;
			char ans;
			std::cin >> ans;
			if (ans == 'y') {
				system("CLS");
			}//end of if
			else if (ans == 'n') {
				system("CLS");
			}//end of elif
		}//end of if
	}//end of while
	return 0;
}//end of main
