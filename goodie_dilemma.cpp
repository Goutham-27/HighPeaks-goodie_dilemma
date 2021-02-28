#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <bits/stdc++.h> 
using namespace std;

class goodie
{
	public: string name;
	public: int value;
	
	goodie(string str,int x)
	{
		name = str;
		value = x;
	}
  
  
	// To sort the objects based on value
 bool operator <(const goodie & playerObj) const
    {
        return value < playerObj.value;
    }
};

int main () 
{
  
  
  string myText;
  
  int n = 0;
  int k = 0;

  // Reading the input file	
  ifstream MyReadFile("filename.txt");
  
  int counter = 0;
  int real_counter=0;
  
   list<goodie> goodieList;

  
  while (getline (MyReadFile, myText))
   {
     string s = myText;
     string delim = ":";
     
     
   // Parsing the input values 
    int start = 0;
    int end = s.find(delim);
    string nname;
    while (end != string::npos)
    {
         nname = s.substr(start, end - start);
        start = end + delim.length();
        end = s.find(delim, start);
    }

    string value = s.substr(start, end);
    int vvalue = std::stoi(value);
    
    if(counter>1)
    {
        goodie good(nname,vvalue); 
        goodieList.push_back(good);
        real_counter++;
    }
    
    else if(counter == 1)
     n = vvalue;
     
     else
      k = vvalue;
    
    counter++;
  }
  
  
  goodieList.sort();
  
  // Iterating through the list and finding the minimum difference
  list<goodie>::iterator it = goodieList.begin();
  list<goodie>::iterator it1 = goodieList.begin();
  int difference = INT_MAX;
  int diff=0;
  int position = 0;
  
  
  int i=0,j=0;
  while(i<k-1)
  {
      i++;
      it1++;
      
  }
  
  
  
  while(it1!=goodieList.end())
  {
        j++;
        int first = it->value;
        int second = it1->value;
        
         diff = second-first;
        
        if(diff<difference)
        {
            
         difference = diff;
         position = j;
        }
        
        it++;it1++;
         
  }
  
  
  
  i=0;
  it = goodieList.begin();
  while(i<n)
  {
     i++;
     
     if(i==position)
      break;
      
      else 
      it++;
  }
  
  // Writing the output to a file
  ofstream MyWriteFile("output.txt");

  
  MyWriteFile << "The goodies selected for distribution are"<<endl;
  
  i=0;
  while(i<k)
  {
      MyWriteFile<<it->name<<":";
      MyWriteFile<<it->value<<endl;
      it++;
      i++;
  }
  
  MyWriteFile<<"And the difference between the chosen goodie with highest price and the lowest price is "
                 <<difference<<endl; 
  
  
  MyReadFile.close();
}
