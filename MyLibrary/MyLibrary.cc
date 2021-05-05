#include "MyLibrary.h"

MyLibrary::MyLibrary(const std::string &books_data_base,
                     const std::string &readers_data_base) {
  books_data_base_ = books_data_base;
  readers_data_base_ = readers_data_base;
  std::ifstream doc_books_data_base(books_data_base,
                                    std::ios::binary | std::ios::app);
  std::ifstream doc_readers_data_base(readers_data_base,
                                      std::ios::binary | std::ios::app);

  std::string temp_string_name_of;
  std::string temp_string_path_to;
  char temp_chapter;

  while (!doc_books_data_base.eof()) {
    doc_books_data_base.get(temp_chapter);
    temp_string_name_of.clear();
    while (temp_chapter != '\n' && !doc_books_data_base.eof()) {
      temp_string_name_of += temp_chapter;
      doc_books_data_base.get(temp_chapter);
    }

    if (doc_books_data_base.eof())
      break;

    doc_books_data_base.get(temp_chapter);
    temp_string_path_to.clear();
    while (temp_chapter != '\n' && !doc_books_data_base.eof()) {
      temp_string_path_to += temp_chapter;
      doc_books_data_base.get(temp_chapter);
    }

    books_map_[temp_string_name_of] = temp_string_path_to;
  }

  while (!doc_readers_data_base.eof()) {
    doc_readers_data_base.get(temp_chapter);
    temp_string_name_of.clear();
    while (temp_chapter != '\n' && !doc_readers_data_base.eof()) {
      temp_string_name_of += temp_chapter;
      doc_readers_data_base.get(temp_chapter);
    }

    if (doc_readers_data_base.eof())
      break;

    doc_readers_data_base.get(temp_chapter);
    temp_string_path_to.clear();
    while (temp_chapter != '\n' && !doc_readers_data_base.eof()) {
      temp_string_path_to += temp_chapter;
      doc_readers_data_base.get(temp_chapter);
    }

    reader_map_[temp_string_name_of] = temp_string_path_to;
  }
}

void MyLibrary::ShowBooks() const {
  std::cout << "Books in library:\n";

  for (auto book_name : books_map_)
    std::cout << book_name.first << std::endl;
}

void MyLibrary::ShowReaders() const {
  std::cout << "Readers in library:\n";

  for (auto reader_name : reader_map_)
    std::cout << reader_name.first << std::endl;
}

void MyLibrary::ShowReadersBooks(const std::string &reader_name) const {
  if (reader_map_.find(reader_name) != reader_map_.end()) {
    std::ifstream reader_file(reader_map_.find(reader_name)->second,
                              std::ios_base::binary);

    char temp_chapter;
    std::string temp_string;

    while (!reader_file.eof()) {
      reader_file.get(temp_chapter);
      temp_string.clear();
      while (temp_chapter != '\n' && !reader_file.eof()) {
        temp_string += temp_chapter;
        reader_file.get(temp_chapter);
      }
      std::cout << temp_string << std::endl;
    }
    return;
  }
  std::cout << "The " << reader_name << " isn't regisrated\n";
  return;
}

bool MyLibrary::FindBook(const std::string &book_name) const {
  if (books_map_.find(book_name) != books_map_.end())
    return true;
  return false;
}

bool MyLibrary::FindReader(const std::string &reader_name) const {
  if (reader_map_.find(reader_name) != reader_map_.end())
    return true;
  return false;
}

bool MyLibrary::AddBook(const std::string &book_name) {
  if (books_map_.find(book_name) == books_map_.end()) {
    const char k_new_book = 'n';
    const char k_existing_book = 'e';
    char answer = k_new_book;

    books_map_[book_name] = "docs/" + book_name + "_books_path_and_readers";
    std::ofstream book_file(books_map_[book_name], std::ios::binary);

    while (true) {
      std::cout << "would you like to create new book or add existing? (n/e): ";
      std::cin >> answer;
      if (answer == 'n') {
        book_file << "docs/" + book_name + ".txt\n";
        std::cout << "book: " << book_name << " created" << std::endl;
        break;
      }

      if (answer == 'e') {
        std::string book_path;
        std::cout << "Put path to the book: ";
        std::cin >> book_path;
        book_file << book_path << std::endl;
        break;
      }

      std::cout << "Wrong answer! try again.\n";
    }
    return true;
  }
  std::cout << "This book already exist!\n";
  return false;
}

bool MyLibrary::AddReader(const std::string &reader_name) {
  if (reader_map_.find(reader_name) == reader_map_.end()) {
    reader_map_[reader_name] = "docs/" + reader_name + "_readers_reading_books";
    return true;
  }
  std::cout << "This reader already exist!\n";
  return false;
}

bool MyLibrary::GiveBookToReader(const std::string &book_name,
                                 const std::string &reader_name) {
  if ((books_map_.find(book_name) != books_map_.end()) &&
      (reader_map_.find(reader_name) != reader_map_.end())) {
    std::fstream reader_file(reader_map_[reader_name],
                             std::ios::binary | std::ios::in | std::ios::out |
                                 std::ios::app);
    std::fstream book_file(books_map_[book_name],
                           std::ios::binary | std::ios::in | std::ios::out |
                               std::ios::app);

    char temp_chapter;
    std::string temp_string;

    while (!reader_file.eof()) {
      reader_file.get(temp_chapter);
      temp_string.clear();
      while (temp_chapter != '\n' && !reader_file.eof()) {
        temp_string += temp_chapter;
        reader_file.get(temp_chapter);
      }
      if (temp_string == book_name)
        return true;
    }
    reader_file.clear();

    reader_file.seekp(0, std::ios_base::end);
    reader_file << book_name << std::endl;
    book_file.seekp(0, std::ios_base::end);
    book_file << reader_name << std::endl;

    return true;
  }
  return false;
}

bool MyLibrary::GetBookFromReader(const std::string &book_name,
                                  const std::string &reader_name) {
  if (reader_map_.find(reader_name) != reader_map_.end()) {
    std::fstream reader_file(reader_map_.find(reader_name)->second,
                             std::ios_base::binary | std::ios::in | std::ios::out); 

    char temp_chapter;
    std::string temp_string;
    std::set<std::string> set_to_write;

    while (!reader_file.eof()) { 
      reader_file.get(temp_chapter);
      temp_string.clear();
      while (temp_chapter != '\n' && !reader_file.eof()) {
        temp_string += temp_chapter;
        reader_file.get(temp_chapter);
      }
      if (temp_string != book_name)
        set_to_write.insert(temp_string);
    }

    reader_file.close();
    reader_file.open(reader_map_.find(reader_name)->second,
                     std::ios_base::binary | std::ios::out | std::ios::trunc);

    for (auto book_name_in_vector : set_to_write)
      reader_file << book_name_in_vector << std::endl;

    reader_file.close();
    return true;
  }
  std::cout << "The " << reader_name << " isn't regisrated\n";
  return false;
}

MyLibrary::~MyLibrary() {
  std::ofstream doc_books_data_base(books_data_base_,
                                    std::ios::binary | std::ios::trunc);
  std::ofstream doc_readers_data_base(readers_data_base_,
                                      std::ios::binary | std::ios::trunc);

  for (auto book : books_map_)
    doc_books_data_base << book.first << std::endl << book.second << std::endl;

  for (auto reader : reader_map_)
    doc_readers_data_base << reader.first << std::endl
                          << reader.second << std::endl;
}