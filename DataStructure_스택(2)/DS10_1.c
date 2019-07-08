#include <stdio.h>
#include <string.h>

void PUSH(char *p, char ch, int *top) {
	p[++(*top)] = ch;
}
char POP(char *p, int * top) {
	char ch;

	ch = p[(*top)];
	p[(*top)--] = '\0';

	return ch;
}

//단항연산자 + - 체크
void Find(char *p) {
	int i;
	//수식 처음에 오는경우
	if (p[0] == '+') p[0] = '=';
	if (p[0] == '-') p[0] = '_';

	for (i = 0; p[i]; i++) {
		if (p[i] == '+' || p[i] == '-' || p[i] == '*' || p[i] == '/' || p[i] == '!' || p[i] == '>' || p[i] == '<' || p[i] == '&' || p[i] == '|' || p[i] == '(') {
			if (p[i + 1] == '+') p[i + 1] = '=';
			else if (p[i + 1] == '-') p[i + 1] = '_';
		}
	}
}

int Priority(char ch) {
	if (ch == '(' || ch == ')')                return 0;
	else if (ch == '|')                   return 1;
	else if (ch == '&')                   return 2;
	else if (ch == '<' || ch == '>')          return 3;
	else if (ch == '+' || ch == '-')          return 4;
	else if (ch == '*' || ch == '/')          return 5;
	else if (ch == '!' || ch == '=' || ch == '_') return 6;
}

void Convert(char *p) {
	char st[50], tmp;   //st: 연산자 쌓아둘 스택
	int i, top = -1, len;

	Find(p);   //단항연산자 + - 검사
	len = strlen(p);

	for (i = 0; i<len; i++) {

		if (p[i] == '+' || p[i] == '-' || p[i] == '*' || p[i] == '/' || p[i] == '!' || p[i] == '>' || p[i] == '<' || p[i] == '&' || p[i] == '|' || p[i] == '=' || p[i] == '_')
		{
			//스택이 비어있지않고 스택내 연산자가 지금확인중인 연산자보다 운선순위가 높을경우

			while (top != -1 && Priority(p[i]) <= Priority(st[top]))
			{
				tmp = POP(st, &top);   //스택상단 원소 반환받기.
				print(tmp);         //출력
			}

			PUSH(st, p[i], &top);   //연산자 스택에다 입력

			if ((p[i] == '&') || (p[i] == '|')) i++; //&& ||의 경우 처음오는 & | 만 스택에다 넣을거임(print 함수에서 & |일때 && ||로 출력)   
		}

		else if (p[i] == '(')
			PUSH(st, p[i], &top);

		else if (p[i] == ')') {
			tmp = POP(st, &top);
			while (tmp != '(') {   //여는괄호 나올때까지 스택상단부터 출력
				print(tmp);
				tmp = POP(st, &top);
			}
		}

		else
			printf("%c", p[i]); //숫자(대문자) 출력
	}

	while (top != -1) {   //스택에 남은거 비워질때까지 출력
		tmp = POP(st, &top);
		print(tmp);
	}printf("\n");

}

void print(char ch) {
	if (ch == '=')         printf("+");
	else if (ch == '_')   printf("-");
	else if (ch == '&')   printf("&&");
	else if (ch == '|')   printf("||");
	else            printf("%c", ch);
}
void main() {
	char str[101];

	int n, i;

	scanf("%d", &n); getchar(); //버퍼제거
	for (i = 0; i<n; i++) {
		gets(str);
		Convert(str);
	}
}

