#include <iostream>

int process(std::istream &in, std::ostream &out)
{
    std::string line;
    bool writeToOutput = true;

    while (std::getline(in, line))
    {
        if (line == "42")
        {
            writeToOutput = false;
        }

        if (writeToOutput)
        {
            out << line << "\n";
        }
    }

    return 0;
}
