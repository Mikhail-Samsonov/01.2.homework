#include <algorithm>
#include <iostream>
#include <vector>
#include "process.h"

auto compare = [](const ip_address& a, const ip_address& b)
{
	for (int i = 0; i < 4; i++)
		if (a[i] != b[i]) return a[i] > b[i];

	return true;
};

auto print = [](const std::vector<ip_address>& ip,
		std::function<bool(const ip_address&)> is_act)
{
	for (const auto& i: ip)
		if (is_act(i)) std::cout << i << std::endl;
};

auto act_all = [](const ip_address& ip)
{ return true; };

auto act_1st_eq_1 = [](const ip_address& ip)
{ return ip[0] == 1; };

auto act_1st_eq_46_and_2nd_eq_70 = [](const ip_address& ip)
{ return ip[0] == 46 && ip[1] == 70; };

auto act_any_eq_46 = [](const ip_address& ip)
{
	for (const auto& i: ip)
	{
		if (i == 46)
			return true;
	}
	return false;
};


int main()
{
	try
	{
		// контейнер
		std::vector<ip_address> ip;
		ip.reserve(1000);

		// чтение
		for (std::string line; std::getline(std::cin, line);)
		{
			size_t pos = line.find_first_of('\t');
			std::string s;
			if (pos != std::string::npos && pos > 0)
			{
				s = line.substr(0, pos);
			}
			else
			{
				throw std::runtime_error("Invalid input!");
			}
			ip.push_back(splitter(s, '.'));
		}

		// сортировка
		sort(ip.begin(), ip.end(), compare);

		// вывод
		print(ip, act_all);
		print(ip, act_1st_eq_1);
		print(ip, act_1st_eq_46_and_2nd_eq_70);
		print(ip, act_any_eq_46);
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}