#include <openssl/sha.h>
#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>

int main(int, char**)
{
    unsigned char hash[SHA256_DIGEST_LENGTH];
    const std::string message{"CMake is awesome!"};
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, message.c_str(), message.size());
    SHA256_Final(hash, &sha256);

    std::stringstream ss; 
    for(const auto& c : hash)
    {
        ss << std::hex << std::setw(2) << std::setfill('0') << (int)c;
    }

    std::cout << "The sha256 hash of the message '" << message << "' is:\n";
    std::cout << "\t" << ss.str() << "\n";
}