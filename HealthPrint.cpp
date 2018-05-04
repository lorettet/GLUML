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

//------------------------------------------------- Surcharge d'opérateurs
//HealthPrint & HealthPrint::operator = ( const HealthPrint & unHealthPrint )
// Algorithme :
//
//{
//} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
HealthPrint::HealthPrint ( const HealthPrint & unHealthPrint )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <HealthPrint>" << endl;
#endif
} //----- Fin de HealthPrint (constructeur de copie)


HealthPrint::HealthPrint ( string line)
// Algorithme :
//
{
	//TODO
#ifdef MAP
    cout << "Appel au constructeur de <HealthPrint>" << endl;
#endif
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
