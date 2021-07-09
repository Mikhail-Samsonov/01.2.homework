#include <algorithm>
#include <iostream>
#include <vector>
#include "ip_filter.h"

int main() {
  try {
    std::vector<ipAddress> ipPool;
    ipPool.reserve(1000);

    for (std::string line; std::getline(std::cin, line);) {
      size_t pos = line.find_first_of('\t');
      std::string s;
      if (pos != std::string::npos && pos > 0) {
        s = line.substr(0, pos);
      } else {
        throw std::runtime_error("Invalid input!");
      }
      ipPool.push_back(split(s, '.'));
    }

    auto compare = [](ipAddress a, ipAddress b) {
      for (int i = 0; i < 4; i++) {
        if (a[i] != b[i]) return a[i] > b[i];
      }

      return true;
    };

    sort(ipPool.begin(), ipPool.end(), compare);

    // all
    for (const auto& i : ipPool) {
      std::cout << i << std::endl;
    }

    // 1st eq 1
    for (const auto& i : ipPool) {
      if (i[0] == 1) std::cout << i << std::endl;
    }

    // 1st eq 46 && 2nd eq 70
    for (const auto& i : ipPool) {
      if (i[0] == 46 && i[1] == 70) std::cout << i << std::endl;
    }

    // any eq 46
    for (const auto& i : ipPool) {
      for (const auto& e : i) {
        if (e == 46) {
          std::cout << i << std::endl;
          break;
        }
      }
    }

  } catch (const std::exception& e) {
    std::cerr << e.what() << std::endl;
  }

  return 0;
}