# DSA-Project-Financial Helper
 
# Introduction:
 
In this project we tried to build a library which contains methods to assist people with their financial decisions using optimized algorithms. 
 
**The following services are provided:-**
 
1. Calculating the maximum possible profit using only one buy and one sell operation.
 
2. Calculating the maximum possible profit using minimal buy and sell trading operations
 
3. Building a model which would predict the best day to buy and sell shares to achieve a specific profit the earliest.
 
4. Risk analysis for each trade in order to make the maximum profit from that trade.
 
5. Finding the span of a stock’s price on a given day.
 
6. Calculating the maximum value of trades that can be executed under a complexity constraint.
 
7. Calculating the total cost of the mortgage.
 
8. Checking if it is possible to carry out a sequence of currency exchange to end up with more money than initial investment.
 
## Technical Aspects 
 
This code contains one class which has eight structures. Each structure contains various functions that help carry out the above mentioned operations. 
 
### Data Structures
 
The following data structures have been used in this project:-
 
1. Vector
2. Stacks
3. Priority Queue
4. Unordered Maps
5. Directed Graph
 
 
## Detailed explanation of the code
 
The class FinancialHelper contains eight structures that would carry out the operations desired by the user. Once the user selects a specific operation, the functions specified in that structure are carried out. 
 
### 1. Profit Maximization 
The maximum possible profit is calculated using only one buy and one sell operation.
 
The input contains the number of days and the predicted share prices for those days. The output gives out a single integer which is the maximum possible profit.
 
It contains two member functions:-
1. Help() which gives information about the operation. 
2. Methodstart() which performs the actual calculation. 
 
#### Sample
 
##### Test case 1:-
 
Enter Number of Days: 14
 
Enter 14 values:  5 1 6 3 2 5 6 1 3 6 2 5 5 10
 
Maximum Profit: 9
 
*Explanation:-Buy the stock on day 2 for $1 and sell on the last day for $ 10.*
 
##### Test case 2:-
 
Enter Number of Days: 8
 
Enter 8 values: 100 10 12 5 6 14 5 6
 
Maximum Profit: 9
 
*Explanation:-Buy the stock on day 4 for $5 and sell after 2 days for $ 14.*
 
### 2. Profit Maximization Extended
The maximum possible profit is calculated using minimal buy and sell trading operations.
 
Through this operation the maximum possible profit is given while using the smallest possible trading operations over a given period of time, according to a given sequence of predicted share prices. The input contains the number of days and the predicted share prices for those days.The output contains a single integer which is the maximum profit using the smallest number of trading operations possible throughout the given time.
 
It contains two member functions:-
1. Help() which gives information about the operation. 
2. Methodstart() which calculates the maximum possible profit. 
 
#### Sample
 
##### Test case 1:-
 
Enter Number of Days: 14
 
Enter 14 values:  5 1 6 3 2 5 6 1 3 6 2 5 5 10
 
Maximum Profit: 22
 
*Explanation:-The smallest operation required is 8. This can be achieved by:-*
1. Buy at day 2 for $1 and selling the next day for $6 to get a $5 profit.
2. Then, buy after 2 days at $2 and sell on the second day for $6 to make a $4 profit.
3. Then buy for $1, sell for $6 to make $5.
4. And lastly buy at $2 , sell for $10 on the last day to make $8.
 
*Therefore, the total profit = 5+5+5+8= 22.*
 
##### Test case 2:-
 
Enter Number of Days: 8
 
Enter 8 values: 100 10 12 5 6 14 5 6
 
Maximum Profit: 12
 
*Explanation:-The smallest operation required is 6.*
 
### 3. Fast Profit 
 
Predicts the best days to buy and sell to get desired profit
 
Through this operation the data is analyzed to build a model which will predict the best day to buy and sell shares to achieve a specific profit the earliest. 
 
INPUT: The number of days for which the share values are predicted and the profits that need to be achieved. 
 
OUTPUT: The output would contain the day on which the share was bought and the day on which the share was sold to achieve the given profits. 
If is not possible to achieve the desired profit, -1 is returned.
 
It contains three member functions:-
1. Help() which gives information about the operation. 
2. Methodstart() 
3. Solution() 
 
#### Sample
 
##### Test case 1:-
 
Please input the number of days for which you have predicted values: 6
 
Please enter 6 values:  3 1 2 1 4 5 
 
Enter number of queries: 2
 
What is the desired target for profits? 3 2 
 
To make desired profit in shortest amount of time you should buy and sell on the following days respectively: 
4 5,
3 5
 
 
*Explanation:-*
1. To achieve a profit of 3, we can buy on either day 2 or day 4 and sell on day 5. Or we can buy on day 3 and sell on day 6. However, the approach that takes the minimum number of days is when we buy on day 4 and sell on day 5. Thus, 4 5 is the answer.
2. To achieve a profit of 2 , we can buy on day 1 & sell on day 6 or buy on day 3 and sell on day 5. Since 3 5 have lesser number of days, that is the answer.
 
##### Test case 2:-
 
 
Please input the number of days for which you have predicted values: 6
 
Please enter 6 values:  3 6 9 8 2 4 
 
Enter number of queries: 2
 
What is the desired target for profits? 5 2 
 
To make desired profit in shortest amount of time you should buy and sell on the following days respectively: 
1 4,
2 4 
 
### 4. Risk Trading 
 
In this operation risk analysis is done for each trade in order to make the maximum profit from that trade.
 
It would require the input of the number of trades available & allowed, probability that a trade would make profit, potential profit and loss of the trade.It would calculate & return the maximum expected amount of money that can be made considering the given constraints, probablities and prices.
 
It contains two member functions:-
1. Help() which gives information about the operation. 
2. Methodstart() 
 
#### Sample
 
##### Test case 1:-
 
Enter the number of trades available: 4
 
Enter the maximum number of trades allowed: 2
 
Enter 4 Probabilities: 0.5 0.5 0.5 0.5
 
Enter 4 potential profit values: 4.0 1.0 2.0 3.0
 
Enter 4 potential loss values: 4.0 5.0 1.0 1.0
 
Maximum expected amount of money that can be made: 1.50
 
*Explanation:-There are 4 transactions available and we can perform atmost 2 of them. The probablilty that each transaction results in a profit is 0.5. If the 3rd and 4th transactions are performed, expected amount of money: (0.5*2.0)-((1-0.5)*1.0)+(0.5*3.0)-((1-0.5)*1.0)=1.5. This is greater than all the other possibilities that we could calculate therefore this is the answer.*
 
##### Test case 2:-
 
Enter the number of trades available: 2
 
Enter the maximum number of trades allowed: 2
 
Enter 2 Probabilities: 0.9 0.5
 
Enter 2 potential profit values: 1.0 0.5
 
Enter 2 potential loss values: 100.0 0.4
 
Maximum expected amount of money that can be made: 0.05
 
*Explanation:-There are 2 transactions available and we can perform atmost 2 of them. The probability that the first transaction is profitable is 0.9, and for the 2nd it is 0.5.If the 2nd transaction is performed, expected amount of money: (0.5*0.5)-((1-0.5)*0.4)=0.05. This is greater than all the other possibilities that we could calculate therefore this is the answer.*
 
### 5. Stock Span
 
Finds the span of the stock’s price on a given day.
 
In this problem we have a series of n daily price quotes for a stock and we need to calculate the span of stock’s price for all n days. The span of the stock’s price on a given day is defined as the maximum number of consecutive days just before the given day, for which the price of the stock on the current day is less than or equal to its price on the given day.
 
How do we do this? 
 
Iterate all element of array and push index in stack. Now pop index from stack when current value greater than or equal top index of stack. At the end of this there will two possible state of stack
 
Case 1: When stack is empty that means, all previous prices was smaller than current prices Case 2: When stack is not empty that means, there is atleast one price which higher than current prices.
 
It contains two member functions:-
1. Help() which gives information about the operation. 
2. Methodstart() 
 
#### Sample
 
##### Test case 1:-
 
Enter the number days: 6
 
Enter n space-separated integer for the price of stock on n consecutive days: 
 
10 4 5 90 120 80
 
The stock span for day 1=1
 
The stock span for day 2=1
 
The stock span for day 3=2
 
The stock span for day 4=4
 
The stock span for day 5=5
 
The stock span for day 6=1
 
 
##### Test case 2:-
 
Enter the number days: 8
 
Enter n space-separated integer for the price of stock on n consecutive days: 
 
12 4 5 15 2 3 4 7
 
The stock span for day 1=1
 
The stock span for day 2=1
 
The stock span for day 3=2
 
The stock span for day 4=4
 
The stock span for day 5=1
 
The stock span for day 6=2
 
The stock span for day 7=3
 
The stock span for day 8=4
 
 
### 6. Wise Investing
 
Calculates the maximum value of trades that can be executed under a complexity constraint.
 
We are given a maximum total complexity of trades that we can fulfill in one day. We are given a list of trades to choose from. Each one has a value, v and a complexity, c. We need to find the maximum value of trades that can be executed, given the complexity constraint. Input: The inputs are a pair of arrays, v and c, and a maximum complexity, mc. The elements of v represent trade value in millions of dollars and is any positive integer. The complexity is between 0-100 and represents a percentage. The maximum complexity is a scalar integer.
 
*Returns: The maximum value of trades that can be executed.*
 
It contains three member functions:-
1. Help() which gives information about the operation. 
2. Methodstart() 
3. helper()
 
#### Sample
 
##### Test case 1:-
 
Enter no. of trades: 3
 
Enter n space-separated integer for Trade values: 
6 10 12
 
Enter n space-separated integer for complexities: 
30 60 90
 
Enter maximum complexity:
150
 
Maximum value of trade that you can execute is: 22
 
*Explanation:-A profit of 22 is achieved by trading 2 for a trade value of 10 + trading 3 with trade value of 12 adding upto a total complexity of 60+90=150.*
 
##### Test case 2:-
 
Enter no. of trades: 5
 
Enter n space-separated integer for Trade values:  
10 22 56 45 45
 
Enter n space-separated integer for complexities: 
5 14 22 18 24
 
Enter maximum complexity: 
20
 
Maximum value of trade that you can execute is: 45
 
*Explanation:-A profit of 45 is achieved by trading 4 for a trade value of 45 and total complexity of 18.*
 
### 7. Mortgage Repayment
 
Calculates the total cost of the mortgage.
 
A client might want to know what the total estimated cost of their mortgage would be, before signing the contract.
Therefore, we have developed a method which takes in three things – the initial level of debt, the percentage interest and the percentage repayment.
 
Returns:-
A single integer representing the total cost of the mortgage. (Repayment is a fixed percentage of the initial debt, and the interest is a percentage of the current debt.)
 
It contains two member functions:-
1. Help() which gives information about the operation. 
2. Methodstart() 
 
#### Sample
 
##### Test case 1:-
 
Enter 3 space-separated three integers – the initial level of debt, the percentage interest, and the percentage repayment:
 
1000 5 10
 
The total cost of the mortgage is: 1100
 
 
##### Test case 2:-
 
Enter 3 space-separated three integers – the initial level of debt, the percentage interest, and the percentage repayment:
 
578624457 10 15
 
The total cost of the mortgage is 6.36487e+08
 
 
### 8. Forex Trading 
 
Checks if it is possible to carry out a given currency exchange with a profit at the end of the exchange.
 
It contains three member functions:-
1. Help() which gives information about the operation. 
2. helper()
3. Methodstart()
 
#### Sample
 
##### Test case 1:-
 
Enter n = no. of currencies and m = no. of exchanges:-
4 4 
 
Enter m rows of space separated integers x y w, where x y w represent a unidirectional exchange edge from x to y with exchange rate w.(w can be given as log(1/(no. of units of y in exchange of 1 unit of x))):
 
1 2 -5
 
4 1 2
 
2 3 2
 
3 1 1
 
Yes, there exists an exchange cycle such that if you start with 1 unit of some currency, perform a sequence of exchanges, and get more than one unit of the same currency in Forex Trading.
 
 
*Explanation:-*
If we start with 1 unit of currency 1 and exchange it for currency 2 we get 32 units of currency 2 as exchange rate is -5 (we (units of x[i])*2^(-w[i])units of currency y[i] for exchange with x[i]). Following that if these 32 units of currency 2 is exchanged with 3, we end up with 8 units of currency 3 and finally exchanging currency 3 with 1 we get 4 units of currency 1.
Therefore, we started with 1 unit of currency 1 and ended with 4 units of 1 in one cycle. If the following cycle is followed again and again infinite profit can be earned.*
 
##### Test case 2:-
 
Enter n = no. of currencies and m = no. of exchanges:
3 3
 
Enter m rows of space separated integers x y w, where x y w represent a unidirectional exchange edge from x to y with exchange rate w.(w can be given as log(1/(no. of units of y in exchange of 1 unit of x))):
 
1 2 7
 
1 3 5
 
2 3 2
 
There exist no such exchange cycle for the given data. 
 
 
*Explanation:-Following any path for currency exchange does not lead to profit a profit, therefore no such cycle exists.*
 
 

