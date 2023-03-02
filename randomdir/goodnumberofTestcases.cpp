#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef  long int li;
typedef  long long int lli;
typedef unsigned long long int ulli;
#define all(x) (x).begin(), (x).end()
#define INF 1e18
#define nl '\n'
#define ll long long





long long solve(int*ar,int n){
  if(ar[0]!=0) return ar[0]-1;
  int l,r;
  
  vi uniq;
  uniq.push_back(0);
  int shouldbe = 0;

  for(int i=0;i<n;i++){
    if(ar[i]==uniq.back()) continue;
    uniq.push_back(ar[i]);
  } 
  
  n= uniq.size();
  // skipp the first continuous sequence. and find x
  l=0;
  int x=0,k=0;
  shouldbe = 0;
  for(int i=0;i<n && l<n;i++)
  {
   if(uniq[i]==shouldbe){
    x++;
    shouldbe++;
    l=i;
   }else break;

  }
  // cout<<x<<' '<<l<<' '<<n<<' ';
  

  if(x==1) return -1;    // because we have always 0 and x will be 1 except at polls
  else if(l>=n-1) return 0; // we have read all input;
  // for each continuousSequence of len >= X-1 k++;
  l++;
  int cnt = 0;
  
  // cout<<x<<' ';
  shouldbe = uniq[l]; // we are now going to start finding a continuous segment
  while (l<n)
  { cnt =0;
    shouldbe =uniq[l];
  for(;l<n;l++)  {
  if(uniq[l]==shouldbe++) cnt++;
  else break;
  }
  
  if(cnt >= x-1) k++;
  }
  return k;
}
int main()
{

#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
int od,n,ev,x,ans,t,m;
cin>>t;

while(t--){
  cin>>n;
  int ar[n];
  for(int i=0;i<n;i++) cin>>ar[i];
  sort(ar,ar+n);
  cout<<solve(ar,n)<<'\n';
  
}


// this is some editing file.
return 0;
}


