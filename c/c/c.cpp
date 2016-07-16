


// 666.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "stddef.h"
#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "windows.h"
#include "math.h"
int main()
{
	char *content;
	int i,j,j1,b1,b2,b3,b4,b5,b6,c1,c2,c3,v3;
	double a1,a2,a3,a4,a5,a6,a7,a8,s,s1,s2,v,v1,v2;
	a1=1,a2=1;
	char lat[10],lat1[10],lon[11],lon1[11],date1[5],date2[5],date3[3],time1[3],time2[3],time3[3],time4[3],time5[3],time6[3];
	size_t length;
	FILE *fp,*fp1;
	HWND hWnd=GetConsoleWindow();
	HDC hdc=GetWindowDC(hWnd);
	HPEN hpen;
	HPEN old_pen;
	MoveToEx(hdc,a1,a2,NULL);
    fp=fopen("c:\\152\\export.gpx","r");
	fp1=fopen("c:\\152\\1.csv","w");
	fseek(fp,0,SEEK_END);
	length=ftell(fp);
    fseek(fp,0,SEEK_SET);
	content=new char[length+1];
	fread(content,sizeof(char),length,fp);
	content[length]='\0';
	i=0;
	while(!(content[i]=='<'&&content[i+1]=='/'&&content[i+2]=='g'&&content[i+3]=='p'&&content[i+4]=='x'&&content[i+5]=='>'))
	{
	    if(content[i]==' '&&content[i+1]=='l'&&content[i+2]=='a'&&content[i+3]=='t')    
	    {
			strncpy(lat,&content[i+6],9);
	        strncpy(lon,&content[i+22],10);
	        strncpy(date1,&content[i+44],4);
			strncpy(date2,&content[i+49],2);
			strncpy(date3,&content[i+52],2);
            strncpy(time1,&content[i+55],2);
			strncpy(time2,&content[i+58],2);
			strncpy(time3,&content[i+61],2);
			strncpy(lat1,&content[i+97],9);
			strncpy(lon1,&content[i+113],10);
			strncpy(time4,&content[i+146],2);
			strncpy(time5,&content[i+149],2);
			strncpy(time6,&content[i+152],2);
	        lat[9]=0;
	        lon[10]=0;
	        date1[5]=0;
			date2[5]=0;
			date3[3]=0;
			time1[3]=0;
			time2[3]=0;
			time3[3]=0;
            time4[3]=0;
			time5[3]=0;
			time6[3]=0;
			a1=atof(lat);
			a2=atof(lon);
			a3=atof(lat1);
			a4=atof(lon1);
			b1=atoi(time1);
			b2=atoi(time2);
			b3=atoi(time3);
            b4=atoi(time4);
			b5=atoi(time5);
			b6=atoi(time6); 
			c1=atoi(date1);
			c2=atoi(date2);
			c3=atoi(date3);
	        j=b1*3600+b2*60+b3;
            j1=b3*3600+b4*60+b5;	
			a5=a1*11094;
			a6=a3*11094;
			a7=a2*85276;
			a8=a4*85276;
			s1=(a6-a5)*(a6-a5);
			s2=(a8-a7)*(a8-a7);
			s=sqrt(s1*s1+s2*s2);
			v=s/j-j1;
			v1=v/1000;
			v2=fabs(v1);
			v3=floor(v2);
			if(0<v3<255)
			{
                   hpen=CreatePen(PS_SOLID,2,RGB(v3,255-v3,0));
		           old_pen=(HPEN)SelectObject(hdc,hpen);
	               LineTo(hdc,a1*1000-40770,a2*1000-111768);
			       DeleteObject(hpen);
			};
		}
		else (!(content[i]==' '&&content[i+1]=='l'&&content[i+2]=='a'&&content[i+3]=='t'));
        i++;    
	}
	SelectObject(hdc,old_pen);
	fclose(fp); 
	fclose(fp1);
	getchar();
	return 0;
}

