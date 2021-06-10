#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <string>
int min(int a, int b) {
    return a < b ? a : b;
}
int minDis(char word1[2000], char word2[2000]) {
	int n1 = strlen(word1);
	int n2 = strlen(word2);
	int dp[2000][2000];
    dp[0][0] = 0;
	for (int j = 1; j <= n2; j++)  //初始化dp[0][0..n2]
		dp[0][j] = dp[0][j - 1] + 1;
	for (int i = 1; i <= n1; i++)
		dp[i][0] = dp[i - 1][0] + 1; //初始化dp[0..n1][0]

    /*根据推导出的关系求值*/
    for (int i = 1; i <= n1; i++) {
        for (int j = 1; j <= n2; j++) {
            // 如果 word1[i] 与 word2[j] 相等。第 i 个字符对应下标是 i-1
            if (word1[i-1] == word2[j-1]) {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else {
                dp[i][j] = min(min(dp[i - 1][j - 1], dp[i][j - 1]), dp[i - 1][j]) + 1;
            }
        }
    }
    return dp[n1][n2];
}
int main(void) {
    char word1[2000];
    char word2[2000];
    scanf("%s", word1);
    scanf("%s", word2);
    int min = minDis(word1, word2);
    printf("%d", min);
}