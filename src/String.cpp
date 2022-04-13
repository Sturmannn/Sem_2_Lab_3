#include "String.h"

int count = 0;

TString::TString()
{
  length = 0;
  string = 0;
}

TString::TString(char* _string)
{
  if (_string == 0) throw "Length of string == 0";
  length = StrLen(_string) + 1;
  string = new char[length];
  for (int i = 0; i < length; i++)	string[i] = _string[i];
}

TString::TString(int len, char c)
{
  if (len <= 0) throw "Length of string == 0";
  length = len + 1;
  string = new char[length];
  for (int i = 0; i < len; i++)  string[i] = c;
  string[len] = '\0';
}

TString::TString(const TString& p)
{
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

int TString::Find(TString& p)
{
  if (p.length > length)  return -1;
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
	if (flag == 1)
	  return i;
  }
  return -1;
}

int TString::GetCountOfSplit()
{
  return count;
}

TString* TString::Split(char c)
{
  //int count = 0;
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
	  strings[index].string[strings[index].length] = '\0';
	  index++;
	  start = i + 1;
	}
  }
  strings[index].length = length - start;
  delete[] strings[index].string;
  strings[index].string = new char[strings[index].length];
  for (int k = 0; k < strings[index].length; k++)  strings[index].string[k] = string[k + start];
  index++;
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
  /*if (length <= p.length) return false;
  for (int i = 0; i < p.length; i++)
  {
	if (string[i] < p.string[i]) return false;
  }
  return true;*/
}

char& TString::operator[](int n)
{
  if (string == 0) throw "String is empty";
  if (n > length - 1 || n < 0) throw "Out of range";
  return string[n];
}

std::ostream& operator<<(std::ostream& B, TString& A)
{
  for (int i = 0; i < A.length; i++)  B << A.string[i];
  return B;
}

std::istream& operator>>(std::istream& B, TString& A)
{
  B >> A.length;
  if (A.string != 0) delete[] A.string;
  A.string = new char[A.length + 1];
  for (int i = 0; i < A.length; i++)  B >> A.string[i];
  A.string[A.length] = '\0';
  return B;
}
