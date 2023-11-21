#ifndef BLOCK_H
#define BLOCK_H

#include <vector>
#include <string>
#include <iostream>
#include "Transaction.h"

class Block {
private:
  int index = 0;
  long long timestamp;
  std::vector<Transaction> transactions;
  std::string previousHash;
  std::string hash;
  int nonce;

public:
  Block();
  Block(const std::string& previousHash);

  void addTransaction(const Transaction& transaction);
  long long generateTimestamp() const;
  std::string calculateHash(int nonce) const;
  long long getTimestamp() const;
  void printBlockTransactions() const;
  std::string getPreviousHash() const;
  std::string getHash() const;
  int getNonce() const;
  void mineBlock(const int& difficulty);

  void printBlock() const;
};

#endif
