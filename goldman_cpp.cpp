1.

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string,vector<string>>m;
    for(auto l:strs){
        string temp=l;
        sort(temp.begin(),temp.end());
        m[temp].push_back(l);

    }
    vector<vector<string>>ans;
    for(auto l:m){
        ans.push_back(l.second);
    }
    return ans;

   // expected complexity :  n*slog(s) n is the number of strings and s is the length of the string    
}



2.

bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        if((max(rec1[0],rec2[0])<min(rec1[2],rec2[2])) and  (max(rec1[1],rec2[1]) < min(rec1[3],rec2[3])) ){
            return true;
        }
        return false;
  }


3.

  int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int ans=0;
        int left=0;
        int product=1;
        if(k==0 or k==1){
            return 0;
        }
        for(int right=0;right<nums.size();right++){
            product*=nums[right];
            while(product>=k){
                product/=nums[left];
                left++;
            }
            ans+=right-left+1;
            
        }
        return ans;
        
    }

4.
string encode(string src)
{     
  string ans="";
  ans+=src[0];
  int temp=1;
  for(int i=1;i<src.length();i++){
      if(src[i]==src[i-1]){
          temp++;
      }
      else{
          ans+=to_string(temp);
          ans+=src[i];
          temp=1;
      }
      
  }
  ans+=to_string(temp);
  return ans;
}     


5.
int nthUglyNumber(int n) {
        vector<int>ugly_nums(n);
        int idx_2=0,idx_3=0,idx_5=0;
        ugly_nums[0]=1;
        for(int i=1;i<n;i++){
            ugly_nums[i]= min ( ugly_nums[idx_2] * 2, min( ugly_nums[idx_3] * 3,ugly_nums[idx_5] *5 ) );
            if(ugly_nums[i]==ugly_nums[idx_2] * 2){
                idx_2++;
            }
            if(ugly_nums[i]==ugly_nums[idx_3] * 3){
                idx_3++;
            }
            if(ugly_nums[i]==ugly_nums[idx_5] * 5){
                idx_5++;
            }
        }
        return ugly_nums[n-1];
        
        
        
        
    }

6.

 string gcdOfStrings(string str1, string str2) {
        if(str1+str2==str2+str1){
            return str2.substr(0,__gcd(str1.length(),str2.length()));
            
        }
        return "";
        
    }

7.

int last_position(int n,int m,int k){
    if(((m+k)%n)-1==0){
        return n;
    }
    else if(((m+k)%n)-1==-1){
        return n-1;
    }
    return ((m+k)%n)-1;

}

8.

 int numDecodings(string s) {
    vector<ll int>dp(s.length()+1,0);
    dp[s.length()]=1;
    for(ll int i=s.length()-1; i>=0;i--){
        if(s[i]=='0'){
            dp[i]=0;
        }
        else{
            dp[i]=dp[i+1]%1000000007;
            if(i<(s.length()-1) and (s[i]=='1' or (s[i]=='2' and s[i+1]<'7')) ){
                dp[i]+=dp[i+2]%1000000007;
            }
        }
    }
    return dp[0]%1000000007;
}
9.
string printMinNumberForPattern(string S){
    stack<int>st;
    int num=1;
    string ans="";
    for(auto l:S){
        if(l=='D'){
            st.push(num);
            num++;
        }
        else{
            st.push(num);
            num++;
            while(!st.empty()){
                ans+=to_string(st.top());
                st.pop();
            }
        }
    }
    st.push(num);
    while(!st.empty()){
        ans+=to_string(st.top());
        st.pop();
    }
    return ans;
        
}

10.
make a min heap of size 10:
push 1st 10 elements to the heap, now start iterating/ taking input if the curr element is greater than the top element at the heap ,remove the top element and push this curr element to the heap
in the end you will be having 10 largest element in the heap

11.
 int *findTwoElement(int *arr, int n) {
        int *ans=new int[2];
        for(int i=0;i<n;i++){
            if(arr[abs(arr[i])-1]>0){
               arr[abs(arr[i])-1]=-1*arr[abs(arr[i])-1];
            }
            else{
                ans[0]=abs(arr[i]);
            }
        }
        for(int i=0;i<n;i++){
            if(arr[i]>0){
                ans[1]=i+1;
            }
        }

        return ans;
    }

12. no. of squares of a  n*n square board will be 1^2+2^2+3^2+4^4......n^2= n*(n+1)*(2n+1)/6
    

13.

string decodeString(string s) {
    string temp="";
    stack<string>alpha;
    stack<int>num;
    int temp_num=0;
    for(int i=0;i<s.length();i++){
        if(islower(s[i])){
            temp+=s[i];
        }
        else if(isdigit(s[i])){
            temp_num=(temp_num*10)+(s[i]-'0');
        }
        else if(s[i]=='['){
            alpha.push(temp);
            num.push(temp_num);
            temp="";
            temp_num=0;

        }
        else if(s[i]==']'){
            string to_append=temp;
            int how_many_times_to_append=num.top();
            num.pop();
            temp=alpha.top(); // to append with
            alpha.pop();
            while(how_many_times_to_append--){
               temp+=to_append;
            }
        }
    }
    return temp;
        
}

14.
int minSubArrayLen(int target, vector<int>& nums){
    int sum=0;
    int left=0,right=0;
    int ans=INT_MAX;
    while(left<=right and right<nums.size()){
        sum+=nums[right];
        while(sum>=target){
            ans=min(ans,right-left+1);
            sum-=nums[left];
            left++;
        }
        right++;
 }
 return ans==INT_MAX ? 0:ans;
}

15.
 bool canPair(vector<int> nums, int k) {
    unordered_map<int,int>m;
    for(auto l:nums){
        m[l%k]++;
    }
    if(m[0]%2 != 0){
        return false;
    }
    for(auto l:m){
        if(l.first!=0 and m[k-l.first]!=l.second){
            return false;

        }
    }
    return true;
        
}