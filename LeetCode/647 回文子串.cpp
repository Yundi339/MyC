class Solution {
public:
    int countSubstrings(string s) {
        string temp;
        temp.reserve(2*s.size() + 3);
        temp.push_back('$');
        temp.push_back('#');
        for (char &c : s){
            temp.push_back(c);
            temp.push_back('#');
        }
        temp.push_back('@');
        
        int ans = 0;
        int *radius = new int[temp.size()];
        for(int i=2; i<temp.size()-2; i++){
            radius[i] = 0;
            while(temp[i - radius[i]] == temp[i + radius[i]]){
                if(temp[i - radius[i]] != '#')
                    ans++;
                radius[i]++;
            }
        }              
        delete[] radius;
        return ans;
    }
};