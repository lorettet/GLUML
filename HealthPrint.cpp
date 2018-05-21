/*************************************************************************
                           HealthPrint  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <HealthPrint> (fichier HealthPrint.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <map>
#include <string>
//------------------------------------------------------ Include personnel
#include "HealthPrint.h"
#include "lib/split.h"
#include "Analyzer.h"
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type HealthPrint::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

	map<string, double> HealthPrint::getNumAttribute()
    {
        return numAttribute;
    }

    map<string, string> HealthPrint::getCatAttribute() 
    {
        return catAttribute;
    }
    
     void HealthPrint::display()
    {
		cout << "id : " << noID << endl;
		cout << "---------- NUM --------------" << endl;
		for(auto elem : numAttribute)
		{
			cout << elem.first << " : " << elem.second << endl;
		}
		
		cout << "---------- CAT --------------" << endl;
		for(auto elem : catAttribute)
		{
			cout << elem.first << " : " << elem.second << endl;
		}
	}
	
	string HealthPrint::getNoID(){
		return noID;
	}

//------------------------------------------------- Surcharge d'opérateurs
//HealthPrint & HealthPrint::operator = ( const HealthPrint & unHealthPrint )
// Algorithme :
//
//{
//} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
/*HealthPrint::HealthPrint ( const HealthPrint & unHealthPrint )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <HealthPrint>" << endl;
#endif
} //----- Fin de HealthPrint (constructeur de copie)
*/

HealthPrint::HealthPrint ( string line, vector<string> & labelOrder)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <HealthPrint>" << endl;
#endif
	auto attributes = split(line,";");
	
	int index = 0;
	for(auto label : labelOrder)
	{
		string type = Analyzer::hpDescription[label];
		
		if(type == "ID")
		{
			noID = attributes[index];
		}
		else if(type == "double")
		{
			
			numAttribute[label] = stod(attributes[index]);
		}
		else if(type == "string")
		{ 
			catAttribute[label] = attributes[index];
		}
		index++;
	}
} //----- Fin de HealthPrint


HealthPrint::~HealthPrint ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <HealthPrint>" << endl;
#endif
} //----- Fin de ~HealthPrint


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
