class Solution {
    public int maxIceCream(int[] arr, int coins) {
        Arrays.sort(arr);
        int count=0;
        for(int i=0;i<arr.length && coins>=arr[i];i++){
            count++;
            coins-=arr[i];
            
            }
        return count;
        }
        
    }