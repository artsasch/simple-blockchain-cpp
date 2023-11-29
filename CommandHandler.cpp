#include "CommandHandler.h"
#include <iostream>

void handleCreateWallet(Wallet*& w, const std::vector<std::string>& commands) {
  if (commands.size() < 2) {
    std::cout << "Insufficient arguments for createwallet." << std::endl;
    return;
  }
  int walletAmount = std::stoi(commands[1]);
  delete w;
  w = new Wallet(walletAmount);
  std::cout << "Wallet created." << std::endl;
}

void handlePrintWallet(Wallet* w) {
  if (w != nullptr) {
    w->printWallet();
  } else {
    std::cout << "No wallet created." << std::endl;
  }
}

void handleCreateBlock(Block*& b) {
  if (b != nullptr) {
    std::string prevBlockHash = b->getHash();
    delete b;
    b = new Block(prevBlockHash);
  } else {
    delete b;
    b = new Block();
  }
  std::cout << "Block created." << std::endl;
}

void handleCreateTransaction(Wallet*& w, Block*& b, Transaction*& t, const std::vector<std::string>& commands) {
  int walletBalance = w->getBalance();
  int transactionAmount = std::stoi(commands[3]);
  if (walletBalance >= transactionAmount) {
    int newBalance = walletBalance - transactionAmount;
    w->changeBalance(newBalance);
    delete t;
    t = new Transaction(commands[1], commands[2], transactionAmount, commands[4]);
    b->addTransaction(*t);
    std::cout << "Transaction created and added to block." << std::endl;
  } else {
    std::cout << "Not enough balance on your wallet." << std::endl;
  }
}

void handleAddBlockInBlockchain(Blockchain*& chain, Block*& b, const int& difficulty) {
  chain->addBlock(*b, difficulty);
  std::cout << "Block added in blockchain." << std::endl;
}

void handlePrintBlockTransactions(Block*& b) {
  b->printBlockTransactions();
}

void handlePrintBlockchainBlocks(Blockchain*& chain) {
  chain->printBlockchainBlocks();
}