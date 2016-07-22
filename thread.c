#include<stdio.h>
#include<pthread.h>
void *row();
void *col();
void *box();
int a[10][10];
int main()
{
        int sum,i,j;
        void *m;
        for(i = 1;i <= 9;i++)
        {
                for(j = 1;j<=9;j++)
                {
                        scanf("%d",&a[i][j]);
                }
        }
        pthread_t tid[3];
        pthread_create(&tid[0],NULL,row,NULL);
        pthread_join(tid[0],&m);
        if(m == 9)
		printf("rows ok");
		else
		printf("not ok");
        pthread_create(&tid[1],NULL,col,NULL);
        pthread_join(tid[1],&m);
        if(m == 9)
		printf("cols ok");
		else
		printf("not ok");
	pthread_create(&tid[2],NULL,box,NULL);
        pthread_join(tid[2],&m);
        if(m == 9)
		printf("boxes ok");
	else
		printf("not ok");

}
void *row()
{
        int i,j,k = 0,p = 0,h = 0;

        for(i = 1;i<= 9;i++)
        {
		int b[10] = {0};
                for(j = 1;j <= 9;j++)
		{
			b[a[i][j]] = 1;
		}
		 int f = 0;
		for(k = 1;k <= 9;k++){
			if(b[k] == 0)
			{
				f = 1;
				break;
			}
		}
		if(f == 0)
			h++;
        }
pthread_exit((void *)h);
}
void *col()
{
        int i,j,k = 0,p = 0,h = 0;

        for(j = 1;j<= 9;j++)
        {
		int b[10] = {0};
                for(i = 1;i <= 9;i++)
		{
			b[a[i][j]] = 1;
		}
		 int f = 0;
		for(k = 1;k <= 9;k++){
			if(b[k] == 0)
			{
				f = 1;
				break;
			}
		}
		if(f == 0)
			h++;
        }
pthread_exit((void *)h);
}
void *box()
{
	int i,j,k,l,m,n,h = 0,x;
	for(i = 1;i <= 7;i+=3)
	{
		for(j = 1;j <= 7;j+=3)
		{
			int b[10] = {0};
			for(k = i;k < i+3;k++)
			{
				for(l = j;l<j+3;l++)
				{
					b[a[k][l]] = 1;
				}
			}
			int f = 0;
			for(m = 1;m <= 9;m++){
			if(b[m] == 0)
			{
				f = 1;
				break;
			}
			}
				if(f == 0)
					h++;
		}
	}
pthread_exit((void *)h);
}
