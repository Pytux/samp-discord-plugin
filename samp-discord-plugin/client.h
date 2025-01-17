#pragma once

#include <string>
#include <sstream>
#include <vector>

namespace SAMP
{
	enum EConnectMode {
		SAMP_CONNECT_UNKNOWN,
		SAMP_CONNECT_SERVER,
		SAMP_CONNECT_DEBUG
	};

	struct ServerData {
		EConnectMode connect = SAMP_CONNECT_UNKNOWN;
		std::string address;
		std::string port;
		std::string username;

		std::vector<std::string> getDataFromStream(std::stringstream& stream, std::string default);
	};

	bool readServerData(const char* cmdline, ServerData& data);
}
