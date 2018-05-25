/*************************************************************************
                           Analyzer  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Analyzer> (fichier Analyzer.h) ----------------
#if ! defined ( ANALYZER_H )
#define ANALYZER_H
//---------------------------------------------------------------- INCLUDE
#include "PatientHealthPrint.h"
#include "Disease.h"
//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Analyzer>
//
//
//------------------------------------------------------------------------

class Analyzer
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //

    void setRefFile(string refHpPath, string hpDescriptionPath);

    list<PatientHealthPrint> analyze(string patientHpPath);

    map<string,Disease> getKnownDiseases();

    Disease getDisease(string name);

    void writeHistory(PatientHealthPrint PatientHp); 

    void showHistory(iostream out, string date, string idEmploye, string idHp);

//------------------------------------------------- Surcharge d'opérateurs
    Analyzer & operator = ( const Analyzer & unAnalyzer );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    Analyzer ( const Analyzer & unAnalyzer );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Analyzer ( string histPath);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Analyzer ( );
    // Mode d'emploi :
    //
    // Contrat :
    //
//----------------------------------------------------- Attributs public
    static map<string, string> hpDescription;

//------------------------------------------------------------------ PRIVE
private:
//----------------------------------------------------- Méthodes privées

    void makeDiseases(ifstream & refHpStream);

    void searchDiseases(PatientHealthPrint PatientHp);

//----------------------------------------------------- Attributs privées

    int nbRefHp; 
    string historyPath;
    map<string, Disease> diseaseList;

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <Analyzer>

#endif // Analyzer_H
