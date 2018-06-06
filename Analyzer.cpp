/*************************************************************************
                           Analyzer  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Analyzer> (fichier Analyzer.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <fstream>
#include <map>
#include <list>
#include <vector>
#include <math.h>
#include <chrono>
#include <time.h>
#include <sstream>
#include <iomanip>
//------------------------------------------------------ Include personnel
#include "Analyzer.h"
#include "lib/split.h"
#include "RefHealthPrint.h"
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Analyzer::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

map<string,Disease> Analyzer::getKnownDiseases()
{
	return diseaseList;
}

Disease Analyzer::getDisease(string name)
{
	return diseaseList[name];
}

void Analyzer::writeHistory(PatientHealthPrint &patientHp)//TODO
{
	ofstream ofs (historyPath, fstream::app);
	
	ostringstream ostrs;
	char buffer[20];
	time_t rawtime = chrono::system_clock::to_time_t(chrono::system_clock::now());
	struct tm* timeinfo = localtime(&rawtime);
	strftime(buffer, 20, "%d/%m/%Y",timeinfo);
	string date(buffer);
	ostrs << date << ";" << patientHp.getNoID() << ";" << username;
	ostrs << fixed << setprecision(1);
	for(auto attr : patientHp.getNumAttribute())
	{
		ostrs << ";" << attr.first << ":" << attr.second;
	}
	for(auto attr : patientHp.getCatAttribute())
	{
		ostrs << ";" << attr.first << ":" << attr.second;
	}
	
	ostrs << endl;
	string sep = "";
	for(auto value : patientHp.getPatientDiseases())
	{
		if(value.second >= 0.25)
		{
			ostrs << sep << value.first << ":" << value.second*100;
			sep = ";";
		}
	}
	
	ofs << ostrs.str() << endl;
	
}

void Analyzer::showHistory(ostream & out, string date, string idEmploye, string idHp)//TODO
{
	ifstream ifs (historyPath);
	if(!ifs)
	{
		cerr << "Erreur lors de l'ouverture du fichier " << historyPath << endl;
		return;
	}
	string hpLine;
	while(ifs>> hpLine)
	{
		vector<string> strs = split(hpLine, ";");
		string _date = strs[0];
		string _idHp = strs[1];
		string _idEmp = strs[2];
		
		// check filter
		if(idEmploye != "" && idEmploye!=_idEmp) {ifs>>hpLine;continue;}
		if(idHp != "" && idHp!=_idHp) {ifs>>hpLine;continue;}
		if(date != "" && date!=_date) {ifs>>hpLine;continue;}
		
		out << "Employé : " << _idEmp;
		out << " | Id : " << _idHp;
		out << " | Date : "<< _date << endl;
		out << "HEALTH PRINT :" << endl;
		for(unsigned int i = 3; i<strs.size(); i++)
		{
			vector<string> value = split(strs[i],":");
			out << "\t" << value[0] << " : " << value[1] << endl;
		}
		string diseaseLine;
		ifs >> diseaseLine;
		
		vector<string> dList = split(diseaseLine,";");
		out << "POSSIBLE DISEASE :" << endl;
		for(string v : dList)
		{
			vector<string> value = split(v,":");
			out << "\t" << value[0] << " : " << value[1] << "%" << endl;
		}
		out << "-----------------------------------------" << endl;
	}
}	

vector<PatientHealthPrint> Analyzer::analyze(string patientHpPath)
{

	ifstream ifs (patientHpPath);

	string firstLine;
	
	ifs >> firstLine;

	vector<string> labelOrder = split(firstLine,";");

	vector<PatientHealthPrint> resultList;

	string line;
#ifdef PERF
	auto startTime = clock();
#endif
	while(ifs >> line)
	{
		PatientHealthPrint patientHp (line, labelOrder);
		searchDiseases(patientHp);
		writeHistory(patientHp);
		resultList.push_back(patientHp);
	}
#ifdef PERF
	auto endTime = clock();
	double time = (double)(endTime-startTime)/ CLOCKS_PER_SEC;
	cout << setprecision(6) << fixed;
	cout << "Analyse effectué en " <<time << "s" << endl;
#endif

	return resultList;
}
//------------------------------------------------- Surcharge d'opérateurs
//Analyzer & Analyzer::operator = ( const Analyzer & unAnalyzer )
// Algorithme :
//
//{
//} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
Analyzer::Analyzer ( const Analyzer & unAnalyzer )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Analyzer>" << endl;
#endif
	//TODO
} //----- Fin de Analyzer (constructeur de copie)


Analyzer::Analyzer ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Analyzer>" << endl;
#endif
} //----- Fin de Analyzer


Analyzer::~Analyzer ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Analyzer>" << endl;
#endif
	//TODO
} //----- Fin de ~Analyzer

void Analyzer::setRefFile(string refHpPath, string hpDescriptionPath)
{
	diseaseList.clear();
	ifstream ifs (hpDescriptionPath);
	
	if(!ifs)
	{
		cerr << "Error : Erreur lors de l'ouverture du fichier " << hpDescriptionPath << endl;
		return;
	}
	
	
	string firstLine;
	ifs >> firstLine;
	bool normalOrder;
	if(firstLine.find_first_of("AttributeName")==0)
	{
		normalOrder = true;
	}
	else
	{
		normalOrder = false;
	}
	
	string line;
	
	while(ifs >> line)
	{
		
		auto splited = split(line,";");
		if(normalOrder)
		{
			hpDescription[splited[0]] = splited[1];
		}
		else
		{
			hpDescription[splited[1]] = splited[0];
		}
	}
	
	ifs.close();
	
	ifs.open(refHpPath);
	
	if(!ifs)
	{
		cerr << "Error : Erreur lors de l'ouverture du fichier " << refHpPath << endl;
		return;
	}
	
	makeDiseases(ifs);
	
}

void Analyzer::makeDiseases(ifstream & refHpStream)
{	
	
#ifdef PERF
	cout << "Lecture du fichier..." << endl;
	auto beginTime = clock();
#endif
	string firstLine;
	
	refHpStream >> firstLine;
	
	vector<string> labelOrder = split(firstLine,";");
	
	string line;
	
	map<string, vector<RefHealthPrint>> diseaseHpMap;
	
	while(refHpStream >> line)
	{	
		RefHealthPrint refHp(line, labelOrder);
		string name = refHp.getDisease();
		
		diseaseHpMap[name].push_back(refHp);
	}
	
#ifdef PERF
	{
		auto endTimeFile = clock();
		double time = (double)(endTimeFile-beginTime)/ CLOCKS_PER_SEC;
		cout << setprecision(6) << fixed;
		cout << "Fichier lu en " <<time << "s" << endl;
	}
#endif
	
	cout << diseaseHpMap.size() << " maladies" << endl;
	
	for(auto hpref : diseaseHpMap) // map<string "nom maladie", vector<RefHealthPrint> "empreintes associées">
	{
#ifdef PERF
		cout << "Analyse pour " << hpref.first;
		auto startTime = clock();
#endif
		map<string,double> t_moy;
		map<string,double> t_ec;
		Disease d(hpref.first);
		
		for(auto hp : hpref.second) //vector<RefHealthPrint> "empreintes associées"
		{	
			
			for(auto attr : hp.getCatAttribute()) // map <string "name attribute", string "valeur attribut">
			{
				d.incrCatAttribute(attr.first,attr.second);
			}

			for(auto attr : hp.getNumAttribute()) // map <string "name attribute", double "valeur attribut">
			{
				t_moy[attr.first] += attr.second;
				t_ec[attr.first] += (attr.second*attr.second);
			}
			d.incrNbSickPeople();
		}
		for(auto & elem : t_moy)
		{
			elem.second = elem.second / (double)d.getNbSickPeople();
		}
		
		for(auto & elem : t_ec)
		{
			elem.second = (elem.second / (double)d.getNbSickPeople()) - (t_moy[elem.first]*t_moy[elem.first]);
			elem.second = sqrt(elem.second);
			if(elem.second < fabs(t_moy[elem.first]/2))
			{
				d.addNumAttribute(elem.first, t_moy[elem.first], elem.second);
			}
		}
		
		d.setPercentagesCatAttribute();
		diseaseList[hpref.first] = d;
		
#ifdef PERF
		auto endTime = clock();
		double time = (double)(endTime-startTime)/ CLOCKS_PER_SEC;
		cout << setprecision(6) << fixed;
		cout << " faite en " <<time << "s" << endl;
#endif
		
	}
	
#ifdef PERF
	{
		auto endTime = clock();
		auto time = (double)(endTime-beginTime)/ CLOCKS_PER_SEC;
		cout << setprecision(6) << fixed;
		cout << "Temps totale : " <<time << "s" << endl;
	}
#endif
	
	
}

void Analyzer::searchDiseases(PatientHealthPrint & PatientHp)
{
	int nbAtt;
	double percent;
	double vNum;// = 0;
	string vCat;
	double avg;
	double sd;

	auto patientNumMap = PatientHp.getNumAttribute();
	auto patientCatMap = PatientHp.getCatAttribute();

	for(auto d : diseaseList)
	{
		nbAtt = 0;
		percent = 0;

		for(auto a : d.second.getNumAttribute())
		{
			if(patientNumMap.find(a.first) != patientNumMap.end())
			{
				vNum = patientNumMap[a.first];
			}
			else continue;
			
			avg = a.second.first; 
			sd = a.second.second;

			if(vNum > avg-sd && vNum < avg+sd)
			{
				if(vNum > avg)
				{
					percent += (vNum - avg)*(-0.5/sd) +1;
				}else
				{
					percent += (vNum - avg)*(0.5/sd) +1;
				}
			}
			nbAtt++;
		}

		for(auto a : d.second.getCatAttribute())
		{
			if(patientCatMap.find(a.first) != patientCatMap.end())
			{
				vCat = patientCatMap[a.first];
			}
			else continue;
			
			if(a.second.find(vCat) != a.second.end())
			{
				percent += a.second[vCat];
			}

			nbAtt++;
		}

		PatientHp.setDiseasePercent(d.first, percent/nbAtt);
	}
	
	
}

void Analyzer::setUsername(string name)
{
	username = name;
}

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
