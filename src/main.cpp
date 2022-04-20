#include "String.h"

inline void line()
{
  std::cout << std::endl;
}


int main()
{
  char A[] = "ITMM";
  TString str1;
  TString str2(A);
  TString str3(5, 'z');
  TString str4 = str2;
  TString* split;
  int** symbols;
  std::cout << "String: " << str3.GetString() << "\n" << "Length: " << str3.GetLength() << "\n";
  line();

  str1.SetString("I am a student ");
  str3 = A;
  str4 = str1 + str3;
  std::cout << str4;
  line();

  std::cout << "Index of 's' in '"<< str4 << "' == " << str4.Find('s') << "\t";
  line();

  if (str2 == str3) std::cout << "str2 == str3\n";
  if (str1 < str3) std::cout << "str1 < str3\n";
  if (str2 > str4) std::cout << "str2 > str4\n";
  line();

  std::cout << "str2.string[0] == " << str2[0] << std::endl;
  line();

  /*std::cout << "Input the length of A and string:\n"; // Если нужно, раскомментируйте. P.S. Вводить длину строки без нулевого символа.
  std::cin >> str3;
  std::cout << "str3 == " << str3 << std::endl;
  line();*/

  split = str1.Split(' ');
  for (int i = 0; i < str1.GetCountOfSplit(); i++)
  {
	std::cout << split[i] << "\n";
  }
  line();

  str1 += str3;
  str2 = str1.DoubleStr(2);
  
  std::cout << str2 << "\n";
  line();

  int* indexes = str2.Find(str3);
  std::cout << "Indexes of   '" << str3 << "'   in   '" << str2 << "'   ==  ";
  for (int i = 0; i < str2.GetCountOfFindIndexes(); i++)
	std::cout << indexes[i] << "  ";
  line();

  std::cout << "Most popular symbol in '"<< str3 << "' is: '" << str3.MostPopularSymbol() << "'\n";
  line();

  symbols = str3.StringOfSymbols();
  std::cout << "String of symbols in '" << str3 << "' is:\n";
  for (int i = 0; i < str3.GetCountStringOfSymbols(); i++)
	std::cout << "'" << char(symbols[i][0]) << "' - " << symbols[i][1] << "\n";
  line();

  for (int i = 0; i < str3.GetCountStringOfSymbols(); i++) 
	delete[] symbols[i]; 
  delete[] symbols;
  delete[] indexes;
  return 0;
}
