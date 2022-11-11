#include "decoder/decoder.h"
#include <string>
std::string decoder(std::string message, int count)
{
    for(int i = 0; i < message.length(); ++i)
        if ((message[i] >= int('A') && message[i] <= int('Z')) || (message[i] >= int('a') && message[i] <= int('z')))
        {
            count %= 26;
            message[i] -= count;
            if ((message[i] <= int('A') - 1 && message[i] >= int('A') - count) || (message[i] <= int('a') - 1 && message[i] >= int('a') - count))
                message[i] += 26;
        }
    return message;
}
