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
	cout << endl << "Affichage de toutes les maladies :" << endl;
	for(auto d : diseases)
	{
		cout << d.first << endl;
	}

}
