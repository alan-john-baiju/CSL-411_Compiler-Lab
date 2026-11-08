#include<stdio.h>
#include<string.h>
char input[100];
int i=0;
int error=0;
void E(), EP(), T(), TP(), F();
void E(){
	T();
	EP();
}
void EP(){
	if(input[i]=='+'){
		i++;
		T();
		EP();
	}
}
void T(){
	F();
	TP();
}
void TP(){
	if(input[i]=='*'){
		i++;
		F();
		TP();
	}
}
void F(){
	if(input[i]=='i' && input[i+1]=='d')
		i+=2;
	else if(input[i]=='i')
		i++;
	else if(input[i]=='('){
		i++;
		E();
		if(input[i]==')')
			i++;
		else
			error=1;
	}
	else
		error=1;
}
int main(){
	printf("\nEnter An Input String:");
	scanf("%s",input);
	E();
	if(input[i]=='\0' && error==0)
		printf("\nString Accepted\n");
	else
		printf("\nString Rejected\n");
	return 0;
}