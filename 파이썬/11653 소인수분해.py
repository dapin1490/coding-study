n = int(input())
div = 2

while n != 1:
    if n % div == 0:
        print(div)
        n //= div  # "n /= div"라고 써도 결과는 정상적으로 출력되지만 n이 실수형으로 바뀐다
    else:
        div += 1
