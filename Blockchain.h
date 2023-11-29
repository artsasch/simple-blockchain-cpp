#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H

#include <vector>
#include <string>
#include "Block.h"
#include "Transaction.h"

class Blockchain {
private:
  Blockchain() {};
  Blockchain(const Blockchain&) = delete;
  Blockchain& operator=(const Blockchain&) = delete;

  static Blockchain* instance;

  std::vector<Block> chain;
public:
  static Blockchain* getInstance();

  void addBlock(Block& block, const int& difficulty);

  void printBlockchainBlocks() const;
};

#endif