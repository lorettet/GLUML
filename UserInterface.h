#include <iostream>
#include <vector>

class UserInterface
{
	private:
		// methodes
		bool Login();
		void EnableEcho(bool);
		std::vector<std::string> split(std::string str, std::string sep = " ");

		// variables
		const std::string prompt = "> ";

	public:
		UserInterface();

		virtual ~UserInterface();

		void Run();
};
