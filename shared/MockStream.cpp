#include<iostream>


// https://stackoverflow.com/a/53382083
struct mock_membuf : public std::streambuf
{
    mock_membuf(char *begin, char *end)
    {
        this->setg(begin, begin, end);
    }
};

struct mock_stream : public std::istream
{
    mock_membuf streamBuffer;

public:
    mock_stream(char *buffer, int offset, int nbytes)
        : std::istream(nullptr), streamBuffer(buffer + offset, buffer + offset + nbytes)
    {
        rdbuf(&streamBuffer);
    }
};