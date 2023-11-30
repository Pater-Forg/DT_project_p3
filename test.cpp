#include ".\Squirrel2\Squirrel2.h"
#include "gtest/gtest.h"


using namespace std;

// ТЕСТЫ
TEST(FunctionTesting, rand_float_test) {
    // тест 1
    float min = 5; 
    float max = min;
    EXPECT_EQ(5, rand_float(min, max));
}

TEST(FunctionTesting, fill_bag_test) {
    // тест 2
    float* bag = new float[1000000];
    int count = 1000000;
    float min_w = -10;
    float max_w = 20;
    EXPECT_EQ(false, fill_bag(bag, count, min_w, max_w));
}

TEST(FunctionTesting, average_make_test) {
    // тест 3
    float* arr = new float[1000000];
    int count = 0;
    float avg;
    EXPECT_EQ(false, average(arr, count, avg));
}
 

int main(int argc, char** argv) {
	// run tests
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
