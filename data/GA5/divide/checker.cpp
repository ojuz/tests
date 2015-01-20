#include <stdio.h>
#include <set>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <cmath>

using namespace std;

void ERROR(const char *s) {
	printf("Incorrect\n");
	exit(0);
}

int N, X[100005], Y[100005], A[10];
char res[100], usr_res[100];

bool is_double(char *s) {
	int l = strlen(s);
	if (l > 20) return false;

	bool ret = false;
	int cnt = 0;

	while (l--) {
		if ('0' <= s[l] && s[l] <= '9') {
			++cnt;
			continue;
		}
		else if (s[l] == '.') {
			ret = (cnt <= 6);
			cnt = 0;
		}
		else {
			if (l != 0 || s[l] != '-') return false;
		}
	}

	if (cnt > 10) ret = false;
	return ret;
}

double X1, X2, Y1, Y2;
int a[9];

int main(int argc, char *argv[]) {
	int i, tmp;

	FILE *in = fopen(argv[1], "r");
	FILE *out = fopen(argv[2], "r");
	FILE *usrout = fopen(argv[3], "r");

	tmp = fscanf(in, "%d", &N);
	if (tmp != 1) ERROR("??");

	for (i = 1; i <= N; i++) {
		tmp = fscanf(in, "%d%d", X + i, Y + i);
		if (tmp != 2) ERROR("??");
	}

	for (i = 0; i < 9; i++) {
		tmp = fscanf(in, "%d", A + i);
		if (tmp != 1) ERROR("??");
	}

	fclose(in);

	char *rp = fgets(res, 100, out); if (rp == NULL) ERROR("??");
	char *urp = fgets(usr_res, 100, usrout); if (urp == NULL) ERROR("??");
	if (strcmp(res, usr_res)) ERROR("가능/불가능 여부가 다릅니다.");
	if (!strncmp(res, "IMPOSSIBLE", 10)) return 0 & puts("Correct");

	tmp = fscanf(usrout, "%s", res);
	if (tmp != 1 || !is_double(res)) ERROR("x좌표 출력이 잘못되었습니다.");
	sscanf(res, "%lf", &X1);

	tmp = fscanf(usrout, "%s", res);
	if (tmp != 1 || !is_double(res)) ERROR("x좌표 출력이 잘못되었습니다.");
	sscanf(res, "%lf", &X2);

	tmp = fscanf(usrout, "%s", res);
	if (tmp != 1 || !is_double(res)) ERROR("y좌표 출력이 잘못되었습니다.");
	sscanf(res, "%lf", &Y1);

	tmp = fscanf(usrout, "%s", res);
	if (tmp != 1 || !is_double(res)) ERROR("y좌표 출력이 잘못되었습니다.");
	sscanf(res, "%lf", &Y2);

	tmp = fscanf(usrout, "%s", res);
	if (tmp == 1) ERROR("불필요한 출력..");

	if (X1 > X2) swap(X1, X2);
	if (Y1 > Y2) swap(Y1, Y2);

	for (i = 1; i <= N; i++) {
		if (abs(X1 - X[i]) <= 1e-5) ERROR("직선이 보석 지나감");
		if (abs(X2 - X[i]) <= 1e-5) ERROR("직선이 보석 지나감");
		if (abs(Y1 - Y[i]) <= 1e-5) ERROR("직선이 보석 지나감");
		if (abs(Y2 - Y[i]) <= 1e-5) ERROR("직선이 보석 지나감");
	}

	if (abs(X1 - X2) <= 1e-5) ERROR("같은 직선 2개");
	if (abs(Y1 - Y2) <= 1e-5) ERROR("같은 직선 2개");

	for (i = 1; i <= N; i++) {
		if (X[i] < X1) {
			if (Y[i] < Y1) ++a[0];
			else if (Y[i] < Y2) ++a[1];
			else ++a[2];
		}
		else if (X[i] < X2){
			if (Y[i] < Y1) ++a[3];
			else if (Y[i] < Y2) ++a[4];
			else ++a[5];
		}
		else {
			if (Y[i] < Y1) ++a[6];
			else if (Y[i] < Y2) ++a[7];
			else ++a[8];
		}
	}

	sort(a, a + 9);
	sort(A, A + 9);
	for (i = 0; i < 9; i++) if (a[i] != A[i]) ERROR("제대로 분할 안됨");

	fcloseall();
	puts("Correct");
	return 0;
}