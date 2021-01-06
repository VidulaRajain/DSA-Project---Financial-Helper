#include<bits/stdc++.h>
using namespace std;
#define int long long
 
 
/// @brief Contains the operations a user can carry out 
///
/// This class contains different structures, each performing different banking or investment operations. The user can choose whatever operation they desire. 
class FinancialHelper
{
    public:
        /// @brief The maximum possible profit is calculated using only one buy and one sell operation.  
        ///
        /// The input contains the number of days and the predicted share prices for those days. The output gives out a single integer which is the maximum possible profit.
        struct ProfitMaximization
        {  
         
            /// @returns Information about the operation. 
            void help();
            void MethodStart();
            
        };
 
        /// @brief Max possible profit using minimal buy and sell trading operations
        ///
        /// Through this operation the maximum possible profit is given while using the smallest possible trading operations over a given period of time, according to a given sequence of predicted share prices.
        ///The input contains the number of days and the predicted share prices for those days.The output contains a single integer which is the maximum profit using the smallest number of trading operations possible throughout the given time.
 
        struct ProfitMaximizationExtended
        {
             /// @returns information about the operation. 
            void help();
            void MethodStart();
        };
        /// @brief Predicts the best days to buy and sell to get desired profit. 
        ///
        /// Through this operation the data is analyzed to build a model which will predict the best day to buy and sell shares to achieve a specific profit the earliest.
        ///INPUT: The number of days for which the share values are predicted and the profits that need to be achieved. 
        /// OUTPUT: The output would contain the day on which the share was bought and the day on which the share was sold to achieve the given profits. If is not possible to achieve the desired profit, -1 is returned.
 
        struct FastProfit
        {
            /// @returns information about the operation. 
            void help();
            void MethodStart();
            void Solution(unordered_map<int, int> &m, int target, vector<int> &v);
        };
 
        /// @brief In this operation risk analysis is done for each trade in order to make the maximum profit from that trade.
        ///
        ///  It would require the input of the number of trades available & allowed, probability that a trade would make profit, potential profit and loss of the trade.It would calculate & return the maximum expected amount of money that can be made considering the given constraints, probablities and prices. 
        struct RiskTrading
        { 
            /// @returns information about the operation. 
            void help();
            
            void MethodStart();
        };
 
    ///@brief Finds the span of the stock’s price on a given day. 
    ///
    /// In this problem we have a series of n daily price quotes for a stock 
    ///and we need to calculate the span of stock’s price for all n days. The span of the stock’s price on a given day
    ///is defined as the maximum number of consecutive days just before the given day, for which the price of the stock
    /// on the current day is less than or equal to its price on the given day.
  ///
  /// How do we do this?
///
 ///Iterate all element of array and push index in stack.
 /// Now pop index from stack when current value greater than or equal top index of stack. At the end of this there will two possible state of stack
 ///
 /// Case 1: When stack is empty that means, all previous prices was smaller than current prices
 ///
 /// Case 2: When stack is not empty that means, there is atleast one price which higher than current prices.
 ///
        struct StockSpan
        {             
			/// @returns information about the operation.
            void help();
            void MethodStart();
        };
 
    ///@brief Calculates the maximum value of trades that can be executed under a complexity constraint
    ///
      /// We are given a maximum total complexity of trades that we can fulfill in one day.
    /// We are given a list of trades to choose from. Each one has a value, v and a complexity, c.
    /// We need to find   the maximum value of trades that can be executed, given the complexity constraint.
 ///
///Input: The inputs are a pair of arrays, v and c, and a maximum complexity, mc. 
///The elements of v represent trade value in millions of dollars and is any positive integer.
/// The complexity is between 0-100 and represents a percentage. The maximum complexity is a scalar integer.
///
///@returns The maximum value of trades that can be executed.
        struct WiseInvesting
        {
            /// @returns information about the operation. 
            void help();
            int MethodStart(vector<int> &v,vector<int> &c,int mc,int index_trade,int current_value,int current_complexity,int max_value);
            void helper();
        };
 
    ///@brief Calculates the total cost of the mortgage 
    ///
    /// A client might want to know what the total estimated cost of their mortgage would be, before signing the contract. 
   /// Therefore, we have developed a method which takes in three things – the initial level of debt, the percentage interest and the percentage repayment.
   /// @returns a single integer representing the total cost of the mortgage. 
   ///(Repayment is a fixed percentage of the initial debt, and the interest is a percentage of the current debt.)
  
        struct MortgageRepayment
        {             
			/// @returns information about the operation.
            void help();
            void MethodStart();
        };
 
    ///@brief Checks if it is possible to carry out a given currency exchange 
    ///
    /// Details 
        struct ForexTrading
        {             
			/// @returns information about the operation.
            void help();
            void helper();
            int MethodStart(vector<vector<int> > &adj, vector<vector<int> > &cost);
        };
};
 
void FinancialHelper::ProfitMaximization::help()
{
    cout<<"Help for Method Profit Maximization\n";
    cout<<" Through this operation the maximum possible profit is given , over a given period of time, using only one buy and one sell operation according to a given sequence of predicted share prices.\n ";
    cout<<" The input contains the number of days and the predicted share prices for those days.\n";
    cout<<" The output gives out a single integer which is  the maximum possible profit.\n";
}
 
void FinancialHelper::ProfitMaximization::MethodStart()
{  
    /// In this function we calculate the maximum possible profit
    /// @param n stores the user input for number the number of days for which we have predicted share prices
    /// @param v is the vector that stores the predicted values 
    /// @param max_diff is the variable that stores the maximum profit
    /// @returns The maximum possible profit using one buy and one sell operation 
    cout<<"Method : Profit Maximization\n";
    cout<<"Enter Number of Days: \n";
    int n; cin>>n;
    cout<<"Enter "<<n<<" values\n";
    vector<int> v(n); for(int i=0; i<n; i++) cin>>v[i];
    vector<int> suffix_max(n);
    int maxx = suffix_max[n-1] = v[n-1];
 
    for(int i=n-2; i>=0; i--) 
    {
        maxx = max(maxx, v[i]);
        suffix_max[i] = maxx;
    }
 
    int max_diff = INT_MIN;
    for(int i=0; i<n; i++)
    {
        max_diff = max(suffix_max[i]-v[i], max_diff);
    }
 
    cout<< "\nMaximum Profit: " << max_diff<<endl;
 
}
 
void FinancialHelper::ProfitMaximizationExtended::help()
{
    cout<<"help for Method Profit Maximization Extended\n";
    cout<<"Through this operation, the maximum possible profit is given while using the smallest possible trading operations over a given period of time, according to a given sequence of predicted share prices.\n ";
    cout<<"The input contains the number of days and the predicted share prices for those days.\n";
    cout<<"The output contains a single integer which is the maximum profit using the smallest number of trading operations possible throughout the given time.\n";
}
 
void FinancialHelper::ProfitMaximizationExtended::MethodStart()
{  
    /// In this function we calculate the maximum possible profit
    /// @param n stores the user input for number the number of days for which we have predicted share prices
    /// @param v is the vector that stores the predicted values 
    /// @param ans is the variable that stores the maximum profit
    /// @returns A single integer which is the maximum profit using the smallest number of trading operations possible throughout the given time.
 
    cout<<"Method 2 Start\n";
    cout<<"Enter Number of Days: \n";
    int n; cin>>n;
    cout<<"Enter "<<n<<" values\n";
    vector<int> v(n); for(int i=0; i<n; i++) cin>>v[i];
 
    int minn = INT_MAX, maxx = INT_MIN; 
    int i=0, ans=0;
    while(i<v.size())
    {
        maxx = max(v[i], maxx);
        minn = min(v[i], minn);
        if(i==v.size()-1 || v[i]>v[i+1])
        {
            ans+=maxx-minn;
            minn = INT_MAX, maxx = INT_MIN;
        }
        i++;
    }
    cout<< "\nMaximum Profit: " << ans << endl;
}
void FinancialHelper::FastProfit::help()
{
    cout<<"help for Method : Fast Trading\n";
    cout<<" Through this operation the data is analyzed to build a model which will predict the best day to buy and sell shares to achieve a specific profit the earliest.\n";
    cout<<"INPUT: The number of days for which the share values are predicted and the profits that need to be achieved. \n";
    cout<<"OUTPUT: The output would contain the day on which the share was bought and the day on which the share was sold to achieve the given profits. If is not possible to acieve the desired profit, -1 is returned.\n";
}
 
void FinancialHelper::FastProfit::Solution(unordered_map<int, int> &m, int target, vector<int> &v)
{   
    
    
    vector<pair<int,int>> ans;
    for(int i=0; i<v.size(); i++)
    {
        if(m[target+v[i]]>i+1)
        {
            ans.push_back(make_pair(i+1, m[target+v[i]]));
        }
    }
    if(ans.size()==0) {cout<<-1; return;}
 
    pair<int, int> minn = ans[0];
    for(auto i:ans)
    {
        if((minn.second) > (i.second))
            minn = i;
        else if((minn.second) == (i.second))
            if((minn.first) < (i.first))
                minn = i;
    }
    cout<<"\n"<<minn.first<<' '<<minn.second;
}
 
void FinancialHelper::FastProfit::MethodStart()
{
    
    /// @param n Stores user input for the number of days
    /// @param m is the unordered map 
    /// @param d is the desired target for profits 
    /// @see FinancialHelper::FastProfit::Solution() 
    /// @returns The days on which the share should be bought and sold to achieve the desired profits.
    /// @warning The function returns -1 if the desired profits are not possible to achieve. 
    cout<<"Method : Fast Profit\n";
 
    unordered_map<int, int> m;
 
    cout<<"Please input the number of days for which you have predicted values: \n";
    int n,d; cin>>n;
    cout<<"Please enter "<<n<<" values: \n";
    vector<int> v(n); for(int i=0; i<n; i++) {cin>>v[i]; m[v[i]]=i+1;}
    cout<<"Enter number of queries: \n";
    cin>>d;
    cout<<"What is the desired target for profits?\n";
    vector<int> target(d); for(int i=0; i<d; i++) cin>>target[i];
 
    cout<<"To make desired profit in shortest amount of time you should buy and sell on the following days respectively: \n";
    for(int i=0; i<d; i++)
    {
        FinancialHelper::FastProfit::Solution(m, target[i] ,v);
        if(i<d-1) cout<<',';
    }
    cout<<endl;
}
 
void FinancialHelper::RiskTrading::help()
{
    cout<<"Help for Method 4\n"; // Medium Q1
    cout<<"In this operation risk analysis is done for each trade in order to make the maximum profit from that trade. \n ";
    cout<<" It would require the input of the number of trades available & allowed, probability that a trade would make profit, potential profit and loss of the trade.\n";
    cout<<" It would calculate & return the maximum expected amount of money that can be made considering the given constraints, probablities and prices. \n";
}
 
void FinancialHelper::RiskTrading::MethodStart()
{
    
    ///@param n stores user input for the number of trades available 
    ///@param n stores the maximum number of trades allowed 
    ///@param p contains the probabalities that a trade would make profit 
    ///@param x stores the potential profit values
    ///@param y stores the potential loss values 
    ///@param pq is the priority queue we use in this function 
    ///@param ans stores the answer
    ///@returns the maximum expected amount of money that can be made considering the given constraints, probablities and prices
    cout<<"Method : Risk Trading\n";
    int n, m;
    cout<<"Enter the number of trades available: \n";
    cin >> n;
    cout<<"Enter the maximum number of trades allowed: \n";
    cin >> m;
    double p[n], x[n], y[n];
    cout<<"Enter "<<n<<" Probabilities: \n";
    for(int i = 0; i < n; i++)
        cin >> p[i];
    cout<<"Enter " <<n << " potential profit values: \n";
    for(int i = 0; i < n; i++)
        cin >> x[i];
    cout<<"Enter " << n <<" potential loss values: \n";
    for(int i = 0; i < n; i++)
        cin >> y[i];
 
    priority_queue<double> pq;
 
    for(int i=0; i<n; i++)
    {
        pq.push(x[i]*p[i] - y[i]*(1-p[i]));
    }
    double ans=0;
    for(int i=0; i<m; i++)
    {
        if(pq.top()>0)
            ans+=pq.top();
        pq.pop();
    }
    cout<<"\nMaximum expected amount of money that can be made: "<<fixed<<setprecision(2)<<ans<<endl;
}
 
 
void FinancialHelper::StockSpan::help()
{
    cout<<"help for Method Stock Span\n";
    cout<<"Find the span Si of the stock’s price on a given day i.";
    cout<<"The span of the stock’s price on a given day is defined as the maximum number of consecutive days just before the given day, for which the price of the stock on the current day is less than or equal to its price on the given day.";

}
 
void FinancialHelper::StockSpan::MethodStart() 
{ 
   
    ///@param n stores user input for the number of days 
    ///@param A stores the probabilities for each day
    ///@param ans stores the span values 
    ///@note Span value for the first element is always 1. We then need to calculate the span value for the rest of the elements. 
    ///@returns n space-separated values indicating Stock Span on each day
    cout<<"Method : Stock Span\n";
    int n;
    cout<<"Enter the number days: \n";
    cin >> n;
    int A[n], ans[n];
    cout<<"Enter n space-separated integer for the price of stock on n consecutive days: \n";
    for(int i = 0; i < n; i++)
        cin >> A[i];
    stack<int> st; 
    st.push(0); 
  
    ///@note Span value of first element is always 1 
    ans[0] = 1; 
  
    /// So we need to  calculate span values for rest of the elements. 
    ///
    ///We run a loop from i=1 to n and pop elements from stack while stack is not empty and top of stack is smaller than price[i].
    for (int i = 1; i < n; i++) { 
        
        while (!st.empty() && A[st.top()] <= A[i]) 
            st.pop(); 
  
        /// If stack becomes empty, then price[i] is greater than all elements on left of it, i.e., price[0], price[1], ..price[i-1].  
        /// Else price[i] is greater than elements after top of stack .
        ans[i] = (st.empty()) ? (i + 1) : (i - st.top()); 
  
        // Push this element to stack 
        st.push(i); 
    } 
    for (int i = 0; i < n; i++) 
        cout<<"\nThe stock span for day "<<i+1<<"=" << ans[i] <<endl; 
    cout<<endl;
} 
  
void FinancialHelper::WiseInvesting::help()
{
    cout<<"help for Method Wise Investing\n";
    cout<<"Calculates the maximum value of trades that can be executed under a given complexity constraint.\n";
    cout<<"Given a maximum total complexity of trades that can be fulfilled in one day and a list of trades to choose from. Each one has a value, v and a complexity, c.";
 cout<<"This operation finds the maximum value of trades that can be executed, given the complexity constraint.\n";
 cout<<"Input: The inputs are a pair of arrays, v and c, and a maximum complexity, mc. The elements of v represent trade value in millions of dollars and is any positive integer.";
cout<<"The complexity is between 0-100 and represents a percentage. The maximum complexity is a scalar integer.\n It returns The maximum value of trades that can be executed.";

}
 
int FinancialHelper::WiseInvesting::MethodStart(vector<int> &v,vector<int> &c,int mc,int index_trade,int current_value,int current_complexity,int max_value)
{
    
    ///@param v stores the list of trade values
    ///@param c stores the list of complexities 
    ///@param index_trade 
    ///@returns Maximum value of trade that can be executed 
 
    if(index_trade == v.size())
        return max_value;
    int sum=0;
    for(int i=index_trade;i<v.size();i++)
        sum+=c[i];
    if(current_complexity + sum <= mc)  //all trades after can be chosen
    {
        int total_values_after = 0;
        for(int i=index_trade;i<v.size();i++)
            total_values_after+=v[i];
        if(current_value + total_values_after > max_value)
            max_value = current_value + total_values_after;
        return max_value;
    }
    if(current_complexity + c[index_trade] <= mc)  // current trade can be chosen
    {
        if(current_value + v[index_trade] > max_value)
            max_value = current_value + v[index_trade];  // update max_value;
        max_value = FinancialHelper::WiseInvesting::MethodStart(v, c, mc, index_trade + 1, current_value + v[index_trade],current_complexity + c[index_trade], max_value); // next trade
    }
    max_value = max(max_value,FinancialHelper::WiseInvesting::MethodStart(v, c, mc, index_trade + 1, current_value, current_complexity, max_value)); // next td
    return max_value;
}
 
void FinancialHelper::WiseInvesting::helper()
{
    
    ///@param n stores user input for the number of trade values 
    ///@param v stores the list of trade values
    ///@param c stores the list of complexities 
    ///@param mc stores the maximum complexity 
    
    ///@returns Maximum value of trade that can be executed by calling the function Methodstart()
    ///@see FinancialHelper::WiseInvesting::MethodStart
    cout<<"Method : Wise Investing\n";
    int n;
    cout<<"Enter no. of trades \n";
    cin>>n;
    vector<int> v(n), c(n);
    cout<<"Enter n space-separated integer for Trade values \n";
    for(int i = 0; i < n; i++)
            cin >> v[i];
    cout<<"Enter n space-separated integer for complexities \n";
    for(int i = 0; i < n; i++)
            cin >> c[i];
    int mc;
    cout<<"Enter maximum complexity \n";
    cin>>mc;
    cout<<"\nMaximum value of trade that you can execute is "<<FinancialHelper::WiseInvesting::MethodStart(v,c,mc,0,0,0,0)<<endl;
}
 
void FinancialHelper::MortgageRepayment::help()
{
    cout<<"help for Method Mortgage Repayment\n";
    cout<<"The function calculates the Total Mortgage Payment for a given the initial level of debt, the percentage interest, and the percentage repayment. \n";
}
 
void FinancialHelper::MortgageRepayment::MethodStart()
{
    
    ///@param initialLevelOfDebt It is the initial level of debt
    ///@param interestPercentage It is the percentage of interest
    ///@param repaymentPercentage It is a fixed percentage of the initial debt
    ///@returns  A value representing the total cost of the mortgage.
    cout<<"Method : Mortgage Repayment\n";
    int initialLevelOfDebt, interestPercentage, repaymentPercentage;
    cout<<"Enter 3 space-separated three integers – the initial level of debt, the percentage interest, and the percentage repayment \n";
    cin>>initialLevelOfDebt>>interestPercentage>>repaymentPercentage;
    int debt = initialLevelOfDebt;  // initialize current debt
        int repayment = initialLevelOfDebt * repaymentPercentage / 100;
        int n_repay = 0;
        int interest_rate = 1 + interestPercentage / 100;
    while(debt > repayment)
    {
        debt = debt * interest_rate - repayment;  // Add interest and make repayment
        n_repay += 1;
    }
    double cost = initialLevelOfDebt * 10 / 100 + n_repay * repayment + debt;
    cout<<"\nThe total cost of the mortgage is "<<cost<<endl;
}
 
void FinancialHelper::ForexTrading::help()
{
    cout<<"help for Method Forex Trading\n";
    cout<<"The problem checks whether it is possible to start with one unit of some currency, perform a sequence of exchanges, and get more than one unit of the same currency in Forex Trading.\n";
}
 
void FinancialHelper::ForexTrading::helper() {
    ///  Given a list of currencies 𝑐1, 𝑐2, . . . , 𝑐𝑛 together with a list of exchange rates: 𝑟𝑖𝑗 is the number of units of currency 𝑐𝑗 that one gets for one unit of 𝑐𝑖. You would like to check whether it is possible to start with one unit of some currency, perform a sequence of exchanges, and get more than one unit of the same currency.
    /// In other words, you would like to find currencies 𝑐𝑖1, 𝑐𝑖2, . . . , 𝑐𝑖𝑘 such that 𝑟𝑖1,𝑖2 · 𝑟𝑖2,𝑖3 · 𝑟𝑖𝑘−1,𝑖𝑘 , 𝑟𝑖𝑘,𝑖1 > 1. 
    ///For this, you construct the following graph: vertices are currencies 𝑐1, 𝑐2, . . . , 𝑐𝑛, the weight of an edge from 𝑐𝑖 to 𝑐𝑗 is equal to − log 𝑟𝑖𝑗 . 
    ///There it suffices to check whether is a negative cycle in this graph. Indeed, assume that a cycle 𝑐𝑖 → 𝑐𝑗 → 𝑐𝑘 → 𝑐𝑖 has negative weight. This means that −(log 𝑐𝑖𝑗 + log 𝑐𝑗𝑘 + log 𝑐𝑘𝑖) < 0 and hence log 𝑐𝑖𝑗 + log 𝑐𝑗𝑘 + log 𝑐𝑘𝑖 > 0
    ///
    ///@param n is the number of currencies
    ///@param m is the number of currency exchange trades
    ///@param x represents a currency
    ///@param y represents a currency
	///@param w represents the rate of exchange from currency x to currency y
    ///@returns "Yes, there exists an exchange cycle such that if you start with 1 unit f some currency, perform a sequence of exchanges, and get more than one unit of the same currency in Forex Trading." if such a cycle exists, else "There exists no such exchange cycle for the given data."
    cout<<"Method : Forex Trading\n";
    int n, m;
    cout<<"Enter n = no. of currencies and m = no. of exchanges\n";
    cin >> n >> m;
    vector<vector<int> > adj(n, vector<int>());
    vector<vector<int> > cost(n, vector<int>());
    cout<<"\nEnter m rows of sapce seperated interger x y w, where x y w represent a unidirectional exchange edge from x to y with exchange rate w.(w can be given as log(1/(no. of units of y in exchange of 1 unit of x))) \n";
    for (int i = 0; i < m; i++) {
            int x, y, w;
            cin >> x >> y >> w;
            adj[x - 1].push_back(y - 1);
            cost[x - 1].push_back(w);
    }
    if(FinancialHelper::ForexTrading::MethodStart(adj, cost)==0)
	cout<<"\nThere exist no such exchange cycle for the given data. \n";
    else
	cout<<"\nYes, there exist an exchange cycle such that if you start with 1 unit of some currency, perform a sequence of exchanges, and get more than one unit of the same currency in Forex Trading.\n";
}
 
int FinancialHelper::ForexTrading::MethodStart(vector<vector<int> > &adj, vector<vector<int> > &cost) {
 
    /// The method takes an adjacency list and a list of weights corresponding to each edge as inputs and performs Bellman-Ford algorithm for negative edge detection n-1 times (where n is no. of vertices) iteratively to find if a negative cycle exists. 
    ///@param adj stores the adjacency
    ///@param cost stores the cost
    ///@param dist stores the distance 
    ///@returns 1 or 0
    vector<long> dist(adj.size(), INT_MAX);
    dist[0] = 1;
    for (int i = 0; i < adj.size(); i++) {
        for(int u = 0; u < adj.size(); u++){
            for (int k = 0; k < adj[u].size(); k++) {
                int v = adj[u][k];
                if(dist[u] != INT_MAX && dist[v] > dist[u] + cost[u][k]) {
                    dist[v] = dist[u] + cost[u][k];
                    if(i == adj.size() - 1) 
                        return 1;
                }
            }
        }
    }
    return 0;
}
 
void PrintMethods()
{
    /// This function gives the user different operations to choose from 
    cout<<"1 Profit Maximization"<<endl;
    cout<<"2 Profit Maximization Extended"<<endl;
    cout<<"3 Fast Profit"<<endl;
    cout<<"4 Risk Trading"<<endl;
    cout<<"5 Stock Span"<<endl;
    cout<<"6 Wise Investing"<<endl;
    cout<<"7 Mortgage Repayment"<<endl;
    cout<<"8 Forex Trading"<<endl;
    cout<<"Press any other value to exit program"<<endl;
}
 
/// The main function takes the user input. 
/// The user can choose different options according to the task that needs to be performed. 
int32_t main()
{
    
    FinancialHelper sh;
	while(1)
    {
        // Operations
    int operation;
    do {
        cout << "\nSelect Operation : \n";
        PrintMethods();
        if (cin >> operation && (operation >= 1 && operation <= 9)) break;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
    }
    while(true);

    switch (operation)
    {
        case 1:
        {
            cout<<"Method-1\nType help for more details else press y to continue\n";
            FinancialHelper::ProfitMaximization yo;
            string s;
            cin>>s;
            cout<<"\n\n\n\n";
            if(s=="y")
            {
                yo.MethodStart();
            }
            else if(s=="help")
            {
                yo.help();
                yo.MethodStart();
            }
            else
            {
                cout<<"Please enter valid parameters and try again";
            }
            break;
        }

        case 2:
        {
            cout<<"Method-2\nType help for more details else press y to continue\n";
            FinancialHelper::ProfitMaximizationExtended yo;
            string s;
            cin>>s;
            cout<<"\n\n\n\n";
            if(s=="y")
            {
                yo.MethodStart();
            }
            else if(s=="help")
            {
                yo.help();
                yo.MethodStart();
            }
            else
            {
                cout<<"Please enter valid parameters and try again";
            }
            break;
        }
        
        case 3:
        {
            cout<<"Method-3\nType help for more details else press y to continue\n";
            FinancialHelper::FastProfit yo;
            string s;
            cin>>s;
            cout<<"\n\n\n\n";
            if(s=="y")
            {
                yo.MethodStart();
            }
            else if(s=="help")
            {
                yo.help();
                yo.MethodStart();
            }
            else
            {
                cout<<"Please enter valid parameters and try again";
            }
            break;
        }
        
        case 4:
        {
            cout<<"Method-4\nType help for more details else press y to continue\n";
            FinancialHelper::RiskTrading yo;
            string s;
            cin>>s;
            cout<<"\n\n\n\n";
            if(s=="y")
            {
                yo.MethodStart();
            }
            else if(s=="help")
            {
                yo.help();
                yo.MethodStart();
            }
            else
            {
                cout<<"Please enter valid parameters and try again";
            }
            break;
        }

        case 5:
        {
            cout<<"Method-5\nType help for more details else press y to continue\n";
            FinancialHelper::StockSpan yo;
            string s;
            cin>>s;
            cout<<"\n\n\n\n";
            if(s=="y")
            {
                yo.MethodStart();
            }
            else if(s=="help")
            {
                yo.help();
                yo.MethodStart();
            }
            else
            {
                cout<<"Please enter valid parameters and try again";
            }
            break;
        }
        
        case 6:
        {
            cout<<"Method-6\nType help for more details else press y to continue\n";
            FinancialHelper::WiseInvesting yo;
            string s;
            cin>>s;
            cout<<"\n\n\n\n";
            if(s=="y")
            {
                yo.helper();
            }
            else if(s=="help")
            {
                yo.help();
                yo.helper();
            }
            else
            {
                cout<<"Please enter valid parameters and try again";
            }
            break;
        }

        case 7:
        {
            cout<<"Method-7\nType help for more details else press y to continue\n";
            FinancialHelper::MortgageRepayment yo;
            string s;
            cin>>s;
            cout<<"\n\n\n\n";
            if(s=="y")
            {
                yo.MethodStart();
            }
            else if(s=="help")
            {
                yo.help();
                yo.MethodStart();
            }
            else
            {
                cout<<"Please enter valid parameters and try again";
            }
            break;
        }
        case 8:
        {
            cout<<"Method-8\nType help for more details else press y to continue\n";
            FinancialHelper::ForexTrading yo;
            string s;
            cin>>s;
            cout<<"\n\n\n\n";
            if(s=="y")
            {
                yo.helper();
            }
            else if(s=="help")
            {
                yo.help();
                yo.helper();
            }
            else
            {
                cout<<"Please enter valid parameters and try again";
            }
            break;
        }

        case 9:
        {
            exit(1);
        }
                
    }
    }
    return 0;
}
