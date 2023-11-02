#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H

#include <vector>
#include <string>
#include "Block.h"
#include "Transaction.h"

class Blockchain {
private:
  std::vector<Block> chain;
  int difficulty;
  std::vector<Transaction> pendingTransactions;
  double miningReward;

public:
  Blockchain();
  void addBlock(Block newBlock);
  bool isChainValid() const;
  void minePendingTransactions(const std::string& miningRewardAddress);
  void createTransaction(const Transaction& transaction);
  double getBalanceOfAddress(const std::string& address) const;
};

#endif
