#include <iostream>
#include <vector>

class UserInterface
{
	private:
		// methodes
		bool Login();
		void EnableEcho(bool);

		// variables
		const std::string prompt = "> ";

	public:
		UserInterface();

		virtual ~UserInterface();

		void Run();
};
