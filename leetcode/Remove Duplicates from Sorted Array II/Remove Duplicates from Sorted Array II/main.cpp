#include "Solution.h"
#include "gtest\gtest.h"

int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();

	// pause to show the results
	getchar();
	return 0;
}
