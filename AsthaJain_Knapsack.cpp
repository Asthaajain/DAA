#include <iostream>
#include <math.h>


using namespace std;


int main()
{

	int p[5] = {0,1,2,5,6};

	int wt[5] = {0,2,3,4,5};

	int m=8, n=4, x, y;

	int k[5][9];


	cout<<"\nThe 0/1 Knapsac problem via Dynamic programming. \n\n";

	cout<<"\nWeight and Priority Table. \n\n";


	for(int i =0; i<=n; i++)
	{
		for(int w=0; w<=m; w++)
		{
			if(i==0 || w==0)

				k[i][w]=0;


			else
			if(wt[i] <= w)

				k[i][w] = max( p[i] + k[i-1][w - wt[i]],  k[i-1][w] );



			else
				k[i][w]= k[i-1][w];
				
			y = w;

		}

			x = i;
			
	}
	
	

	for(int i=0; i<=n; i++)                            //just for display but will increase the complexity
	{
		for(int w=0; w<=m; w++)
		{

			cout<<k[i][w]<<"  ";

		}

			cout<<"\n";
	}


    cout<<"\n\n";

	
	
	int ele;

	ele = k[x][y];

	cout<<"Element 1: "<<ele;
	cout<<"\n";

	ele = k[x][y] - p[x];

	cout<<"Element 2: "<<ele;
	cout<<"\n\n";

	cout<<"\n\n";

   return 0;

}
