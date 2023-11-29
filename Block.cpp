#include "Block.h"

int indexCount = 0;
int tempNonce = 0;

Block::Block()
    : index(indexCount++),
      timestamp(generateTimestamp()),
      transactions(),
      previousHash("0"),
      nonce(0) {}

Block::Block(const std::string &previousHash)
    : index(indexCount++),
      timestamp(generateTimestamp()),
      transactions(),
      previousHash(previousHash),
      nonce(0) {}

void Block::addTransaction(const Transaction& transaction) {
  transactions.push_back(transaction);
}

long long Block::generateTimestamp() const {
   return std::time(nullptr);
}

std::string Block::calculateHash(std::string& hashBlockData, int& nonce) const {
  std::string preHashStr = hashBlockData + std::to_string(nonce);
  return HashUtil::sha256(preHashStr);
}

long long Block::getTimestamp() const {
  return timestamp;
}

std::string Block::getHash() const {
  return hash;
}

std::string Block::getPreviousHash() const {
  return previousHash;
}

void Block::printBlock() const {
  std::cout << "Block's index: " << this->index << std::endl;
  std::cout << "Block's timestamp: " << this->timestamp << std::endl;
  std::cout << "Block's previousHash: " << this->previousHash << std::endl;
  std::cout << "Block's hash: " << this->hash << std::endl;
  std::cout << "Block's nonce: " << this->nonce << std::endl;
}

void Block::printBlockTransactions() const {
  std::cout << "--------------------------" << std::endl;
  for (const Transaction& transaction : transactions) {
    transaction.printTransactionData();
    std::cout << "--------------------------" << std::endl;
  }
}

void Block::mineBlock(const int& difficulty) {
  std::string target(difficulty, '0');
  std::string hashBlockTransactions = HashUtil::hashBlockTransactions(transactions);
  std::string headerBlockStr = std::to_string(index) + std::to_string(timestamp) + previousHash;
  std::string hashBlockData = HashUtil::sha256(hashBlockTransactions + headerBlockStr);

  do {
    tempNonce++;
    hash = calculateHash(hashBlockData, tempNonce);
    std::cout << "hash: " << hash << std::endl;
  } while (hash.substr(0, difficulty) != target);

  nonce = tempNonce;
  tempNonce = 0;
}