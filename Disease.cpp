/*************************************************************************
                           Disease  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Disease> (fichier Disease.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <map>
#include <iomanip>
//------------------------------------------------------ Include personnel
#include "Disease.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Disease::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

	string Disease::getName()
	{
		return name;
	}

    map<string,pair<double, double>> Disease::getNumAttribute()
    {
    	return numAttribute;
    }

    map<string,map<string, double>> Disease::getCatAttribute()
    {
    	return catAttribute;
    }
    
    int Disease::getNbSickPeople()
    {
		return nbSickPeople;
	}
    
    void Disease::incrNbSickPeople()
    {
		nbSickPeople++;
	}
	
	void Disease::incrCatAttribute(string name, string value){
		catAttribute[name][value]++;
	}
	
	void Disease::setPercentagesCatAttribute(){
		for(auto & attr : catAttribute)
		{
			for(auto & value : attr.second)
			{
				value.second = value.second / (double) nbSickPeople;
			}
		}
	}
	
	void Disease::addNumAttribute(string name, double avg, double sd){
		numAttribute[name] = make_pair(avg,sd);
	}
	
	void Disease::display(ostream & os)
	{
		os << fixed << setprecision(1);
		os << "---------------------------- "<<name<<" ---------------------------" << endl ;
		os << "NB SICK PEOPLE : " << nbSickPeople << endl;
		os << "NUM ATTRIBUTE--------------" << endl ;
		for( auto elem : numAttribute)
		{
			os << elem.first << " :  avg = " << elem.second.first <<" | sd = " << elem.second.second << endl;
		}
		
		os << "CAT ATTRIBUTE--------------" << endl ;
		for( auto elem : catAttribute)
		{
			os << elem.first << endl;
			for( auto value : elem.second)
			{
				os << " :  valueAttr = " << value.first <<" | percentage = " << value.second << endl;
			}
		}
	}
//------------------------------------------------- Surcharge d'opérateurs
//Disease & Disease::operator = ( const Disease & unDisease )
// Algorithme :
//
//{
//} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
/*Disease::Disease ( const Disease & unDisease )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Disease>" << endl;
#endif
} //----- Fin de Disease (constructeur de copie)*/


Disease::Disease (string name_d) : name(name_d)
// Algorithme :
//
{
	nbSickPeople = 0;
#ifdef MAP
    cout << "Appel au constructeur de <Disease>" << endl;
#endif
} //----- Fin de Disease

Disease::Disease ()
// Algorithme :
//
{
	nbSickPeople = 0;
#ifdef MAP
    cout << "Appel au constructeur de <Disease>" << endl;
#endif
} //----- Fin de Disease


Disease::~Disease ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Disease>" << endl;
#endif
} //----- Fin de ~Disease


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
