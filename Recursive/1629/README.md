# 곱셈

https://www.acmicpc.net/problem/1629

## 풀이

a^n를 계산했으면 a^(2n)과 a^(2n+1)도 O(1)에 계산할 수 있음

a^(2n) % b = (a^n % b)^2 % b

a^(2n+1) % b = ((a^n % b)^2 % b) * a % b
