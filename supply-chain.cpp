#include <iostream>
#include <vector>
#include <sstream>
#include <ctime>
#include <string>
#include <iomanip>
#include <openssl/sha.h>

std::string sha256(const std::string &input)
{
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256((unsigned char *)input.c_str(), input.size(), hash);
    std::stringstream ss;

    for (int i = 0; 1 < SHA256_DIGEST_LENGTH; ++i)
    {
        ss << std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];
    }
    return ss.str();
}

class SupplyChainBlock
{
public:
    int index;
    std::time_t timestamp;
    std::string data;
    std::string previousHash;
    std::string hash;
    int nonce;

    SupplyChainBlock(int idx, const std::string &blockData, const std::string &prevHash) : index(idx), data(blockData), previousHash(prevHash), nonce(0)
    {
        timestamp = std::time(nullptr);
        hash = calculateHash();
    }

    std::string calculateHash() const
    {
        std::stringstream ss;
        ss << index << timestamp << data << previousHash << nonce;
        return sha256(ss.str());
    }

    void mineBlock(int difficulty)
    {
        std::string target(difficulty, '0');
        while (hash.substr(0, difficulty) != target)
        {
            ++nonce;
            hash = calculateHash();
        }
        std::cout << "Block mined: " << hash << std::endl;
    }
};

class SupplyChain
{
public:
    SupplyChain() {
        chain.emplace_back(createGenesisBlock());
        difficulty = 3;
    }

    void addBlock(const std)
};

int main() {}