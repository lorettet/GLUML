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
// La classe analyzer est la classe principale de notre projet, elle gère
// la création des empreintes de références et patients, le calcul des 
// critères d'analyse des maladies, l'analyse des empreintes patients ainsi
// que l'historique de la session courante.
//------------------------------------------------------------------------

class Analyzer
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

    // Mode d'emploi :
    // Cette méthode définira le fichier refHpPath comme fichier de référence
    // c'est dans ce fichier que les empreintes de références seront réupérées
    // Le fichier hpDescriptionPath défini le type chacune des données présentes
    // dans refHpPath. Elle utilise la méthode privée makeDiseases pour créer
    // les maladies en fonction de ces empreintes.
    // Contrat :
    // Les deux fichiers doivent être au format CSV et le fichier refHpPath doit
    // contenir en 1ere ligne la description de son contenu et également
    // respecter les spécifications donnéees par le fichier hpDescriptionPath
    void setRefFile(string refHpPath, string hpDescriptionPath);
  
    // Mode d'emploi :
    // Cette méthode analyse l'emsenble des empreintes patient présentes dans le
    // fichier patientHpPath, il retourne les empreintes patient analysées contenant
    // la liste des maladies avec leurs pourcentages de chances associées.
    // Contrat :
    // Le fichier patientHpPath doit être au format CSV et doit contenir en 1ere 
    // ligne la description de son contenu et également respecter les spécifications
    // donnéees par le fichier hpDescriptionPath
    vector<PatientHealthPrint> analyze(string patientHpPath);
  
    // Mode d'emploi :
    //  Cette méthode renvoie la liste des noms de maladies gérées par le système.
    // Contrat :
    //
    map<string,Disease> getKnownDiseases();
  
    // Mode d'emploi :
    // Cette méthode renvoie une maladie en fonction du nom passé en paramétre
    // Contrat :
    //
    Disease getDisease(string name);

    // Mode d'emploi :
    // Cette mathode privée est appelée lors de l'analyse d'une empreinte patient
    // elle permet d'ajouter à l'historique l'empreinte patient analysée ainsi que
    // l'heure et l'employé qui s'en est chargé
    // Contrat :
    //
    void writeHistory(PatientHealthPrint &PatientHp); 

    // Mode d'emploi :
    //  Cette méthode affiche l'historique de l'application sur le fluc out en fonction
    // des paramétre qui lui sont fournis (date si != null affichera les analyses
    // réalisée à la date donnée, idEmploye si != null affichera les analyses réalisées
    // par l'employé en question, idHp si != null affichera les analyses référentes
    // à l'empreinte demandée). Ces paramétres peuvent être superposés.
    // Contrat :
    //
    void showHistory(ostream & out, string date, string idEmploye, string idHp);
   
    // Mode d'emploi :
    //  Cette méthode défini le nom de l'utilisateur courant.
    // Contrat :
    //
    void setUsername(string name);
    
//------------------------------------------------- Surcharge d'opérateurs
    Analyzer & operator = ( const Analyzer & unAnalyzer );
  
//-------------------------------------------- Constructeurs - destructeur
    Analyzer ( const Analyzer & unAnalyzer );

    Analyzer ( );

    virtual ~Analyzer ( );

//----------------------------------------------------- Attributs public
    static map<string, string> hpDescription;

//------------------------------------------------------------------ PRIVE
private:
//----------------------------------------------------- Méthodes privées
    // Mode d'emploi :
    // Cette méhtode privée est appelée lors du chargement du jeu de données
    // de références, elle réalise l'ensemble des calculs necessaires pour 
    // obtenir les critères d'analyse de chaque maladie.
    // Contrat :
    //  refHpStream est un flux du fichier d'empreinte de références au bon
    // format.
    void makeDiseases(ifstream & refHpStream);
  
    // Mode d'emploi :
    //  Cette méthode réalise l'analyse d'une empreinte patient.
    // Contrat :
    //  
    void searchDiseases(PatientHealthPrint &PatientHp);

//----------------------------------------------------- Attributs privées

    int nbRefHp;  // nombre d'empreintes de références
    const string historyPath = "file/historique.txt"; //fichier historique
  
    // Map associant à chaque nom de maladie l'object maladie.
    map<string, Disease> diseaseList; 
    string username; // Nom de l'utilisateur courant

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <Analyzer>

#endif // Analyzer_H
