#include "UserInterface.h"
#include "termios.h"

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
	return;
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
		auto cmd = strs[0];
		if(cmd=="?" || cmd=="help")
		{
			cout << "TODO : display help" << endl;
		}
		else if(cmd == "exit")
		{
			return;
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
	return (login=="root" && passwd=="toor");
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
