#include <string>
#include "buffered_channel.h"

int main(int argc, char const *argv[])
{
    BufferedChannel<std::string> ch(4);
    return 0;
}