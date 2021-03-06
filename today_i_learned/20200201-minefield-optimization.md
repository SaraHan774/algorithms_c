### 지뢰찾기

* [코드 링크 : minefield.c](../minefield.c)

* 문제 
    * `*`은 지뢰이고 `.` 은 지뢰가 아니다. 
    * `.`인 자리에 바로 인접한 가로, 세로, 대각선에 있는 지뢰의 개수를 출력하라
    * input 은 [20200127.md](./20200127.md) 파일에서 확인  
    
* 시도 1 
    * `*`인 곳을 찾아서 그곳을 중심으로 근처 가로, 세로, 대각선 방향의 8칸을 if문으로 검사한다.
    * 검사 조건은 배열의 가로, 세로 길이를 넘는지 & 검사 자리에 `*` 이 없는지의 여부이다.  
    * `*`인 자리의 인덱스는 보조 배열에 -1로 표시해 놓는다. (출력 시 `*` 로 바꿔서 출력) 
    * 인접한 지뢰 개수만큼 보조 배열의 값을 1씩 증가시킨다. 
    * 대충 아래와 같은 엄청난 if 문들을 작성하게 되었다 ... 

```
for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){

            if(matrix[i][j] == '*'){
                ret_matrix[i][j] = -1;


                if(i <= m-1 && j <= n-1 && matrix[i+1][j+1] != '*'){
                    ret_matrix[i+1][j+1]++;
                }
                if(i >= 1 && j >= 1 && matrix[i-1][j-1] != '*'){
                    ret_matrix[i-1][j-1]++;
                }
                if(i <= m-1 && matrix[i+1][j] != '*'){
                    ret_matrix[i+1][j]++;
                }
                if(j <= n-1 && matrix[i][j+1] != '*'){
                    ret_matrix[i][j+1]++;
                }
                if(i >= 1 && matrix[i-1][j] != '*'){
                    ret_matrix[i-1][j]++;
                }
                if(j >= 1 && matrix[i][j-1] != '*'){
                    ret_matrix[i][j-1]++;
                }
                if(i >= 1 && j <= n - 1 && matrix[i-1][j+1] != '*'){
                    ret_matrix[i-1][j+1]++;
                }
                if(i <= m-1 && j >= 1 && matrix[i+1][j-1] != '*'){
                    ret_matrix[i+1][j-1]++;
                }
            }
        }
    }

```

* 시도 2 
    * `*` 중심으로 8군데 순회하는 과정을 for문으로 처리한다. 
    * 변화량을 배열에 담는다. 예를들어 `matrix[i + 변화량][j + 변화량]` 과 같이 처리한다. 
    * 만약 `i + 변화량` 과 `j + 변화량` 이 배열의 가로, 세로 길이보다 크거나 작을 경우 (인덱스 범위를 벗어난 경우) 곧바로 for 문을 `continue` 키워드로 건너뛰어 버린다. 
    * if 문의 개수가 현저히 줄었다. 
    
```
#include <stdio.h>
#include <stdlib.h>
#define DELTA 8

...

int main(){ 

    int dx []= {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy [] = {-1, 0, 1, -1, 1, -1, 0, 1};

    int m, n;
    int row_size = m;
    int col_size = n;
    //행렬의 크기 입력받기 m x n 행렬
    scanf("%d", &m);
    scanf("%d", &n);

...

for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){

            if(matrix[i][j] == '*'){
                ret_matrix[i][j] = -1;

                //시도 2 
                for(int k = 0; k < DELTA; k++){

                    printf("DEBUG : dx[%d] = %d, dy[%d] = %d \n", k, dx[k], k, dy[k]);
                    printf("DEBUG : i = %d, j = %d\n", i, j);

                    if((i + dx[k] > row_size || i + dx[k] < 0) || (j + dy[k] > col_size || j + dy[k] < 0)){
                        continue;
                    }

                    if(matrix[i + dx[k]][j + dy[k]] != '*'){
                        puts("DEBUG : ret_matrix++");
                        ret_matrix[i + dx[k]][j + dy[k]]++;
                    }
                }
            }
        }
    }

... 


```