#if ! defined (SPLIT_H)
#define SPLIT_H

#include <string>
#include <vector>

using namespace std;

inline vector<string> split(string str, string sep = " ")
{
	string token;
	vector<string> res;
	while(str != ""){

	  
	  if(str.find_first_of(sep) == string::npos)
	  {
		res.push_back(str);
		return res;
	  }
	  
	  token = str.substr(0,str.find_first_of(sep));
	  str = str.substr(str.find_first_of(sep) + 1);
	  res.push_back(token);
	  
	}
	return res;
}

#endif /* split.h */
