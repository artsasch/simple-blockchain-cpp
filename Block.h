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
  Block(long long ts, const std::vector<Transaction>& txs, const std::string& prevHash);
  std::string calculateHash() const;
  void mineBlock(int difficulty);
  long long getTimestamp() const;
  std::vector<Transaction> getTransactions() const;
  std::string getPreviousHash() const;
  std::string getHash() const;
  int getNonce() const;
};

#endif
