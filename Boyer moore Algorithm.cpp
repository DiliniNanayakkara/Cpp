#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include <bits/stdc++.h>
# define NO_OF_CHARS 256 


using namespace std;
int main()
{
	string pat="971121";
	
	fstream newfile;
    vector<char> myvector;

    int lineNumber=0, i=0;
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
                for (i = 0; i < 56; i++)
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
	
    int badchar[NO_OF_CHARS];  
	 
    i=0;
	while(i < NO_OF_CHARS){
		badchar[i] = -1;  
        i++;
	}
	
    i=0;
    while (i < p){
		badchar[(int) pat[i]] = i;  
        i++;
	}
  	
    int k = 0;  
                
    while(k <= (s - p)){
	  
        int j = p - 1;  

        while(j >= 0 && pat[j] == myvector.at(k+j)){
        	j--;
		} 
  
        if (j < 0){  
			cout<<"Pattern found at Index " << k+1 <<endl;
			if(k+p<s){
				k=k+p-badchar[myvector[k+p]];
			}
			else{
				k = k+1;
			}
        }    
        else{
        	k = k + max(1, j-badchar[myvector.at(k+j)]);
		}  
		      
    }  
    
    return 0;
}  
  

