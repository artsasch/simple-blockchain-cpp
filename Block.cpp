#include "Block.h"
#include "HashUtil.h"
#include "Transaction.h"
#include <ctime>
#include <string>

Block::Block(const std::vector<Transaction> &transactions, const std::string &previousHash)
    : timestamp(generateTimestamp()), transactions(transactions), previousHash(previousHash), hash(calculateHash(timestamp)) {}

long long Block::generateTimestamp() const {
   return std::time(nullptr);
}

long long Block::getTimestamp() const {
  return timestamp;
}

std::string Block::calculateHash(long long timestamp) const {
  std::string str_timestamp = std::to_string(timestamp);
  return HashUtil::sha256(str_timestamp);
}

std::string Block::getHash() const {
  return hash;
}

std::string Block::getPreviousHash() const {
  return previousHash;
}

void Block::printBlock() const {
  std::cout << "Block's timestamp: " << this->timestamp << std::endl;
  std::cout << "Block's previousHash: " << this->previousHash << std::endl;
  std::cout << "Block's hash: " << this->hash << std::endl;
}

void Block::printBlockTransactions() const {
  for (const Transaction& transaction : transactions) {
    transaction.printTransactionData();
    std::cout << "--------------------------" << std::endl;
  }
}