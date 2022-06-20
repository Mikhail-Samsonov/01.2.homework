#ifndef IP_FILTER_H
#define IP_FILTER_H

#include <iostream>
#include <vector>
#include <sstream>
#include <experimental/iterator>

using ip_address = std::vector<int>;

ip_address splitter(const std::string& str, char delim);

std::ostream& operator<<(std::ostream&, const ip_address&);

#endif //IP_FILTER_H