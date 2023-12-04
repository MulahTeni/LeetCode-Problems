class Solution {
public:
    string decodeString(string s) {
        string str="";
        s = '*'+s;
        for(char c : s){
            if(c!=']'){
                str.push_back(c);
            }else{
                string tmp = "";
                while(str.back()!='['){
                    tmp = str.back() + tmp;
                    str.pop_back();
                }
                str.pop_back();
                int num=0, i=1;
                while(!str.empty()){
                    num += (str.back() - '0')*i;
                    i*=10;
                    str.pop_back();
                    if(!isdigit(str.back())) break;
                }
                for(i=0; i<num; i++){
                    str += tmp;
                }
            }
        }
        return {str.begin()+1, str.end()};
    }
};
// youtube