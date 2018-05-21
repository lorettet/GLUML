#include <iostream>
#include <map>
#include "UserInterface.h"
#include "Analyzer.h"

using namespace std;


map<std::string,std::string> Analyzer::hpDescription;

int main(int size, char** args)
{
	UserInterface ui;
	ui.Run();
	return 0;
}
