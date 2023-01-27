class Solution {
public:
/*
s-> 10 , 6 , 9 , 3 
s-> 10 , 6, 12 , -11 
s-> 10,6, -132
s-> 10, 0 (6/-132)
s-> 0 17 
s-> 17 5
s-> 22
*/

//second_number is top of stack && first_number is next element
long long int addition(long long int first_number ,long long int second_number){
    long long int sum = first_number+second_number;
    return sum;
}
long long int subtraction(long long int first_number , long long int second_number){
    long long int difference = second_number-first_number;
    return difference;
}
long long int multiplication(long long int first_number , long long int second_number){
    long long int multiply = first_number*second_number*1LL;
    return multiply;
}
long long int division(long long int first_number , long long int second_number){
    long long int divide = second_number/first_number;
    return divide;
}
    
int evalRPN(vector<string>& tokens) {
        stack<long long int>Operation;
        for(int i=0;i<tokens.size();i++){
            //operands
            if(tokens[i]!="+" and tokens[i]!="-" and tokens[i]!="*" and tokens[i]!="/"){
                int value = stoi(tokens[i]);
                Operation.push(value);
            }
            //operator
            else{
               long long int first_number = Operation.top(); 
                Operation.pop();
                long long int second_number = Operation.top(); 
                Operation.pop();
                if(tokens[i]=="+"){
                    int value_to_push = addition( first_number ,  second_number);
                    Operation.push(value_to_push);
                }
                if(tokens[i]=="-"){
                    int value_to_push = subtraction( first_number ,  second_number);
                    Operation.push(value_to_push);
                }
                if(tokens[i]=="*"){
                    int value_to_push = multiplication( first_number ,  second_number);
                    Operation.push(value_to_push);
                }
                if(tokens[i]=="/"){
                    int value_to_push = division( first_number ,  second_number);
                    Operation.push(value_to_push);
                }
            }
        }

    long long int answer = Operation.top();
    Operation.pop();
    return answer;
    }
};
