class Solution {
public:
    int nthUglyNumber(int n) {
set<long long int>number;
number.insert(1); //1st ugly number

long long int factor = 1 ; 

for(int i=0;i<n;i++){

factor = *number.begin();

long long int fact_2 = factor *2;
long long int fact_3 =  factor *3;
long long int fact_5 = factor *5;
number.erase(factor);
number.insert(fact_2); 
number.insert(fact_3); 
number.insert(fact_5); 
}
return factor ;
    }
}; 
 
