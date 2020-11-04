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
	
	for(int i=0;i<=s-p;i++)
	{	
		int count=0;
		for(int j=0;j<p;j++)
		{
			if(myvector.at(i+j)!=pat[j])
			{
				break;
			}
			else
			{
				count++;
			}	
		}
			
		if(count==p)
		{
			cout << "Pattern Found at Index " << i << endl;
		}
	}
	
	
	return 0;
}
  
