#include <iostream>
#include "Analyzer.h"
#include "PatientHealthPrint.h"
#include <fstream>

using namespace std;

map<std::string,std::string> Analyzer::hpDescription;

int main()
{
	Analyzer a;
	a.setUsername("1");
	a.setRefFile("../refHPSet.txt","../param.txt");
	for(auto patHp : a.analyze("emp.txt"))
	{	
		cout << "Patient : " << patHp.getNoID() << endl;
		for (auto disease : patHp.getPatientDiseases())
		{
			cout << disease.first << " : " << disease.second << endl;
		}
	}

}
