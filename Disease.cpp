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

    pair<double, double> Disease::getNumAttribute(string name)
    {
    	return numAttribute[name];
    }

    map<string, double> Disease::getCarAttribute(string name)
    {
    	return catAttribute[name];
    }

//------------------------------------------------- Surcharge d'opérateurs
//Disease & Disease::operator = ( const Disease & unDisease )
// Algorithme :
//
//{
//} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
Disease::Disease ( const Disease & unDisease )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Disease>" << endl;
#endif
} //----- Fin de Disease (constructeur de copie)


Disease::Disease ()
// Algorithme :
//
{
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
