/*************************************************************************
                           UserInterface  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/


//-------- Interface de la classe <UserInterface> (fichier UserInterface.h) ------------
#if ! defined ( USERINTERFACE_H )
#define USERINTERFACE_H

//--------------------------------------------------- Interfaces utilisées
#include <iostream>
#include <vector>
#include "Analyzer.h"

//------------------------------------------------------------------------
// Rôle de la classe <UserInterface>
// Cette classe est l'interface utilisateur de l'application sur la console
//------------------------------------------------------------------------
class UserInterface
{
//----------------------------------------------------------------- PUBLIC
public:
//----------------------------------------------------- Méthodes publiques
	// Mode d'emploi :
    	// Elle permet de gérer le login des utilisateurs avec leurs identifiants
	// Puis leur permet de choisir entre les fonctionnalités de l'application
	// qui sont: affichage d'historique, le choix des maladies de référence
	// et l'analyse d'empreintes patient
	// Elle a aussi une commande help pour afficher les instructions
	void Run();
	
//-------------------------------------------- Constructeurs - destructeur
	UserInterface();

	virtual ~UserInterface();
	
private:
//----------------------------------------------------- Méthodes privées
	// Mode d'emploi
	// Cette méthode demande à l'utilisateur de rentrer son nom d'utilisateur
	// et son mot de passe dans la console
	// S'ils sont valides, renvoie le nom d'utilisateur
	// Sinon, renvoie string vide
	std::string Login();
	
	//Methode active ou desactive l'affichage de ce que l'utilisateur
	// tappe dans le terminal
	//Utilisée pour ne pas afficher le mot de passe lors du login
	void EnableEcho(bool);

//----------------------------------------------------- Attributs privés
	// Prompteur de la console de l'interface utilisateur
	std::string prompt;
	
	// Objet analyser s'occupe du traitement des empreintes: création du modèle,
	// calcul des probabilités, gestion de l'historique
	Analyzer analyzer;

	
};


#endif // UserInterface_H
