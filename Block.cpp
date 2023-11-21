#include "Block.h"
#include "Blockchain.h"
#include "HashUtil.h"
#include "Transaction.h"
#include <ctime>
#include <string>
#include <vector>

Block::Block()
    : timestamp(generateTimestamp()),
      transactions(),
      previousHash("0"),
      nonce(0) {}

Block::Block(const std::string &previousHash)
  : timestamp(generateTimestamp()),
    transactions(),
    previousHash(previousHash),
    nonce(0){}

void Block::addTransaction(const Transaction& transaction) {
  transactions.push_back(transaction);
}

long long Block::generateTimestamp() const {
   return std::time(nullptr);
}

long long Block::getTimestamp() const {
  return timestamp;
}

std::string Block::calculateHash(int nonce) const {
  std::string str_nonce = std::to_string(nonce);
  return HashUtil::sha256(str_nonce);
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
  std::cout << "--------------------------" << std::endl;
  for (const Transaction& transaction : transactions) {
    transaction.printTransactionData();
    std::cout << "--------------------------" << std::endl;
  }
}

void Block::mineBlock(const int& difficulty) {
  std::string target(difficulty, '0');
  std::cout << "Mining started" << std::endl;

  do {
    nonce++;
    hash = calculateHash(nonce);
    std::cout << nonce << std::endl;
  } while (hash.substr(0, difficulty) != target);

  std::cout << "Block mined: " << hash << std::endl;
}