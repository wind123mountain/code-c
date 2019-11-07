#include <stdio.h>
#include <stdlib.h>
//#include <conio.h>

typedef struct point{
        float x;
        float y;
}Point2D;


int main()
{

    int so_nguyen = 9;
    int *con_tro_so_nguyen = (int *)malloc(sizeof(int));
    float *con_tro_so_thuc = (float *)malloc(sizeof(float));
    char *con_tro_ky_tu = (char *)malloc(sizeof(char));
    //printf("Dia cho bien khai bao thuong %p \n",&so_nguyen);

    
    printf("Dia cho con tro so nguyen %p \n",con_tro_so_nguyen);
    printf("Dia cho con tro so thuc %p \n",con_tro_so_thuc);
    printf("Dia cho con tro ky tu %p \n",con_tro_ky_tu);
	   
		
		*con_tro_so_nguyen = 107;
    *con_tro_so_thuc = 3.1416;
    *con_tro_ky_tu = 'A';
    
    printf("Noi dung con tro so nguyen %d \n",*con_tro_so_nguyen);
    printf("Noi dung con tro so thuc %5.4f \n",*con_tro_so_thuc);
    printf("Noi dung con tro ky tu %c \n",*con_tro_ky_tu);

		printf("Dia cho con tro so nguyen %p \n",con_tro_so_nguyen);
    printf("Dia cho con tro so thuc %p \n",con_tro_so_thuc);
    printf("Dia cho con tro ky tu %p \n",con_tro_ky_tu);
	   
		
		*con_tro_so_nguyen = 6868;
    *con_tro_so_thuc = 2.17;
    *con_tro_ky_tu = 'B';
    
    printf("Noi dung con tro so nguyen %d \n",*con_tro_so_nguyen);
    printf("Noi dung con tro so thuc %5.4f \n",*con_tro_so_thuc);
    printf("Noi dung con tro ky tu %c \n",*con_tro_ky_tu);
    

		free(con_tro_so_nguyen);
		free(con_tro_so_thuc);
		free(con_tro_ky_tu);




    Point2D a;
    Point2D *con_tro_a = (Point2D *)malloc(sizeof(Point2D));
        
    a.x = 2.4;
    a.y = 4.6;
    printf("\n Toa do cua a la (%4.2f,%4.2f) ",a.x,a.y);

    con_tro_a->x = 3.4;
    con_tro_a->y = 4.2;

    printf("\n Toa do cua con tro a la (%4.2f,%4.2f) ",con_tro_a->x,con_tro_a->y);
		printf("\n Dia chi con tro point 2D %p \n",con_tro_a);
		//printf("\n Kich thuoc cau truc point 2D %d \n",sizeof(Point2D));
		free(con_tro_a);
   
    //con_tro_so_nguyen = (char *)malloc(1024*sizeof(char));
    //con_tro_a = (Point2D *)malloc(1024*sizeof(Point2D));
   
    
    
    
    
    getch();
    return 0;
}
