#ifndef BLOCK_H
#define BLOCK_H

#include <vector>
#include <string>
#include <iostream>
#include "Transaction.h"

class Block {
private:
  long long timestamp;
  std::vector<Transaction> transactions;
  std::string previousHash;
  std::string hash;
  int nonce;

public:
  Block(const std::vector<Transaction>& transactions, const std::string& previousHash);
  long long generateTimestamp() const;
  std::string calculateHash(long long timestamp) const;
  int calculateNonce() const;
  void mineBlock(int difficulty);
  long long getTimestamp() const;
  void printBlockTransactions() const;
  std::string getPreviousHash() const;
  std::string getHash() const;
  int getNonce() const;

  void printBlock() const;
};

#endif
