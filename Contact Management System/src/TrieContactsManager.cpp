#include "../include/TrieContactsManager.hpp"
#include <set>

void TrieContactsManager::addContact(Contact *c) {
  auto [f, s, p] = c->getContactDetails();
  addToTree(f, c, firstName);
  addToTree(s, c, lastName);
  addToTree(p, c, phone);
}

std::vector<Contact *>
TrieContactsManager::getContacts(const std::string &pref) {
  auto temp = _getContacts(pref, firstName);
  std::set<Contact *> ans(temp.begin(), temp.end());

  temp = _getContacts(pref, lastName);
  ans.insert(temp.begin(), temp.end());

  temp = _getContacts(pref, phone);
  ans.insert(temp.begin(), temp.end());

  return std::vector<Contact *>(ans.begin(), ans.end());
}