#include <bits/stdc++.h>
using namespace std;

int main()
{
	int i, j, k, n;
	float count = 0;
	cout << "Enter number of variables: ";
	cin >> n;

	float main[2*n][2*n]; // This is the array of order 2nx2n in which the original matrix will be stored
	float t;
	float inv[2*n][2*n]; // this is the array in which the inverse of the matrix will be stored
	float consta[n][1];		 // this is the array in which of the values of the constants will be stored
	float ans[n][1];		 // this is the array in which our final answers will be stored

	// Storing the coefficients and the constants of the equation
	for (i = 0; i < n; i++)
	{
		for (j = 0; j <= n; j++)
		{
			if (j == n)
			{
				cout << "Enter the value of the constant for equation number " << i + 1 << ": ";
				cin >> consta[i][0];
			}
			else
			{
				cout << "Enter coefficient of equation number " << i + 1 << " x" << j + 1 << ": ";
				cin >> main[i][j];
			}
		}
	}

	// Initialising the second half of the matrix as an identity matrix
	for (i = 0; i < n; i++)
	{
		for (j = n; j < 2 * n; j++)
		{
			if (i == j - n)
			{
				main[i][j] = 1;
			}
			else
			{
				main[i][j] = 0;
			}
		}
	}

	// Calculating the inverse of the matrix now
	for (i = 0; i < n; i++)
	{
		t = main[i][i];
		for (j = i; j < 2 * n; j++)
		{
			main[i][j] = main[i][j] / t;
		}
		for (j = 0; j < n; j++)
		{
			if(i!=j){
				t=main[j][i];
				for (k = 0; k < 2*n; k++)
				{
					main[j][k]=main[j][k]-(t*main[i][k]);
				}
				
			}
		}
	}

	

	// Checking to see if there any invalid values in the inverse matrix and then storing the values in an NxN matrix for further operations
	for (i = 0; i < n; i++)
	{
		int z=0;
		for (j = n; j < 2*n; j++)
		{
			if(isinf(main[i][j]==1||isnan(main[i][j]==1))){
				count=1;
				break;
			}
			inv[i][z++]=main[i][j];
		}
		
		
	}

	//If there are no invalid values in the inverse matrix, then we multiply the inverse matrix with the matrix containing the constants
	if(count ==0){
		//Displaying the inverse matrix
		// cout<<"\n\nInverse Matrix\n\n";
		// for(i = 0;i<n;i++){
		// 	for (j =0;j < n;j++)
		// 	{
		// 		cout<<"\t"<<inv[i][j];
		// 	}
		// 	cout<<"\n";
		// }

		//Initialising all the values of the answer matrix to 0
		for ( i = 0; i < n; i++)
		{
			ans[i][0]=0;
		}

		//Multiplying the inverse matrix to the constants matrix
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < 1; j++)
			{
				for(k = 0;k<n;++k){
					ans[i][j]+= inv[i][k]*consta[k][j];
				}
			}	
		}	

		//Displaying the values of the variables
		for(i=0;i<n;i++){
			for(j=0;j<1;j++)
				cout<<"x"<<i+1<<": "<<ans[i][0];
			cout<<"\n";
		}	
	}
	else{
		cout<<"\nThe system of equations has no unique solution";
	}


	return 0;
}