#include "MyLibrary/MyLibrary.h"

int main(int arg_c, char *arg[]) {
  std::filesystem::create_directories("./docs");
  MyLibrary library_1("docs/Books_data_base.txt", "docs/Readers_data_base.txt");

  char answer;
  char temp_chapter;
  std::string temp_string;
  std::string temp_string_1;

  while (true) {
    std::cout << "Choose any operation from list below:\n"
              << "        1. Show books in library\n"
              << "        2. Show readers in library\n"
              << "        3. Show readers books\n"
              << "        4. Find book\n"
              << "        5. Find reader\n"
              << "        6. Add book\n"
              << "        7. Add reader\n"
              << "        8. Give book to reader\n"
              << "        9. Get book from reader\n"
              << "        0. Quit\n"
              << "Yore answer: ";

    std::cin >> answer;
    std::cout << std::endl;
    std::cin.get();

    switch (answer) {
    case '1':
      library_1.ShowBooks();
      break;

    case '2':
      library_1.ShowReaders();
      break;

    case '3':
      std::cout << "Put reader name: ";
      std::cin.get(temp_chapter);
      temp_string.clear();
      while (temp_chapter != '\n') {
        temp_string += temp_chapter;
        std::cin.get(temp_chapter);
      }

      library_1.ShowReadersBooks(temp_string);
      break;

    case '4':
      std::cout << "Put book name: ";
      std::cin.get(temp_chapter);
      temp_string.clear();
      while (temp_chapter != '\n') {
        temp_string += temp_chapter;
        std::cin.get(temp_chapter);
      }
      library_1.FindBook(temp_string) ? std::cout << "This book exist\n"
                                                  << std::endl
                                      : std::cout << "This book dosen't exist\n"
                                                  << std::endl;
      break;

    case '5':
      std::cout << "Put reader name: ";
      std::cin.get(temp_chapter);
      temp_string.clear();
      while (temp_chapter != '\n') {
        temp_string += temp_chapter;
        std::cin.get(temp_chapter);
      }
      library_1.FindReader(temp_string) ? std::cout << "This reader exist\n"
                                                    << std::endl
                                        : std::cout << "This reader "
                                                    << "dosen't exist\n"
                                                    << std::endl;
      break;

    case '6':
      std::cout << "Put book name: ";
      std::cin.get(temp_chapter);
      temp_string.clear();
      while (temp_chapter != '\n') {
        temp_string += temp_chapter;
        std::cin.get(temp_chapter);
      }
      library_1.AddBook(temp_string);
      break;

    case '7':
      std::cout << "Put reader name: ";
      std::cin.get(temp_chapter);
      temp_string.clear();
      while (temp_chapter != '\n') {
        temp_string += temp_chapter;
        std::cin.get(temp_chapter);
      }
      library_1.AddReader(temp_string);
      break;

    case '8':
      std::cout << "Put book name: ";
      std::cin.get(temp_chapter);
      temp_string.clear();
      while (temp_chapter != '\n') {
        temp_string += temp_chapter;
        std::cin.get(temp_chapter);
      }
      std::cout << "Put reader name: ";
      std::cin.get(temp_chapter);
      temp_string_1.clear();
      while (temp_chapter != '\n') {
        temp_string_1 += temp_chapter;
        std::cin.get(temp_chapter);
      }
      if (library_1.FindBook(temp_string) &&
          library_1.FindReader(temp_string_1))
        library_1.GiveBookToReader(temp_string, temp_string_1);
      break;

      case '9':
      std::cout << "Put book name: ";
      std::cin.get(temp_chapter);
      temp_string.clear();
      while (temp_chapter != '\n') {
        temp_string += temp_chapter;
        std::cin.get(temp_chapter);
      }
      std::cout << "Put reader name: ";
      std::cin.get(temp_chapter);
      temp_string_1.clear();
      while (temp_chapter != '\n') {
        temp_string_1 += temp_chapter;
        std::cin.get(temp_chapter);
      }
      if (library_1.FindBook(temp_string) &&
          library_1.FindReader(temp_string_1))
        library_1.GetBookFromReader(temp_string, temp_string_1);
      break;

    case '0':
      return 0;

    default:
      std::cout << "Incorrect answer!\n";
    }

    std::cout << std::endl;
  }

  return 0;
}