#include "encoder/encoder.h"
#include <string>
std::string encoder(std::string message, int count)
{
    for(int i = 0; i < message.length(); ++i)
        if ((message[i] >= int('A') && message[i] <= int('Z')) || (message[i] >= int('a') && message[i] <= int('z')))
        {
            count %= 26;
            message[i] += count;
            if ((message[i] >= int('Z') + 1 && message[i] <= int('Z') + count) || (message[i] >= int('z') + 1 && message[i] <= int('z') + count))
                message[i] -= 26;
        }
    return message;
}
