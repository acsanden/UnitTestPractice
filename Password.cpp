#include "Password.h"
#include <string>
#include <cctype>

using std::string;


/*
  The function receives a string counts how many times the same character 
  occurs at the beginning of the string, before any other characters (or the
  end of the string). The function is case-sensitive so 'Z' is different than
  'z' and any ASCII characters are allowed.
*/
int Password::count_leading_characters(string phrase){
  int repetition = 1;
  int index = 0;

  while( index < phrase.length()-1 && phrase[index] == phrase[index+1] ){
    repetition++;
    index++;
  }
  return repetition;
}



bool has_mixed_case(string phrase){
  bool is_mixed_case = false;
  int index = 0;
  while( index < phrase.length()-1){
    if(isupper(phrase[index]) && islower(phrase[index+1])){
        is_mixed_case = true;
    }
    if(islower(phrase[index]) && isupper(phrase[index+1])){
      is_mixed_case = true;
    }

  }
  return is_mixed_case;

}
