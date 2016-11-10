///////////Insertion Sort Algorithm/////////////////
////////////////////////////////////////////////////
////////////Written by Yuze Liu/////////////////////

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <time.h>

using namespace std;

//This function will get all the name and put them into a vector//
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



int main()
{
  //static const int arr[] = {16,2,77,29,100,1,45,72,0,33,29,1};
  //vector<int> nums (arr, arr + sizeof(arr) / sizeof(arr[0]) );
  
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
  string keyName;
  for(unsigned int i=1;i< nums.size();i++)

    {
      int key=nums[i];
      keyName=names[i];
      int j=i-1;
      vector<int>::iterator it;
      vector<string>::iterator iit;
      while (j>=0 && nums[j]>key)
       {
         it = nums.begin();
         it = nums.insert (it+j, key);
         iit = names.begin();
         iit= names.insert (iit+j,keyName);
         nums.erase(nums.begin()+j+2);
         names.erase(names.begin()+j+2);
         --j;
        
       }
     
   }

  t2=clock();
  for(unsigned int i=0;i<nums.size();i++)
     {
       cout << nums[i] << " "<< names[i] <<endl;
     }
   float diff((float)t2-(float)t1);
   float runningTime = (float)diff/CLOCKS_PER_SEC;
   cout << "The running time is: " << runningTime << endl;
  return 0;
}
