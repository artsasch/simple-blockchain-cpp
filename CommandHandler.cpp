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