#ifndef COMMANDHANDLER_H
#define COMMANDHANDLER_H

#include "Wallet.h"
#include "Block.h"
#include "Transaction.h"
#include "Blockchain.h"
#include <vector>
#include <string>

void handleCreateWallet(Wallet*& w, const std::vector<std::string>& commands);
void handlePrintWallet(Wallet* w);

#endif