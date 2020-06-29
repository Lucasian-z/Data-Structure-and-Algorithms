#include <stdio.h>
#include <stdlib.h>
#include <mem.h>
#include <string.h>

int main()
{
    FILE *fp = fopen("test.txt", "r+");//perror与fp之间不能有其他函数
    if (NULL == fp) {
        perror("fopen");
    }
    char c;
    //while ((c = fgetc(fp)) != EOF) {
        //putchar(c);
    //}
    //c = 'H';
    //int ret = fputc(c, fp);
    //if (ret == EOF) {//若无写权限
        //perror("fpuc");
    //}
    //写入数据：1.
    //fclose(fp);
    char buf[10] = "10000";
    //while (memset(buf, 0, sizeof(buf)), fgets(buf, sizeof(buf), fp) != NULL) {
        //puts(buf);//中文本文格式要为GBK，utf-8不行
    //}
    int val = 0;
    //int ret = fwrite(&val, sizeof(int), 1, fp);
    int ret = fread(&val, sizeof(int), 1, fp);
    printf("val = %d\n", val);
    printf("%d\n", ret);
    fclose(fp);
    return 0;
}
