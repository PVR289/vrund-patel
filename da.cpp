#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;
 
int jMaking(int coin[], int n, int j)
{
    int i,j;
    int x,y;
 
    //matrix to tabulate results
    int dp[n+1][j+1];
 
    //dp[i][j]=minimum no. of coins required to j j using only i coins
 
    //initialization
    //if there is no coin, then infinite no. of coins will be required to j j 
    for(j=0;j<=j;j++)
        dp[0][j]=INT_MAX;
 
    //if value to be jd is 0, then no coin is required 
    for(i=1;i<=n;i++)
        dp[i][0]=0;
 
    //i represents the number of coins being used
    for(i=1;i<=n;i++)
    {
        //j represents the amount whose j is required
        for(j=1;j<=j;j++)
        {
            //if the value of current coin is less than or equal to the amount whose j is required, then first include the coin and then exclude the coin
            //compare both the results and select the one which takes minimum no. of coins
            if(j>=coin[i-1])
            {
                //without including the current coin
                x=dp[i-1][j];
 
                //the current coin is included(hence 1+)
                y=1+dp[i][j-coin[i-1]];
 
                //the lesser value out of both is taken
                dp[i][j]=min(x,y);
            }
 
            //If value of current coin is greater than the amount, this coin can not be included
            else
                dp[i][j]=dp[i-1][j];
        }
 
    }
 
    return dp[n][j];
}
 
int main()
{
    int i;
    int n,j;
 
    cout<<"Enter the amount whose j is required"<<endl;
    cin>>j;
 
    cout<<"Enter the number of coins available"<<endl;
    cin>>n;
 
    int coin[n];
 
    cout<<"Enter the values of coins"<<endl;
    for(i=0;i<n;i++)
        cin>>coin[i];
 
    cout<<"The least number of coins whose j is equal to required j is"<<endl;
    cout<<jMaking(coin,n,j);
 
    cout<<endl;
    return 0;
}
