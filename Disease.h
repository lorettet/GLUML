/*************************************************************************
                           Disease  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Disease> (fichier Disease.h) ----------------
#if ! defined ( DISEASE_H )
#define DISEASE_H

//--------------------------------------------------- Interfaces utilisées
#include <iostream>
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Disease>
//
//
//------------------------------------------------------------------------

class Disease
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //

    string getName();

    map<string,pair<double, double>> getNumAttribute();

    map<string,map<string, double>> getCatAttribute();
    
    void incrNbSickPeople();
    
    int getNbSickPeople();
    
    void display(ostream & os = std::cout);
    
    void incrCatAttribute(string name, string value);
    
    void setPercentagesCatAttribute();
    
    void addNumAttribute(string name, double avg, double sd);

//------------------------------------------------- Surcharge d'opérateurs



//-------------------------------------------- Constructeurs - destructeur
    //Disease ( const Disease & unDisease );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Disease ( std::string name_d);
    // Mode d'emploi :
    //
    // Contrat :
    //

    Disease ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Disease ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE
private:
    string name;

    map<string, pair<double, double>> numAttribute;

    map<string, map<string, double>> catAttribute;

    int nbSickPeople;

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <Disease>

#endif // Disease_H
