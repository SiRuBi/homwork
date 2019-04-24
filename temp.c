#include <stdio.h>  
#include <unistd.h>  
#include <sys/types.h>  
#include <sys/wait.h>  
#include <stdlib.h>  
#include <string.h>  
#define MAXLINE 100 // 넉넉하게 100잡아줍니다 

 int main(void) { 

	 int pid, len = 5, i, j, status; 

     char buffer[MAXLINE]; 
	 char copy[MAXLINE]; 
	 FILE *fp = NULL; // 파일 두개를 open합니다 
	FILE *fp2 = NULL; 
				fp = fopen("sample.txt", "r"); 
				fp2 = fopen("output.txt", "w"); 
					if (fp == NULL) { // sample파일 없으면 종료합니다 
						 printf("File Open Fail!\n"); 
						 return 0; 
										    } 
						fgets(buffer, MAXLINE, fp); // sample파일로부터 문자열을 읽습니다 
						len = strlen(buffer) - 1; // 길이를구합니다 끝에 널문자포함이므로 -1을 합니다 
						for (i = 0; i<len; i++) { // 길이만큼 반복합니다     pid = fork(); // fork로 자식생성합니다 
							if (pid == 0) { 
								strncpy(copy, buffer, i + 1); // i+1만큼의 문자열을 copy변수로 복사합니다 
								 copy[i + 1] = '\0'; // 끝에 널을 넣어 문자열의끝을 나타냅니다. 
								 fprintf(fp2, "%s\n", copy); // 복사한문자열과 \n을 파일에 입력합니다 
								 printf("%d -> %d\n", getppid(), getpid()); // 부모와 자식프로세스의 아이디를 출력합니다 
								 exit(1); // 자식프로세스 종료합니다 
																			   } 
								 waitpid(pid, &status, WNOHANG); // 해당자식이 종료될때까지 기다립니다 
								 sleep(0.1); // 0.1초 슬립합니다 그래야 순서대로 됩니다 
												 } 
	 fclose(fp); 
	 fclose(fp2); 
	 return 0; 
									  } 
