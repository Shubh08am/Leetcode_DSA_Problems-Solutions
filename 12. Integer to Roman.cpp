class Solution {
public:
    string intToRoman(int num) {
  string roman[13] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

 int rom[13] = {1000, 900, 500, 400, 100,  90,  50,  40, 10,   9,   5,   4,  1};
 string res;
  for (int i=0; i<13; i++) {
  int last = num/rom[i];
     for (int j=0; j<last; j++) {
                 res += roman[i];
            }
     num = num % rom[i];
   }
    return res;       
    }
};
