#include "Blockchain.h"

void Blockchain::addBlock(Block &block, const int& difficulty) {
  block.mineBlock(difficulty);
  chain.push_back(block);
}

void Blockchain::printBlockchainBlocks() const {
  std::cout << "--------------------------" << std::endl;
  for (const Block& block : chain) {
    block.printBlock();
    std::cout << "--------------------------" << std::endl;
  }
}

Blockchain & Blockchain::getInstance() {
  static Blockchain instance;
  return instance;
}