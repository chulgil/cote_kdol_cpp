
## Longest Common Subsequence

### 정의
Ref : 
  - https://www.acmicpc.net/problem/9251
  - https://www.techiedelight.com/ko/longest-common-subsequence/

> Longest Common Substring : 
> 부분 수열 중 공통된 가장 긴 문자열을 의미
>
> [A BCD EF]  F BCD FG -> BCD

> Longest Common Subsequence : *이번문제
> 부분 수열 중 공통된 가장 긴 수열을 의미
>
> [A BCD E F] , [F BCDF G] -> BCDF
>

### 입력

첫째 줄과 둘째 줄에 두 문자열이 주어진다. 
문자열은 알파벳 대문자로만 이루어져 있으며, 최대 1000글자로 이루어져 있다.

> ACAYKP
> 
> CAPCAK

### 출력 
첫째 줄에 입력으로 주어진 두 문자열의 LCS의 길이를 출력한다.

> ACAK
> 
> 4

### 최장 공통 문자열 점화식
```

  i 0 1 2 3 4 5 6
j - - A C A Y K P
0 - 0 0 0 0 0 0 0
1 C 0 0 1 1 1 1 1
2 A 0 1 1 2 2 2 2
3 P 0 1 1 2 2 2 3
4 C 0 1 2 2 2 2 2
5 A 0 2 2 3 3 3 3
6 K 0 2 2 3 3 4 4



  i 0 1 2 3 4 5 6
j - - A B C D E F
0 - 0 0 0 0 0 0 0
1 F 0 0 0 0 0 0 1
2 B 0 0 1 0 0 0 0
3 C 0 0 0 2 0 0 0
4 D 0 0 0 0 3 0 0
5 F 0 0 0 0 0 0 1
6 G 0 0 0 0 0 0 0

W[A,B,C,D,E,F]
H[F,B,C,D,F,G]
LCS[i][j] = {0}

if W[i] == H[j]:
    LCS[i][j] = LCS[i - 1][j - 1] + 1
else
    LCS[i][j] = 0

개선

LCS[i] = {0}
if W[i] == H[j]:
    LCS[i] = LCS[i - 1] + 1
else
    LCS[i] = 0
```

### 최장 공통 부분수열 점화식

```
  i 0 1 2 3 4 5 6
j - - A B C D B F
0 - 0 0 0 0 0 0 0
1 A 0 1 1 1 1 1 1
2 C 0 1 1 2 2 2 2
3 A 0 2 2 3 3 3 3
4 B 0 2 3 3 3 3 3
5 D 0 2 3 3 4 4 4
6 G 0 2 3 3 4 4 4

W[A,B,C,D,E,F]
H[A,C,A,B,D,G]
LCS[i] = {0}
if W[i] == H[j]:
    LCS[i] = LCS[i - 1] + 1
else
    LCS[i] = MAX(LCS[i-1], LCS[i])



  i 0 1 2 3 4 5 6
j - - A C A Y K P
0 - 0 0 0 0 0 0 0
1 C 0 0 1 1 1 1 1
2 A 0 1 1 2 2 2 2
3 P 0 1 1 2 2 2 3
4 C 0 1 2 2 2 2 3
5 A 0 2 2 3 3 3 3
6 K 0 2 2 3 3 4 4


  i 0 1 2 3 4 5 6 7
j - - A B C B D A B
0 - 0 0 0 0 0 0 0 0
1 B 0 0 1 1 1 1 1 1
2 D 0 0 1 1 2 3 3 3
3 C 0 0 1 2 2 3 3 3
4 A 0 1 1 2 2 3 4 4
5 B 0 1 2 2 3 3 4 5
6 A 0 1 2 2 3 3 4 5

-> 4


  i 0 1 2 3 4 5 6
j - - A G G T A B
0 - 0 0 0 0 0 0 0
1 G 0 0 1 1 1 1 1
2 X 0 0 1 1 1 1 1
3 T 0 0 1 1 2 2 2
4 X 0 0 1 1 2 2 2
5 A 0 1 1 1 2 3 3
6 Y 0 1 1 1 2 3 3
7 B 0 1 1 1 2 3 4

A G G T A B 에서 G가 몇번 연속 -> 1
A G G T A B 에서 GXT가 몇번 연속 -> 2
A G G T A B 에서 GXTXA가 몇번 연속 -> 3
A G G T A B 에서 GXTXAYB가 몇번 연속 -> 4

같으면 대각선+1
다르면 MAX(오른쪽,위쪽)

```
ABC 에서 AAC를 찾는경우 

LCS(X, Y)

LCS(ABC, AAC) = MAX(LCS(AB, AAC), LCS(ABC, AA))

LCS(AB, AAC) = LCS(AB, AA) + C
LCS(ABC, AA) = LCS(AB, AAC) + C


