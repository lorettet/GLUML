#include <iostream>
#include "Analyzer.h"
#include "Disease.h"
#include <fstream>

using namespace std;

map<std::string,std::string> Analyzer::hpDescription;

int main()
{
	Analyzer a;
	a.setUsername("1");
	a.setRefFile("../refHPSet.txt","../param.txt");
	auto diseases = a.getKnownDiseases();
	for(auto d : diseases)
	{
		d.second.display();
	}
}
