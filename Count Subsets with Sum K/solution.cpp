int findWays(vector<int>& arr, int w)
{

	// Write your code here.
	int n=arr.size();
	long long int t[n+1][w+1];

	//initialization
	for(int i=0;i<n+1;i++){
		for(int j=0;j<w+1;j++){
			if(i==0) t[i][j]=0;
			if(j==0) t[i][j]=1;
		}
	}

	//iterative code

	for(int i=1;i<n+1;i++){
		for(int j=1;j<w+1;j++){
			if(arr[i-1]<=j){
				t[i][j]=(t[i-1][j]+t[i-1][j-arr[i-1]]) % 1000000007;
			}
			else{
				t[i][j]=t[i-1][j];
			}
		}
	}
	return t[n][w];
}
