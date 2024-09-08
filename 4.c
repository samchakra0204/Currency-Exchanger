#include<stdio.h>
#include<sys/wait.h>
#define MAX 20
void ChildProcess(void);
void ParentProcess(void);
void main(void)
{
pid_t pid;
pid = fork();
if (pid == 0)
ChildProcess();
else
ParentProcess();
}
void ChildProcess(void)
{
int i;
for (i = 1; i <= MAX; i++)
printf("This line is from child, value = %d", i);
printf("*** Child process is done ***");
}
void ParentProcess(void)
{
int i, status;
wait(&status);
for (i = 1; i <= MAX; i++)
printf("This line is from parent, value = %d", i);
printf("*** Parent is done ***");
}