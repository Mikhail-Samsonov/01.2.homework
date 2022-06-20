#include "process.h"

ip_address splitter(const std::string& str, char delim)
{
	ip_address a;

	std::istringstream input{ str };
	std::stringstream str_to_int;

	int b{ 0 };

	for (std::string byte; std::getline(input, byte, delim);)
	{
		str_to_int.clear();

		str_to_int << byte;
		str_to_int >> b;

		if (a.size() > 3 || str_to_int.fail() || b < 0 || b > 255)
			throw std::runtime_error("Invalid ip address!");

		a.push_back(b);
	}

	if (a.size() != 4)
		throw std::runtime_error("Invalid ip address!");

	return a;
}

std::ostream& operator<<(std::ostream& os, const ip_address& ip)
{
	copy(ip.begin(), ip.end(), std::experimental::make_ostream_joiner(os, "."));
	return os;
}