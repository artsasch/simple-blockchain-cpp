#include "Wallet.h"
#include <openssl/rand.h>
#include <sstream>
#include <iomanip>

Wallet::Wallet(const double balance)
  : privateKey(generatePrivateKey()),
    publicKey(generatePublicKey(privateKey)),
    address(generateAddress(publicKey)),
    balance(balance) {}

std::string Wallet::generatePrivateKey() const {
  unsigned char buffer[32];
  
  RAND_bytes(buffer, sizeof(buffer));
  
  std::stringstream hexStream;
  hexStream << std::hex << std::setfill('0');
  for (int i = 0; i < sizeof(buffer); i++) {
    hexStream << std::setw(2) << (unsigned)buffer[i];
  }
  
  std::string pvtKey = hexStream.str();
  return pvtKey;
}

std::string Wallet::generatePublicKey(const std::string &privateKey) const {
  std::string pblKey = "0" + privateKey;
  return pblKey;
}

std::string Wallet::generateAddress(const std::string &publicKey) const {
  std::string addr = "0" + publicKey;
  return addr;
}

std::string Wallet::getPrivateKey() const {
  return privateKey;
}

std::string Wallet::getPublicKey() const {
  return publicKey;
}

std::string Wallet::getAddress() const {
  return address;
}

double Wallet::getBalance() const {
  return balance;
}