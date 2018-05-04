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

//------------------------------------------------- Surcharge d'opérateurs
    HealthPrint & operator = ( const HealthPrint & unHealthPrint );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    HealthPrint ( const HealthPrint & unHealthPrint );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    HealthPrint (string line);
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
};

//-------------------------------- Autres définitions dépendantes de <HealthPrint>

#endif // HealthPrint_H