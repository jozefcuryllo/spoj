#include <gtest/gtest.h>
#include "../shared/MockStream.cpp"
#include "Code.cpp"

TEST(MainTest, GreenAssertions)
{

    char buffer[] = "5\n6\n16 52\n82\n42\n91\n9\n\n";
    mock_stream in(buffer, 0, sizeof(buffer) / sizeof(char));

    testing::internal::CaptureStdout();
    int res = process(in, std::cout);
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(0, res);
    EXPECT_EQ("5\n6\n16 52\n82\n", output);
}

TEST(MainTest, EdgeCaseMinimumAssertions)
{
    char buffer[] = "42\n91\n9\n\n";
    mock_stream in(buffer, 0, sizeof(buffer) / sizeof(char));

    testing::internal::CaptureStdout();
    int res = process(in, std::cout);
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(0, res);
    EXPECT_EQ("", output);
}