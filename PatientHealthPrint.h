/*************************************************************************
                           PatientHealthPrint  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <PatientHealthPrint> (fichier PatientHealthPrint.h) ----------------
#if ! defined ( PATIENTHEALTHPRINT_H )
#define PATIENTHEALTHPRINT_H
//---------------------------------------------------------------- INCLUDE
#include "HealthPrint.h"
//--------------------------------------------------- Interfaces utilisées
#include <iostream>
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <PatientHealthPrint>
//
//
//------------------------------------------------------------------------

class PatientHealthPrint : public HealthPrint
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //

    map<string, double> getPatientDiseases(); 
    
    void display(ostream & stream = std::cout);

    void setDiseasePercent(string name, double value);
//------------------------------------------------- Surcharge d'opérateurs
    PatientHealthPrint & operator = ( const PatientHealthPrint & unPatientHealthPrint );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    PatientHealthPrint ( string line, vector<string> & labelOrder );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~PatientHealthPrint ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE
private: 
//----------------------------------------------------- Méthodes privées

//----------------------------------------------------- Attributs privés   
    map<string, double> diseases;
protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <PatientHealthPrint>

#endif // PatientHealthPrint_H
