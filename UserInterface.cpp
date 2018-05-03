#include "UserInterface.h"
#include "termios.h"
#include "lib/picosha2.h"
#include <fstream>
#include <unistd.h>

using namespace std;

UserInterface::UserInterface()
{
#ifdef MAP
	cout << "[DEBUG] Constuction de UserInterface" << endl;
#endif
}

UserInterface::~UserInterface()
{
#ifdef MAP
	cout << "[DEGUB] Destruction de UserInterface" << endl;
#endif
}

void UserInterface::Run()
{
	cout << "lancement de l'appli" << endl;
	if(!Login())
	{
		cerr << "Login ou mot de pass incorrect" << endl;
		return;
	}
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
		for(auto i : strs)
		{
			cout << i;
		}
		cout << endl;
		if(cmd=="?" || cmd=="help")
		{
			cout << "TODO : display help" << endl;
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
					//TODO : mettre le bon appel
					cerr << "Vous devez spécifier un fichier" << endl;
					break;
				case 2:
					//TODO : mettre le bon appel
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
			
			const char* args[nbArgs];
			for(unsigned int i = 0; i<nbArgs; i++)
			{
				args[i] = (strs[i].c_str());
			}
			string emp;
			string date;
			string idEmp;
			
			int c;
			
			while((c = getopt(nbArgs, (char* const*)args, "d:e:p:")) != -1)
			{
				switch(c)
				{
					case 'd':
						date = string(optarg);
						break;
					case 'e':
						emp = string(optarg);
						break;
					case 'p':
						idEmp = string(optarg);
						break;
					default:
						break;
				}
			}
			
			cout << "emp " << emp << endl;
			cout << "date" << date << endl;
			cout << "idEmp" << idEmp << endl;
			
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

vector<string> UserInterface::split(string str, string sep)
{
	string token;
	vector<string> res;
	while(token != str){
	  token = str.substr(0,str.find_first_of(sep));
	  str = str.substr(str.find_first_of(sep) + 1);
	  res.push_back(token);
	}
	return res;
}
