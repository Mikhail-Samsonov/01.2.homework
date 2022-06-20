#include <gtest/gtest.h>
#include <random>
#include "process.h"

TEST(suite_split, name_split)
{
	int from{ 0 };
	int to{ 255 };

	std::random_device rd;
	std::mt19937 mersenne(rd());
	std::uniform_int_distribution<> dis(from, to);

	std::string a;
	std::stringstream buf;

	for (int it{ 0 }; it < 100000; it++)
	{
		int i = dis(mersenne);
		int j = dis(mersenne);
		int k = dis(mersenne);
		int t = dis(mersenne);

		buf.str("");
		buf.clear();
		a = "";
		a.clear();
		buf << i << '.' << j << '.' << k << '.' << t;
		buf >> a;

		ip_address address(splitter(a, '.'));
		ASSERT_EQ(address[0], i);
		ASSERT_EQ(address[1], j);
		ASSERT_EQ(address[2], k);
		ASSERT_EQ(address[3], t);
	}
}

int main(int argc, char** argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}