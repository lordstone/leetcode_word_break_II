class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        vector<string> res;
        if(s.length() == 0) return res;
        string out = "";
        int ptr = 0;
        DFS(res, wordDict, out, s, 0);
        return res;
    }
    
    void DFS(vector<string>& res, unordered_set<string>& wordDict, string out, string& s, int ptr){
        if(wordDict.find(s.substr(ptr)) != wordDict.end()){
            out += s.substr(ptr);
            res.push_back(out);
            return;
        }
        for(int i = ptr + 1; i < s.length(); i ++){
            string tmp = s.substr(ptr, i - ptr);
            if(wordDict.find(tmp) != wordDict.end()){
                string tmpOut = out;
                if(i < s.length() - 1){
                    tmpOut += tmp + " ";
                    DFS(res, wordDict, tmpOut, s, i);
                }
            }
        }
    }
};
