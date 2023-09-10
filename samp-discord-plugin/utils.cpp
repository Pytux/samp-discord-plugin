#include "utils.h"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

namespace UTILS
{
	std::vector<std::string> UTILS::splitString(const std::string& input, char delimiter)
	{
			std::vector<std::string> result;
			std::stringstream ss(input);
			std::string token;

			while (std::getline(ss, token, delimiter)) {
				result.push_back(token);
			}

			return result;
	}
}