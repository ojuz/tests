#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <set>

using namespace std;
typedef long long ll;

void ERROR(const char* str) {
	printf("Incorrect - %s", str);
	exit(0);
}

int N, Q;
char CST[20], USRCST[20];
char S[200005], E[200005];

int main(int argc, char *argv[]){
	FILE *in = fopen(argv[1], "r");
	FILE *out = fopen(argv[2], "r");
	FILE *usrout = fopen(argv[3], "r");

	int i;

	if (fscanf(in, "%d%s", &N, S + 1) != 2) ERROR("??A");
	if (fscanf(out, "%s", CST) != 1) ERROR("??B");
	if (fscanf(usrout, "%s%s", USRCST, E + 1) != 2) ERROR("출력 형식을 다시 살펴보세요");

	if (strcmp(CST, USRCST)) {
		ERROR("비용이 정답과 다릅니다.");
	}

	if (strcmp(USRCST, "WRONG")) {
		ll cost; sscanf(USRCST, "%lld", &cost);
		if ((int)strlen(E + 1) != N) ERROR("복구된 괄호열의 길이가 N과 다릅니다.");
		int depth = 0;

		ll tcost = 0;
		for (i = 1; i <= N; i++) {
			if (S[i] == '(') {
				++depth;
				if (E[i] != '(') ERROR("원래 '('이 있던 자리에 다른 문자가 있습니다.");
			}
			else if (S[i] == ')') {
				--depth;
				if (E[i] != ')') ERROR("원래 ')'이 있던 자리에 다른 문자가 있습니다.");
			}
			else {
				int a, b; if (fscanf(in, "%d%d", &a, &b) != 2) ERROR("??");
				if (E[i] == ')') {
					if (depth == 0) ERROR("올바르지 않은 괄호열을 출력했습니다.");
					--depth;
					tcost += b;
				}
				else if (E[i] == '(') {
					++depth;
					tcost += a;
				}
				else {
					ERROR("복구된 문자열에 '(', ')'를 제외한 다른 문자가 있습니다.");
				}
			}
			if (depth < 0) ERROR("올바르지 않은 괄호열을 출력했습니다.");
		}

		if (depth != 0) ERROR("올바르지 않은 괄호열을 출력했습니다.");
		if (cost != tcost) ERROR("복구된 문자열의 실제 비용과 출력한 비용이 다릅니다.");
	}

	printf("Correct");
	return 0;
}
