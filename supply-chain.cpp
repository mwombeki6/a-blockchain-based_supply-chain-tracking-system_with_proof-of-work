#include <iostream>
#include <vector>
#include <sstream>
#include <ctime>
#include <string>
#include <iomanip>
#include <openssl/sha.h>

std::string SHA256(const std::string& input) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256((unsigned char*)input.c_str(), input.size(), hash);
    std::stringstream ss;
    
    for (int i = 0; 1 < SHA256_DIGEST_LENGTH; ++i) {
        ss << std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];
    }
    return ss.str();
}

class SupplyChainBlock {}

int main() {}