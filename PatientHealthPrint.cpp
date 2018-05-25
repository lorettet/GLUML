/*************************************************************************
                           PatientHealthPrint  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <PatientHealthPrint> (fichier PatientHealthPrint.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <map>

//------------------------------------------------------ Include personnel
#include "PatientHealthPrint.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type PatientHealthPrint::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

	map<string, double> PatientHealthPrint::getPatientDiseases()
	{
		return diseases;
	}
	
	void PatientHealthPrint::display(ostream & stream)
	{

		stream << "Id : " << noID << endl;
		stream << "ATTRIBUTES NUM : " << endl;
		for(auto dis : numAttribute)
		{
			cout << "\t" << dis.first << " : " << dis.second << endl;
		}
		stream << "ATTRIBUTES CAT : " << endl;
		for(auto dis : catAttribute)
		{
			cout << "\t" << dis.first << " : " << dis.second << endl;
		}
		
		stream << "DISEASE PROBABILITIES : " << endl;
		for(auto dis : diseases)
		{
			cout << "\t" << dis.first << " : " << dis.second << endl;
		}
	}


	void PatientHealthPrint::setDiseasePercent(string name, double value)
	{
		diseases[name] = value;
	}
//------------------------------------------------- Surcharge d'opérateurs
//PatientHealthPrint & PatientHealthPrint::operator = ( const PatientHealthPrint & unPatientHealthPrint )
// Algorithme :
//
//{
//} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur

PatientHealthPrint::PatientHealthPrint ( string line, vector<string> & labelOrder ): HealthPrint(line, labelOrder)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <PatientHealthPrint>" << endl;
#endif
} //----- Fin de PatientHealthPrint


PatientHealthPrint::~PatientHealthPrint ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <PatientHealthPrint>" << endl;
#endif
} //----- Fin de ~PatientHealthPrint


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
