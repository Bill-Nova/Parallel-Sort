#include <stdio.h>
#include <windows.h>
#include <time.h>

//If your computer is 32-bit, change longlong to int!!!!

long long Input_Add[1000];
long long Sort_Add[1000];
long long Input_MAX=1000;

DWORD WINAPI Parallel_Sort(LPVOID lpParam){
	long long ID=(long long)lpParam;
	long long Key=0;
	long long X=Input_Add[ID];
	
	long long Counter=ID;
Loop_H:	
	Counter++;
	if(Counter<=Input_MAX){
		Key=Key+(Input_Add[Counter]<X);
		goto Loop_H;
	}
	
	
	Counter=ID;
Loop_L:
	Counter--;
	if(Counter>=0){
		Key=Key+(Input_Add[Counter]<=X);
		goto Loop_L;
	}
	
	Sort_Add[Key]=X;
	ExitThread;
}

int main(){
	long long Counter;
	long long Thread_Max=Input_MAX;
//------------------------------------------------
	Counter=0;
	srand((unsigned)time(NULL));
Loop_Input_Rand:
		Input_Add[Counter]=rand()%1000;
	if(Counter!=Thread_Max){
		Counter++;
		goto Loop_Input_Rand;
	}
//------------------------------------------------
	HANDLE h;
Create_Thread_Loop:
	h=CreateThread(NULL,0,Parallel_Sort,(LPVOID)Thread_Max,0,NULL);
	if(h==NULL){ 
		printf("Creater Thread ERR!!!");
		goto ERR_End;
	}
	CloseHandle(h);
	if(Thread_Max!=0){
		Thread_Max--;
		goto Create_Thread_Loop;
	}
//--------------------------------------------------
	Sleep(1000);
	Counter=Input_MAX;
Printf_Loop:
	printf("%d",Sort_Add[Counter]);
	printf(" ");
	if(Counter!=0){
		Counter--;
		goto Printf_Loop;
	}
//------------------------------------------------
	ERR_End:
}
