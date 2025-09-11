bool isPowerOfFour(int n) {
    if(n==0)
        {
        return 0;
        }
    for(int i=0;i<=16;i++)
        {
        if((int)pow(4,i)==n)
            {
            return 1;
            }
        }
    return 0;
    
}
