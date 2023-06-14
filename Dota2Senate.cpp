class Solution {
public:
    string predictPartyVictory(string senate) {
        string del = "";
        while(senate.find("D")!=std::string::npos && senate.find("R")!=std::string::npos ){
            string newS = "";
            for(char c : senate){
                if(del.empty()){
                    del.push_back(c);
                    newS.push_back(c);
                }else{
                    if(c=='R'){
                        if(del.back()=='D')   del.pop_back();
                        else{
                            newS.push_back(c);
                            del.push_back('R');
                        }
                    }else{
                        if(del.back()=='R')   del.pop_back();
                        else{
                            newS.push_back(c);
                            del.push_back('D');
                        }
                    }
                }
                //cout<<"c : "<<c<<"\ndel : "<<del<<"\nnewS : "<<newS<<endl;
            }
            
            senate = newS;
        }
        if(senate.find("D")!=std::string::npos) return "Dire";
        return "Radiant";
        /*
        int r1=0, r2=0;
        for(char c : senate){
            if(c=='R'){
                if(r1>=0)   ++r1, ++r2;
                else{
                    if(r2==0)     ++r1;
                    else          ++r2;
                }
            }else{
                if(r1<=0)   --r2, --r1;
                else{
                    if(r2==0)     --r1;
                    else          --r2;
                }
            }
        }
        if(r1>0)    return "Radiant";
        if(r1<0)    return "Dire";
        if(senate.back()=='R')    return "Radiant";
        return "Dire";
        */
    }
};