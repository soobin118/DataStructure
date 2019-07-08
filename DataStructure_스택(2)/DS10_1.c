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

//���׿����� + - üũ
void Find(char *p) {
	int i;
	//���� ó���� ���°��
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
	char st[50], tmp;   //st: ������ �׾Ƶ� ����
	int i, top = -1, len;

	Find(p);   //���׿����� + - �˻�
	len = strlen(p);

	for (i = 0; i<len; i++) {

		if (p[i] == '+' || p[i] == '-' || p[i] == '*' || p[i] == '/' || p[i] == '!' || p[i] == '>' || p[i] == '<' || p[i] == '&' || p[i] == '|' || p[i] == '=' || p[i] == '_')
		{
			//������ ��������ʰ� ���ó� �����ڰ� ����Ȯ������ �����ں��� ������� �������

			while (top != -1 && Priority(p[i]) <= Priority(st[top]))
			{
				tmp = POP(st, &top);   //���û�� ���� ��ȯ�ޱ�.
				print(tmp);         //���
			}

			PUSH(st, p[i], &top);   //������ ���ÿ��� �Է�

			if ((p[i] == '&') || (p[i] == '|')) i++; //&& ||�� ��� ó������ & | �� ���ÿ��� ��������(print �Լ����� & |�϶� && ||�� ���)   
		}

		else if (p[i] == '(')
			PUSH(st, p[i], &top);

		else if (p[i] == ')') {
			tmp = POP(st, &top);
			while (tmp != '(') {   //���°�ȣ ���ö����� ���û�ܺ��� ���
				print(tmp);
				tmp = POP(st, &top);
			}
		}

		else
			printf("%c", p[i]); //����(�빮��) ���
	}

	while (top != -1) {   //���ÿ� ������ ����������� ���
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

	scanf("%d", &n); getchar(); //��������
	for (i = 0; i<n; i++) {
		gets(str);
		Convert(str);
	}
}

