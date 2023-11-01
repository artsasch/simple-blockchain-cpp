#ifndef BLOCK_H
#define BLOCK_H

#include <vector>
#include <string>
#include "Transaction.h"

using namespace std;

class Block {
private:
  long long timestamp;
  vector<Transaction> transactions;
  string previousHash;
  string hash;
  int nonce;

public:
  Block(long long ts, const vector<Transaction>& txs, const string& prevHash);
  string calculateHash() const;
  void mineBlock(int difficulty);
  long long getTimestamp() const;
  vector<Transaction> getTransactions() const;
  string getPreviousHash() const;
  string getHash() const;
  int getNonce() const;
};

#endif
