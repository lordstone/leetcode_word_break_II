class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        vector<vector<string>> res (s.length() + 1, vector<string> (0));
        res[0].push_back("");
        for(int i = 1; i <= s.length(); i ++){
            for(int j = 0; j < i; j ++){
                string strToSearch = s.substr(j, i - j);
                if(res[j].size() != 0 && wordDict.find(strToSearch) != wordDict.end()){
                    for(auto &obj : res[j]){
                        string strToAdd = ((obj == "") ? strToSearch : obj + " " + strToSearch);
                        res[i].push_back(strToAdd);
                    }//end adding 
                }
            }
        }
        return res[s.length()];
    }
};
