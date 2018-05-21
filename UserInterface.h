#include <iostream>
#include <vector>
#include "Analyzer.h"

class UserInterface
{
	private:
		// methodes
		bool Login();
		void EnableEcho(bool);

		// variables
		const std::string prompt = "> ";
		const std::string defaultHisto = "./Historique.txt";
		Analyzer* analyzer;

	public:
		UserInterface();

		virtual ~UserInterface();

		void Run();
};
