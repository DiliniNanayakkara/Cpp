#include<iostream>
#include<string>
#include<bits/stdc++.h>

using namespace std;

void findmin(int n, int score[]);

int main()
{
	int n, k, i, j;
	int score[n+2];
	int mask[n+2];
	int count = 0;
	
	//Number of students
	cin>>n;
	
	
	//Scores for each student
	for(i=1;i<=n;i++)
	{
		cin>>score[i];

	}
	
	score[0] = score[1];
	score[n+1] = score[n];
	
	findmin(n, score);
	
	return 0;
}

void findmin(int n, int score[])
{
	int count = 0;
	int i, j;
	int mask[n+2];
	
	for(i=1;i<=n;i++)
	{
		if((score[i-1]>=score[i]) && (score[i]<=score[i+1]))
		{
			mask[i] = 1;
			
			for(j=i-1;j && (score[j]>score[j+1]);j--)
			{
				mask[j] = mask[j+1]+1;
			}
			
			for(;i<n && (score[i]<score[i+1]);i++)
			{
				mask[i+1] = mask[i]+1;
			}
		}
		
	}
	
	for(i=1;i<=n;i++)
	{
		if((score[i-1]<score[i]) && (score[i]>score[i+1]))
		{
			mask[i] = max(mask[i-1],mask[i+1])+1;
		}
	}
	
	
	//Print the result
	for(i=1;i<=n;i++)
	{
		//cout<<mask[i];
		count = count+mask[i];
	}
	
	cout<<count<<endl;
}
