#include <experimental/iterator>
#include <iostream>
#include <sstream>
#include <vector>
#include "../ip_filter.h"

ipAddress split(const std::string& str, char delim) {
  ipAddress a;

  std::istringstream input{str};
  std::stringstream strToInt;

  int b{0};

  for (std::string strByte; std::getline(input, strByte, delim);) {
    strToInt.str("");
    strToInt.clear();

    strToInt << strByte;
    strToInt >> b;

    if (a.size() >= 4 || strToInt.fail() || b < 0 ||
        b > 255)
      throw std::runtime_error("Invalid ip address!");

    a.push_back(b);
  }

  if (a.size() < 4)
    throw std::runtime_error("Invalid ip address!");

  return a;
}

std::ostream& operator<<(std::ostream& os, const ipAddress& ip) {
  copy(ip.begin(), ip.end(), std::experimental::make_ostream_joiner(os, "."));
  return os;
}