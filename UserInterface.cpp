#include "UserInterface.h"
#include "termios.h"
#include "lib/picosha2.h"
#include <fstream>
#include <unistd.h>
#include "lib/split.h"
#include "string.h"

using namespace std;

UserInterface::UserInterface()
{
#ifdef MAP
	cout << "[DEBUG] Constuction de UserInterface" << endl;
#endif
	analyzer = new Analyzer(defaultHisto);
}

UserInterface::~UserInterface()
{
#ifdef MAP
	cout << "[DEGUB] Destruction de UserInterface" << endl;
#endif
	delete analyzer;
}

void UserInterface::Run()
{
	cout << "lancement de l'appli" << endl;
#ifdef LOGIN
	if(!Login())
	{
		cerr << "Login ou mot de pass incorrect" << endl;
		return;
	}
#endif
	cout << "Connecté" << endl;
	string s;
	cin.clear();
	cout << prompt;
	cin.ignore();
	while(getline(cin,s))
	{
		if(s=="")
		{
			cout << prompt;
			continue;
		}
		
		auto strs = split(s);
		const auto cmd = strs[0];
		const unsigned int nbArgs = strs.size();
		if(cmd=="?" || cmd=="help")
		{
			cout << "help"<<"\t\t\t\t"<<"Affiche l'aide"<<endl;
			cout << "analys-emp file"<<"\t\t\t"<<"Analyse une liste d'empreintes"<<endl;
			cout << "set-ref file"<<"\t\t\t"<<"Spécifie un fichier d'empreinte de référence"<<endl;
			cout << "aff-maladie [nom]"<<"\t\t"<<"Affiche la liste de toutes les maladie ou les caractéristiques d'une malaide en particulier"<<endl;
			cout << "aff-histo [-e nomEmp ] [-d jj/mm/aaaa] [-h empreinte]"<<"\t\t"<<"Affiche l'historique des analyses"<<endl;
		}
		else if(cmd == "exit")
		{
			return;
		}
		else if(cmd == "aff-maladie")
		{
			switch(nbArgs)
			{
				case 1:
					//TODO : mettre le bon appel
					cout << "Affichage de toutes les maladies" << endl;
					break;
				case 2:
					//TODO : mettre le bon appel
					cout << "Affichage des infos de la maladie : " << strs[1] << endl;
					break;
				default:
					cerr << "Too many arguments" << endl;
					break;
			}
		}
		else if(cmd == "set-ref")
		{
			switch(nbArgs)
			{
				case 1:
				case 2:
					cerr << "Vous devez spécifier deux fichier" << endl;
					break;
				case 3:
					analyzer->setRefFile(strs[1],"data/HealthMeasurementDescription.txt");
					cout << "changement de ref"<< endl;
					break;
				default:
					cerr << "Too many arguments" << endl;
					break;
			}
		}
		else if(cmd == "analys-emp")
		{
			switch(nbArgs)
			{
				case 1:
					//TODO : mettre le bon appel
					cerr << "Vous devez spécifier un fichier" << endl;
					break;
				case 2:
					//TODO : mettre le bon appel
					cout << "Traitement des analyses"<< endl;
					break;
				default:
					cerr << "Too many arguments" << endl;
					break;
			}
		}
		else if(cmd == "aff-histo")
		{
			
			char* args[nbArgs];
			for(unsigned int i = 0; i<nbArgs; i++)
			{
				args[i] = strdup(strs[i].c_str());
			}
			string emp;
			string date;
			string hp;
			
			int c;
			
			while((c = getopt(nbArgs, args, "d:e:h:")) != -1)
			{
				switch(c)
				{
					case 'd':
						date = string(optarg);
						break;
					case 'e':
						emp = string(optarg);
						break;
					case 'h':
						hp = string(optarg);
						break;
					default:
						break;
				}
			}

			cout << "emp : "<<emp<<endl;
			cout << "date : "<<date<<endl;
			cout << "hp : "<<hp<<endl;
			
			
			for(unsigned int i = 0; i<nbArgs; i++)
			{
				free(args[i]);
			}
			
			// On reset la fonction optget
			optind=1;
			
			//TODO : appelle à la fonction
			cout << "TODO : appelle à la fonction" << endl;
			
		}
		else
		{
			cout << "Command \"" << cmd << "\" does not exist. Try \"help\" or \"?\"" << endl;
		}
		cout << prompt;
	}
}

bool UserInterface::Login()
{
	string login;
	string passwd;
	cout << "Login : ";
	cin >> login;
	cout << "Password : " ;
	EnableEcho(false);
	cin >> passwd;
	EnableEcho(true);
	cout << endl;
	string hash = picosha2::hash256_hex_string(login+":"+passwd);
	
	ifstream users("file/users.conf",ios::in);
	if(!users)
	{
		cerr << "Le fichier \"users.conf\" n'existe pas" << endl;
		return false;
	}
	
	string user;
	
	while(users>>user)
	{
		if(user==hash)
			return true;
	}
	return false;
	
}

void UserInterface::EnableEcho(bool enable)
{
	struct termios t;

	tcgetattr(0, &t);
	
	if(enable)
	{
		t.c_lflag |= ECHO;
	}
	else
	{
		t.c_lflag &= ~ECHO;
	}
	
	tcsetattr(0, TCSANOW, &t);
}

