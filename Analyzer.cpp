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

void Analyzer::writeHistory(PatientHealthPrint patientHp)
{
	ofstream ofs (historyPath);
//	ofs << patientHp.display();
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


Analyzer::Analyzer ( string histPath) : historyPath(histPath)
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
	
	map<string,double> t_moy;
	map<string,double> t_ec;
	
	for(auto hpref : diseaseHpMap) // map<string "nom maladie", vector<RefHealthPrint> "empreintes associées">
	{
		Disease d(hpref.first);
		
		//debug
		cout << "TEST MALADIE " << hpref.first << endl;
		//
		
		for(auto hp : hpref.second) //vector<RefHealthPrint> "empreintes associées"
		{
			//debug
			cout << "	TEST NB HP " << hp.getNoID() << endl;
			//
			
			
			for(auto attr : hp.getCatAttribute()) // map <string "name attribute", string "valeur attribut">
			{
				//debug
				cout << "		TEST name attr = " << attr.first << " value attr = " << attr.second;
				//
				
				d.incrCatAttribute(attr.first,attr.second);
				
				//debug
				cout << " nb pers = " << d.getCatAttribute()[attr.first][attr.second] << endl;
				//
			}

			for(auto attr : hp.getNumAttribute()) // map <string "name attribute", double "valeur attribut">
			{
				//debug
				cout << "	TEST NB HP " << hp.getNoID() << endl;
				//
			
				t_moy[attr.first] += attr.second;
				t_ec[attr.first] += (attr.second*attr.second);
				
				//debug
				cout << "		TEST name attr = " << attr.first << " moy = " << t_moy[attr.first] << " ec = " << t_ec[attr.first] << endl;
				//
			}
			d.incrNbSickPeople();
			cout <<"NB SICK : " << d.getNbSickPeople() <<endl;
		}
		for(auto & elem : t_moy)
		{
			elem.second = elem.second / (double)d.getNbSickPeople();
			//debug
			cout << "		TEST name attr = " << elem.first << " moy = " << elem.second << endl;
			//
		}
		
		for(auto & elem : t_ec)
		{
			elem.second = (elem.second / (double)d.getNbSickPeople()) - (t_moy[elem.first]*t_moy[elem.first]);
			//debug
			cout << "		TEST name attr = " << elem.first << " ec = " << elem.second << endl;
			//
			if(elem.second < t_moy[elem.first]/2)
			{
				d.addNumAttribute(elem.first, t_moy[elem.first], elem.second);
			}
		}
		
		d.setPercentagesCatAttribute();
		//for(auto & attr : d.getCatAttribute())
		//{
			//for(auto & value : attr.second)
			//{
				//value.second = value.second / (double)d.getNbSickPeople();
			//}
		//}
		
		diseaseList[hpref.first] = d;
		d.display();
		
		
	}
	
	
}


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
