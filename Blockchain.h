#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H

#include <vector>
#include <string>
#include "Block.h"
#include "Transaction.h"

class Blockchain {
private:
  std::vector<Block> chain;

public:
  Blockchain();
  void addBlock(Block block);
};

#endif
