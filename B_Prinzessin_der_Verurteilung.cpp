#include<bits/stdc++.h>
using namespace std;
 
 
 
#define intt long long
#define floatt double   
#define fast_cin() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)  
#define T long long int t; cin>>t; while(t--)
#define f(n) for(int i=0;i<n;i++)
#define fj(i,n) for(int j=i;j<n;j++)
#define pre(p) fixed<<setprecision(p)
 
 
/////NUMBER OF PRIME FACTORS OF N
int primeFactors(int n)
{
    set<int> s;
    
    // Print the number of 2s that divide n
    while (n % 2 == 0)
    {
       // cout << 2 << " ";
       s.insert(2);
        n = n/2;
    }
 
    // n must be odd at this point. So we can skip
    // one element (Note i = i +2)
    for (int i = 3; i <= sqrt(n); i = i + 2)
    {
        // While i divides n, print i and divide n
        while (n % i == 0)
        {
           // cout << i << " ";
           s.insert(i);
            n = n/i;
        }
    }
 
    // This condition is to handle the case when n
    // is a prime number greater than 2
    if (n > 2){
       // cout << n << " ";
       s.insert(n);
    }
       return s.size();
}
 
 
 
/////FACTORS OF N//////
vector <intt> factors(int x) {
    vector <intt> result;
    intt i = 1;
    while(i*i <= x) {
        if(x % i == 0) {
            result.push_back(i);
       
            if(x/i != i) {
                result.push_back(x/i);
            }
        }
        i++;
    }
    return result;
}
 ///////
 
 
 
 
/////PRIME NUMBERS///// 
 vector<intt> prime(int n)
{
    vector<intt> result;
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));
 
    for (intt p = 2; p * p <= n; p++)
    {
        if (prime[p] == true)
        {
            for (intt i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
    for (intt p = 2; p <= n; p++)
        if (prime[p])
         {
         result.push_back(p);
         }
         return result;
}
//////////

void solve() {
    int n;
    string s;
    cin >> n >> s;
    set<string> se;
   
     for(int i=0;i<n;i++){
        string ss;
        for(int k = 0; k < 5 && i + k < n; k++) {
            ss.push_back(s[i + k]);
            se.insert(ss);
        }
    }
  
    for(int len=1;len<6;len++){
        string t(len, 'a');
        while(true) {
            if(se.count(t) == 0) {
                cout << t << '\n';
                return;
            }
            int idx = len - 1;
            while(idx >= 0 && t[idx] == 'z') {
                t[idx] = 'a';
                idx--;
            }
            if(idx < 0) break;
            t[idx]++;
        }
    }
}



 
 
int main()
{
 
 T{
   solve();  
 }
    
}