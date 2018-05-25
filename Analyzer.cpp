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
	ofstream ofs (historyPath);
//	ofs << patientHp.display();
}

void Analyzer::showHistory(iostream out, string date, string idEmploye, string idHp)//TODO
{

}

list<PatientHealthPrint> Analyzer::analyze(string patientHpPath)
{

	ifstream ifs (patientHpPath);

	string firstLine;
	
	ifs >> firstLine;
	
	cout << firstLine << endl;

	vector<string> labelOrder = split(firstLine,";");

	list<PatientHealthPrint> resultList;

	string line;

	while(ifs >> line)
	{
		cout << "analyse" << endl;
		PatientHealthPrint patientHp (line, labelOrder);
		resultList.push_back(patientHp);
		searchDiseases(patientHp);
		writeHistory(patientHp);
	}

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


Analyzer::Analyzer ( string user) : username(user)
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
	
	cout << diseaseHpMap.size() << " maladies" << endl;
	
	for(auto hpref : diseaseHpMap) // map<string "nom maladie", vector<RefHealthPrint> "empreintes associées">
	{
		cout << "Analyse pour " << hpref.first;
		auto startTime = clock();
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
		
		auto endTime = clock();
		double time = (double)(endTime-startTime)/ CLOCKS_PER_SEC;
		cout << " faite en " <<time << "s" << endl;
		
	}
	
	
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

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
