#pragma once
#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <filesystem>

class MyLibrary {
private:
  std::map<std::string, std::string> books_map_;
  std::map<std::string, std::string> reader_map_;
  std::string books_data_base_;
  std::string readers_data_base_;

public:
  MyLibrary(const std::string &, const std::string &);
  MyLibrary(const MyLibrary &) = delete;

  void ShowBooks() const;
  void ShowReaders() const;
  void ShowReadersBooks(const std::string &) const;
  bool FindBook(const std::string&) const;
  bool FindReader(const std::string&) const;
  bool AddBook(const std::string &);
  bool AddReader(const std::string &);
  bool GiveBookToReader(const std::string &, const std::string &);
  bool GetBookFromReader(const std::string &, const std::string &);

  ~MyLibrary();
};