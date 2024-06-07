#include "googletest/googletest/include/gtest/gtest.h"
#include <sstream>
#include "../include/ParentDisplay.h"

class ParentDisplayTest : public ::testing::Test {
protected:
    ParentDisplay parentDisplay;
};

TEST_F(ParentDisplayTest, TrimLeadingAndTrailingSpaces) {
    std::string input = "   Hello, World!   ";
    std::string expected = "Hello, World!";
    EXPECT_EQ(parentDisplay.trim(input), expected);
}

TEST_F(ParentDisplayTest, TrimNoSpaces) {
    std::string input = "Hello";
    std::string expected = "Hello";
    EXPECT_EQ(parentDisplay.trim(input), expected);
}

TEST_F(ParentDisplayTest, TrimOnlySpaces) {
    std::string input = "   ";
    std::string expected = "";
    EXPECT_EQ(parentDisplay.trim(input), expected);
}

TEST_F(ParentDisplayTest, PrintPageBreak) {
    std::stringstream buffer;
    std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());

    parentDisplay.printPageBreak();

    std::cout.rdbuf(old);

    std::string expected = "\n-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_\n\n";
    EXPECT_EQ(buffer.str(), expected);
}

// Testing getInput function is more complex as it requires handling stdin.
// We'll use a helper function to simulate input.
std::string simulateInput(ParentDisplay& display, const std::string& input, const std::string& prompt) {
    std::stringstream inputBuffer(input);
    std::streambuf* oldIn = std::cin.rdbuf(inputBuffer.rdbuf());

    std::stringstream outputBuffer;
    std::streambuf* oldOut = std::cout.rdbuf(outputBuffer.rdbuf());

    std::string result = display.getInput(prompt);

    std::cin.rdbuf(oldIn);
    std::cout.rdbuf(oldOut);

    return result;
}

TEST_F(ParentDisplayTest, GetInputValid) {
    std::string prompt = "Enter something: ";
    std::string input = "  user input  \n";
    std::string expected = "user input";
    std::string result = simulateInput(parentDisplay, input, prompt);
    EXPECT_EQ(result, expected);
}

TEST_F(ParentDisplayTest, GetInputEmpty) {
    std::string prompt = "Enter something: ";
    std::string input = "\n  user input\n";
    std::string expected = "user input";
    std::string result = simulateInput(parentDisplay, input, prompt);
    EXPECT_EQ(result, expected);
}
