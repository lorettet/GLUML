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
//  Cette classe représente les empreintes patients
//------------------------------------------------------------------------

class PatientHealthPrint : public HealthPrint
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // Mode d'emploi :
    //  Renvoie la liste des noms de maladie auxquelles l'empreinte correspond
    // et a chacun est associé le pourcentage de correspondance
    map<string, double> getPatientDiseases(); 
    
    // Mode d'emploi :
    //  Affiche l'empreinte patient sur le flux stream (console par défaut)
    void display(ostream & stream = std::cout);

    // Mode d'emploi :
    //  Ajoute le nom de la maladie name à la liste des maladies associées
    //  à l'empreinte et lui défini value en pourcentage de correspondance
    // Contrat :
    //  name doit être le nom d'une maladie gérée par le système
    //  value doit être un pourcentage (0 <= value <= 1)
    void setDiseasePercent(string name, double value);
//------------------------------------------------- Surcharge d'opérateurs
    PatientHealthPrint & operator = ( const PatientHealthPrint & unPatientHealthPrint );

//-------------------------------------------- Constructeurs - destructeur
    // Mode d'emploi :
    //  Créé une empreinte patient avec line une ligne du fichier d'empreintes
    // patients et labelOrder spécifiant l'ordre des données dans line
    // Contrat :
    //  line doit respecté le format CSV et venir du fichier d'empreintes patients
    //  et doit respecter l'ordre des données spécifié par labelOrder
    PatientHealthPrint ( string line, vector<string> & labelOrder );

    virtual ~PatientHealthPrint ( );


//------------------------------------------------------------------ PRIVE
private: 
//----------------------------------------------------- Méthodes privées

//----------------------------------------------------- Attributs privés
    // liste des noms de maladie auxquelles l'empreinte correspond
    // et a chacun est associé le pourcentage de correspondance
    map<string, double> diseases;
protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <PatientHealthPrint>

#endif // PatientHealthPrint_H
