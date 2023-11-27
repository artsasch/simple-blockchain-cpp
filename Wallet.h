#ifndef WALLET_H
#define WALLET_H

#include <string>
#include "Transaction.h"

class Wallet {
private:
  std::string privateKey;
  std::string publicKey;
  std::string address;
  double balance;

  std::string generatePrivateKey() const;
  std::string generatePublicKey(const std::string& privateKey) const;
  std::string generateAddress(const std::string& publicKey) const;

public:
  Wallet(const double balance);

  void signTransaction(Transaction& transaction);
  std::string getPrivateKey() const;
  std::string getPublicKey() const;
  std::string getAddress() const;
  double getBalance() const;
  void printWallet() const;
};

#endif
