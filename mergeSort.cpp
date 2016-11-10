///////////Merge Sort Algorithm///////////
//////////////////////////////////////////
//////Written by Yuze Liu/////////////////
#include <vector>
#include <iostream>
#include <time.h>

using namespace std;

typedef vector<int>::iterator vec_it;
typedef vector<string>::iterator string_it;

vector<string> getWords(string s)
{
    vector<string> parts;
    const char characters[]= "aAbBcCdDeEfFgGhHiIjJkKlLmMnNoOpPqQrRsStTuUvVwWxXyYzZ";
    string::size_type from=0;
    string::size_type to=s.length();

    while(from != s.length())
    {
       from = s.find_first_of(characters,from);
       if(from <s.length())
        { to = s.find_first_not_of(characters,from);

          if(to<s.length())
            { parts.push_back(s.substr(from,to-from));
             from = to;
            }
          else if(to == s.length())
             parts.push_back(s.substr(from,s.length()-from-1));
          else
            { parts.push_back(s.substr(from,s.length()-from));
              break;
            }
        } 
        else if(from == s.length())
          parts.push_back(s.substr(from));
        else
          from = s.length();
        
    }
    
    return parts;
}

//This function will get all the numbers and put them in a vector//
vector<string> getNumber(string s)
{
    vector<string> parts;
    const char characters[]= "0123456789";
    string::size_type from=0;
    string::size_type to=s.length();

    while(from != s.length())
    {
       from = s.find_first_of(characters,from);
       if(from <s.length())
        { to = s.find_first_not_of(characters,from);

          if(to<s.length())
            { parts.push_back(s.substr(from,to-from));
             from = to;
            }
          else if(to == s.length())
             parts.push_back(s.substr(from,s.length()-from-1));
          else
            { parts.push_back(s.substr(from,s.length()-from));
              break;
            }
        }
        else if(from == s.length())
          parts.push_back(s.substr(from));
        else
          from = s.length();

    }
    
    return parts;
}



void merge(vec_it left, vec_it left_end, vec_it right, vec_it right_end, vec_it numbers, string_it leftStr, string_it leftStr_end, string_it rightStr, string_it rightStr_end, string_it names)
{
    while (left != left_end) {
        if (*left < *right || right == right_end) {
            *numbers = *left;
            *names = *leftStr;
            ++left;
            ++leftStr;
        } else {
            *numbers = *right;
            *names = *rightStr;
            ++right;
            ++rightStr;
        }

        ++numbers;
        ++names;
    }

    while (right != right_end) {
        *numbers = *right;
        *names = *rightStr;
        ++right;
        ++rightStr;
        ++numbers;
        ++names;
    }
}

void merge_sort(vector<int>& numbers,vector<string>& names)
{
    if (numbers.size() <= 1) 
    {
        return;
    }

    vector<int>::size_type middle = numbers.size() / 2;
    vector<string>::size_type middleStr =names.size()/2;

    vector<int> left(numbers.begin(), numbers.begin() + middle);
    vector<int> right(numbers.begin() + middle, numbers.end());

    vector<string> leftStr(names.begin(),names.begin()+middleStr);
    vector<string> rightStr(names.begin()+middleStr,names.end());

    merge_sort(left,leftStr);
    merge_sort(right,rightStr);

    merge(left.begin(), left.end(), right.begin(), right.end(), numbers.begin(), leftStr.begin(),leftStr.end(),rightStr.begin(),rightStr.end(),names.begin());
}

int main()
{
  string content;
  string whole;
  while(getline(cin,content))
    {
      whole = whole + content;
    }

  vector<string> names = getWords(whole);
  vector<string> number= getNumber(whole);
  vector<int> nums;
  
  for(string::size_type i=0;i<number.size();i++)
      {
        string s = number[i];
        int value = atoi(s.c_str());
        nums.push_back(value);
      }
  clock_t t1,t2;
  t1=clock();
  merge_sort(nums,names);
  t2=clock();
  for(unsigned int i=0;i<number.size();i++)
    { 
       cout<< nums[i]<< " " << names[i] <<endl;
    }
  float diff ((float)t2-(float)t1);
  float runningTime = diff / CLOCKS_PER_SEC;
  cout <<"The running time is: " << runningTime <<endl;
  return 0;
}
