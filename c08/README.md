
# 팰린드롬의 최소삽입거리 minimum insertion palindrome

## 정의

> 팬린드롬(palindrome)이란 회문으로 'level', 'deed'와 같이 역순으로 읽어도 같은 문장이 되는 절 또는 숫자를 말한다. 
> 일반적으로 단어사이 구두점과 뛰어쓰기는 허용된다.


Ref : 
  - https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/

---

### 입력

첫째 줄에 팰린드롬의 최소 삽입거리를 구할 문자열을 입력한다.
`ex: zzazz`

### 출력 

첫째 줄에 최소 삽입 횟수를 출력한다.

| 번호 | 입력     | 출력 |
| :--- | :------- | :--- |
| 1    | zzazz    | 0    |
| 2    | mbadm    | 2    |
| 3    | leetcode | 5    |


---


### 점화식 세우기

먼저 무차별 대입방식으로 base case를 도출해본다.

문제의 정의가 편집이 아닌 삽입이기 때문에 팰린드롬문자열을 만들기위해 최소문자를 삽입하는 케이스를 도출한다.


| 번호 | 입력  | 출력 |
| :--- | :---- | :--- |
| 1    | aba   | 0    |
| 2    | abcea | 2    |
| 3    | xaaaa | 5    |


```console
0 : aba -> 삽입케이스 없음
2 : abcea -> b,e가 다르므로 be 앞뒤로 e,b 삽입
        a b[e] c e[b] a
  또는  a [e]b c [b]e a
1 : xaaaa -> x,a가 다르므로 xa 앞뒤로 a,x 삽입
        x[a] aaa a[x]
           x aaa a[x] -> a를 삽입하지 않아도 회문문자열 가능
```


매번 두 문자 사이에 임의의 문자를 삽입하는 경우 시간 복잡도는 지수 수준으로 증가하기 때문에 동적 계획법으로 해결한다.

| Input | i     | i+1   |      | j-1   | j     | 최소삽입 |
| :---- | :---- | :---- | :--- | :---- | :---- | :------- |
| 1     |       | a     | b    | a     |       | 0        |
| 2     | a     | b [e] | c    | e [b] | a     | 2        |
| 2     | a     | [e] b | c    | [b] e | a     | 2        |
| 3     | [a] x | a     | a    | a     | a [x] | 2        |
| 3     | x     | a     | a    | a     | a [x] | 1        |

5 - 2 = 3
3 + 1 = 4

6 - 2 = 4i
  x b a a b y
  0 1 2 3 4 5
i 4 3 2 1 0
j 5 4 3 2 1
  b
  y



  x a a a a
  0 1 2 3 4
i       a
j         a
i     a
j       a
i   a
j     a
i x
j   a

size = 5
i = 5 - 2 : 3
j = 3 + 1 : 4

i = 2
j = 3

```console
Input1. Input[i] == Input[j]
  - zz : dp[i][j] = 0
  - zz : dp[i+1][j-1] = 0
  - a : pass
Input2. Input[i] != Input[j]
  - be : dp[i+1][j-1] = 2 (삽입 케이스가 두번)
  - c : pass
Input3. Input[i] != Input[j]
  - be : dp[i+1][j-1] = 1 (삽입 케이스가 한번)
  - c : pass
```
Input3의 경우를 위해 최소값을 찾아야 한다.




 
```console

  i - - a a x
  j - 0 1 2 3
  - 0   
  a 1   0  
  a 3       1

```
    0 1 2 3 4
s = m b a d m

 i  1 2 3 4 
j   d m   0
1 b 
2 m
i 5 - 2 = 3
j 3 + 1 = 4



  x b a a b y
y x 1 2 3 4 5
b 1 b
a 2   a
a 3     a
b 4       b
x 5         y
