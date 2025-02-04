//邻接的格子的坐标
const int dx[5] = {-1, 0, 0, 0, 1};
const int dy[5] = {0, -1, 0, 1, 0};

//输入
int M, N;
int tile[MAX_M][MAX_N];

int opt[MAX_M][MAX_N];   //保存最优解
int flip[MAX_M][MAX_N];  //保存中间结果

//查询(x,y)的颜色
int get(int x, int y) {
	int c = tile[x][y];
	for (int d = 0; d < 5; d++) {
		int x2 = x + dx[d], y2 = y + dy[d];
		if (0 <= x2 && x2 < M && 0 < y2 && y2 < N) {
			c += flip[x2][y2];
		}
	}
	return c % 2;
} 

//求出第 1 行确定情况下的最小操作次数
//不存在解的话返回 -1
int calc() {
	//求出从第 2 行开始的翻转方法
	for (int i = 1; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (get(i-1, j) != 0) {
				//(i-1,j)是黑色的话，则必须翻转这个格子
				flip[i][j] = 1; 
			}
		}
	}
	
	//判断最后一行是否全白
	for (int j = 0; j < N; j++) {
		if (get(M - 1, j) !=0 ) {
			//无解
			return -1; 
		}
	} 
	
	//统计翻转的次数
	int res = 0;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			res += flip[i][j];
		}
	} 
	return res;
} 

void solve() {
	int res = -1;
	
	//按照字典序尝试第一行的所有可能性
	for (int i = 0; i < 1 << N; i++) {
		memset(flip, 0 , sizeof(flip));
		for (int j = 0; j < N; j++) {
			flip[0][N - j - 1] = i >> j & 1;
		}
		int num = calc();
		if (num >= 0 && (res < 0 || res > num)) {
			res = num;
			memcpy(opt, flip, sizeof(flip));
		}		
	} 
	
	if (res < 0) {
		//无解
		printf("IMPOSSIBLE\n");		 
	} else {
	  for (int i = 0; i < M; i++) {
	  	for (int j = 0; j < N; j++) {
	  		printf("%d%c", opt[i][j], j + 1 == N ? '\n' : ' ');
	  	}
	  }
	}
}



