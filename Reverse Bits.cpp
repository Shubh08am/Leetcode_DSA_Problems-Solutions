class Solution {

public:

    uint32_t reverseBits(uint32_t n) {

        

    unsigned int  NO_OF_BITS = sizeof(n) * 8; 

    unsigned int reverse_n = 0, i, temp; 

  

    for (i = 0; i < NO_OF_BITS; i++) 

    { 

        temp = (n & (1 << i)); 

        if(temp) 

            reverse_n |= (1 << ((NO_OF_BITS - 1) - i)); 

    } 

   

    return reverse_n; 

} 

};
