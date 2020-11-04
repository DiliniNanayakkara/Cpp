#include<iostream>
#include<fstream>
#include<string>
#include <bits/stdc++.h>

using namespace std;
int main()
{
	string pat="971121";
	
	fstream newfile;
    vector<char> myvector;

    int lineNumber=0,i;
    newfile.open("pi.txt",ios::in);
    if (newfile.is_open())
    {
      string line;
      while(getline(newfile, line))
      {
        lineNumber++;
        
        if(lineNumber>21)
        {
            if(!line.empty())
            {
                for (int i = 0; i < 54; i++)
                {
                    if (line[i]!=' ')
                    {
                        myvector.push_back(line[i]);
                        
                    }
                }
            }

         }
      }
      newfile.close();
   }
   int s=myvector.size();
	int p=pat.length();
	int lps[p]; 
    int len = 0; 
  
    lps[0] = 0; 
    i = 1; 
    while (i < p) { 
        if (pat[i] == pat[len]) { 
            len++; 
            lps[i] = len; 
            i++; 
        } 
        else  
        {
        
            if (len != 0) { 
                len = lps[len - 1]; 
  
                
            } 
            else 
            { 
                lps[i] = 0; 
                i++; 
            } 
        } 
    }
	i = 0; 
    int j = 0; 
    while (i < s) { 
        if (pat[j] == myvector.at(i)) { 
            j++; 
            i++; 
        } 
  
        if (j == p) { 
            printf("pattern found at Index %d \n", i - j); 
            j = lps[j - 1]; 
        } 
  
        
        else if (i < s && pat[j] != myvector.at(i)) { 
             
            if (j != 0) 
                j = lps[j - 1]; 
            else
                i = i + 1; 
        } 
    } 
}


