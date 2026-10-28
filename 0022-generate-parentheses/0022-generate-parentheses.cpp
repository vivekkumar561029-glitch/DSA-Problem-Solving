class Solution {
public:
    void generate(vector<string>&res,string s,int op,int cl,int n)
{
    if( cl==n)
    {
        res.push_back(s);
        return;
    }

if(op<n) generate(res,s+'(',op+1,cl,n);
if(cl<op) generate( res,s+')',op,cl+1,n);

}
    vector<string> generateParenthesis(int n) {
        vector<string>res;
        generate(res,"",0,0,n);
        return res;
    }
};