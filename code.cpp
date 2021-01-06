#include<bits/stdc++.h>
 using namespace std;
 #define int long long
  
  
 class FinancialHelper
 {
     public:
         struct ProfitMaximization
         {  
          
             void help();
             void MethodStart();
             
         };
  
  
         struct ProfitMaximizationExtended
         {
             void help();
             void MethodStart();
         };
  
         struct FastProfit
         {
             void help();
             void MethodStart();
             void Solution(unordered_map<int, int> &m, int target, vector<int> &v);
         };
  
         struct RiskTrading
         { 
             void help();
             
             void MethodStart();
         };
  
         struct StockSpan
         {             
             void help();
             void MethodStart();
         };
  
         struct WiseInvesting
         {
             void help();
             int MethodStart(vector<int> &v,vector<int> &c,int mc,int index_trade,int current_value,int current_complexity,int max_value);
             void helper();
         };
  
   
         struct MortgageRepayment
         {             
             void help();
             void MethodStart();
         };
  
         struct ForexTrading
         {             
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
   
     ans[0] = 1; 
   
     for (int i = 1; i < n; i++) { 
         
         while (!st.empty() && A[st.top()] <= A[i]) 
             st.pop(); 
   
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
