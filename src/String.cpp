#include "String.h"


TString::TString()
{
  length = 0;
  string = 0;
  countSplit = 0;
  countFinds = 0;
  countStringOfSymbols = 0;
}

TString::TString(char* _string) : TString()
{
  if (_string == 0) throw "Length of string == 0";
  length = StrLen(_string) + 1;
  string = new char[length];
  for (int i = 0; i < length; i++)	string[i] = _string[i];
}

TString::TString(int len, char c) : TString()
{
  if (len <= 0) throw "Length of string == 0";
  length = len + 1;
  string = new char[length];
  for (int i = 0; i < len; i++)  string[i] = c;
  string[len] = '\0';
}

TString::TString(const TString& p)
{
  countStringOfSymbols = p.countStringOfSymbols;
  countSplit = p.countSplit;
  countFinds = p.countFinds;
  length = p.length;
  string = new char[length];
  for (int i = 0; i < length; i++)	string[i] = p.string[i];
}

TString::~TString()
{
  if (string != 0)
  {
	delete[] string;
	string = 0;
  }
  length = 0;
  countSplit = 0;
  countFinds = 0;
  countStringOfSymbols = 0;
}

char* TString::GetString()
{
  return string;
}

void TString::SetString(char* _string)
{
  if (_string == 0) throw "Length of string == 0";
  length = StrLen(_string) + 1;
  string = new char[length];
  for (int i = 0; i < length; i++)	string[i] = _string[i];
}

int TString::GetLength()
{
  return length;
}

int TString::StrLen(const char* str)
{
  int i = 0;
  while (str[i] != '\0')  i++;
  return i;
}

int TString::Find(char c)
{
  for (int i = 0; i < length - 1; i++)	if (string[i] == c) return i;
  return -1;
}

int* TString::Find(TString& p)
{
  int* tmp = new int[length - 1];
  int count = 0;
  int k = 0;
  if (p.length > length)  throw "Word size is too big";
  for (int i = 0; i < length; i++)
  {
	bool flag = 1;
	for (int j = 0; j < p.length - 1; j++)
	{
	  if (string[i + j] != p.string[j])
	  {
		flag = 0;
		break;
	  }
	}
	if (flag == 1) {
	  tmp[k] = i;
	  k++;
	  count++;
	}
  }
  if (k == 0) throw "No entry";
  int* ind = new int[count];
  for (int i = 0; i < count; i++)	ind[i] = tmp[i];
  delete[] tmp;
  SetCountOfFindIndexes(count);
  return ind;
}

int TString::GetCountOfSplit()
{
  return countSplit;
}

int TString::GetCountOfFindIndexes()
{
  return countFinds;
}

int TString::GetCountStringOfSymbols()
{
  return countStringOfSymbols;
}

TString* TString::Split(char c)
{
  int count = 0;
  for (int i = 0; i < length - 1; i++)	if (string[i] == c)	count++;
  if (count == 0) return this;
  count++;
  TString* strings = new TString[count];
  int start = 0;
  int index = 0;
  for (int i = 0; i < length; i++)
  {
	if (string[i] == c)
	{
	  strings[index].length = i - start + 1;
	  delete[] strings[index].string;
	  strings[index].string = new char[strings[index].length];
	  for (int j = 0; j < strings[index].length - 1; j++)  strings[index].string[j] = string[j + start];
	  strings[index].string[strings[index].length - 1] = '\0';
	  index++;
	  start = i + 1;
	}
  }
  strings[index].length = length - start;
  delete[] strings[index].string;
  strings[index].string = new char[strings[index].length];
  for (int k = 0; k < strings[index].length; k++)  strings[index].string[k] = string[k + start];
  index++;
  SetCountOfSplit(count);
  return strings;
}

TString TString::operator+(const char* s)
{
  if (s == 0) return *this;
  TString A;
  int len = length + StrLen(s);
  A.string = new char[len];
  A.length = len;
  for (int i = 0; i < length - 1; i++)	A.string[i] = string[i];
  for (int j = length - 1; j < len; j++)  A.string[j] = s[j - length + 1];
  return A;
}

TString TString::operator+(const TString& p)
{
  if (p.string == 0) return *this;
  TString A;
  int len = length + p.length - 1;
  A.string = new char[len];
  A.length = len;
  for (int i = 0; i < length - 1; i++)	A.string[i] = string[i];
  for (int j = length - 1; j < len; j++)  A.string[j] = p.string[j - length + 1];
  return A;
}

TString& TString::operator=(const TString& p)
{
  if (this == &p) return *this;
  if (string != 0)  delete[] string;
  length = p.length;
  string = new char[length];
  for (int i = 0; i < length; i++)	string[i] = p.string[i];
  return *this;
}

TString& TString::operator=(const char* s)
{
  if (string != 0) delete[] string;
  length = StrLen(s) + 1;
  string = new char[length];
  for (int i = 0; i < length; i++)	string[i] = s[i];
  return *this;
}

TString& TString::operator+=(const char* s)
{
  if (StrLen(s) == 0) return *this;
  int len = length + StrLen(s);
  char* c = new char[len];
  for (int i = 0; i < length - 1; i++)	c[i] = string[i];
  for (int j = length; j < len; j++)  c[j] = s[j - length + 1];
  if (string != 0)  delete[] string;
  string = c;
  length = len;
  return *this;
}

TString& TString::operator+=(const TString& p)
{
  if (StrLen(p.string) == 0) return *this;
  int len = length + p.length - 1;
  char* c = new char[len];
  for (int i = 0; i < length - 1; i++)	c[i] = string[i];
  for (int j = length - 1; j < len; j++)  c[j] = p.string[j - length + 1];
  if (string != 0)  delete[] string;
  string = c;
  length = len;
  return *this;
}

bool TString::operator==(TString& p)
{
  if (length != p.length) return false;
  for (int i = 0; i < length; i++)
  {
	if (string[i] != p.string[i]) return false;
  }
  return true;
}

bool TString::operator<(TString& p)
{
  int len = length > p.length ? p.length : length;
  for (int i = 0; i < len; i++)
  {
	if (string[i] < p.string[i]) return true;
	else if (string[i] > p.string[i]) return false;
  }
  if (length >= p.length) return false;
  else return true;
}

bool TString::operator>(TString& p)
{
  int len = length > p.length ? p.length : length;
  for (int i = 0; i < len; i++)
  {
	if (string[i] < p.string[i]) return false;
	else if (string[i] > p.string[i]) return true;
  }
  if (length >= p.length) return true;
  else return false;
}

char& TString::operator[](int n)
{
  if (string == 0) throw "String is empty";
  if (n > length - 1 || n < 0) throw "Out of range";
  return string[n];
}

TString& TString::DoubleStr(int k)
{
  if (string == 0) throw "String is empty";
  int length = StrLen(string) * k + 1;
  char* str = new char[length];
  int start = 0;
  for (int i = 0; i < k; i++)
  {
	for (int j = 0; j < this->length - 1; j++)
	{
	  str[j + start] = string[j];
	}
	start = StrLen(string) * (i + 1);
  }
  str[length - 1] = '\0';
  delete[] string;
  string = str;
  this->length = length;
  return *this;
}

char TString::MostPopularSymbol()
{
  if (string == 0) throw "String is empty";
  int symb[128] = { 0 };
  int index = 0;
  int count = 0;
  for (int i = 0; i < length - 1; i++)  symb[int(string[i])]++;
  for (int j = 0; j < 128; j++)
	if (symb[j] > count)
	{
	  index = j;
	  count = symb[j];
	}

  return index;
}

int** TString::StringOfSymbols()
{
  if (string == 0) throw "String is empty";
  int symb[128] = { 0 };
  int index = 0;
  int count = 0;
  
  for (int i = 0; i < length - 1; i++)
  {
	symb[int(string[i])]++;
	if (symb[int(string[i])] == 1)
	{
	  count++;
	}
  }
  int** res = new int* [count];
  int k = 0;
  for (int j = 0; j < length; j++)
  {
	if (symb[int(string[j])] > 0)
	{
	  res[k] = new int[2];
	  res[k][0] = string[j];
	  res[k][1] = symb[int(string[j])];
	  symb[int(string[j])] = 0;
	  k++;
	}
  }
  SetCountStringOfSymbols(count);
  return res;
}

void TString::SetCountStringOfSymbols(int count)
{
  countStringOfSymbols = count;
}

void TString::SetCountOfSplit(int count)
{
  countSplit = count;
}

void TString::SetCountOfFindIndexes(int count)
{
  countFinds = count;
}

std::ostream& operator<<(std::ostream& B, TString& A)
{
  for (int i = 0; i < A.length; i++)  B << A.string[i];
  return B;
}

std::istream& operator>>(std::istream& B, TString& A)
{
  B >> A.length;
  A.length++;
  if (A.string != 0) delete[] A.string;
  A.string = new char[A.length];
  for (int i = 0; i < A.length - 1; i++)  B >> A.string[i];
  A.string[A.length - 1] = '\0';
  return B;
}
