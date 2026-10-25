#include "include/Contact.hpp"
#include "include/TrieContactsManager.hpp"
#include <iostream>
#include <memory>

int main() {

  auto m = std::make_unique<TrieContactsManager>();

  auto a = std::make_shared<Contact>("A", "B", "+911234567890");
  auto b = std::make_shared<Contact>("B", "C", "+911234567891");
  auto c = std::make_shared<Contact>("C", "D", "+911234567892");
  auto d = std::make_shared<Contact>("D", "E", "+911234567893");

  m->addContact(a.get());
  m->addContact(b.get());
  m->addContact(c.get());
  m->addContact(d.get());

  auto ans = m->getContacts("A");

  for (auto &c : ans) {
    auto [f, l, p] = c->getContactDetails();
    std::cout << f << " " << l << " " << p << std::endl;
  }

  ans = m->getContacts("AB");

  for (auto &c : ans) {
    auto [f, l, p] = c->getContactDetails();
    std::cout << f << " " << l << " " << p << std::endl;
  }

  return 0;
}