#ifndef HASHUTIL_H
#define HASHUTIL_H

#include <string>
#include <openssl/sha.h>
#include <sstream>
#include <iomanip>
#include <vector>
#include <algorithm>

const std::string BASE58_ALPHABET = "123456789ABCDEFGHJKLMNPQRSTUVWXYZabcdefghijkmnopqrstuvwxyz";

class HashUtil {
public:
  static std::string sha256(const std::string& input) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, input.c_str(), input.size());
    SHA256_Final(hash, &sha256);

    std::stringstream ss;
    for(int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
      ss << std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];
    }

    return ss.str();
  }

  static std::string base58Encode(const std::vector<unsigned char>& input) {
    std::vector<int> digits(input.size() * 138 / 100 + 1, 0);

    for (size_t i = 0; i < input.size(); ++i) {
        int carry = input[i];
        for (size_t j = 0; j < digits.size(); ++j) {
            carry += digits[j] << 8;
            digits[j] = carry % 58;
            carry /= 58;
        }
    }

    std::string result;
    for (size_t i = 0; i < digits.size(); ++i) {
        result += BASE58_ALPHABET[digits[i]];
    }

    for (size_t i = 0; i < input.size() && input[i] == 0; ++i) {
        result += '1';
    }

    std::reverse(result.begin(), result.end());
    return result;
  }

  static std::vector<unsigned char> hexStringToByteArray(const std::string& hex) {
    std::vector<unsigned char> bytes;
    for (size_t i = 0; i < hex.length(); i += 2) {
      std::string byteString = hex.substr(i, 2);
      unsigned char byte = static_cast<unsigned char>(strtol(byteString.c_str(), nullptr, 16));
      bytes.push_back(byte);
    }
    return bytes;
  }
};

#endif
