#include "Wallet.h"
#include "HashUtil.h"
#include <openssl/rand.h>
#include <openssl/ec.h>
#include <openssl/obj_mac.h>
#include <openssl/bn.h>
#include <openssl/ripemd.h>
#include <sstream>
#include <iomanip>
#include <iostream>

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

std::string Wallet::generatePublicKey(const std::string& privateKey) const {
  EC_KEY *key = nullptr;
  BIGNUM *prv = nullptr;
  EC_POINT *pub = nullptr;
  std::string pblKey;

  do {
    key = EC_KEY_new_by_curve_name(NID_secp256k1);
    if (!key) break;

    prv = BN_new();
    BN_hex2bn(&prv, privateKey.c_str());

    if (!EC_KEY_set_private_key(key, prv)) break;

    pub = EC_POINT_new(EC_KEY_get0_group(key));
    if (!EC_POINT_mul(EC_KEY_get0_group(key), pub, prv, nullptr, nullptr, nullptr)) break;
    EC_KEY_set_public_key(key, pub);

    char *hexPub = EC_POINT_point2hex(EC_KEY_get0_group(key), pub, POINT_CONVERSION_COMPRESSED, nullptr);
    pblKey = std::string(hexPub);
    OPENSSL_free(hexPub);
  } while (0);

  EC_POINT_free(pub);
  BN_free(prv);
  EC_KEY_free(key);

  return pblKey;
}

std::string Wallet::generateAddress(const std::string &publicKey) const {
  std::vector<unsigned char> pubKey = HashUtil::hexStringToByteArray(publicKey);

  unsigned char sha256Result[SHA256_DIGEST_LENGTH];
  SHA256(pubKey.data(), pubKey.size(), sha256Result);

  unsigned char ripemd160Result[RIPEMD160_DIGEST_LENGTH];
  RIPEMD160(sha256Result, sizeof(sha256Result), ripemd160Result);

  unsigned char secondSha256[SHA256_DIGEST_LENGTH];
  SHA256(ripemd160Result, sizeof(ripemd160Result), secondSha256);

  std::vector<unsigned char> addressBytes(ripemd160Result, ripemd160Result + RIPEMD160_DIGEST_LENGTH);
  addressBytes.insert(addressBytes.end(), secondSha256, secondSha256 + 4);

  return HashUtil::base58Encode(addressBytes);
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

void Wallet::changeBalance(int& newBalance) {
  balance = newBalance;
}

void Wallet::printWallet() const {
  std::cout << "Block's private key: " << this->privateKey << std::endl;
  std::cout << "Block's public key: " << this->publicKey << std::endl;
  std::cout << "Block's address: " << this->address << std::endl;
  std::cout << "Block's balance: " << this->balance << std::endl;
}