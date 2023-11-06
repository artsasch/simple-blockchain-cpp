#ifndef BLOCK_H
#define BLOCK_H

#include <vector>
#include <string>
#include "Transaction.h"

class Block {
private:
  long long timestamp;
  std::vector<Transaction> transactions;
  std::string previousHash;
  std::string hash;
  int nonce;

public:
  Block(long long timestamp, const std::vector<Transaction>& transactions, const std::string& previousHash);
  std::string calculateHash() const;
  int calculateNonce() const;
  void mineBlock(int difficulty);
  long long getTimestamp() const;
  std::vector<Transaction> getTransactions() const;
  std::string getPreviousHash() const;
  std::string getHash() const;
  int getNonce() const;
};

#endif
