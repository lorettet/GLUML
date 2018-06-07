#OS
Cette application a été conçu pour tourner sous le système d'exploitation Linux

#Makefile
Executez la commande make pour compiler le projet.
make clean permet de supprimer tous les fichiers compilé
make tests permet de lancer les tests (voir plus bas)
##Paramètres
Vous pouvez donner des paramètres à la commande make pour modifier l'application. Par défaut, l'application compile en mode release, avec le système d'identification, et l'affichage des performances.
* DEBUG=yes/no : Affiche ou non les appelles aux constructeurs et destructeurs
* LOGIN=yes/no : Active ou non le processus d'identification
* PERF=yes/no  : Affiche ou non des informations quant à la performance de set-ref

Utilisez la commande make par exemple comme suit :
`make DEBUG=yes LOGIN=no`

#Fonctionnement de L'application
##Identification
L'application fonctionne avec des identifiants. Ces identifiants sont stockés dans le fichier file/users.conf. Les informations à l'interieur sont hashé (SHA256). Le fichier contient au moins l'utilisateur "root" avec comme mot de passe "toor". Si vous désirez ajouter un utilisateur, utiliser la commande :

`./add-user login password`

Vous devez avoir sur votre ordinateur la commande sha256deep pour ajouter un utilisateur.

##Fonctionnement
L'application ressemple à un terminal. Vous pouvez tapper des commandes pour effectuer les actions désirées. Les commandes sont :

###help	
Affiche l'aide
###analys-emp file
Analyse une liste d'empreintes
###set-ref refFile descFile
Spécifie un fichier d'empreinte de référence. **A faire avant d'effectuer une analyse.**
###aff-maladie [nom]
Affiche la liste de toutes les maladie ou les caractéristiques d'une malaide en particulier.
###aff-histo [-e nomEmp ] [-d jj/mm/aaaa] [-p empreinte]
Affiche l'historique des analyses. Les options permettent de filtrer les données affichées.
* -e : pour un employé
* -d : pour une date
* -p : pour une empreinte
###exit
Ferme l'application. <kbd>Ctrl</kbd> + <kbd>D</kbd> ferme aussi l'application

#Tests
Nous avons réalisé 7 tests qui sont spécfiés dans le manuel de tests. Pour lancer les tests executer la commande `make tests` dans le dossier racine du projet. Cette commande va appeler un script qui va parcourir tous les dossiers de test (test/Test-*) et effectuer le test. Une comparaison entre un fichier écrit en dure et la sortie du programme est alors faite. A la toute fin, vous pouvez voir le nombre de tests qui sont passé

#Git
Le projet se trouve également sur github : <https://github.com/lorettet/GLUML>

