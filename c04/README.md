
## backtracking (최장 증가 부분 수열)

### 정의
> Ref : 
> 
> https://www.acmicpc.net/problem/15649
> 
> https://github.com/encrypted-def/basic-algo-lecture/blob/master/0x0C/15649.cpp


```mermaid


flowchart TD

%% Colors %%
classDef blue fill:#66deff,stroke:#000,color:#000
classDef green fill:#6ad98b,stroke:#000,color:#000

n0["루트
선택[1,2,3] 경로[]"]

n0 --> |1| n1( )
n0 --> |2| n2( ):::blue
n0 --> |3| n3( )

n0 -- "후위순회" --> n1( ):::green
n1 -- "전위순회" --> n0


n2 --> |1| n2n1( )
n2 --> |3| n2n3( )

n3["선택[1,2]
경로[3]"]
n3 --> |1| n3n1( )
n3 --> |2| n3n2( )

n1 --> |3| n1n3( )
n1n2 --> |3| n1n2n3( )
n1n3 --> |2| n1n3n2( )

```



### 역추적 알고리즘의 수도코드
```

result = []
def backtrack(경로, 선택리스트):
    if 종료조건 만족:
        result.add
        return
    for 선택 in 선택리스트:
        선택하기
        backtrack(경로, 선택리스트)
        선택해제


for 선택 in 선택리스트:
    선택리스트에서 선택 제거
    경로.add(선택)

    backtrack(경로, 선택리스트)
    
    경로.remove(선택)
    선택을 선택리스트로 복원


```
