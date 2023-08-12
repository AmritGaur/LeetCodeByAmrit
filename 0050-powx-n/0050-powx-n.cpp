class Solution {
public:
    double myPow(double x, int n) {
        if(n==0 || x==1){
            return 1;
        }
        double sum=1.0;
        long long int y=n;
        if(y<0){
            y=-1*y;
        }
        
        while(y!=0){
        if(y%2==1){
            sum*=x;
            y--;
        }
        else{
            x=x*x;
            y=y/2;
        }
        }
        
        if(n<0){
            return (1/sum);
        }
        else if(n>0){
        return sum; 
        }
        return 0;
    }
};