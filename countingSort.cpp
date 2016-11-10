////////////Counting Sort Algorithm///////////////////////////
//////////////////////////////////////////////////////////////
////////Written by Yuze Liu///////////////////////////////////
#include <iostream>
#include <vector>
#include <string>
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
    //vector<int> nums{2,5,3,0,2,3,0,3};
    //vector<string> str{"a","b","c","d","e","f","g","h"};
   
    string content;
    string whole;
    while(getline(cin,content))
      {
        whole = whole + content;
      }

    vector<string> str = getWords(whole);
    vector<string> number= getNumber(whole);
    vector<int> nums;
  
    for(string::size_type i=0;i<number.size();i++)
        {
          string s = number[i];
          int value = atoi(s.c_str());
          nums.push_back(value);
        }

   
    vector<int> sortedVec;
    vector<string> sortedStr;
    clock_t t1,t2;
    t1=clock();
    int key=0;
    for(unsigned int i=0;i<nums.size();++i)
      {
         if(nums[i]>key)
           {
              key = nums[i];
           }
  
       }  
     vector<int> couVec;
     for(int i=0;i <= key;i++)
       {
         couVec.push_back(0);
       }
     
     for(unsigned int i=0;i<nums.size();++i)
       { 
          int position = nums[i];
          ++couVec[position];
       }
     
     vector<int> newCount;
     newCount.push_back(couVec[0]);

     for(unsigned int i=0;i<couVec.size();++i)
       {
          newCount.push_back(newCount[i]+couVec[i+1]);
       
       }
     
     for(unsigned int i=0;i < nums.size();i++)
       {
         sortedVec.push_back(0);
       }
     for(unsigned int i=0;i < nums.size();i++)
       {
         sortedStr.push_back(" ");
       }

     for(int i =nums.size()-1;i>=0;--i)
       {
          int val=nums[i];
          //string strval=str[i];
          int newVal=newCount[val]-1;
          --newCount[val];
          sortedVec[newVal]=sortedVec[newVal]+val;
          sortedStr[newVal]=str[i];
          
       }
      t2=clock();
      float diff((float)t2-(float)t1);
      float runningTime = diff/CLOCKS_PER_SEC;
   for(unsigned int i=0;i<sortedVec.size();i++)
      {
         cout<< sortedVec[i] << " " << sortedStr[i] <<endl;
      }
    cout <<"The running time is: " << runningTime <<endl;
   return 0;
}
