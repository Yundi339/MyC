#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
const char op[4] = {'+','-','*','/'};
bool flag = false;
int cal(int& num1,int& num2,int& op){
    if(op==0) return num1 + num2;
    else if(op==1) return num1 - num2;
    else if(op==2) return num1 * num2;
    else return num1 / num2;
}

int getNum(string& temp){
    if(temp == "10") return 10;
    else if(temp == "A") return 1;
    else if(temp == "J") return 11;
    else if(temp == "Q") return 12;  
    else if(temp == "K") return 13;
    else if(temp == "joker" || temp == "JOKER") {
        flag = true;
        return -1;
    }
    else return temp[0]-'0';
}

int num[4];
int num_index[4];
int op_index[3];

bool map[4];

bool dfs(int sum, int k) {   
    if(k == 3){
        return sum == 24;
    }
    for(int i=0;i<4;i++){
        if(!map[i]){
            map[i] = 1;
            num_index[k+1] = i;
            for(int j=0;j<4;j++){
                op_index[k] = j;
                if(dfs(cal(sum,num[i], j),k+1))
                    return true;
            }        
            map[i] = 0;
        }
    }   
    return false;
}

int main()
{
    string card[4];
    for(int i:{0,1,2,3}){
        cin >> card[i];
        num[i] = getNum(card[i]);
    }
    if (flag){
        cout << "ERROR";
        return 0;
    }
    for(int i:{0,1,2,3}){
        map[i] = 1;
        num_index[0] = i;
        if (dfs(num[i], 0)){
            cout << card[num_index[0]] << op[op_index[0]]<< card[num_index[1]] << op[op_index[1]]<< card[num_index[2]] << op[op_index[2]]<< card[num_index[3]];
            return 0;
        }
        map[i] = 0;
    }
    cout << "NONE";
    return 0;
}