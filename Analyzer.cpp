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

//------------------------------------------------------ Include personnel
#include "Analyzer.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Analyzer::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs
Analyzer & Analyzer::operator = ( const Analyzer & unAnalyzer )
// Algorithme :
//
{
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
Analyzer::Analyzer ( const Analyzer & unAnalyzer )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Analyzer>" << endl;
#endif
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
} //----- Fin de ~Analyzer


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées