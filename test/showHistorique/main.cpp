#include <iostream>
#include "Analyzer.h"
#include <fstream>

using namespace std;

map<std::string,std::string> Analyzer::hpDescription;

int main()
{
	Analyzer a;
	a.setUsername("1");
	a.setRefFile("ref.txt","param.txt");
	a.analyze("emp7.txt");
	a.setUsername("2");
	a.analyze("emp8.txt");
	a.setUsername("3");
	a.analyze("emp9.txt");
	ifstream h("file/historique.txt");
	string s;
	while(h>>s)
	{
		cout << s << endl;
	}

}
