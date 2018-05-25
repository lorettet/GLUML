/*************************************************************************
                           HealthPrint  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <HealthPrint> (fichier HealthPrint.h) ----------------
#if ! defined ( HEALTHPRINT_H )
#define HEALTHPRINT_H

//--------------------------------------------------- Interfaces utilisées
#include <map>
#include <list>
#include <vector>

using namespace std;
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <HealthPrint>
//
//
//------------------------------------------------------------------------

class HealthPrint
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //

    map<string, double> getNumAttribute(); 

    map<string, string> getCatAttribute();
    
    string getNoID();
    
    virtual void display();

//------------------------------------------------- Surcharge d'opérateurs
    HealthPrint & operator = ( const HealthPrint & unHealthPrint );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur

    HealthPrint (string line, vector<string> & labelOrder);
    // Mode d'emploi :
    //
    // Contrat :
    //

    HealthPrint ( );

    virtual ~HealthPrint ( ) = 0;
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    map<string, double> numAttribute;
    map<string, string> catAttribute;
    string noID;
};

//-------------------------------- Autres définitions dépendantes de <HealthPrint>

#endif // HealthPrint_H
