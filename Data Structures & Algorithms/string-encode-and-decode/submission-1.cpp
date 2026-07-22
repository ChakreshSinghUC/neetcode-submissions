class Solution {
   private:
    queue<int> characterCount;

   public:
    string encode(vector<string>& strs) {
        string encodedString;

        for (auto s : strs) {
            encodedString += s;
            characterCount.push(s.length());
        }

        return encodedString;
    }

    vector<string> decode(string s) {
        vector<string> decodedString;
        int currIndex = 0;
        while (!characterCount.empty()) {
            string t = "";
            for(int i = currIndex; i< currIndex+characterCount.front(); i++)
            {
                t+=s[i];
            }
            currIndex += characterCount.front();
            decodedString.push_back(t);
            characterCount.pop();
        }
        return decodedString;
    }
};
