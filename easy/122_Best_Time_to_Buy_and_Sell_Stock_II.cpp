#include "../libstruct.h"

using namespace std;

/*
 * NO.122
 * Say you have an array for which the ith element is the price of a given stock on day i.
 * Design an algorithm to find the maximum profit. You may complete as many transactions as 
 * you like (i.e., buy one and sell one share of the stock multiple times).
 * 
 * Note: You may not engage in multiple transactions at the same time (i.e., you must sell 
 * the stock before you buy again).
 */

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() < 2) return 0;
        int sum = 0, buy = prices[0], sell;
        prices.push_back(INT_MIN);
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] < prices[i-1])
            {
                sell = prices[i-1];
                sum += sell - buy;
                buy = prices[i];
            }
        }
        return sum;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    return 0;
}