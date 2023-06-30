//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

void dfs(char curr, unordered_map<char, unordered_set<char>>& adjList, unordered_set<char>& visited, vector<char>& ans) {
    visited.insert(curr);

    for (char nbr : adjList[curr]) {
        if (visited.count(nbr) == 0)
            dfs(nbr, adjList, visited, ans);
    }

    ans.push_back(curr);
}

class Solution{
    public:
    string findOrder(string dictionary[], int n, int k) {
        //code here
        
         vector<char> ans;
    unordered_map<char, unordered_set<char>> adjList;

    for (int i = 0; i < n; i++) {
        for (char c : dictionary[i]) {
            adjList[c] = unordered_set<char>();
        }
    }

    for (int i = 0; i < n - 1; i++) {
        string a = dictionary[i];
        string b = dictionary[i + 1];
        int minLen = min(a.length(), b.length());

        if (a.length() > b.length() && a.substr(0, minLen) == b.substr(0, minLen)) {
            return "";
        }

        for (int j = 0; j < minLen; j++) {
            if (a[j] != b[j]) {
                adjList[a[j]].insert(b[j]);
                break;
            }
        }
    }

    unordered_set<char> visited;

    for (auto& x : adjList) {
        if (visited.count(x.first) == 0)
            dfs(x.first, adjList, visited, ans);
    }

    reverse(ans.begin(), ans.end());
    
    string fin = "";
    
    for(auto c: ans)
        fin += c;
        
    return fin;
    }
};

//{ Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends