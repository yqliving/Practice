//素数不能被比它小的整数整除, 建一个boolean 数组, 从2开始, 把其倍数小于N的都删掉.//12 ms:
class Solution {  
    public:
    int countPrimes(int n) {  
     //2,3,5,7,11,13,17   
     //20  5  
     //init check  n  
     bool *a = new bool[n];  
     for(int i=2; i*i<n; i++) {  
        if(!a[i]) {  
            for(int j=i; i*j<n; j++) {  
                a[i*j] = true;  
            }  
        }  
     }  
     int c=0;  
       
     for(int i=2; i<n; i++) {  
         if(a[i] == false) ++c;  
     }  
     return c;  
    }  
};  


/*
//Here notPrime[i] refer to the number a = 2* i + 1, so the marking process starts from a^2 which is 2i(i+1) back to index
class Solution {
public:
int countPrimes(int n) {
    if(--n < 2) return 0;
    int m = (n + 1)/2, count = m, k, u = (sqrt(n) - 1)/2;
    bool notPrime[m] = {0};
    
    for(int i = 1; i <= u;i++)
        if(!notPrime[i])
          for(k = (i+ 1)*2*i; k < m;k += i*2 + 1)
              if (!notPrime[k])
              {
                  notPrime[k] = true;
                  count--;
              }
    return count;
}
};

//28ms
/*
class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;
        double c = sqrt(n);
        bool *bv = new bool[n];
        for(int i = 3; i <= c; i += 2)
            if (!bv[i]) 
                for(int j = i*i, k = i << 1; j < n; j += k)
                    bv[j] = 1;
        int num = 1;
        for(int i = 3; i < n; i += 2)
            if(!bv[i]) num++;
        return num;
    }
};




/*class Solution {
public:
   int countPrimes(int n) {
    if (n<=2) return 0;
    
	//vector<bool> passed(n, true);// array is faster than vector
    bool* passed = new bool[n];   //change it from vector<bool> to bool*, 216ms -> 40ms
    
	int sum = 1;
	int upper = sqrt(n);
	for (int i=3; i<n; i+=2) {
		if (!passed[i]) {
			sum++;
			//avoid overflow
			if (i>upper) continue;
			for (int j=i*i; j<n; j+=i) {
				passed[j] = true;
			}
		}
	}
	return sum;
}
};

