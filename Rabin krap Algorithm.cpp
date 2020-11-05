#include<string.h>
#include<iostream>
#include<vector>
#include<fstream>
#include <bits/stdc++.h>
# define NO_OF_CHARS 256 
using namespace std;
 

#define d 256
void get_input(vector<char>& vec)
{
    char c;
    while (1)
    {
        c = getchar();
        if (c == '\n')
        break;
        vec.push_back(c);
    }
    return;
}
 
int main()
{
	fstream newfile;
    vector<char>myvector;
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
    
     string pattern="971121";
    char *text,*pat;
    text=&myvector[0];
    text[myvector.size()]='\0';
    pat=&pattern[0];
    pat[pattern.size()]='\0';
    int q = 101;  // A prime number
	int p=0;
	int h=1;
	int t=0;
    int pattenlen = pattern.length();
    int stringlen = myvector.size();
    int j;
   
 
	j=0;
    while (j< pattenlen-1){
	
        h = (h*d)%q;
 		j++;
}
j=0;
    while (j <pattenlen)
    {
        p = (d * p + pattern[j]) % q;
        t = (d * t + myvector[j]) % q;
        j++;
    }
 
j=0;
    while (j <= stringlen - pattenlen)
    {
 
        
        if ( p == t )
        {
            
            for (i = 0; i < pattenlen; i++)
            {
                if (myvector[j + i] != pattern[i])
                    break;
            }
            if (i == pattenlen)  
            {
                printf("Pattern found at Index %d \n", j);
            }
        }
 
        
        if ( j < stringlen - pattenlen)
        {
            t = (d * (t - myvector[j] * h) + myvector[j + pattenlen]) % q;
 
            if (t < 0)
                t = (t + q);
        }
        j++;
    }

    return 0;
}
 

 
 

 

