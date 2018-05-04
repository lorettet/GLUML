/*************************************************************************
                           RefHealthPrint  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <RefHealthPrint> (fichier RefHealthPrint.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <map>
//------------------------------------------------------ Include personnel
#include "RefHealthPrint.h"
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type RefHealthPrint::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

	string RefHealthPrint::getDisease()
	{
		return disease;
	}

//------------------------------------------------- Surcharge d'opérateurs
//RefHealthPrint & RefHealthPrint::operator = ( const RefHealthPrint & unRefHealthPrint )
// Algorithme :
//
//{
//} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
RefHealthPrint::RefHealthPrint ( const RefHealthPrint & unRefHealthPrint ) : HealthPrint(unRefHealthPrint)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <RefHealthPrint>" << endl;
#endif
} //----- Fin de RefHealthPrint (constructeur de copie)


RefHealthPrint::RefHealthPrint ( string line ): HealthPrint(line)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <RefHealthPrint>" << endl;
#endif
} //----- Fin de RefHealthPrint


RefHealthPrint::~RefHealthPrint ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <RefHealthPrint>" << endl;
#endif
} //----- Fin de ~RefHealthPrint


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
