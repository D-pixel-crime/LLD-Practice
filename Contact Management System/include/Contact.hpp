#include <string>
#include <tuple>

#pragma once

class Contact {
private:
  const std::string firstName;
  const std::string lastName;
  const std::string phoneNumber;

public:
  Contact(std::string _first, std::string _last, std::string _phone)
      : firstName(_first), lastName(_last), phoneNumber(_phone) {}

  std::tuple<const std::string &, const std::string &, const std::string &>
  getContactDetails() const {
    return {firstName, lastName, phoneNumber};
  }
};