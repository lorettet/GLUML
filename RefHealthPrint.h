/*************************************************************************
                           RefHealthPrint  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <RefHealthPrint> (fichier RefHealthPrint.h) ----------------
#if ! defined ( REFHEALTHPRINT_H )
#define REFHEALTHPRINT_H
//---------------------------------------------------------------- INCLUDE
#include "HealthPrint.h"
//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <RefHealthPrint>
//
//
//------------------------------------------------------------------------

class RefHealthPrint : public HealthPrint
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //

    string getDisease();
    
    virtual void display();

//------------------------------------------------- Surcharge d'opérateurs
    RefHealthPrint & operator = ( const RefHealthPrint & unRefHealthPrint );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    //RefHealthPrint ( const RefHealthPrint & unRefHealthPrint );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    RefHealthPrint ( string line, vector<string> & labelOrder );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~RefHealthPrint ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE
private: 
//----------------------------------------------------- Méthodes privées

//----------------------------------------------------- Attributs privés   
    string disease;
protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <RefHealthPrint>

#endif // RefHealthPrint_H
