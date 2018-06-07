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
// Cette classe s'occupe de la gestion des maladies.
//------------------------------------------------------------------------

class Disease
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // Mode d'emploi :
    //  Renvoie le nom de la maladie
    string getName();

    // Mode d'emploi :
    //  Renvoie la liste des attributs numérique pris en compte dans
    // pour l'analyse de la maladie ainsi que la moyenne et l'écart-type de chacun
    map<string,pair<double, double>> getNumAttribute();

    // Mode d'emploi :
    //  Renvoie la liste des attributs catégoriels pris en compte dans
    //  l'analyse de la maladie ainsi que le pourcentage d'apparition associé
    // à chaque valeur prise par celui-ci
    map<string,map<string, double>> getCatAttribute();
    
    // Mode d'emploi :
    //  Incremente le nombre de personne ayant la maladie
    void incrNbSickPeople();
    
    // Mode d'emploi :
    //  Renvoi le nombre de personne ayant la maladie
    int getNbSickPeople();
    
    // Mode d'emploi :
    //  Affiche la maladie sur le flux passé en paramétre (console par défaut)
    void display(ostream & os = std::cout);
    
    // Mode d'emploi :
    //  Incrémente le nombre de personne ayant la valeur value pour l'attribut name.
    //  Si l'attribut ou la valeur n'existent pas, les créé et les ajoute à la
    //  liste d'attributs catégoriels.
    void incrCatAttribute(string name, string value);
    
    // Mode d'emploi :
    //  Pour tous les attributs catégoriels de la maladie, et pour toutes les valeurs
    //  de chaque attribut, remplace le nombre de personne ayant l'attribut avec la valeur
    //  par le pourcentage par rapport au nombre total de malades ayant cette maladie.
    void setPercentagesCatAttribute();
    
    // Mode d'emploi :
    //  Ajoute a la liste des attributs numériques l'attribut name ainsi que la moyenne
    // et l'écart-type qui lui sont associés.
    void addNumAttribute(string name, double avg, double sd);

//------------------------------------------------- Surcharge d'opérateurs
//-------------------------------------------- Constructeurs - destructeur

    Disease ( std::string name_d);

    Disease ( );
  
    virtual ~Disease ( );

//------------------------------------------------------------------ PRIVE
private:
    string name; // Nom de la maladie

    // Liste des attributs numériques qui associe à chaque attribut, la moyenne
    //  et l'écart-type de ses valeurs trouvées dans les empreintes de références
    map<string, pair<double, double>> numAttribute;

    // Liste des attributs catégoriels qui associe à chaque attribut une liste des
    // valeurs qu'il peut prendre ainsi que le pourcentage d'apparition de cette valeur
    // dans les empreintes de références
    map<string, map<string, double>> catAttribute;

    int nbSickPeople; // Nombre de personne ayant la maladie

protected:
//----------------------------------------------------- Méthodes protégées
//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <Disease>

#endif // Disease_H
