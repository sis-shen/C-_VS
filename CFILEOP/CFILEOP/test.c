#define  _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <sys/stat.h>


//int main()
//{
//	//׼��һ���ļ�
//	FILE* pfile = fopen("file.txt", "w");//"w"ģʽ���ļ�file.txt
//	int code = 1;
//	const char* msg = "this is a msg";
//	fprintf(pfile, "get msg : %s code:%d", msg, code);
//	fclose(pfile);
//	//=====
//
//	pfile = fopen("file.txt", "r");
//	char str[5] = { 0 };
//	fgets(str, sizeof(str), pfile);//��ȥ�Զ���ӵ�\0,�����ļ������4���ַ�
//	printf(str);
//	printf("|");
//	return 0;
//}

int main()
{
	FILE* pfile = fopen("file.txt", "w");//"w"ģʽ���ļ�file.txt
	char msg[] = "this is a msg";
	fwrite(msg, sizeof(char), strlen(msg), pfile);

	fclose(pfile);

	return 0;
}

