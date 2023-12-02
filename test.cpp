#include "./Squirrel2/Squirrel2.h"
#include "gtest/gtest.h"


// ТЕСТЫ
TEST(RandFloatTest, MaxMinEquality) {
    // тест 1
    float min = 5; 
    float max = min;
    EXPECT_EQ(5, rand_float(min, max));
}


TEST(FillBagTest, NonStandartSuit) {
    // тест 2
    float* bag = new float[1000000];
    int count = 1000000;
    float min_w = -10;
    float max_w = 20;
    EXPECT_EQ(false, fill_bag(bag, count, min_w, max_w));
    delete bag;
}


TEST(AverageMakeTest, ZeroCountSuit) {
    // тест 3
    float* arr = new float[1000000];
    for (size_t i = 0; i < 1000000; i++) {
        arr[i] = i;
    }
    int count = 0;
    float avg;
    EXPECT_EQ(false, average(arr, count, avg));
    delete arr;
}
 

TEST(AverageMakeTest, StandartSuit) {
    // тест 4
    float* arr = new float[2];
    for (size_t i = 0; i < 2; i++) {
        arr[i] = i;
    }
    int count = 2;
    float avg;
    EXPECT_EQ(true, average(arr, count, avg));
    delete arr;
}
 

int main(int argc, char** argv) {
	// run tests
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
