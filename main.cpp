#include <iostream>
#include "Transaction.h"
#include "Block.h"
#include "Blockchain.h"
#include "Wallet.h"
#include "HashUtil.h"

int main() {
  Blockchain myBlockchain;
  Wallet userWallet;

  Transaction tx1 = userWallet.createTransaction("recipientAddressHere", 50.0);
  myBlockchain.createTransaction(tx1);

  myBlockchain.minePendingTransactions(userWallet.getAddress());

  double balance = userWallet.getBalance();
  std::cout << "User's balance: " << balance << std::endl;

  return 0;
}
