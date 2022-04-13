#pragma once
#include <iostream>

class TString
{
public:

  TString();
  TString(char* _string);
  TString(int len, char c);
  TString(const TString& p);
  ~TString();

  char* GetString();
  void SetString(char* _string);
  
  int GetLength();

  int StrLen(const char* str);
  int Find(char ñ);
  int Find(TString& p);
  int GetCountOfSplit();
  TString* Split(char c);

  TString operator + (const char* s);
  TString operator + (const TString& p);
  TString& operator = (const TString& p);
  TString& operator = (const char* s);
  TString& operator += (const char* s);
  TString& operator += (const TString& p);
  bool operator == (TString& p);
  bool operator < (TString& p);
  bool operator > (TString& p);
  char& operator [] (int n);
  friend std::ostream& operator << (std::ostream& B, TString& A);
  friend std::istream& operator >> (std::istream& B, TString& A);

protected:

  char* string;
  int length;

};