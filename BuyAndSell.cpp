class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int min=prices[0];
      
       int profit = 0;
       for(int i=1;i<prices.size();i++)
       {
           int x = prices[i]-min;
           if(prices[i]<min )
           {
               min = prices[i];
              
           }
           if(x>profit)
           {
               profit = x;
           }
       } 
       return profit;
    }
};