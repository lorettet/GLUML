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
//  Cette classe gère les différentes empreintes
//------------------------------------------------------------------------

class HealthPrint
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

    // Mode d'emploi :
    //  Renvoi la liste des attributs numériques avec leur valeur associée
    map<string, double> getNumAttribute(); 
    
    // Mode d'emploi :
    //  Renvoi la liste des attributs catégoriels avec leur valeur associée
    map<string, string> getCatAttribute();
    
    // Mode d'emploi :
    //  Renvoi l'id de l'empreinte
    string getNoID();
    
    // Mode d'emploi :
    //  Affiche une empreinte avec toutes ses informations
    virtual void display();

//------------------------------------------------- Surcharge d'opérateurs
    HealthPrint & operator = ( const HealthPrint & unHealthPrint );

//-------------------------------------------- Constructeurs - destructeur
    // Mode d'emploi :
    //  Créé une empreinte avec line une ligne du fichier d'empreintes
    // et labelOrder décrivant l'ordre des données dans la ligne
    // Contrat :
    //  line doit respecté le format CSV et venir d'un fichier d'empreintes 
    //  et doit respecter l'ordre des données spécifié par labelOrder
    HealthPrint (string line, vector<string> & labelOrder);

    HealthPrint ( );

    virtual ~HealthPrint ( ) = 0;

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    // Liste des attributs numériques avec pour chacun sa valeur pour 
    // cette empreinte
    map<string, double> numAttribute;
  
    // Liste des attributs catégoriels avec pour chacun sa valeur pour 
    // cette empreinte
    map<string, string> catAttribute;
    string noID; // Id de l'empreinte
};

//-------------------------------- Autres définitions dépendantes de <HealthPrint>

#endif // HealthPrint_H
