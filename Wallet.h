#ifndef WALLET_H
#define WALLET_H

#include <string>
#include "Transaction.h"
#include <openssl/rsa.h>

class Wallet {
private:
  RSA* keyPair;
  std::string publicKey;
  std::string privateKey;
  std::string address;

public:
  Wallet();
  ~Wallet();

  void generateKeyPair();

  double getBalance();

  Transaction createTransaction(const std::string& recipientAddress, double amount);

  void signTransaction(Transaction& transaction);

  std::string getAddress() const;

  std::string getPublicKey() const;
};

#endif
