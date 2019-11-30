### Recursion 

* Factorial (순차 곱셈)
    * n 을 인자로 받는다. 
    * n 이 0보다 큰 경우 n * f(n-1) 을 반환한다. 
    * n 이 0 이 될 때 1을 반환한다. 
    
* 직접 재귀, 간접 재귀 
    * 함수 내부에서 자기 자신의 함수를 다시 호출하면 직접 재귀이다. 
    * 함수 a가 b 를 호출하고 다시 b 가 a를 호출하는 경우 간접 재귀이다. 
    
* 재귀 알고리즘에 알맞는 경우는 
    * 풀어야 할 문제
    * 계산할 함수 
    * 처리할 데이터 구조가 재귀로 정의되는 경우이다. 
    
* 유클리드 호제법 
    * 최대공약수를 재귀적으로 구하는 방법 (Greatest Common Divisor)
    * 직사각형을 정사각형으로 완전히 채운다. 
    * 이렇게 만들 수 있는 정사각형의 가장 긴 변의 길이를 구한다. 
    
``` 
x = a*z 와 y = b*z 를 만족시키는 최대의 정수 z가 존재할 때
z = gdc(x, y)  

최대 공약수는 y = 0 이면 x이고
y가 0이 아니면, gcd(y , x % y) 이다.  

```

### 재귀 알고리즘 분석 

* 하향식 분석과 상향식 분석 (top down & bottom up)

* 재귀 알고리즘의 분석 
    * 재귀 호출을 여러 회 실행하는 함수를 순수하게(genuinely) 재귀적이라 함. 

* [메모이제이션](https://ko.wikipedia.org/wiki/%EB%A9%94%EB%AA%A8%EC%9D%B4%EC%A0%9C%EC%9D%B4%EC%85%98)
    * 배열에 계산 결과를 저장, 위로 올라가면서 배열의 값을 가져다 씀. 

* [블로그 포스트: 꼬리 재귀 최적화(Tail Recursion)](https://bozeury.tistory.com/entry/%EA%BC%AC%EB%A6%AC-%EC%9E%AC%EA%B7%80-%EC%B5%9C%EC%A0%81%ED%99%94Tail-Recursion) 


---

### 보충 
* [로버트 세지윅 : Algorithms in C - ch5.Recursion](https://drive.google.com/file/d/1nFHnmzGAYL1uSIo1qcmZRTYul3N29xUb/view?usp=sharing)

## Recursion and Trees 

* 재귀의 개념은 재귀적으로 정의된 구조인 Tree와 깊은 연관이 있다. 
    * 재귀적으로 짜여진 프로그램을 이해하기 위해 트리를 사용하고, 
    * 트리를 이해하기 위해 재귀를 사용한다. 
    
* 중요한 주제들 
    * divide and conquer : fundamental recursive scheme 
    * dynamic programming : general approach to implementing recursive programs 
    * tree traversal : tree traversal methods underlie recursive tree-processing programs 
    * depth first search : basis for many graph processing algorithms 

* Recursion 을 이용한 프로그램은 언제나 non-recursive 하게 작성할 수 있다. 

* Recursion 을 가능케 한 요인 
    * built-in pushdown stack
    * stack 이 가득 차면 안되므로 최초의 매개변수 N보다 작은 k가 넘어오는 것이 보장되어야. 
        * 언젠가는 끝나야 하므로

* Conditions (Factorial 예제에서) 
    * "They must explicitly solve a basis case" 
        * It computes 0! 
    * "Each recursive call must involve smaller values of the arguments"
        * Under the assumption that it computes k! for k<N (inductive hypothesis), it computes N!
    

    
* Recursive program to evaluate prefix expressions 

```
char *a;
int i;

int eval(){
    int x = 0;
    while(a[i] == ' '){
        i++;
    }

    if(a[i] == '+'){
        i++;
        return eval() + eval();
    }

    if(a[i] == '*'){
        i++;
        return eval() * eval();
    }

    while((a[i] >= '0') && (a[i] <= '9')){
        x = 10 * x + (a[i++] - '0');
        return x;
    }
}
```

* This program is a simple example of a _recursive descent parser_ 
* We can use the same process to convert C programs into machine code. 


* 노드와 포인터로 이루어진 자료 구조들은 내재적으로 재귀성을 띤다. 
    * 따라서, 재귀 프로그램들은 이러한 자료 구조를 조작하는 데 자주 사용되는 함수들에 대한 자연스러운 구현들을 제공한다. 


### Fibonacci Sequence - Recursion with memoization 

```
if n = 0, 1 
    return n

if Fn is in memory, return Fn 
 
if n>1 
    Fn =  F(n-1) + F(n-2)
    save Fn in memory 
    return Fn 
```

* 구현 (memoization) 

```
#include <stdio.h>
#include <time.h>
#define MAX_MEMO 100

int memo[MAX_MEMO];

int fibonacci(int N){
    //base condition
    if(N <= 1){
        return N;
    }

    if(memo[N] != -1){
        return memo[N];
    }

    memo[N] = fibonacci(N-1) + fibonacci(N-2);

    return memo[N];
}

int main(){

    int k;
    for(k = 0; k < 100; k++){
        memo[k] = -1;
    }

    clock_t start, end;

    start = clock();
    int result = fibonacci(40); //raw : 603ms
    end = clock();
    printf("Fibonacci Result : %d , Time : %ld", result, end - start);

    return 0;
}

```


