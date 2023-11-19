#include <gtest/gtest.h>
#include "../shared/MockStream.cpp"
#include "Code.cpp"

TEST(MainTest, GreenAssertions)
{

    char buffer[] = "2\n1 10\n3 5\n\n";
    mock_stream in(buffer, 0, sizeof(buffer) / sizeof(char));

    testing::internal::CaptureStdout();
    int res = process(in, std::cout);
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(0, res);
    EXPECT_EQ("2\n3\n5\n7\n\n3\n5\n", output);
}

TEST(MainTest, EdgeAssertions)
{

    char buffer[] = "2\n1 10000000\n3 500000\n\n";
    mock_stream in(buffer, 0, sizeof(buffer) / sizeof(char));

    testing::internal::CaptureStdout();
    int res = process(in, std::cout);
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(0, res);
}