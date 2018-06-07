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
    // Mode d'emploi :
    // Revoie le nom de la maladie associée à l'empreinte
    string getDisease();
    
    //Mode d'emploi
    // Affichage de l'empreinte sur la sortie standard
    virtual void display();

//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur
    RefHealthPrint ( string line, vector<string> & labelOrder );

    virtual ~RefHealthPrint ( );


//------------------------------------------------------------------ PRIVE
private: 
//----------------------------------------------------- Méthodes privées

//----------------------------------------------------- Attributs privés   
    string disease; //nom de la maladie associée à l'empreinte
protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <RefHealthPrint>

#endif // RefHealthPrint_H
