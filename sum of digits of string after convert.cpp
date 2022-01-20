class Solution {

public:

    int getLucky(string s, int k) {

       

        int n = s.size();

        

        int num = 0;

        

        for(int i = 0; i < n; i++)

        {

            int x = s[i] - 'a' + 1;

            

            while(x > 0)

            {

                num += x % 10;

                

                x = x / 10;

            }

        }

        

        for(int i = 1; i < k; i++)

        {

            int sum = 0;

            

            while(num > 0)

            {

                int r = num % 10;

                

                sum += r;

                

                num = num / 10;

            }

            

            num = sum;

        }

        

        return num;

    }

};
