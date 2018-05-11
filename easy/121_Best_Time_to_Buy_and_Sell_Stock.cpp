#include "../libstruct.h"

using namespace std;

/*
 * NO.121
 * Say you have an array for which the ith element is the price 
 * of a given stock on day i.
 * If you were only permitted to complete at most one transaction (i.e., 
 * buy one and sell one share of the stock), design an algorithm to find 
 * the maximum profit.
 * Note that you cannot sell a stock before you buy one.
 */

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        int bug = prices[0], sell = bug, profit = 0;
        for (int i = 0; i < prices.size(); i++) {
            if (prices[i] < bug) {
                bug = prices[i];
                sell = bug;
            }
            if (prices[i] > sell) {
                sell = prices[i];
                profit = max(profit, sell - bug);
            }
        }
        return profit;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    return 0;
}