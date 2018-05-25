#include <iostream>
#include <vector>
#include "Analyzer.h"

class UserInterface
{
	private:
		// methodes
		std::string Login();
		void EnableEcho(bool);

		// variables
		std::string prompt = "> ";
		Analyzer* analyzer;

	public:
		UserInterface();

		virtual ~UserInterface();

		void Run();
};
