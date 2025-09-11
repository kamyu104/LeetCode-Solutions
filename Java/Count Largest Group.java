class Solution {
    public int countLargestGroup(int n) {
       Map<Integer, Integer>hashMap=new HashMap<Integer,Integer>();
        int maxValue=0;
        for(int i=1;i<=n;i++)
        {
            int key=0,num=i;
            while(num!=0)
            {
                key+=num%10;
                num=num/10;
            }
            hashMap.put(key,hashMap.getOrDefault(key,0)+1);
            maxValue=Math.max(maxValue,hashMap.get(key));
   }
     int count=0;
        for(Map.Entry<Integer,Integer>kvpair: hashMap.entrySet()){
            if(kvpair.getValue()== maxValue)
                {
                ++count;
                }
            }
        return count;
                
    }
}